// This determines how much higher above the usual position the enemy Pokémon
// is during battle. Species that float or fly have nonzero values.
const u8 gEnemyMonElevation[NUM_SPECIES] =
{
    [SPECIES_BUTTERFREE] = 8,
    [SPECIES_BEEDRILL] = 8,
    [SPECIES_PIDGEY] = 16,
    [SPECIES_PIDGEOT] = 4,
    [SPECIES_FEAROW] = 6,
    [SPECIES_ZUBAT] = 8,
    [SPECIES_GOLBAT] = 8,
    [SPECIES_VENOMOTH] = 8,
    [SPECIES_GEODUDE] = 16,
    [SPECIES_MAGNEMITE] = 16,
    [SPECIES_MAGNETON] = 8,
    [SPECIES_GASTLY] = 4,
    [SPECIES_HAUNTER] = 4,
    [SPECIES_VOLTORB] = 10,
    [SPECIES_ELECTRODE] = 12,
    [SPECIES_KOFFING] = 8,
    [SPECIES_WEEZING] = 6,
    [SPECIES_AERODACTYL] = 7,
    [SPECIES_ARTICUNO] = 6,
    [SPECIES_ZAPDOS] = 8,
    [SPECIES_MOLTRES] = 5,
    [SPECIES_DRAGONITE] = 6,
    [SPECIES_MEW] = 8,
    [SPECIES_LEDIAN] = 8,
    [SPECIES_CROBAT] = 6,
    [SPECIES_HOPPIP] = 11,
    [SPECIES_SKIPLOOM] = 12,
    [SPECIES_JUMPLUFF] = 9,
    [SPECIES_YANMA] = 8,
    [SPECIES_MISDREAVUS] = 8,
    [SPECIES_UNOWN] = 8,
    [SPECIES_GLIGAR] = 6,
    [SPECIES_LUGIA] = 6,
    [SPECIES_HO_OH] = 6,
    [SPECIES_CELEBI] = 15,
    [SPECIES_BEAUTIFLY] = 8,
    [SPECIES_DUSTOX] = 10,
    [SPECIES_NINJASK] = 10,
    [SPECIES_SHEDINJA] = 8,
    [SPECIES_WINGULL] = 16,
    [SPECIES_PELIPPER] = 8,
    [SPECIES_MASQUERAIN] = 10,
    [SPECIES_BALTOY] = 4,
    [SPECIES_CLAYDOL] = 10,
    [SPECIES_FLYGON] = 7,
    [SPECIES_GLALIE] = 12,
    [SPECIES_LUNATONE] = 13,
    [SPECIES_SOLROCK] = 4,
    [SPECIES_SWABLU] = 12,
    [SPECIES_ALTARIA] = 8,
    [SPECIES_DUSKULL] = 9,
    [SPECIES_SHUPPET] = 12,
    [SPECIES_BANETTE] = 8,
    [SPECIES_CASTFORM] = 16,
    [SPECIES_BELDUM] = 8,
    [SPECIES_RAYQUAZA] = 6,
    [SPECIES_LATIAS] = 6,
    [SPECIES_LATIOS] = 6,
    [SPECIES_JIRACHI] = 12,
    [SPECIES_DEOXYS] = 8,
    [SPECIES_CHIMECHO] = 12,
    [SPECIES_BURMYPLANT] = 10,
    [SPECIES_BURMYSANDY] = 10,
    [SPECIES_BURMYTRASH] = 10,
    [SPECIES_WORMADAMPLANT] = 8,
    [SPECIES_WORMADAMSANDY] = 8,
    [SPECIES_WORMADAMTRASH] = 8,
    [SPECIES_MOTHIM] = 10,
    [SPECIES_COMBEE] = 15,
    [SPECIES_VESPIQUEN] = 4,
    [SPECIES_DRIFLOON] = 5,
    [SPECIES_DRIFBLIM] = 7,
    [SPECIES_MISMAGIUS] = 3,
    [SPECIES_BRONZOR] = 9,
    [SPECIES_BRONZONG] = 7,
    [SPECIES_CARNIVINE] = 8,
    [SPECIES_MAGNEZONE] = 4,
    [SPECIES_TOGEKISS] = 4,
    [SPECIES_YANMEGA] = 6,
    [SPECIES_GLISCOR] = 9,
    [SPECIES_PORYGONZ] = 2,
    [SPECIES_PROBOPASS] = 6,
    [SPECIES_DUSKNOIR] = 6,
    [SPECIES_FROSLASS] = 7,
    [SPECIES_ROTOM] = 10,
    // [SPECIES_ROTOMHEAT] = 6,
    // [SPECIES_ROTOMWASH] = 6,
    // [SPECIES_ROTOMFROST] = 6,
    // [SPECIES_ROTOMFAN] = 6,
    // [SPECIES_ROTOMMOW] = 6,
    [SPECIES_UXIE] = 6,
    [SPECIES_MESPRIT] = 6,
    [SPECIES_AZELF] = 6,
    // [SPECIES_GIRATINAORIGIN] = 7,
    [SPECIES_CRESSELIA] = 3,
    [SPECIES_PHIONE] = 8,
    [SPECIES_MANAPHY] = 10,
    [SPECIES_DARKRAI] = 4,
};
