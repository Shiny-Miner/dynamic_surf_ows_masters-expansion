#include "defines.h"
#include "config.h"
#include "pal_tags.h"
#include "../include/global.h"
#include "../include/field_effect.h"
#include "../include/species.h"
#include "../include/moves.h"
#include "../include/sprite.h"
#include "../include/gba/types.h"
#include "../include/fieldmap.h"


#define PAL_TAG_SURF_BLOB 0x1100
#define PAL_TAG_SURF_NEW 0x3001

#define NO_OVERLAY {0, 0, NULL, NULL, NULL, NULL, NULL}

#define overworld_frame(ptr, width, height, frame) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}
#define surf_template(tag, image, cb) {.tileTag = 0xFFFF, .paletteTag = tag, .oam = gEventObjectBaseOam_32x32, .anims = gSurfablePokemonAnimTable, .images = image, .affineAnims = gDummySpriteAffineAnimTable, .callback = cb}

extern s32 gFieldEffectArguments[8];
extern void UpdateSurfMonOverlay(struct Sprite *sprite);

const struct Coords16 sDirectionToVectors[] = {
    { 0,  0},
    { 0,  1},
    { 0, -1},
    {-1,  0},
    { 1,  0},
    {-1,  1},
    { 1,  1},
    {-1, -1},
    { 1, -1}
};

// Images
/*==============================
GEN I
==============================*/
extern const u32 surfBlobTiles[];
extern const u16 surfBlobPal[];

