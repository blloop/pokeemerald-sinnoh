#include "global.h"
#include "battle_anim.h"
#include "item_menu_icons.h"
#include "sprite.h"
#include "random.h"
#include "gpu_regs.h"
#include "item.h"
#include "rtc.h"
#include "item_icon.h"
#include "sound.h"
#include "menu.h"
#include "malloc.h"
#include "util.h"
#include "trig.h"
#include "graphics.h"
#include "battle_scripts.h"
#include "battle_controllers.h"
#include "constants/moves.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "battle_util.h"
#include "constants/songs.h"

static void SpriteCB_SpriteOnMonForDuration(struct Sprite *sprite);

// const data
// general
static const union AffineAnimCmd sSquishTargetAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 64, 0, 16), //Flatten
    AFFINEANIMCMD_FRAME(0, 0, 0, 64),
    AFFINEANIMCMD_FRAME(0, -64, 0, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSquishTargetShortAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 64, 0, 4), //Flatten
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -64, 0, 4),
    AFFINEANIMCMD_END,
};

// U-Turn
const struct SpriteTemplate gUTurnBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimShadowBall,
};

const struct SpriteTemplate gUTurnBallBackSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_RAZOR_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gAffineAnims_ShadowBall,
    .callback = AnimAbsorptionOrb,
};

// shadow sneak
const struct SpriteTemplate gShadowSneakImpactSpriteTemplate =
{
    .tileTag = ANIM_TAG_IMPACT,
    .paletteTag = ANIM_TAG_HANDS_AND_FEET,
    .oam = &gOamData_AffineNormal_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_IceCrystalHit,
    .callback = AnimIceEffectParticle
};

// power trick
const struct SpriteTemplate gPowerTrickSpriteTemplate =
{
    .tileTag = ANIM_TAG_POWER_TRICK,
    .paletteTag = ANIM_TAG_POWER_TRICK,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sAffineAnims_SpinningBone,
    .callback = SpriteCB_SpriteOnMonForDuration
};

static void AnimTask_WaitAffineAnim(u8 taskId)
{
    struct Task* task = &gTasks[taskId];

    if (!RunAffineAnimFromTaskData(task))
        DestroyAnimVisualTask(taskId);
}

void AnimTask_SquishTarget(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);

    PrepareAffineAnimInTaskData(task, spriteId, sSquishTargetAffineAnimCmds);
    task->func = AnimTask_WaitAffineAnim;
}

void AnimTask_SquishTargetShort(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);

    PrepareAffineAnimInTaskData(task, spriteId, sSquishTargetShortAffineAnimCmds);
    task->func = AnimTask_WaitAffineAnim;
}

const union AffineAnimCmd sSpriteAffineAnim_HydroCannonBall[] = {
    AFFINEANIMCMD_FRAME(16, 16, 0, 16), //Double in size
    AFFINEANIMCMD_END
};

const union AffineAnimCmd* const sSpriteAffineAnimTable_HydroCannonBall[] = {
    sSpriteAffineAnim_HydroCannonBall,
};

const struct SpriteTemplate gSpriteTemplate_ChloroblastShot = {
    .tileTag = ANIM_TAG_HYDRO_PUMP,
    .paletteTag = ANIM_TAG_HYDRO_PUMP,
    .oam = &gOamData_AffineDouble_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_HydroCannonBall,
    .callback = AnimShadowBall
};

u8 LoadBattleAnimTarget(u8 arg)
{
    u8 battler;

    if (IsDoubleBattle())
    {
        switch (gBattleAnimArgs[arg])
        {
        case 0:
            battler = gBattleAnimAttacker;
            break;
        default:
            battler = gBattleAnimTarget;
            break;
        case 2:
            battler = BATTLE_PARTNER(gBattleAnimAttacker);
            break;
        case 3:
            battler = BATTLE_PARTNER(gBattleAnimTarget);
            break;
        }
    }
    else
    {
        if (gBattleAnimArgs[arg] == 0)
            battler = gBattleAnimAttacker;
        else
            battler = gBattleAnimTarget;
    }

    return battler;
}

static void SpriteCB_SpriteOnMonForDuration(struct Sprite *sprite)
{
    u8 target = LoadBattleAnimTarget(0);

    if (!IsBattlerSpriteVisible(target))
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(target, 0);
        sprite->y = GetBattlerSpriteCoord(target, 1);
        sprite->x += gBattleAnimArgs[1];
        sprite->y += gBattleAnimArgs[2];
        sprite->data[0] = 0;
        sprite->data[1] = gBattleAnimArgs[3];
        sprite->data[2] = gBattleAnimArgs[4];
        sprite->data[3] = 0;
        sprite->callback = AnimBrickBreakWall_Step;
    }
}