//=============== SQUIRTLE
extern const u32 squirtleTiles[];
extern const u16 squirtlePal[];
extern const u16 squirtleShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Squirtle[] = {
    overworld_frame(&squirtleTiles[0], 4, 4, 1),
    overworld_frame(&squirtleTiles[0], 4, 4, 0),
    overworld_frame(&squirtleTiles[0], 4, 4, 3),
    overworld_frame(&squirtleTiles[0], 4, 4, 2),
    overworld_frame(&squirtleTiles[0], 4, 4, 5),
    overworld_frame(&squirtleTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Squirtle[] = {
    overworld_frame(&squirtleTiles[0], 4, 4, 7),
    overworld_frame(&squirtleTiles[0], 4, 4, 6),
    overworld_frame(&squirtleTiles[0], 4, 4, 9),
    overworld_frame(&squirtleTiles[0], 4, 4, 8),
    overworld_frame(&squirtleTiles[0], 4, 4, 11),
    overworld_frame(&squirtleTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sSquirtleOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Squirtle, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSquirtleOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Squirtle, UpdateSurfMonOverlay);


//=============== WARTORTLE
extern const u32 wartortleTiles[];
extern const u16 wartortlePal[];
extern const u16 wartortleShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Wartortle[] = {
    overworld_frame(&wartortleTiles[0], 4, 4, 1),
    overworld_frame(&wartortleTiles[0], 4, 4, 0),
    overworld_frame(&wartortleTiles[0], 4, 4, 3),
    overworld_frame(&wartortleTiles[0], 4, 4, 2),
    overworld_frame(&wartortleTiles[0], 4, 4, 5),
    overworld_frame(&wartortleTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Wartortle[] = {
    overworld_frame(&wartortleTiles[0], 4, 4, 7),
    overworld_frame(&wartortleTiles[0], 4, 4, 6),
    overworld_frame(&wartortleTiles[0], 4, 4, 9),
    overworld_frame(&wartortleTiles[0], 4, 4, 8),
    overworld_frame(&wartortleTiles[0], 4, 4, 11),
    overworld_frame(&wartortleTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sWartortleOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Wartortle, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sWartortleOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Wartortle, UpdateSurfMonOverlay);

//=============== BLASTOISE
extern const u32 blastoiseTiles[];
extern const u16 blastoisePal[];
extern const u16 blastoiseShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Blastoise[] = {
    overworld_frame(&blastoiseTiles[0], 4, 4, 1),
    overworld_frame(&blastoiseTiles[0], 4, 4, 0),
    overworld_frame(&blastoiseTiles[0], 4, 4, 3),
    overworld_frame(&blastoiseTiles[0], 4, 4, 2),
    overworld_frame(&blastoiseTiles[0], 4, 4, 5),
    overworld_frame(&blastoiseTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Blastoise[] = {
    overworld_frame(&blastoiseTiles[0], 4, 4, 7),
    overworld_frame(&blastoiseTiles[0], 4, 4, 6),
    overworld_frame(&blastoiseTiles[0], 4, 4, 9),
    overworld_frame(&blastoiseTiles[0], 4, 4, 8),
    overworld_frame(&blastoiseTiles[0], 4, 4, 11),
    overworld_frame(&blastoiseTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sBlastoiseOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Blastoise, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sBlastoiseOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Blastoise, UpdateSurfMonOverlay);

//=============== NIDOQUEEN
//extern const u32 nidoqueenTiles[];
//extern const u16 nidoqueenPal[];
//extern const u16 nidoqueenShinyPal[];

//=============== NIDOKING
//extern const u32 nidokingTiles[];
//extern const u16 nidokingPal[];
//extern const u16 nidokingShinyPal[];

//=============== PSYDUCK
extern const u32 psyduckTiles[];
extern const u16 psyduckPal[];
extern const u16 psyduckShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Psyduck[] = {
    overworld_frame(&psyduckTiles[0], 4, 4, 0),
    overworld_frame(&psyduckTiles[0], 4, 4, 1),
    overworld_frame(&psyduckTiles[0], 4, 4, 2),
    overworld_frame(&psyduckTiles[0], 4, 4, 3),
    overworld_frame(&psyduckTiles[0], 4, 4, 4),
    overworld_frame(&psyduckTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Psyduck[] = {
    overworld_frame(&psyduckTiles[0], 4, 4, 6),
    overworld_frame(&psyduckTiles[0], 4, 4, 7),
    overworld_frame(&psyduckTiles[0], 4, 4, 8),
    overworld_frame(&psyduckTiles[0], 4, 4, 9),
    overworld_frame(&psyduckTiles[0], 4, 4, 10),
    overworld_frame(&psyduckTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sPsyduckOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Psyduck, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPsyduckOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Psyduck, UpdateSurfMonOverlay);

//=============== GOLDUCK
extern const u32 golduckTiles[];
extern const u16 golduckPal[];
extern const u16 golduckShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Golduck[] = {
    overworld_frame(&golduckTiles[0], 4, 4, 0),
    overworld_frame(&golduckTiles[0], 4, 4, 1),
    overworld_frame(&golduckTiles[0], 4, 4, 2),
    overworld_frame(&golduckTiles[0], 4, 4, 3),
    overworld_frame(&golduckTiles[0], 4, 4, 4),
    overworld_frame(&golduckTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Golduck[] = {
    overworld_frame(&golduckTiles[0], 4, 4, 6),
    overworld_frame(&golduckTiles[0], 4, 4, 7),
    overworld_frame(&golduckTiles[0], 4, 4, 8),
    overworld_frame(&golduckTiles[0], 4, 4, 9),
    overworld_frame(&golduckTiles[0], 4, 4, 10),
    overworld_frame(&golduckTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sGolduckOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Golduck, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sGolduckOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Golduck, UpdateSurfMonOverlay);


//=============== POLIWAG
extern const u32 poliwagTiles[];
extern const u16 poliwagPal[];
//extern const u16 poliwagShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Poliwag[] = {
    overworld_frame(&poliwagTiles[0], 4, 4, 1),
    overworld_frame(&poliwagTiles[0], 4, 4, 0),
    overworld_frame(&poliwagTiles[0], 4, 4, 3),
    overworld_frame(&poliwagTiles[0], 4, 4, 2),
    overworld_frame(&poliwagTiles[0], 4, 4, 5),
    overworld_frame(&poliwagTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Poliwag[] = {
    overworld_frame(&poliwagTiles[0], 4, 4, 7),
    overworld_frame(&poliwagTiles[0], 4, 4, 6),
    overworld_frame(&poliwagTiles[0], 4, 4, 9),
    overworld_frame(&poliwagTiles[0], 4, 4, 8),
    overworld_frame(&poliwagTiles[0], 4, 4, 11),
    overworld_frame(&poliwagTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sPoliwagOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Poliwag, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPoliwagOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Poliwag, UpdateSurfMonOverlay);

//=============== POLIWHIRL
extern const u32 poliwhirlTiles[];
extern const u16 poliwhirlPal[];
//extern const u16 poliwhirlShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Poliwhirl[] = {
    overworld_frame(&poliwhirlTiles[0], 4, 4, 1),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 0),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 3),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 2),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 5),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Poliwhirl[] = {
    overworld_frame(&poliwhirlTiles[0], 4, 4, 7),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 6),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 9),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 8),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 11),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sPoliwhirlOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Poliwhirl, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPoliwhirlOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Poliwhirl, UpdateSurfMonOverlay);

//=============== POLIWRATH
extern const u32 poliwrathTiles[];
extern const u16 poliwrathPal[];
//extern const u16 poliwrathShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Poliwrath[] = {
    overworld_frame(&poliwrathTiles[0], 4, 4, 1),
    overworld_frame(&poliwrathTiles[0], 4, 4, 0),
    overworld_frame(&poliwrathTiles[0], 4, 4, 3),
    overworld_frame(&poliwrathTiles[0], 4, 4, 2),
    overworld_frame(&poliwrathTiles[0], 4, 4, 5),
    overworld_frame(&poliwrathTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Poliwrath[] = {
    overworld_frame(&poliwrathTiles[0], 4, 4, 7),
    overworld_frame(&poliwrathTiles[0], 4, 4, 6),
    overworld_frame(&poliwhirlTiles[0], 4, 4, 9),
    overworld_frame(&poliwrathTiles[0], 4, 4, 8),
    overworld_frame(&poliwrathTiles[0], 4, 4, 11),
    overworld_frame(&poliwrathTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sPoliwrathOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Poliwrath, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPoliwrathOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Poliwrath, UpdateSurfMonOverlay);


//=============== TENTACOOL
extern const u32 tentacoolTiles[];
extern const u16 tentacoolPal[];
extern const u16 tentacoolShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Tentacool[] = {
    overworld_frame(&tentacoolTiles[0], 4, 4, 1),
    overworld_frame(&tentacoolTiles[0], 4, 4, 0),
    overworld_frame(&tentacoolTiles[0], 4, 4, 3),
    overworld_frame(&tentacoolTiles[0], 4, 4, 2),
    overworld_frame(&tentacoolTiles[0], 4, 4, 5),
    overworld_frame(&tentacoolTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Tentacool[] = {
    overworld_frame(&tentacoolTiles[0], 4, 4, 7),
    overworld_frame(&tentacoolTiles[0], 4, 4, 6),
    overworld_frame(&tentacoolTiles[0], 4, 4, 9),
    overworld_frame(&tentacoolTiles[0], 4, 4, 8),
    overworld_frame(&tentacoolTiles[0], 4, 4, 11),
    overworld_frame(&tentacoolTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sTentacoolOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Tentacool, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sTentacoolOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Tentacool, UpdateSurfMonOverlay);

//=============== TENTACRUEL
extern const u32 tentacruelTiles[];
extern const u16 tentacruelPal[];
extern const u16 tentacruelShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Tentacruel[] = {
    overworld_frame(&tentacruelTiles[0], 4, 4, 1),
    overworld_frame(&tentacruelTiles[0], 4, 4, 0),
    overworld_frame(&tentacruelTiles[0], 4, 4, 3),
    overworld_frame(&tentacruelTiles[0], 4, 4, 2),
    overworld_frame(&tentacruelTiles[0], 4, 4, 4),
    overworld_frame(&tentacruelTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Tentacruel[] = {
    overworld_frame(&tentacruelTiles[0], 4, 4, 7),
    overworld_frame(&tentacruelTiles[0], 4, 4, 6),
    overworld_frame(&tentacruelTiles[0], 4, 4, 9),
    overworld_frame(&tentacruelTiles[0], 4, 4, 8),
    overworld_frame(&tentacruelTiles[0], 4, 4, 11),
    overworld_frame(&tentacruelTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sTentacruelOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Tentacruel, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sTentacruelOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Tentacruel, UpdateSurfMonOverlay);

//=============== SLOWPOKE
extern const u32 slowpokeTiles[];
extern const u16 slowpokePal[];
extern const u16 slowpokeShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Slowpoke[] = {
    overworld_frame(&slowpokeTiles[0], 4, 4, 0),
    overworld_frame(&slowpokeTiles[0], 4, 4, 1),
    overworld_frame(&slowpokeTiles[0], 4, 4, 2),
    overworld_frame(&slowpokeTiles[0], 4, 4, 3),
    overworld_frame(&slowpokeTiles[0], 4, 4, 4),
    overworld_frame(&slowpokeTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Slowpoke[] = {
    overworld_frame(&slowpokeTiles[0], 4, 4, 6),
    overworld_frame(&slowpokeTiles[0], 4, 4, 7),
    overworld_frame(&slowpokeTiles[0], 4, 4, 8),
    overworld_frame(&slowpokeTiles[0], 4, 4, 9),
    overworld_frame(&slowpokeTiles[0], 4, 4, 10),
    overworld_frame(&slowpokeTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sSlowpokeOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Slowpoke, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSlowpokeOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Slowpoke, UpdateSurfMonOverlay);

//=============== SLOWBRO
extern const u32 slowbroTiles[];
extern const u16 slowbroPal[];
extern const u16 slowbroShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Slowbro[] = {
    overworld_frame(&slowbroTiles[0], 4, 4, 0),
    overworld_frame(&slowbroTiles[0], 4, 4, 1),
    overworld_frame(&slowbroTiles[0], 4, 4, 2),
    overworld_frame(&slowbroTiles[0], 4, 4, 3),
    overworld_frame(&slowbroTiles[0], 4, 4, 4),
    overworld_frame(&slowbroTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Slowbro[] = {
    overworld_frame(&slowbroTiles[0], 4, 4, 6),
    overworld_frame(&slowbroTiles[0], 4, 4, 7),
    overworld_frame(&slowbroTiles[0], 4, 4, 8),
    overworld_frame(&slowbroTiles[0], 4, 4, 9),
    overworld_frame(&slowbroTiles[0], 4, 4, 10),
    overworld_frame(&slowbroTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sSlowbroOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Slowbro, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSlowbroOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Slowbro, UpdateSurfMonOverlay);

//=============== SEEL
extern const u32 seelTiles[];
extern const u16 seelPal[];
extern const u16 seelShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Seel[] = {
    overworld_frame(&seelTiles[0], 4, 4, 1),
    overworld_frame(&seelTiles[0], 4, 4, 0),
    overworld_frame(&seelTiles[0], 4, 4, 3),
    overworld_frame(&seelTiles[0], 4, 4, 2),
    overworld_frame(&seelTiles[0], 4, 4, 5),
    overworld_frame(&seelTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Seel[] = {
    overworld_frame(&seelTiles[0], 4, 4, 7),
    overworld_frame(&seelTiles[0], 4, 4, 6),
    overworld_frame(&seelTiles[0], 4, 4, 9),
    overworld_frame(&seelTiles[0], 4, 4, 8),
    overworld_frame(&seelTiles[0], 4, 4, 11),
    overworld_frame(&seelTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sSeelOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Seel, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSeelOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Seel, UpdateSurfMonOverlay);

//=============== DEWGONG
extern const u32 dewgongTiles[];
extern const u16 dewgongPal[];
extern const u16 dewgongShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Dewgong[] = {
    overworld_frame(&dewgongTiles[0], 4, 4, 1),
    overworld_frame(&dewgongTiles[0], 4, 4, 0),
    overworld_frame(&dewgongTiles[0], 4, 4, 3),
    overworld_frame(&dewgongTiles[0], 4, 4, 2),
    overworld_frame(&dewgongTiles[0], 4, 4, 5),
    overworld_frame(&dewgongTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Dewgong[] = {
    overworld_frame(&dewgongTiles[0], 4, 4, 7),
    overworld_frame(&dewgongTiles[0], 4, 4, 6),
    overworld_frame(&dewgongTiles[0], 4, 4, 9),
    overworld_frame(&dewgongTiles[0], 4, 4, 8),
    overworld_frame(&dewgongTiles[0], 4, 4, 11),
    overworld_frame(&dewgongTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sDewgongOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Dewgong, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sDewgongOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Dewgong, UpdateSurfMonOverlay);

//=============== SHELLDER
//extern const u32 shellderTiles[];
//extern const u16 shellderPal[];
//extern const u16 shellderShinyPal[];

//=============== CLOYSTER
//extern const u32 cloysterTiles[];
//extern const u16 cloysterPal[];
//extern const u16 cloysterShinyPal[];

//=============== KRABBY
//extern const u32 krabbyTiles[];
//extern const u16 krabbyPal[];
//extern const u16 krabbyShinyPal[];

//=============== KINGLER
//extern const u32 kinglerTiles[];
//extern const u16 kinglerPal[];
//extern const u16 kinglerShinyPal[];

//=============== LICKITUNG
//extern const u32 lickitungTiles[];
//extern const u16 lickitungPal[];
//extern const u16 lickitungShinyPal[];

//=============== RHYDON
//extern const u32 rhydonTiles[];
//extern const u16 rhydonPal[];
//extern const u16 rhydonShinyPal[];

//=============== KANGASKHAN
//extern const u32 kangaskhanTiles[];
//extern const u16 kangaskhanPal[];
//extern const u16 kangaskhanShinyPal[];

//=============== HORSEA
//extern const u32 horseaTiles[];
//extern const u16 horseaPal[];
//extern const u16 horseaShinyPal[];

//=============== SEADRA
//extern const u32 seadraTiles[];
//extern const u16 seadraPal[];
//extern const u16 seadraShinyPal[];

//=============== GOLDEEN
//extern const u32 goldeenTiles[];
//extern const u16 goldeenPal[];
//extern const u16 goldeenShinyPal[];

//=============== SEAKING
//extern const u32 seakingTiles[];
//extern const u16 seakingPal[];
//extern const u16 seakingShinyPal[];

//=============== STARYU
extern const u32 staryuTiles[];
extern const u16 staryuPal[];
extern const u16 staryuShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Staryu[] = {
    overworld_frame(&staryuTiles[0], 4, 4, 0),
    overworld_frame(&staryuTiles[0], 4, 4, 1),
    overworld_frame(&staryuTiles[0], 4, 4, 2),
    overworld_frame(&staryuTiles[0], 4, 4, 3),
    overworld_frame(&staryuTiles[0], 4, 4, 4),
    overworld_frame(&staryuTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Staryu[] = {
    overworld_frame(&staryuTiles[0], 4, 4, 6),
    overworld_frame(&staryuTiles[0], 4, 4, 7),
    overworld_frame(&staryuTiles[0], 4, 4, 8),
    overworld_frame(&staryuTiles[0], 4, 4, 9),
    overworld_frame(&staryuTiles[0], 4, 4, 10),
    overworld_frame(&staryuTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sStaryuOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Staryu, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sStaryuOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Staryu, UpdateSurfMonOverlay);

//=============== STARMIE
extern const u32 starmieTiles[];
extern const u16 starmiePal[];
extern const u16 starmieShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Starmie[] = {
    overworld_frame(&starmieTiles[0], 4, 4, 0),
    overworld_frame(&starmieTiles[0], 4, 4, 1),
    overworld_frame(&starmieTiles[0], 4, 4, 2),
    overworld_frame(&starmieTiles[0], 4, 4, 3),
    overworld_frame(&starmieTiles[0], 4, 4, 4),
    overworld_frame(&starmieTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Starmie[] = {
    overworld_frame(&starmieTiles[0], 4, 4, 6),
    overworld_frame(&starmieTiles[0], 4, 4, 7),
    overworld_frame(&starmieTiles[0], 4, 4, 8),
    overworld_frame(&starmieTiles[0], 4, 4, 9),
    overworld_frame(&starmieTiles[0], 4, 4, 10),
    overworld_frame(&starmieTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sStarmieOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Starmie, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sStarmieOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Starmie, UpdateSurfMonOverlay);

//=============== TAUROS
//extern const u32 taurosTiles[];
//extern const u16 taurosPal[];
//extern const u16 taurosShinyPal[];

//=============== GYARADOS
//extern const u32 gyaradosTiles[];
//extern const u16 gyaradosPal[];
//extern const u16 gyaradosShinyPal[];

//=============== LAPRAS
extern const u32 laprasTiles[];
extern const u16 laprasPal[];
extern const u16 laprasShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Lapras[] = {
    overworld_frame(&laprasTiles[0], 4, 4, 1),
    overworld_frame(&laprasTiles[0], 4, 4, 0),
    overworld_frame(&laprasTiles[0], 4, 4, 3),
    overworld_frame(&laprasTiles[0], 4, 4, 2),
    overworld_frame(&laprasTiles[0], 4, 4, 5),
    overworld_frame(&laprasTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Lapras[] = {
    overworld_frame(&laprasTiles[0], 4, 4, 7),
    overworld_frame(&laprasTiles[0], 4, 4, 6),
    overworld_frame(&laprasTiles[0], 4, 4, 9),
    overworld_frame(&laprasTiles[0], 4, 4, 8),
    overworld_frame(&laprasTiles[0], 4, 4, 11),
    overworld_frame(&laprasTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sLaprasOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Lapras, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLaprasOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Lapras, UpdateSurfMonOverlay);


//=============== VAPOREON
extern const u32 vaporeonTiles[];
extern const u16 vaporeonPal[];
extern const u16 vaporeonShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Vaporeon[] = {
    overworld_frame(&vaporeonTiles[0], 4, 4, 1),
    overworld_frame(&vaporeonTiles[0], 4, 4, 0),
    overworld_frame(&vaporeonTiles[0], 4, 4, 3),
    overworld_frame(&vaporeonTiles[0], 4, 4, 2),
    overworld_frame(&vaporeonTiles[0], 4, 4, 5),
    overworld_frame(&vaporeonTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Vaporeon[] = {
    overworld_frame(&vaporeonTiles[0], 4, 4, 7),
    overworld_frame(&vaporeonTiles[0], 4, 4, 6),
    overworld_frame(&vaporeonTiles[0], 4, 4, 9),
    overworld_frame(&vaporeonTiles[0], 4, 4, 8),
    overworld_frame(&vaporeonTiles[0], 4, 4, 11),
    overworld_frame(&vaporeonTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sVaporeonOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Vaporeon, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sVaporeonOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Vaporeon, UpdateSurfMonOverlay);


//=============== OMANYTE
//extern const u32 omanyteTiles[];
//extern const u16 omanytePal[];
//extern const u16 omanyteShinyPal[];

//=============== OMASTAR
//extern const u32 omastarTiles[];
//extern const u16 omastarPal[];
//extern const u16 omastarShinyPal[];

//=============== KABUTO
//extern const u32 kabutoTiles[];
//extern const u16 kabutoPal[];
//extern const u16 kabutoShinyPal[];

//=============== KABUTOPS
//extern const u32 kabutopsTiles[];
//extern const u16 kabutopsPal[];
//extern const u16 kabutopsShinyPal[];

//=============== SNORLAX
//extern const u32 snorlaxTiles[];
//extern const u16 snorlaxPal[];
//extern const u16 snorlaxShinyPal[];

//=============== DRATINI
//extern const u32 dratiniTiles[];
//extern const u16 dratiniPal[];
//extern const u16 dratiniShinyPal[];

//=============== DRAGONAIR
//extern const u32 dragonairTiles[];
//extern const u16 dragonairPal[];
//extern const u16 dragonairShinyPal[];

//=============== DRAGONITE
//extern const u32 dragoniteTiles[];
//extern const u16 dragonitePal[];
//extern const u16 dragoniteShinyPal[];

//=============== MEW
//extern const u32 mewTiles[];
//extern const u16 mewPal[];
//extern const u16 mewShinyPal[];

/*==============================
GEN II
==============================*/

//=============== TOTODILE
//extern const u32 totodileTiles[];
//extern const u16 totodilePal[];
//extern const u16 totodileShinyPal[];


//=============== CROCONAW
//extern const u32 croconawTiles[];
//extern const u16 croconawPal[];
//extern const u16 croconawShinyPal[];


//=============== FERALIGATR
//extern const u32 feraligatrTiles[];
//extern const u16 feraligatrPal[];
//extern const u16 feraligatrShinyPal[];

//=============== SENTRET
extern const u32 sentretTiles[];
extern const u16 sentretPal[];
extern const u16 sentretShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Sentret[] = {
    overworld_frame(&sentretTiles[0], 4, 4, 1),
    overworld_frame(&sentretTiles[0], 4, 4, 0),
    overworld_frame(&sentretTiles[0], 4, 4, 3),
    overworld_frame(&sentretTiles[0], 4, 4, 2),
    overworld_frame(&sentretTiles[0], 4, 4, 5),
    overworld_frame(&sentretTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Sentret[] = {
    overworld_frame(&sentretTiles[0], 4, 4, 7),
    overworld_frame(&sentretTiles[0], 4, 4, 6),
    overworld_frame(&sentretTiles[0], 4, 4, 9),
    overworld_frame(&sentretTiles[0], 4, 4, 8),
    overworld_frame(&sentretTiles[0], 4, 4, 11),
    overworld_frame(&sentretTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sSentretOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Sentret, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSentretOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Sentret, UpdateSurfMonOverlay);
//=============== FURRET
extern const u32 furretTiles[];
extern const u16 furretPal[];
extern const u16 furretShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Furret[] = {
    overworld_frame(&furretTiles[0], 4, 4, 1),
    overworld_frame(&furretTiles[0], 4, 4, 0),
    overworld_frame(&furretTiles[0], 4, 4, 3),
    overworld_frame(&furretTiles[0], 4, 4, 2),
    overworld_frame(&furretTiles[0], 4, 4, 5),
    overworld_frame(&furretTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Furret[] = {
    overworld_frame(&furretTiles[0], 4, 4, 7),
    overworld_frame(&furretTiles[0], 4, 4, 6),
    overworld_frame(&furretTiles[0], 4, 4, 9),
    overworld_frame(&furretTiles[0], 4, 4, 8),
    overworld_frame(&furretTiles[0], 4, 4, 11),
    overworld_frame(&furretTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sFurretOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Furret, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sFurretOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Furret, UpdateSurfMonOverlay);
//=============== CHINCHOU
//extern const u32 chinchouTiles[];
//extern const u16 chinchouPal[];
//extern const u16 chinchouShinyPal[];

//=============== LANTURN
//extern const u32 lanturnTiles[];
//extern const u16 lanturnPal[];
//extern const u16 lanturnShinyPal[];

//=============== MARILL
//extern const u32 marillTiles[];
//extern const u16 marillPal[];
//extern const u16 marillShinyPal[];

//=============== POLITOED
extern const u32 politoedTiles[];
extern const u16 politoedPal[];
//extern const u16 politoedShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Politoed[] = {
    overworld_frame(&politoedTiles[0], 4, 4, 0),
    overworld_frame(&politoedTiles[0], 4, 4, 1),
    overworld_frame(&politoedTiles[0], 4, 4, 2),
    overworld_frame(&politoedTiles[0], 4, 4, 3),
    overworld_frame(&politoedTiles[0], 4, 4, 4),
    overworld_frame(&politoedTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Politoed[] = {
    overworld_frame(&politoedTiles[0], 4, 4, 6),
    overworld_frame(&politoedTiles[0], 4, 4, 7),
    overworld_frame(&politoedTiles[0], 4, 4, 8),
    overworld_frame(&politoedTiles[0], 4, 4, 9),
    overworld_frame(&politoedTiles[0], 4, 4, 10),
    overworld_frame(&politoedTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sPolitoedOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Politoed, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPolitoedOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Politoed, UpdateSurfMonOverlay);


//=============== WOOPER
//extern const u32 wooperTiles[];
//extern const u16 wooperPal[];
//extern const u16 wooperShinyPal[];

//=============== QUAGSIRE
//extern const u32 quagsireTiles[];
//extern const u16 quagsirePal[];
//extern const u16 quagsireShinyPal[];

//=============== SLOWKING
extern const u32 slowkingTiles[];
extern const u16 slowkingPal[];
extern const u16 slowkingShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Slowking[] = {
    overworld_frame(&slowkingTiles[0], 4, 4, 0),
    overworld_frame(&slowkingTiles[0], 4, 4, 1),
    overworld_frame(&slowkingTiles[0], 4, 4, 2),
    overworld_frame(&slowkingTiles[0], 4, 4, 3),
    overworld_frame(&slowkingTiles[0], 4, 4, 4),
    overworld_frame(&slowkingTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Slowking[] = {
    overworld_frame(&slowkingTiles[0], 4, 4, 6),
    overworld_frame(&slowkingTiles[0], 4, 4, 7),
    overworld_frame(&slowkingTiles[0], 4, 4, 8),
    overworld_frame(&slowkingTiles[0], 4, 4, 9),
    overworld_frame(&slowkingTiles[0], 4, 4, 10),
    overworld_frame(&slowkingTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sSlowkingOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Slowking, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSlowkingOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Slowking, UpdateSurfMonOverlay);


//=============== QWILFISH
//extern const u32 qwilfishTiles[];
//extern const u16 qwilfishPal[];
//extern const u16 qwilfishShinyPal[];

//=============== SNEASEL
//extern const u32 sneaselTiles[];
//extern const u16 sneaselPal[];
//extern const u16 sneaselShinyPal[];

//=============== CORSOLA
//extern const u32 corsolaTiles[];
//extern const u16 corsolaPal[];
//extern const u16 corsolaShinyPal[];

//=============== REMORAID
//extern const u32 remoraidTiles[];
//extern const u16 remoraidPal[];
//extern const u16 remoraidShinyPal[];

//=============== OCTILLERY
//extern const u32 octilleryTiles[];
//extern const u16 octilleryPal[];
//extern const u16 octilleryShinyPal[];

//=============== MANTINE
//extern const u32 mantineTiles[];
//extern const u16 mantinePal[];
//extern const u16 mantineShinyPal[];

//=============== KINGDRA
//extern const u32 kingdraTiles[];
//extern const u16 kingdraPal[];
//extern const u16 kingdraShinyPal[];

//=============== MILTANK
//extern const u32 miltankTiles[];
//extern const u16 miltankPal[];
//extern const u16 miltankShinyPal[];

//=============== SUICUNE
//extern const u32 suicuneTiles[];
//extern const u16 suicunePal[];
//extern const u16 suicuneShinyPal[];

//=============== TYRANITAR
//extern const u32 tyranitarTiles[];
//extern const u16 tyranitarPal[];
//extern const u16 tyranitarShinyPal[];

//=============== LUGIA
//extern const u32 lugiaTiles[];
//extern const u16 lugiaPal[];
//extern const u16 lugiaShinyPal[];


/*==============================
GEN III
==============================*/
//=============== MUDKIP
//extern const u32 mudkipTiles[];
//extern const u16 mudkipPal[];
//extern const u16 mudkipShinyPal[];

//=============== MARSHTOMP
//extern const u32 marshtompTiles[];
//extern const u16 marshtompPal[];
//extern const u16 marshtompShinyPal[];

//=============== SWAMPERT
extern const u32 swampertTiles[];
extern const u16 swampertPal[];
extern const u16 swampertShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Swampert[] = {
    overworld_frame(&swampertTiles[0], 4, 4, 1),
    overworld_frame(&swampertTiles[0], 4, 4, 0),
    overworld_frame(&swampertTiles[0], 4, 4, 3),
    overworld_frame(&swampertTiles[0], 4, 4, 2),
    overworld_frame(&swampertTiles[0], 4, 4, 5),
    overworld_frame(&swampertTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Swampert[] = {
    overworld_frame(&swampertTiles[0], 4, 4, 7),
    overworld_frame(&swampertTiles[0], 4, 4, 6),
    overworld_frame(&swampertTiles[0], 4, 4, 9),
    overworld_frame(&swampertTiles[0], 4, 4, 8),
    overworld_frame(&swampertTiles[0], 4, 4, 11),
    overworld_frame(&swampertTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sSwampertOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Swampert, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSwampertOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Swampert, UpdateSurfMonOverlay);

//=============== ZIGZAGOON
//extern const u32 zigzagoonTiles[];
//extern const u16 zigzagoonPal[];
//extern const u16 zigzagoonShinyPal[];

//=============== LINOONE
//extern const u32 linooneTiles[];
//extern const u16 linoonePal[];
//extern const u16 linooneShinyPal[];

//=============== LOTAD
//extern const u32 lotadTiles[];
//extern const u16 lotadPal[];
//extern const u16 lotadShinyPal[];

//=============== LOMBRE
//extern const u32 lombreTiles[];
//extern const u16 lombrePal[];
//extern const u16 lombreShinyPal[];

//=============== LUDICOLO
//extern const u32 ludicoloTiles[];
//extern const u16 ludicoloPal[];
//extern const u16 ludicoloShinyPal[];

//=============== PELIPPER
//extern const u32 pelipperTiles[];
//extern const u16 pelipperPal[];
//extern const u16 pelipperShinyPal[];

//=============== EXPLOUD
//extern const u32 exploudTiles[];
//extern const u16 exploudPal[];
//extern const u16 exploudShinyPal[];

//=============== MAKUHITA
//extern const u32 makuhitaTiles[];
//extern const u16 makuhitaPal[];
//extern const u16 makuhitaShinyPal[];

//=============== HARIYAMA
//extern const u32 hariyamaTiles[];
//extern const u16 hariyamaPal[];
//extern const u16 hariyamaShinyPal[];

//=============== AGGRON
//extern const u32 aggronTiles[];
//extern const u16 aggronPal[];
//extern const u16 aggronShinyPal[];

//=============== CARVANHA
//extern const u32 carvanhaTiles[];
//extern const u16 carvanhaPal[];
//extern const u16 carvanhaShinyPal[];

//=============== SHARPEDO
//extern const u32 sharpedoTiles[];
//extern const u16 sharpedoPal[];
//extern const u16 sharpedoShinyPal[];

//=============== WAILMER
extern const u32 wailmerTiles[];
extern const u16 wailmerPal[];
extern const u16 wailmerShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Wailmer[] = {
    overworld_frame(&wailmerTiles[0], 4, 4, 1),
    overworld_frame(&wailmerTiles[0], 4, 4, 0),
    overworld_frame(&wailmerTiles[0], 4, 4, 3),
    overworld_frame(&wailmerTiles[0], 4, 4, 2),
    overworld_frame(&wailmerTiles[0], 4, 4, 5),
    overworld_frame(&wailmerTiles[0], 4, 4, 4),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Wailmer[] = {
    overworld_frame(&wailmerTiles[0], 4, 4, 7),
    overworld_frame(&wailmerTiles[0], 4, 4, 6),
    overworld_frame(&wailmerTiles[0], 4, 4, 9),
    overworld_frame(&wailmerTiles[0], 4, 4, 8),
    overworld_frame(&wailmerTiles[0], 4, 4, 11),
    overworld_frame(&wailmerTiles[0], 4, 4, 10),
};
const struct SpriteTemplate sWailmerOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Wailmer, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sWailmerOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Wailmer, UpdateSurfMonOverlay);

//=============== WAILORD
//extern const u32 wailordTiles[];
//extern const u16 wailordPal[];
//extern const u16 wailordShinyPal[];

//=============== BARBOACH
//extern const u32 barboachTiles[];
//extern const u16 barboachPal[];
//extern const u16 barboachShinyPal[];

//=============== WHISCASH
//extern const u32 whiscashTiles[];
//extern const u16 whiscashPal[];
//extern const u16 whiscashShinyPal[];

//=============== CORPHISH
//extern const u32 corphishTiles[];
//extern const u16 corphishPal[];
//extern const u16 corphishShinyPal[];

//=============== CRAWDAUNT
//extern const u32 crawdauntTiles[];
//extern const u16 crawdauntPal[];
//extern const u16 crawdauntShinyPal[];

//=============== FEEBAS
//extern const u32 feebasTiles[];
//extern const u16 feebasPal[];
//extern const u16 feebasShinyPal[];

//=============== MILOTIC
//extern const u32 miloticTiles[];
//extern const u16 miloticPal[];
//extern const u16 miloticShinyPal[];

//=============== SPHEAL
extern const u32 sphealTiles[];
extern const u16 sphealPal[];
extern const u16 sphealShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Spheal[] = {
    overworld_frame(&sphealTiles[0], 4, 4, 0),
    overworld_frame(&sphealTiles[0], 4, 4, 1),
    overworld_frame(&sphealTiles[0], 4, 4, 2),
    overworld_frame(&sphealTiles[0], 4, 4, 3),
    overworld_frame(&sphealTiles[0], 4, 4, 4),
    overworld_frame(&sphealTiles[0], 4, 4, 5),
};
const struct SpriteTemplate sSphealOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Spheal, UpdateSurfBlobFieldEffect);

//=============== AZUMARILL
extern const u32 azumarillTiles[];
extern const u16 azumarillPal[];
extern const u16 azumarillShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Azumarill[] = {
    overworld_frame(&azumarillTiles[0], 4, 4, 0),
    overworld_frame(&azumarillTiles[0], 4, 4, 1),
    overworld_frame(&azumarillTiles[0], 4, 4, 2),
    overworld_frame(&azumarillTiles[0], 4, 4, 3),
    overworld_frame(&azumarillTiles[0], 4, 4, 4),
    overworld_frame(&azumarillTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Azumarill[] = {
    overworld_frame(&azumarillTiles[0], 4, 4, 6),
    overworld_frame(&azumarillTiles[0], 4, 4, 7),
    overworld_frame(&azumarillTiles[0], 4, 4, 8),
    overworld_frame(&azumarillTiles[0], 4, 4, 9),
    overworld_frame(&azumarillTiles[0], 4, 4, 10),
    overworld_frame(&azumarillTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sAzumarillOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Azumarill, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sAzumarillOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Azumarill, UpdateSurfMonOverlay);
//=============== SEALEO
extern const u32 sealeoTiles[];
extern const u16 sealeoPal[];
extern const u16 sealeoShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Sealeo[] = {
    overworld_frame(&sealeoTiles[0], 4, 4, 0),
    overworld_frame(&sealeoTiles[0], 4, 4, 1),
    overworld_frame(&sealeoTiles[0], 4, 4, 2),
    overworld_frame(&sealeoTiles[0], 4, 4, 3),
    overworld_frame(&sealeoTiles[0], 4, 4, 4),
    overworld_frame(&sealeoTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Sealeo[] = {
    overworld_frame(&sealeoTiles[0], 4, 4, 6),
    overworld_frame(&sealeoTiles[0], 4, 4, 7),
    overworld_frame(&sealeoTiles[0], 4, 4, 8),
    overworld_frame(&sealeoTiles[0], 4, 4, 9),
    overworld_frame(&sealeoTiles[0], 4, 4, 10),
    overworld_frame(&sealeoTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sSealeoOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Sealeo, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSealeoOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Sealeo, UpdateSurfMonOverlay);


//=============== WALREIN
extern const u32 walreinTiles[];
extern const u16 walreinPal[];
extern const u16 walreinShinyPal[];
const struct SpriteFrameImage gSurfingOverworldPicTable_Walrein[] = {
    overworld_frame(&walreinTiles[0], 4, 4, 0),
    overworld_frame(&walreinTiles[0], 4, 4, 1),
    overworld_frame(&walreinTiles[0], 4, 4, 2),
    overworld_frame(&walreinTiles[0], 4, 4, 3),
    overworld_frame(&walreinTiles[0], 4, 4, 4),
    overworld_frame(&walreinTiles[0], 4, 4, 5),
};
const struct SpriteFrameImage gSurfingOverlayPicTable_Walrein[] = {
    overworld_frame(&walreinTiles[0], 4, 4, 6),
    overworld_frame(&walreinTiles[0], 4, 4, 7),
    overworld_frame(&walreinTiles[0], 4, 4, 8),
    overworld_frame(&walreinTiles[0], 4, 4, 9),
    overworld_frame(&walreinTiles[0], 4, 4, 10),
    overworld_frame(&walreinTiles[0], 4, 4, 11),
};
const struct SpriteTemplate sWalreinOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Walrein, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sWalreinOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Walrein, UpdateSurfMonOverlay);


//=============== CLAMPERL
//extern const u32 clamperlTiles[];
//extern const u16 clamperlPal[];
//extern const u16 clamperlShinyPal[];

//=============== HUNTAIL
//extern const u32 huntailTiles[];
//extern const u16 huntailPal[];
//extern const u16 huntailShinyPal[];

//=============== GOREBYSS
//extern const u32 gorebyssTiles[];
//extern const u16 gorebyssPal[];
//extern const u16 gorebyssShinyPal[];

//=============== RELICANTH
//extern const u32 relicanthTiles[];
//extern const u16 relicanthPal[];
//extern const u16 relicanthShinyPal[];

//=============== LUVDISC
//extern const u32 luvdiscTiles[];
//extern const u16 luvdiscPal[];
//extern const u16 luvdiscShinyPal[];

//=============== LATIAS
//extern const u32 latiasTiles[];
//extern const u16 latiasPal[];
//extern const u16 latiasShinyPal[];

//=============== LATIOS
//extern const u32 latiosTiles[];
//extern const u16 latiosPal[];
//extern const u16 latiosShinyPal[];

//=============== KYOGRE
//extern const u32 kyogreTiles[];
//extern const u16 kyogrePal[];
//extern const u16 kyogreShinyPal[];

//=============== RAYQUAZA
//extern const u32 rayquazaTiles[];
//extern const u16 rayquazaPal[];
//extern const u16 rayquazaShinyPal[];



/*==================================================
	RIDEABLE POKEMON STRUCTURE
==================================================*/

struct RideableMons
{
	u16 species;
	u16 filler;
	const u16* palAddr;
	const u16* shinyPalAddr;
	const struct SpriteTemplate* overworldGfx;
	const struct SpriteTemplate* overlayGfx;
};

const struct RideableMons gSurfablePokemon[] =
{
	{
		.species = SPECIES_SQUIRTLE,
		.palAddr = &squirtlePal[0],
		.shinyPalAddr = &squirtleShinyPal[0],
		.overworldGfx = &sSquirtleOverworld,
		.overlayGfx = &sSquirtleOverlay,
	},
	{
		.species = SPECIES_WARTORTLE,
		.palAddr = &wartortlePal[0],
		.shinyPalAddr = &wartortleShinyPal[0],
		.overworldGfx = &sWartortleOverworld,
		.overlayGfx = &sWartortleOverlay,
	},
	{
		.species = SPECIES_BLASTOISE,
		.palAddr = &blastoisePal[0],
		.shinyPalAddr = &blastoiseShinyPal[0],
		.overworldGfx = &sBlastoiseOverworld,
		.overlayGfx = &sBlastoiseOverlay,
	},
	{
		.species = SPECIES_NIDOQUEEN,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_NIDOKING,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_PSYDUCK,
		.palAddr = &psyduckPal[0],
		.shinyPalAddr = &psyduckShinyPal[0],
		.overworldGfx = &sPsyduckOverworld,
		.overlayGfx = &sPsyduckOverlay,
	},
	{
		.species = SPECIES_GOLDUCK,
		.palAddr = &golduckPal[0],
		.shinyPalAddr = &golduckShinyPal[0],
		.overworldGfx = &sGolduckOverworld,
		.overlayGfx = &sGolduckOverlay,
	},
	{
		.species = SPECIES_POLIWAG,
		.palAddr = &poliwagPal[0],
		.shinyPalAddr = 0,
		.overworldGfx = &sPoliwagOverworld,
		.overlayGfx = &sPoliwagOverlay,
	},
	{
		.species = SPECIES_POLIWHIRL,
		.palAddr = &poliwhirlPal[0],
		.shinyPalAddr = 0,
		.overworldGfx = &sPoliwhirlOverworld,
		.overlayGfx = &sPoliwhirlOverlay,
	},
	{
		.species = SPECIES_POLIWRATH,
		.palAddr = &poliwrathPal[0],
		.shinyPalAddr = 0,
		.overworldGfx = &sPoliwrathOverworld,
		.overlayGfx = &sPoliwrathOverlay,
	},
	{
		.species = SPECIES_TENTACOOL,
		.palAddr = &tentacoolPal[0],
		.shinyPalAddr = &tentacoolShinyPal[0],
		.overworldGfx = &sTentacoolOverworld,
		.overlayGfx = &sTentacoolOverlay,
	},
	{
		.species = SPECIES_TENTACRUEL,
		.palAddr = &tentacruelPal[0],
		.shinyPalAddr = &tentacruelShinyPal[0],
		.overworldGfx = &sTentacruelOverworld,
		.overlayGfx = &sTentacruelOverlay,
	},
	{
		.species = SPECIES_SLOWPOKE,
		.palAddr = &slowpokePal[0],
		.shinyPalAddr = &slowpokeShinyPal[0],
		.overworldGfx = &sSlowpokeOverworld,
		.overlayGfx = &sSlowpokeOverlay,
	},
	{
		.species = SPECIES_SLOWBRO,
		.palAddr = &slowbroPal[0],
		.shinyPalAddr = &slowbroShinyPal[0],
		.overworldGfx = &sSlowbroOverworld,
		.overlayGfx = &sSlowbroOverlay,
	},
	{
		.species = SPECIES_SEEL,
		.palAddr = &seelPal[0],
		.shinyPalAddr = &seelShinyPal[0],
		.overworldGfx = &sSeelOverworld,
		.overlayGfx = &sSeelOverlay,
	},
	{
		.species = SPECIES_DEWGONG,
		.palAddr = &dewgongPal[0],
		.shinyPalAddr = &dewgongShinyPal[0],
		.overworldGfx = &sDewgongOverworld,
		.overlayGfx = &sDewgongOverlay,
	},
	{
		.species = SPECIES_SHELLDER,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_CLOYSTER,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_KRABBY,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_KINGLER,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LICKITUNG,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_RHYDON,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_KANGASKHAN,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_HORSEA,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SEADRA,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_GOLDEEN,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SEAKING,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_STARYU,
		.palAddr = &staryuPal[0],
		.shinyPalAddr = &staryuShinyPal[0],
		.overworldGfx = &sStaryuOverworld,
		.overlayGfx = &sStaryuOverlay,
	},
	{
		.species = SPECIES_STARMIE,
		.palAddr = &starmiePal[0],
		.shinyPalAddr = &starmieShinyPal[0],
		.overworldGfx = &sStarmieOverworld,
		.overlayGfx = &sStarmieOverlay,
	},
	{
		.species = SPECIES_TAUROS,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_GYARADOS,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LAPRAS,
		.palAddr = &laprasPal[0],
		.shinyPalAddr = &laprasShinyPal[0],
		.overworldGfx = &sLaprasOverworld,
		.overlayGfx = &sLaprasOverlay,
	},
	{
		.species = SPECIES_VAPOREON,
		.palAddr = &vaporeonPal[0],
		.shinyPalAddr = &vaporeonShinyPal[0],
		.overworldGfx = &sVaporeonOverworld,
		.overlayGfx = &sVaporeonOverlay,
	},
	{
		.species = SPECIES_OMANYTE,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_OMASTAR,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_KABUTO,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_KABUTOPS,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SNORLAX,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_DRATINI,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_DRAGONAIR,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_DRAGONITE,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_MEW,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_TOTODILE,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_CROCONAW,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_FERALIGATR,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SENTRET,
		.palAddr = &sentretPal[0],
		.shinyPalAddr = &sentretShinyPal[0],
		.overworldGfx = &sSentretOverworld,
		.overlayGfx = &sSentretOverlay,
	},
	{
		.species = SPECIES_FURRET,
		.palAddr = &furretPal[0],
		.shinyPalAddr = &furretShinyPal[0],
		.overworldGfx = &sFurretOverworld,
		.overlayGfx = &sFurretOverlay,
	},
	{
		.species = SPECIES_CHINCHOU,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LANTURN,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_MARILL,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
  .species = SPECIES_AZUMARILL,
  .palAddr = &azumarillPal[0],
  .shinyPalAddr = &azumarillShinyPal[0],
  .overworldGfx = &sAzumarillOverworld,
  .overlayGfx = &sAzumarillOverlay,
  },
	{
		.species = SPECIES_POLITOED,
		.palAddr = &politoedPal[0],
		.shinyPalAddr = 0,
		.overworldGfx = &sPolitoedOverworld,
		.overlayGfx = &sPolitoedOverlay,
	},
	{
		.species = SPECIES_WOOPER,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_QUAGSIRE,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SLOWKING,
		.palAddr = &slowkingPal[0],
		.shinyPalAddr = &slowkingShinyPal[0],
		.overworldGfx = &sSlowkingOverworld,
		.overlayGfx = &sSlowkingOverlay,
	},
	{
		.species = SPECIES_QWILFISH,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SNEASEL,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_CORSOLA,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_REMORAID,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_OCTILLERY,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_MANTINE,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_KINGDRA,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_MILTANK,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SUICUNE,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_TYRANITAR,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LUGIA,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_MUDKIP,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_MARSHTOMP,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SWAMPERT,
		.palAddr = &swampertPal[0],
		.shinyPalAddr = &swampertShinyPal[0],
		.overworldGfx = &sSwampertOverworld,
		.overlayGfx = &sSwampertOverlay,
	},
	{
		.species = SPECIES_ZIGZAGOON,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LINOONE,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LOTAD,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LOMBRE,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LUDICOLO,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_PELIPPER,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_EXPLOUD,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_MAKUHITA,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_HARIYAMA,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_AZURILL,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_AGGRON,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_CARVANHA,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SHARPEDO,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_WAILMER,
		.palAddr = &wailmerPal[0],
		.shinyPalAddr = &wailmerShinyPal[0],
		.overworldGfx = &sWailmerOverworld,
		.overlayGfx = &sWailmerOverlay,
	},
	{
		.species = SPECIES_WAILORD,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_BARBOACH,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_WHISCASH,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_CORPHISH,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_CRAWDAUNT,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_FEEBAS,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_MILOTIC,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SPHEAL,
		.palAddr = &sphealPal[0],
		.shinyPalAddr = &sphealShinyPal[0],
		.overworldGfx = &sSphealOverworld,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_SEALEO,
		.palAddr = &sealeoPal[0],
		.shinyPalAddr = &sealeoShinyPal[0],
		.overworldGfx = &sSealeoOverworld,
		.overlayGfx = &sSealeoOverlay,
	},
	{
		.species = SPECIES_WALREIN,
		.palAddr = &walreinPal[0],
		.shinyPalAddr = &walreinShinyPal[0],
		.overworldGfx = &sWalreinOverworld,
		.overlayGfx = &sWalreinOverlay,
	},
	{
		.species = SPECIES_CLAMPERL,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_HUNTAIL,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_GOREBYSS,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_RELICANTH,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LUVDISC,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LATIAS,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_LATIOS,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_KYOGRE,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
	{
		.species = SPECIES_RAYQUAZA,
		.palAddr = 0,
		.shinyPalAddr = 0,
		.overworldGfx = sDefaultSurfBlob,
		.overlayGfx = 0,
	},
};