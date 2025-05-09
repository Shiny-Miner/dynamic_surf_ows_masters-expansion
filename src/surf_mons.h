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

//Surf Template 1 - Normal - 32x32 64x64
#define surf_template(tag, image, cb) {.tileTag = 0xFFFF, .paletteTag = tag, .oam = gEventObjectBaseOam_32x32, .anims = gSurfablePokemonAnimTable, .images = image, .affineAnims = gDummySpriteAffineAnimTable, .callback = cb}
#define surf_template64x64(tag, image, cb) {.tileTag = 0xFFFF, .paletteTag = tag, .oam = gObjectEventBaseOam_64x64, .anims = gSurfablePokemonAnimTable, .images = image, .affineAnims = gDummySpriteAffineAnimTable, .callback = cb}

//Surf Template 2 - Separate East/West Frames - 32x32 64x64
#define surf_template2(tag, image, cb) {.tileTag = 0xFFFF, .paletteTag = tag, .oam = gEventObjectBaseOam_32x32, .anims = gSurfablePokemonAnimTable2, .images = image, .affineAnims = gDummySpriteAffineAnimTable, .callback = cb}
#define surf_template2_64x64(tag, image, cb) {.tileTag = 0xFFFF, .paletteTag = tag, .oam = gObjectEventBaseOam_64x64, .anims = sSurfablePokemonAnimTable2, .images = image, .affineAnims = gDummySpriteAffineAnimTable, .callback = cb}

//Surf Template 3 - Four frames per direction - 32x32 64x64 
#define surf_template3(tag, image, cb) {.tileTag = 0xFFFF, .paletteTag = tag, .oam = gEventObjectBaseOam_32x32, .anims = gSurfablePokemonAnimTable3, .images = image, .affineAnims = gDummySpriteAffineAnimTable, .callback = cb}
#define surf_template3_64x64(tag, image, cb) {.tileTag = 0xFFFF, .paletteTag = tag, .oam = gObjectEventBaseOam_64x64, .anims = sSurfablePokemonAnimTable3, .images = image, .affineAnims = gDummySpriteAffineAnimTable, .callback = cb}

// Surf Template 4 - Four frames per direction + unique east and west facing frames 32x32 64x64
#define surf_template4(tag, image, cb) {.tileTag = 0xFFFF, .paletteTag = tag, .oam = gEventObjectBaseOam_32x32, .anims = gSurfablePokemonAnimTable4, .images = image, .affineAnims = gDummySpriteAffineAnimTable, .callback = cb}
#define surf_template4_64x64(tag, image, cb) {.tileTag = 0xFFFF, .paletteTag = tag, .oam = gObjectEventBaseOam_64x64, .anims = sSurfablePokemonAnimTable4, .images = image, .affineAnims = gDummySpriteAffineAnimTable, .callback = cb}

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
extern const u32 surfBlobTiles[];
extern const u16 surfBlobPal[];

/*==============================
    GEN 1
==============================*/

//=============== SQUIRTLE
extern const u32 squirtleTiles[];
extern const u16 squirtlePal[];
extern const u16 squirtleShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Squirtle[] = {
    // Facing South
    overworld_frame(&squirtleTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&squirtleTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&squirtleTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&squirtleTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&squirtleTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&squirtleTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Squirtle[] = {
    // Facing South
    overworld_frame(&squirtleTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&squirtleTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&squirtleTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&squirtleTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&squirtleTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&squirtleTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSquirtleOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Squirtle, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSquirtleOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Squirtle, UpdateSurfMonOverlay);

//=============== WARTORTLE
extern const u32 wartortleTiles[];
extern const u16 wartortlePal[];
extern const u16 wartortleShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Wartortle[] = {
    // Facing South
    overworld_frame(&wartortleTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&wartortleTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&wartortleTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&wartortleTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&wartortleTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&wartortleTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Wartortle[] = {
    // Facing South
    overworld_frame(&wartortleTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&wartortleTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&wartortleTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&wartortleTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&wartortleTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&wartortleTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sWartortleOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Wartortle, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sWartortleOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Wartortle, UpdateSurfMonOverlay);

//=============== BLASTOISE
extern const u32 blastoiseTiles[];
extern const u16 blastoisePal[];
extern const u16 blastoiseShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Blastoise[] = {
    // Facing South
    overworld_frame(&blastoiseTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&blastoiseTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&blastoiseTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&blastoiseTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&blastoiseTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&blastoiseTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Blastoise[] = {
    // Facing South
    overworld_frame(&blastoiseTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&blastoiseTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&blastoiseTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&blastoiseTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&blastoiseTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&blastoiseTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sBlastoiseOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Blastoise, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sBlastoiseOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Blastoise, UpdateSurfMonOverlay);

//=============== PIKACHU
// NOTE: Large, 64x64 Sprite
extern const u32 pikachuTiles[];
extern const u16 pikachuPal[];
extern const u16 pikachuShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Pikachu[] = {
    // Facing South
    overworld_frame(&pikachuTiles[0], 8, 8, 0), // Bob Up
    overworld_frame(&pikachuTiles[0], 8, 8, 1), // Bob Down

    // Facing North
    overworld_frame(&pikachuTiles[0], 8, 8, 2), // Bob Up
    overworld_frame(&pikachuTiles[0], 8, 8, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&pikachuTiles[0], 8, 8, 4), // Bob Up
    overworld_frame(&pikachuTiles[0], 8, 8, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Pikachu[] = {
    // Facing South
    overworld_frame(&pikachuTiles[0], 8, 8, 6), // Bob Up
    overworld_frame(&pikachuTiles[0], 8, 8, 7), // Bob Down

    // Facing North
    overworld_frame(&pikachuTiles[0], 8, 8, 8), // Bob Up
    overworld_frame(&pikachuTiles[0], 8, 8, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&pikachuTiles[0], 8, 8, 10), // Bob Up
    overworld_frame(&pikachuTiles[0], 8, 8, 11), // Bob Down
};

const struct SpriteTemplate sPikachuOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Pikachu, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPikachuOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Pikachu, UpdateSurfMonOverlay);

//=============== RAICHU
// NOTE: Large, 64x64 Sprite
extern const u32 raichuTiles[];
extern const u16 raichuPal[];
extern const u16 raichuShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Raichu[] = {
    // Facing South
    overworld_frame(&raichuTiles[0], 8, 8, 0), // Bob Up
    overworld_frame(&raichuTiles[0], 8, 8, 1), // Bob Down

    // Facing North
    overworld_frame(&raichuTiles[0], 8, 8, 2), // Bob Up
    overworld_frame(&raichuTiles[0], 8, 8, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&raichuTiles[0], 8, 8, 4), // Bob Up
    overworld_frame(&raichuTiles[0], 8, 8, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Raichu[] = {
    // Facing South
    overworld_frame(&raichuTiles[0], 8, 8, 6), // Bob Up
    overworld_frame(&raichuTiles[0], 8, 8, 7), // Bob Down

    // Facing North
    overworld_frame(&raichuTiles[0], 8, 8, 8), // Bob Up
    overworld_frame(&raichuTiles[0], 8, 8, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&raichuTiles[0], 8, 8, 10), // Bob Up
    overworld_frame(&raichuTiles[0], 8, 8, 11), // Bob Down
};

const struct SpriteTemplate sRaichuOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Raichu, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sRaichuOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Raichu, UpdateSurfMonOverlay);

//=============== NIDOQUEEN
extern const u32 nidoqueenTiles[];
extern const u16 nidoqueenPal[];
extern const u16 nidoqueenShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Nidoqueen[] = {
    // Facing South
    overworld_frame(&nidoqueenTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&nidoqueenTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&nidoqueenTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&nidoqueenTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&nidoqueenTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&nidoqueenTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Nidoqueen[] = {
    // Facing South
    overworld_frame(&nidoqueenTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&nidoqueenTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&nidoqueenTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&nidoqueenTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&nidoqueenTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&nidoqueenTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sNidoqueenOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Nidoqueen, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sNidoqueenOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Nidoqueen, UpdateSurfMonOverlay);

//=============== NIDOKING
extern const u32 nidokingTiles[];
extern const u16 nidokingPal[];
extern const u16 nidokingShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Nidoking[] = {
    // Facing South
    overworld_frame(&nidokingTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&nidokingTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&nidokingTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&nidokingTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&nidokingTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&nidokingTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Nidoking[] = {
    // Facing South
    overworld_frame(&nidokingTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&nidokingTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&nidokingTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&nidokingTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&nidokingTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&nidokingTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sNidokingOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Nidoking, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sNidokingOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Nidoking, UpdateSurfMonOverlay);

//=============== PSYDUCK
extern const u32 psyduckTiles[];
extern const u16 psyduckPal[];
extern const u16 psyduckShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Psyduck[] = {
    // Facing South
    overworld_frame(&psyduckTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&psyduckTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&psyduckTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&psyduckTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&psyduckTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&psyduckTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Psyduck[] = {
    // Facing South
    overworld_frame(&psyduckTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&psyduckTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&psyduckTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&psyduckTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&psyduckTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&psyduckTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sPsyduckOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Psyduck, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPsyduckOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Psyduck, UpdateSurfMonOverlay);

//=============== GOLDUCK
extern const u32 golduckTiles[];
extern const u16 golduckPal[];
extern const u16 golduckShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Golduck[] = {
    // Facing South
    overworld_frame(&golduckTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&golduckTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&golduckTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&golduckTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&golduckTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&golduckTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Golduck[] = {
    // Facing South
    overworld_frame(&golduckTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&golduckTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&golduckTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&golduckTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&golduckTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&golduckTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sGolduckOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Golduck, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sGolduckOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Golduck, UpdateSurfMonOverlay);

//=============== POLIWAG
extern const u32 poliwagTiles[];
extern const u16 poliwagPal[];
extern const u16 poliwagShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Poliwag[] = {
    // Facing South
    overworld_frame(&poliwagTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&poliwagTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&poliwagTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&poliwagTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&poliwagTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&poliwagTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Poliwag[] = {
    // Facing South
    overworld_frame(&poliwagTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&poliwagTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&poliwagTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&poliwagTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&poliwagTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&poliwagTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sPoliwagOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Poliwag, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPoliwagOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Poliwag, UpdateSurfMonOverlay);

//=============== POLIWHIRL
extern const u32 poliwhirlTiles[];
extern const u16 poliwhirlPal[];
extern const u16 poliwhirlShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Poliwhirl[] = {
    // Facing South
    overworld_frame(&poliwhirlTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&poliwhirlTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&poliwhirlTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&poliwhirlTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&poliwhirlTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&poliwhirlTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Poliwhirl[] = {
    // Facing South
    overworld_frame(&poliwhirlTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&poliwhirlTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&poliwhirlTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&poliwhirlTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&poliwhirlTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&poliwhirlTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sPoliwhirlOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Poliwhirl, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPoliwhirlOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Poliwhirl, UpdateSurfMonOverlay);

//=============== POLIWRATH
extern const u32 poliwrathTiles[];
extern const u16 poliwrathPal[];
extern const u16 poliwrathShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Poliwrath[] = {
    // Facing South
    overworld_frame(&poliwrathTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&poliwrathTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&poliwrathTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&poliwrathTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&poliwrathTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&poliwrathTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Poliwrath[] = {
    // Facing South
    overworld_frame(&poliwrathTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&poliwrathTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&poliwrathTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&poliwrathTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&poliwrathTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&poliwrathTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sPoliwrathOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Poliwrath, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPoliwrathOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Poliwrath, UpdateSurfMonOverlay);

//=============== TENTACOOL
extern const u32 tentacoolTiles[];
extern const u16 tentacoolPal[];
extern const u16 tentacoolShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Tentacool[] = {
    // Facing South
    overworld_frame(&tentacoolTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&tentacoolTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&tentacoolTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&tentacoolTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&tentacoolTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&tentacoolTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Tentacool[] = {
    // Facing South
    overworld_frame(&tentacoolTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&tentacoolTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&tentacoolTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&tentacoolTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&tentacoolTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&tentacoolTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sTentacoolOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Tentacool, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sTentacoolOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Tentacool, UpdateSurfMonOverlay);

//=============== TENTACRUEL
extern const u32 tentacruelTiles[];
extern const u16 tentacruelPal[];
extern const u16 tentacruelShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Tentacruel[] = {
    // Facing South
    overworld_frame(&tentacruelTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&tentacruelTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&tentacruelTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&tentacruelTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&tentacruelTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&tentacruelTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Tentacruel[] = {
    // Facing South
    overworld_frame(&tentacruelTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&tentacruelTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&tentacruelTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&tentacruelTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&tentacruelTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&tentacruelTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sTentacruelOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Tentacruel, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sTentacruelOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Tentacruel, UpdateSurfMonOverlay);

//=============== SLOWPOKE
extern const u32 slowpokeTiles[];
extern const u16 slowpokePal[];
extern const u16 slowpokeShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Slowpoke[] = {
    // Facing South
    overworld_frame(&slowpokeTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&slowpokeTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&slowpokeTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&slowpokeTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&slowpokeTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&slowpokeTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Slowpoke[] = {
    // Facing South
    overworld_frame(&slowpokeTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&slowpokeTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&slowpokeTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&slowpokeTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&slowpokeTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&slowpokeTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSlowpokeOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Slowpoke, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSlowpokeOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Slowpoke, UpdateSurfMonOverlay);

//=============== SLOWBRO
extern const u32 slowbroTiles[];
extern const u16 slowbroPal[];
extern const u16 slowbroShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Slowbro[] = {
    // Facing South
    overworld_frame(&slowbroTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&slowbroTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&slowbroTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&slowbroTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&slowbroTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&slowbroTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Slowbro[] = {
    // Facing South
    overworld_frame(&slowbroTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&slowbroTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&slowbroTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&slowbroTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&slowbroTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&slowbroTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSlowbroOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Slowbro, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSlowbroOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Slowbro, UpdateSurfMonOverlay);

//=============== SEEL
extern const u32 seelTiles[];
extern const u16 seelPal[];
extern const u16 seelShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Seel[] = {
    // Facing South
    overworld_frame(&seelTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&seelTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&seelTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&seelTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&seelTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&seelTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Seel[] = {
    // Facing South
    overworld_frame(&seelTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&seelTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&seelTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&seelTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&seelTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&seelTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSeelOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Seel, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSeelOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Seel, UpdateSurfMonOverlay);

//=============== DEWGONG
extern const u32 dewgongTiles[];
extern const u16 dewgongPal[];
extern const u16 dewgongShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Dewgong[] = {
    // Facing South
    overworld_frame(&dewgongTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&dewgongTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&dewgongTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&dewgongTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&dewgongTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&dewgongTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Dewgong[] = {
    // Facing South
    overworld_frame(&dewgongTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&dewgongTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&dewgongTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&dewgongTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&dewgongTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&dewgongTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sDewgongOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Dewgong, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sDewgongOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Dewgong, UpdateSurfMonOverlay);

//=============== SHELLDER
extern const u32 shellderTiles[];
extern const u16 shellderPal[];
extern const u16 shellderShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Shellder[] = {
    // Facing South
    overworld_frame(&shellderTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&shellderTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&shellderTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&shellderTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&shellderTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&shellderTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Shellder[] = {
    // Facing South
    overworld_frame(&shellderTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&shellderTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&shellderTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&shellderTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&shellderTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&shellderTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sShellderOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Shellder, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sShellderOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Shellder, UpdateSurfMonOverlay);

//=============== CLOYSTER
extern const u32 cloysterTiles[];
extern const u16 cloysterPal[];
extern const u16 cloysterShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Cloyster[] = {
    // Facing South
    overworld_frame(&cloysterTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&cloysterTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&cloysterTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&cloysterTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&cloysterTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&cloysterTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Cloyster[] = {
    // Facing South
    overworld_frame(&cloysterTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&cloysterTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&cloysterTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&cloysterTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&cloysterTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&cloysterTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sCloysterOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Cloyster, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sCloysterOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Cloyster, UpdateSurfMonOverlay);

//=============== KRABBY
extern const u32 krabbyTiles[];
extern const u16 krabbyPal[];
extern const u16 krabbyShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Krabby[] = {
    // Facing South
    overworld_frame(&krabbyTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&krabbyTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&krabbyTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&krabbyTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&krabbyTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&krabbyTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Krabby[] = {
    // Facing South
    overworld_frame(&krabbyTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&krabbyTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&krabbyTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&krabbyTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&krabbyTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&krabbyTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sKrabbyOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Krabby, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sKrabbyOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Krabby, UpdateSurfMonOverlay);

//=============== KINGLER
// NOTE: Supports unique left/right sprites!
extern const u32 kinglerTiles[];
extern const u16 kinglerPal[];
extern const u16 kinglerShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Kingler[] = {
    // Facing South
    overworld_frame(&kinglerTiles[0], 4, 4, 0),
    overworld_frame(&kinglerTiles[0], 4, 4, 1),

    // Facing North
    overworld_frame(&kinglerTiles[0], 4, 4, 2),
    overworld_frame(&kinglerTiles[0], 4, 4, 3),

    // Facing West
    overworld_frame(&kinglerTiles[0], 4, 4, 4),
    overworld_frame(&kinglerTiles[0], 4, 4, 5),

    // Facing East
    overworld_frame(&kinglerTiles[0], 4, 4, 6),
    overworld_frame(&kinglerTiles[0], 4, 4, 7),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Kingler[] = {
    // Facing South
    overworld_frame(&kinglerTiles[0], 4, 4, 8),
    overworld_frame(&kinglerTiles[0], 4, 4, 9),

    // Facing North
    overworld_frame(&kinglerTiles[0], 4, 4, 10),
    overworld_frame(&kinglerTiles[0], 4, 4, 11),

    // Facing West
    overworld_frame(&kinglerTiles[0], 4, 4, 12),
    overworld_frame(&kinglerTiles[0], 4, 4, 13),

    // Facing East
    overworld_frame(&kinglerTiles[0], 4, 4, 14),
    overworld_frame(&kinglerTiles[0], 4, 4, 15),
};

// This commented out frame order flips Kingler, such that it faces
// towards the screen when moving right. However, this results in
// something a little silly, making the player always facing Kingler's
// largest claw. So, we left it as-is, Kingler will face away from the
// screen when moving right/east, and towards the screen when left/west
//
// const struct SpriteFrameImage gSurfingOverworldPicTable_Kingler[] = {
//     overworld_frame(&kinglerTiles[0], 4, 4, 2),
//     overworld_frame(&kinglerTiles[0], 4, 4, 3),
//     overworld_frame(&kinglerTiles[0], 4, 4, 0),
//     overworld_frame(&kinglerTiles[0], 4, 4, 1),
//     overworld_frame(&kinglerTiles[0], 4, 4, 6),
//     overworld_frame(&kinglerTiles[0], 4, 4, 7),
//     overworld_frame(&kinglerTiles[0], 4, 4, 4),
//     overworld_frame(&kinglerTiles[0], 4, 4, 5),
// };

// const struct SpriteFrameImage gSurfingOverlayPicTable_Kingler[] = {
//     overworld_frame(&kinglerTiles[0], 4, 4, 10),
//     overworld_frame(&kinglerTiles[0], 4, 4, 11),
//     overworld_frame(&kinglerTiles[0], 4, 4, 8),
//     overworld_frame(&kinglerTiles[0], 4, 4, 9),
//     overworld_frame(&kinglerTiles[0], 4, 4, 14),
//     overworld_frame(&kinglerTiles[0], 4, 4, 15),
//     overworld_frame(&kinglerTiles[0], 4, 4, 12),
//     overworld_frame(&kinglerTiles[0], 4, 4, 13),
// };

const struct SpriteTemplate sKinglerOverworld = surf_template2(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Kingler, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sKinglerOverlay = surf_template2(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Kingler, UpdateSurfMonOverlay);

//=============== LICKITUNG
extern const u32 lickitungTiles[];
extern const u16 lickitungPal[];
extern const u16 lickitungShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Lickitung[] = {
    // Facing South
    overworld_frame(&lickitungTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&lickitungTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&lickitungTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&lickitungTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&lickitungTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&lickitungTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Lickitung[] = {
    // Facing South
    overworld_frame(&lickitungTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&lickitungTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&lickitungTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&lickitungTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&lickitungTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&lickitungTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sLickitungOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Lickitung, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLickitungOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Lickitung, UpdateSurfMonOverlay);

//=============== RHYDON
extern const u32 rhydonTiles[];
extern const u16 rhydonPal[];
extern const u16 rhydonShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Rhydon[] = {
    // Facing South
    overworld_frame(&rhydonTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&rhydonTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&rhydonTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&rhydonTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&rhydonTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&rhydonTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Rhydon[] = {
    // Facing South
    overworld_frame(&rhydonTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&rhydonTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&rhydonTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&rhydonTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&rhydonTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&rhydonTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sRhydonOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Rhydon, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sRhydonOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Rhydon, UpdateSurfMonOverlay);

//=============== KANGASKHAN
extern const u32 kangaskhanTiles[];
extern const u16 kangaskhanPal[];
extern const u16 kangaskhanShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Kangaskhan[] = {
    // Facing South
    overworld_frame(&kangaskhanTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&kangaskhanTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&kangaskhanTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&kangaskhanTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kangaskhanTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&kangaskhanTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Kangaskhan[] = {
    // Facing South
    overworld_frame(&kangaskhanTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&kangaskhanTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&kangaskhanTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&kangaskhanTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kangaskhanTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&kangaskhanTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sKangaskhanOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Kangaskhan, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sKangaskhanOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Kangaskhan, UpdateSurfMonOverlay);

//=============== HORSEA
extern const u32 horseaTiles[];
extern const u16 horseaPal[];
extern const u16 horseaShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Horsea[] = {
    // Facing South
    overworld_frame(&horseaTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&horseaTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&horseaTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&horseaTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&horseaTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&horseaTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Horsea[] = {
    // Facing South
    overworld_frame(&horseaTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&horseaTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&horseaTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&horseaTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&horseaTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&horseaTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sHorseaOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Horsea, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sHorseaOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Horsea, UpdateSurfMonOverlay);

//=============== SEADRA
extern const u32 seadraTiles[];
extern const u16 seadraPal[];
extern const u16 seadraShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Seadra[] = {
    // Facing South
    overworld_frame(&seadraTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&seadraTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&seadraTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&seadraTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&seadraTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&seadraTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Seadra[] = {
    // Facing South
    overworld_frame(&seadraTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&seadraTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&seadraTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&seadraTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&seadraTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&seadraTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSeadraOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Seadra, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSeadraOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Seadra, UpdateSurfMonOverlay);

//=============== GOLDEEN
extern const u32 goldeenTiles[];
extern const u16 goldeenPal[];
extern const u16 goldeenShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Goldeen[] = {
    // Facing South
    overworld_frame(&goldeenTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&goldeenTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&goldeenTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&goldeenTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&goldeenTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&goldeenTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Goldeen[] = {
    // Facing South
    overworld_frame(&goldeenTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&goldeenTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&goldeenTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&goldeenTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&goldeenTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&goldeenTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sGoldeenOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Goldeen, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sGoldeenOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Goldeen, UpdateSurfMonOverlay);

//=============== SEAKING
extern const u32 seakingTiles[];
extern const u16 seakingPal[];
extern const u16 seakingShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Seaking[] = {
    // Facing South
    overworld_frame(&seakingTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&seakingTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&seakingTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&seakingTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&seakingTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&seakingTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Seaking[] = {
    // Facing South
    overworld_frame(&seakingTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&seakingTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&seakingTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&seakingTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&seakingTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&seakingTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSeakingOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Seaking, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSeakingOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Seaking, UpdateSurfMonOverlay);

//=============== STARYU
extern const u32 staryuTiles[];
extern const u16 staryuPal[];
extern const u16 staryuShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Staryu[] = {
    // Facing South
    overworld_frame(&staryuTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&staryuTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&staryuTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&staryuTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&staryuTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&staryuTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Staryu[] = {
    // Facing South
    overworld_frame(&staryuTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&staryuTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&staryuTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&staryuTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&staryuTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&staryuTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sStaryuOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Staryu, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sStaryuOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Staryu, UpdateSurfMonOverlay);

//=============== STARMIE
extern const u32 starmieTiles[];
extern const u16 starmiePal[];
extern const u16 starmieShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Starmie[] = {
    // Facing South
    overworld_frame(&starmieTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&starmieTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&starmieTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&starmieTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&starmieTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&starmieTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Starmie[] = {
    // Facing South
    overworld_frame(&starmieTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&starmieTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&starmieTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&starmieTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&starmieTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&starmieTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sStarmieOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Starmie, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sStarmieOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Starmie, UpdateSurfMonOverlay);

//=============== TAUROS
extern const u32 taurosTiles[];
extern const u16 taurosPal[];
extern const u16 taurosShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Tauros[] = {
    // Facing South
    overworld_frame(&taurosTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&taurosTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&taurosTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&taurosTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&taurosTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&taurosTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Tauros[] = {
    // Facing South
    overworld_frame(&taurosTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&taurosTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&taurosTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&taurosTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&taurosTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&taurosTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sTaurosOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Tauros, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sTaurosOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Tauros, UpdateSurfMonOverlay);

//=============== GYARADOS
extern const u32 gyaradosTiles[];
extern const u16 gyaradosPal[];
extern const u16 gyaradosShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Gyarados[] = {
    // Facing South
    overworld_frame(&gyaradosTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&gyaradosTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&gyaradosTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&gyaradosTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&gyaradosTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&gyaradosTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Gyarados[] = {
    // Facing South
    overworld_frame(&gyaradosTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&gyaradosTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&gyaradosTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&gyaradosTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&gyaradosTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&gyaradosTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sGyaradosOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Gyarados, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sGyaradosOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Gyarados, UpdateSurfMonOverlay);

//=============== LAPRAS
extern const u32 laprasTiles[];
extern const u16 laprasPal[];
extern const u16 laprasShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Lapras[] = {
    // Facing South
    overworld_frame(&laprasTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&laprasTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&laprasTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&laprasTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&laprasTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&laprasTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Lapras[] = {
    // Facing South
    overworld_frame(&laprasTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&laprasTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&laprasTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&laprasTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&laprasTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&laprasTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sLaprasOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Lapras, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLaprasOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Lapras, UpdateSurfMonOverlay);

//=============== VAPOREON
extern const u32 vaporeonTiles[];
extern const u16 vaporeonPal[];
extern const u16 vaporeonShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Vaporeon[] = {
    // Facing South
    overworld_frame(&vaporeonTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&vaporeonTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&vaporeonTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&vaporeonTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&vaporeonTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&vaporeonTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Vaporeon[] = {
    // Facing South
    overworld_frame(&vaporeonTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&vaporeonTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&vaporeonTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&vaporeonTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&vaporeonTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&vaporeonTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sVaporeonOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Vaporeon, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sVaporeonOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Vaporeon, UpdateSurfMonOverlay);

//=============== OMANYTE
extern const u32 omanyteTiles[];
extern const u16 omanytePal[];
extern const u16 omanyteShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Omanyte[] = {
    // Facing South
    overworld_frame(&omanyteTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&omanyteTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&omanyteTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&omanyteTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&omanyteTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&omanyteTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Omanyte[] = {
    // Facing South
    overworld_frame(&omanyteTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&omanyteTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&omanyteTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&omanyteTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&omanyteTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&omanyteTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sOmanyteOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Omanyte, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sOmanyteOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Omanyte, UpdateSurfMonOverlay);

//=============== OMASTAR
extern const u32 omastarTiles[];
extern const u16 omastarPal[];
extern const u16 omastarShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Omastar[] = {
    // Facing South
    overworld_frame(&omastarTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&omastarTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&omastarTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&omastarTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&omastarTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&omastarTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Omastar[] = {
    // Facing South
    overworld_frame(&omastarTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&omastarTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&omastarTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&omastarTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&omastarTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&omastarTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sOmastarOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Omastar, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sOmastarOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Omastar, UpdateSurfMonOverlay);

//=============== KABUTO
extern const u32 kabutoTiles[];
extern const u16 kabutoPal[];
extern const u16 kabutoShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Kabuto[] = {
    // Facing South
    overworld_frame(&kabutoTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&kabutoTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&kabutoTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&kabutoTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kabutoTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&kabutoTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Kabuto[] = {
    // Facing South
    overworld_frame(&kabutoTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&kabutoTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&kabutoTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&kabutoTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kabutoTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&kabutoTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sKabutoOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Kabuto, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sKabutoOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Kabuto, UpdateSurfMonOverlay);

//=============== KABUTOPS
extern const u32 kabutopsTiles[];
extern const u16 kabutopsPal[];
extern const u16 kabutopsShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Kabutops[] = {
    // Facing South
    overworld_frame(&kabutopsTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&kabutopsTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&kabutopsTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&kabutopsTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kabutopsTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&kabutopsTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Kabutops[] = {
    // Facing South
    overworld_frame(&kabutopsTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&kabutopsTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&kabutopsTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&kabutopsTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kabutopsTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&kabutopsTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sKabutopsOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Kabutops, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sKabutopsOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Kabutops, UpdateSurfMonOverlay);

//=============== SNORLAX
// NOTE: Large, 64x64 Sprite
// NOTE: Supports unique left/right sprites!
// NOTE: Supports 4-frame animations!
extern const u32 snorlaxTiles[];
extern const u16 snorlaxPal[];
extern const u16 snorlaxShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Snorlax[] = {
    // Facing South
    overworld_frame(&snorlaxTiles[0], 8, 8, 0), // Bob Up
    overworld_frame(&snorlaxTiles[0], 8, 8, 1), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 2), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 3), // Bob Down

    // Facing North
    overworld_frame(&snorlaxTiles[0], 8, 8, 4), // Bob Up
    overworld_frame(&snorlaxTiles[0], 8, 8, 5), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 6), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 7), // Bob Down

    // Facing West
    overworld_frame(&snorlaxTiles[0], 8, 8, 8),  // Bob Up
    overworld_frame(&snorlaxTiles[0], 8, 8, 9),  // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 10), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 11), // Bob Down

    // Facing East
    overworld_frame(&snorlaxTiles[0], 8, 8, 12), // Bob Up
    overworld_frame(&snorlaxTiles[0], 8, 8, 13), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 14), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 15), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Snorlax[] = {
    // Facing South
    overworld_frame(&snorlaxTiles[0], 8, 8, 16), // Bob Up
    overworld_frame(&snorlaxTiles[0], 8, 8, 17), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 18), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 19), // Bob Down

    // Facing North
    overworld_frame(&snorlaxTiles[0], 8, 8, 20), // Bob Up
    overworld_frame(&snorlaxTiles[0], 8, 8, 21), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 22), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 23), // Bob Down

    // Facing West
    overworld_frame(&snorlaxTiles[0], 8, 8, 24), // Bob Up
    overworld_frame(&snorlaxTiles[0], 8, 8, 25), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 26), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 27), // Bob Down

    // Facing East
    overworld_frame(&snorlaxTiles[0], 8, 8, 28), // Bob Up
    overworld_frame(&snorlaxTiles[0], 8, 8, 29), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 30), // Bob Down
    overworld_frame(&snorlaxTiles[0], 8, 8, 31), // Bob Down
};

const struct SpriteTemplate sSnorlaxOverworld = surf_template4_64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Snorlax, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSnorlaxOverlay = surf_template4_64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Snorlax, UpdateSurfMonOverlay);

//=============== DRATINI
extern const u32 dratiniTiles[];
extern const u16 dratiniPal[];
extern const u16 dratiniShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Dratini[] = {
    // Facing South
    overworld_frame(&dratiniTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&dratiniTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&dratiniTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&dratiniTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&dratiniTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&dratiniTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Dratini[] = {
    // Facing South
    overworld_frame(&dratiniTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&dratiniTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&dratiniTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&dratiniTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&dratiniTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&dratiniTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sDratiniOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Dratini, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sDratiniOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Dratini, UpdateSurfMonOverlay);

//=============== DRAGONAIR
extern const u32 dragonairTiles[];
extern const u16 dragonairPal[];
extern const u16 dragonairShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Dragonair[] = {
    // Facing South
    overworld_frame(&dragonairTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&dragonairTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&dragonairTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&dragonairTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&dragonairTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&dragonairTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Dragonair[] = {
    // Facing South
    overworld_frame(&dragonairTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&dragonairTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&dragonairTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&dragonairTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&dragonairTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&dragonairTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sDragonairOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Dragonair, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sDragonairOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Dragonair, UpdateSurfMonOverlay);

//=============== DRAGONITE
extern const u32 dragoniteTiles[];
extern const u16 dragonitePal[];
extern const u16 dragoniteShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Dragonite[] = {
    // Facing South
    overworld_frame(&dragoniteTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&dragoniteTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&dragoniteTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&dragoniteTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&dragoniteTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&dragoniteTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Dragonite[] = {
    // Facing South
    overworld_frame(&dragoniteTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&dragoniteTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&dragoniteTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&dragoniteTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&dragoniteTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&dragoniteTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sDragoniteOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Dragonite, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sDragoniteOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Dragonite, UpdateSurfMonOverlay);

//=============== MEW
extern const u32 mewTiles[];
extern const u16 mewPal[];
extern const u16 mewShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Mew[] = {
    // Facing South
    overworld_frame(&mewTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&mewTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&mewTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&mewTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&mewTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&mewTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Mew[] = {
    // Facing South
    overworld_frame(&mewTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&mewTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&mewTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&mewTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&mewTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&mewTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sMewOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Mew, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sMewOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Mew, UpdateSurfMonOverlay);

/*==============================
    GEN 2
==============================*/

//=============== TOTODILE
extern const u32 totodileTiles[];
extern const u16 totodilePal[];
extern const u16 totodileShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Totodile[] = {
    // Facing South
    overworld_frame(&totodileTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&totodileTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&totodileTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&totodileTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&totodileTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&totodileTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Totodile[] = {
    // Facing South
    overworld_frame(&totodileTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&totodileTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&totodileTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&totodileTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&totodileTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&totodileTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sTotodileOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Totodile, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sTotodileOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Totodile, UpdateSurfMonOverlay);

//=============== CROCONAW
extern const u32 croconawTiles[];
extern const u16 croconawPal[];
extern const u16 croconawShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Croconaw[] = {
    // Facing South
    overworld_frame(&croconawTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&croconawTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&croconawTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&croconawTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&croconawTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&croconawTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Croconaw[] = {
    // Facing South
    overworld_frame(&croconawTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&croconawTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&croconawTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&croconawTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&croconawTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&croconawTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sCroconawOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Croconaw, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sCroconawOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Croconaw, UpdateSurfMonOverlay);

//=============== FERALIGATR
// NOTE: Large, 64x64 Sprite
extern const u32 feraligatrTiles[];
extern const u16 feraligatrPal[];
extern const u16 feraligatrShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Feraligatr[] = {
    // Facing South
    overworld_frame(&feraligatrTiles[0], 8, 8, 0), // Bob Up
    overworld_frame(&feraligatrTiles[0], 8, 8, 1), // Bob Down

    // Facing North
    overworld_frame(&feraligatrTiles[0], 8, 8, 2), // Bob Up
    overworld_frame(&feraligatrTiles[0], 8, 8, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&feraligatrTiles[0], 8, 8, 4), // Bob Up
    overworld_frame(&feraligatrTiles[0], 8, 8, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Feraligatr[] = {
    // Facing South
    overworld_frame(&feraligatrTiles[0], 8, 8, 6), // Bob Up
    overworld_frame(&feraligatrTiles[0], 8, 8, 7), // Bob Down

    // Facing North
    overworld_frame(&feraligatrTiles[0], 8, 8, 8), // Bob Up
    overworld_frame(&feraligatrTiles[0], 8, 8, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&feraligatrTiles[0], 8, 8, 10), // Bob Up
    overworld_frame(&feraligatrTiles[0], 8, 8, 11), // Bob Down
};

const struct SpriteTemplate sFeraligatrOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Feraligatr, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sFeraligatrOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Feraligatr, UpdateSurfMonOverlay);

//=============== SENTRET
extern const u32 sentretTiles[];
extern const u16 sentretPal[];
extern const u16 sentretShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Sentret[] = {
    // Facing South
    overworld_frame(&sentretTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&sentretTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&sentretTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&sentretTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&sentretTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&sentretTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Sentret[] = {
    // Facing South
    overworld_frame(&sentretTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&sentretTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&sentretTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&sentretTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&sentretTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&sentretTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSentretOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Sentret, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSentretOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Sentret, UpdateSurfMonOverlay);

//=============== FURRET
extern const u32 furretTiles[];
extern const u16 furretPal[];
extern const u16 furretShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Furret[] = {
    // Facing South
    overworld_frame(&furretTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&furretTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&furretTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&furretTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&furretTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&furretTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Furret[] = {
    // Facing South
    overworld_frame(&furretTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&furretTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&furretTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&furretTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&furretTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&furretTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sFurretOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Furret, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sFurretOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Furret, UpdateSurfMonOverlay);

//=============== PICHU
// NOTE: Large, 64x64 Sprite
extern const u32 pichuTiles[];
extern const u16 pichuPal[];
extern const u16 pichuShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Pichu[] = {
    // Facing South
    overworld_frame(&pichuTiles[0], 8, 8, 0), // Bob Up
    overworld_frame(&pichuTiles[0], 8, 8, 1), // Bob Down

    // Facing North
    overworld_frame(&pichuTiles[0], 8, 8, 2), // Bob Up
    overworld_frame(&pichuTiles[0], 8, 8, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&pichuTiles[0], 8, 8, 4), // Bob Up
    overworld_frame(&pichuTiles[0], 8, 8, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Pichu[] = {
    // Facing South
    overworld_frame(&pichuTiles[0], 8, 8, 6), // Bob Up
    overworld_frame(&pichuTiles[0], 8, 8, 7), // Bob Down

    // Facing North
    overworld_frame(&pichuTiles[0], 8, 8, 8), // Bob Up
    overworld_frame(&pichuTiles[0], 8, 8, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&pichuTiles[0], 8, 8, 10), // Bob Up
    overworld_frame(&pichuTiles[0], 8, 8, 11), // Bob Down
};

const struct SpriteTemplate sPichuOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Pichu, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPichuOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Pichu, UpdateSurfMonOverlay);

//=============== CHINCHOU
extern const u32 chinchouTiles[];
extern const u16 chinchouPal[];
extern const u16 chinchouShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Chinchou[] = {
    // Facing South
    overworld_frame(&chinchouTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&chinchouTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&chinchouTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&chinchouTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&chinchouTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&chinchouTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Chinchou[] = {
    // Facing South
    overworld_frame(&chinchouTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&chinchouTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&chinchouTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&chinchouTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&chinchouTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&chinchouTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sChinchouOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Chinchou, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sChinchouOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Chinchou, UpdateSurfMonOverlay);

//=============== LANTURN
extern const u32 lanturnTiles[];
extern const u16 lanturnPal[];
extern const u16 lanturnShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Lanturn[] = {
    // Facing South
    overworld_frame(&lanturnTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&lanturnTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&lanturnTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&lanturnTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&lanturnTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&lanturnTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Lanturn[] = {
    // Facing South
    overworld_frame(&lanturnTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&lanturnTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&lanturnTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&lanturnTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&lanturnTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&lanturnTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sLanturnOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Lanturn, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLanturnOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Lanturn, UpdateSurfMonOverlay);

//=============== MARILL
extern const u32 marillTiles[];
extern const u16 marillPal[];
extern const u16 marillShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Marill[] = {
    // Facing South
    overworld_frame(&marillTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&marillTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&marillTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&marillTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&marillTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&marillTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Marill[] = {
    // Facing South
    overworld_frame(&marillTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&marillTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&marillTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&marillTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&marillTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&marillTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sMarillOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Marill, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sMarillOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Marill, UpdateSurfMonOverlay);

//=============== AZUMARILL
extern const u32 azumarillTiles[];
extern const u16 azumarillPal[];
extern const u16 azumarillShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Azumarill[] = {
    // Facing South
    overworld_frame(&azumarillTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&azumarillTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&azumarillTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&azumarillTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&azumarillTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&azumarillTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Azumarill[] = {
    // Facing South
    overworld_frame(&azumarillTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&azumarillTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&azumarillTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&azumarillTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&azumarillTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&azumarillTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sAzumarillOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Azumarill, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sAzumarillOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Azumarill, UpdateSurfMonOverlay);

//=============== POLITOED
extern const u32 politoedTiles[];
extern const u16 politoedPal[];
extern const u16 politoedShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Politoed[] = {
    // Facing South
    overworld_frame(&politoedTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&politoedTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&politoedTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&politoedTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&politoedTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&politoedTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Politoed[] = {
    // Facing South
    overworld_frame(&politoedTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&politoedTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&politoedTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&politoedTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&politoedTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&politoedTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sPolitoedOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Politoed, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPolitoedOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Politoed, UpdateSurfMonOverlay);

//=============== WOOPER
extern const u32 wooperTiles[];
extern const u16 wooperPal[];
extern const u16 wooperShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Wooper[] = {
    // Facing South
    overworld_frame(&wooperTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&wooperTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&wooperTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&wooperTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&wooperTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&wooperTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Wooper[] = {
    // Facing South
    overworld_frame(&wooperTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&wooperTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&wooperTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&wooperTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&wooperTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&wooperTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sWooperOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Wooper, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sWooperOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Wooper, UpdateSurfMonOverlay);

//=============== QUAGSIRE
extern const u32 quagsireTiles[];
extern const u16 quagsirePal[];
extern const u16 quagsireShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Quagsire[] = {
    // Facing South
    overworld_frame(&quagsireTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&quagsireTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&quagsireTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&quagsireTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&quagsireTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&quagsireTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Quagsire[] = {
    // Facing South
    overworld_frame(&quagsireTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&quagsireTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&quagsireTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&quagsireTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&quagsireTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&quagsireTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sQuagsireOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Quagsire, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sQuagsireOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Quagsire, UpdateSurfMonOverlay);

//=============== SLOWKING
extern const u32 slowkingTiles[];
extern const u16 slowkingPal[];
extern const u16 slowkingShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Slowking[] = {
    // Facing South
    overworld_frame(&slowkingTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&slowkingTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&slowkingTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&slowkingTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&slowkingTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&slowkingTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Slowking[] = {
    // Facing South
    overworld_frame(&slowkingTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&slowkingTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&slowkingTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&slowkingTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&slowkingTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&slowkingTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSlowkingOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Slowking, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSlowkingOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Slowking, UpdateSurfMonOverlay);

//=============== QWILFISH
extern const u32 qwilfishTiles[];
extern const u16 qwilfishPal[];
extern const u16 qwilfishShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Qwilfish[] = {
    // Facing South
    overworld_frame(&qwilfishTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&qwilfishTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&qwilfishTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&qwilfishTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&qwilfishTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&qwilfishTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Qwilfish[] = {
    // Facing South
    overworld_frame(&qwilfishTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&qwilfishTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&qwilfishTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&qwilfishTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&qwilfishTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&qwilfishTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sQwilfishOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Qwilfish, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sQwilfishOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Qwilfish, UpdateSurfMonOverlay);

//=============== SNEASEL
extern const u32 sneaselTiles[];
extern const u16 sneaselPal[];
extern const u16 sneaselShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Sneasel[] = {
    // Facing South
    overworld_frame(&sneaselTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&sneaselTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&sneaselTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&sneaselTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&sneaselTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&sneaselTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Sneasel[] = {
    // Facing South
    overworld_frame(&sneaselTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&sneaselTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&sneaselTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&sneaselTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&sneaselTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&sneaselTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSneaselOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Sneasel, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSneaselOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Sneasel, UpdateSurfMonOverlay);

//=============== CORSOLA
extern const u32 corsolaTiles[];
extern const u16 corsolaPal[];
extern const u16 corsolaShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Corsola[] = {
    // Facing South
    overworld_frame(&corsolaTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&corsolaTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&corsolaTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&corsolaTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&corsolaTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&corsolaTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Corsola[] = {
    // Facing South
    overworld_frame(&corsolaTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&corsolaTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&corsolaTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&corsolaTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&corsolaTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&corsolaTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sCorsolaOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Corsola, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sCorsolaOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Corsola, UpdateSurfMonOverlay);

//=============== REMORAID
extern const u32 remoraidTiles[];
extern const u16 remoraidPal[];
extern const u16 remoraidShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Remoraid[] = {
    // Facing South
    overworld_frame(&remoraidTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&remoraidTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&remoraidTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&remoraidTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&remoraidTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&remoraidTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Remoraid[] = {
    // Facing South
    overworld_frame(&remoraidTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&remoraidTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&remoraidTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&remoraidTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&remoraidTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&remoraidTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sRemoraidOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Remoraid, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sRemoraidOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Remoraid, UpdateSurfMonOverlay);

//=============== OCTILLERY
extern const u32 octilleryTiles[];
extern const u16 octilleryPal[];
extern const u16 octilleryShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Octillery[] = {
    // Facing South
    overworld_frame(&octilleryTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&octilleryTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&octilleryTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&octilleryTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&octilleryTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&octilleryTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Octillery[] = {
    // Facing South
    overworld_frame(&octilleryTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&octilleryTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&octilleryTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&octilleryTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&octilleryTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&octilleryTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sOctilleryOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Octillery, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sOctilleryOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Octillery, UpdateSurfMonOverlay);

//=============== MANTINE
extern const u32 mantineTiles[];
extern const u16 mantinePal[];
extern const u16 mantineShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Mantine[] = {
    // Facing South
    overworld_frame(&mantineTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&mantineTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&mantineTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&mantineTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&mantineTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&mantineTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Mantine[] = {
    // Facing South
    overworld_frame(&mantineTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&mantineTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&mantineTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&mantineTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&mantineTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&mantineTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sMantineOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Mantine, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sMantineOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Mantine, UpdateSurfMonOverlay);

//=============== KINGDRA
extern const u32 kingdraTiles[];
extern const u16 kingdraPal[];
extern const u16 kingdraShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Kingdra[] = {
    // Facing South
    overworld_frame(&kingdraTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&kingdraTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&kingdraTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&kingdraTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kingdraTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&kingdraTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Kingdra[] = {
    // Facing South
    overworld_frame(&kingdraTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&kingdraTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&kingdraTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&kingdraTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kingdraTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&kingdraTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sKingdraOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Kingdra, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sKingdraOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Kingdra, UpdateSurfMonOverlay);

//=============== MILTANK
extern const u32 miltankTiles[];
extern const u16 miltankPal[];
extern const u16 miltankShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Miltank[] = {
    // Facing South
    overworld_frame(&miltankTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&miltankTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&miltankTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&miltankTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&miltankTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&miltankTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Miltank[] = {
    // Facing South
    overworld_frame(&miltankTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&miltankTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&miltankTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&miltankTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&miltankTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&miltankTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sMiltankOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Miltank, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sMiltankOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Miltank, UpdateSurfMonOverlay);

//=============== SUICUNE
extern const u32 suicuneTiles[];
extern const u16 suicunePal[];
extern const u16 suicuneShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Suicune[] = {
    // Facing South
    overworld_frame(&suicuneTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&suicuneTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&suicuneTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&suicuneTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&suicuneTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&suicuneTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Suicune[] = {
    // Facing South
    overworld_frame(&suicuneTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&suicuneTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&suicuneTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&suicuneTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&suicuneTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&suicuneTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSuicuneOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Suicune, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSuicuneOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Suicune, UpdateSurfMonOverlay);

//=============== TYRANITAR
extern const u32 tyranitarTiles[];
extern const u16 tyranitarPal[];
extern const u16 tyranitarShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Tyranitar[] = {
    // Facing South
    overworld_frame(&tyranitarTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&tyranitarTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&tyranitarTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&tyranitarTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&tyranitarTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&tyranitarTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Tyranitar[] = {
    // Facing South
    overworld_frame(&tyranitarTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&tyranitarTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&tyranitarTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&tyranitarTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&tyranitarTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&tyranitarTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sTyranitarOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Tyranitar, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sTyranitarOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Tyranitar, UpdateSurfMonOverlay);

//=============== LUGIA
extern const u32 lugiaTiles[];
extern const u16 lugiaPal[];
extern const u16 lugiaShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Lugia[] = {
    // Facing South
    overworld_frame(&lugiaTiles[0], 8, 8, 0), // Bob Up
    overworld_frame(&lugiaTiles[0], 8, 8, 1), // Bob Down

    // Facing North
    overworld_frame(&lugiaTiles[0], 8, 8, 2), // Bob Up
    overworld_frame(&lugiaTiles[0], 8, 8, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&lugiaTiles[0], 8, 8, 4), // Bob Up
    overworld_frame(&lugiaTiles[0], 8, 8, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Lugia[] = {
    // Facing South
    overworld_frame(&lugiaTiles[0], 8, 8, 6), // Bob Up
    overworld_frame(&lugiaTiles[0], 8, 8, 7), // Bob Down

    // Facing North
    overworld_frame(&lugiaTiles[0], 8, 8, 8), // Bob Up
    overworld_frame(&lugiaTiles[0], 8, 8, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&lugiaTiles[0], 8, 8, 10), // Bob Up
    overworld_frame(&lugiaTiles[0], 8, 8, 11), // Bob Down
};

const struct SpriteTemplate sLugiaOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Lugia, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLugiaOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Lugia, UpdateSurfMonOverlay);

/*==============================
    GEN 3
==============================*/

//=============== MUDKIP
extern const u32 mudkipTiles[];
extern const u16 mudkipPal[];
extern const u16 mudkipShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Mudkip[] = {
    // Facing South
    overworld_frame(&mudkipTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&mudkipTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&mudkipTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&mudkipTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&mudkipTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&mudkipTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Mudkip[] = {
    // Facing South
    overworld_frame(&mudkipTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&mudkipTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&mudkipTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&mudkipTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&mudkipTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&mudkipTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sMudkipOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Mudkip, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sMudkipOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Mudkip, UpdateSurfMonOverlay);

//=============== MARSHTOMP
extern const u32 marshtompTiles[];
extern const u16 marshtompPal[];
extern const u16 marshtompShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Marshtomp[] = {
    // Facing South
    overworld_frame(&marshtompTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&marshtompTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&marshtompTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&marshtompTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&marshtompTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&marshtompTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Marshtomp[] = {
    // Facing South
    overworld_frame(&marshtompTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&marshtompTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&marshtompTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&marshtompTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&marshtompTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&marshtompTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sMarshtompOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Marshtomp, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sMarshtompOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Marshtomp, UpdateSurfMonOverlay);

//=============== SWAMPERT
extern const u32 swampertTiles[];
extern const u16 swampertPal[];
extern const u16 swampertShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Swampert[] = {
    // Facing South
    overworld_frame(&swampertTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&swampertTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&swampertTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&swampertTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&swampertTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&swampertTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Swampert[] = {
    // Facing South
    overworld_frame(&swampertTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&swampertTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&swampertTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&swampertTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&swampertTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&swampertTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSwampertOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Swampert, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSwampertOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Swampert, UpdateSurfMonOverlay);

//=============== ZIGZAGOON
extern const u32 zigzagoonTiles[];
extern const u16 zigzagoonPal[];
extern const u16 zigzagoonShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Zigzagoon[] = {
    overworld_frame(&zigzagoonTiles[0], 4, 4, 0),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 1),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 2),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 3),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 4),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Zigzagoon[] = {
    overworld_frame(&zigzagoonTiles[0], 4, 4, 6),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 7),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 8),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 9),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 10),
    overworld_frame(&zigzagoonTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sZigzagoonOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Zigzagoon, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sZigzagoonOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Zigzagoon, UpdateSurfMonOverlay);

//=============== LINOONE
extern const u32 linooneTiles[];
extern const u16 linoonePal[];
extern const u16 linooneShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Linoone[] = {
    overworld_frame(&linooneTiles[0], 4, 4, 0),
    overworld_frame(&linooneTiles[0], 4, 4, 1),
    overworld_frame(&linooneTiles[0], 4, 4, 2),
    overworld_frame(&linooneTiles[0], 4, 4, 3),
    overworld_frame(&linooneTiles[0], 4, 4, 4),
    overworld_frame(&linooneTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Linoone[] = {
    overworld_frame(&linooneTiles[0], 4, 4, 6),
    overworld_frame(&linooneTiles[0], 4, 4, 7),
    overworld_frame(&linooneTiles[0], 4, 4, 8),
    overworld_frame(&linooneTiles[0], 4, 4, 9),
    overworld_frame(&linooneTiles[0], 4, 4, 10),
    overworld_frame(&linooneTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sLinooneOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Linoone, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLinooneOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Linoone, UpdateSurfMonOverlay);

//=============== LOTAD
extern const u32 lotadTiles[];
extern const u16 lotadPal[];
extern const u16 lotadShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Lotad[] = {
    overworld_frame(&lotadTiles[0], 4, 4, 0),
    overworld_frame(&lotadTiles[0], 4, 4, 1),
    overworld_frame(&lotadTiles[0], 4, 4, 2),
    overworld_frame(&lotadTiles[0], 4, 4, 3),
    overworld_frame(&lotadTiles[0], 4, 4, 4),
    overworld_frame(&lotadTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Lotad[] = {
    overworld_frame(&lotadTiles[0], 4, 4, 6),
    overworld_frame(&lotadTiles[0], 4, 4, 7),
    overworld_frame(&lotadTiles[0], 4, 4, 8),
    overworld_frame(&lotadTiles[0], 4, 4, 9),
    overworld_frame(&lotadTiles[0], 4, 4, 10),
    overworld_frame(&lotadTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sLotadOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Lotad, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLotadOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Lotad, UpdateSurfMonOverlay);

//=============== LOMBRE
extern const u32 lombreTiles[];
extern const u16 lombrePal[];
extern const u16 lombreShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Lombre[] = {
    overworld_frame(&lombreTiles[0], 4, 4, 0),
    overworld_frame(&lombreTiles[0], 4, 4, 1),
    overworld_frame(&lombreTiles[0], 4, 4, 2),
    overworld_frame(&lombreTiles[0], 4, 4, 3),
    overworld_frame(&lombreTiles[0], 4, 4, 4),
    overworld_frame(&lombreTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Lombre[] = {
    overworld_frame(&lombreTiles[0], 4, 4, 6),
    overworld_frame(&lombreTiles[0], 4, 4, 7),
    overworld_frame(&lombreTiles[0], 4, 4, 8),
    overworld_frame(&lombreTiles[0], 4, 4, 9),
    overworld_frame(&lombreTiles[0], 4, 4, 10),
    overworld_frame(&lombreTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sLombreOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Lombre, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLombreOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Lombre, UpdateSurfMonOverlay);

//=============== LUDICOLO
extern const u32 ludicoloTiles[];
extern const u16 ludicoloPal[];
extern const u16 ludicoloShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Ludicolo[] = {
    overworld_frame(&ludicoloTiles[0], 4, 4, 0),
    overworld_frame(&ludicoloTiles[0], 4, 4, 1),
    overworld_frame(&ludicoloTiles[0], 4, 4, 2),
    overworld_frame(&ludicoloTiles[0], 4, 4, 3),
    overworld_frame(&ludicoloTiles[0], 4, 4, 4),
    overworld_frame(&ludicoloTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Ludicolo[] = {
    overworld_frame(&ludicoloTiles[0], 4, 4, 6),
    overworld_frame(&ludicoloTiles[0], 4, 4, 7),
    overworld_frame(&ludicoloTiles[0], 4, 4, 8),
    overworld_frame(&ludicoloTiles[0], 4, 4, 9),
    overworld_frame(&ludicoloTiles[0], 4, 4, 10),
    overworld_frame(&ludicoloTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sLudicoloOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Ludicolo, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLudicoloOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Ludicolo, UpdateSurfMonOverlay);

//=============== PELIPPER
extern const u32 pelipperTiles[];
extern const u16 pelipperPal[];
extern const u16 pelipperShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Pelipper[] = {
    overworld_frame(&pelipperTiles[0], 4, 4, 0),
    overworld_frame(&pelipperTiles[0], 4, 4, 1),
    overworld_frame(&pelipperTiles[0], 4, 4, 2),
    overworld_frame(&pelipperTiles[0], 4, 4, 3),
    overworld_frame(&pelipperTiles[0], 4, 4, 4),
    overworld_frame(&pelipperTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Pelipper[] = {
    overworld_frame(&pelipperTiles[0], 4, 4, 6),
    overworld_frame(&pelipperTiles[0], 4, 4, 7),
    overworld_frame(&pelipperTiles[0], 4, 4, 8),
    overworld_frame(&pelipperTiles[0], 4, 4, 9),
    overworld_frame(&pelipperTiles[0], 4, 4, 10),
    overworld_frame(&pelipperTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sPelipperOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Pelipper, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPelipperOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Pelipper, UpdateSurfMonOverlay);

//=============== SURSKIT
extern const u32 surskitTiles[];
extern const u16 surskitPal[];
extern const u16 surskitShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Surskit[] = {
    overworld_frame(&surskitTiles[0], 8, 8, 1),
    overworld_frame(&surskitTiles[0], 8, 8, 0),
    overworld_frame(&surskitTiles[0], 8, 8, 3),
    overworld_frame(&surskitTiles[0], 8, 8, 2),
    overworld_frame(&surskitTiles[0], 8, 8, 5),
    overworld_frame(&surskitTiles[0], 8, 8, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Surskit[] = {
    overworld_frame(&surskitTiles[0], 8, 8, 7),
    overworld_frame(&surskitTiles[0], 8, 8, 6),
    overworld_frame(&surskitTiles[0], 8, 8, 9),
    overworld_frame(&surskitTiles[0], 8, 8, 8),
    overworld_frame(&surskitTiles[0], 8, 8, 11),
    overworld_frame(&surskitTiles[0], 8, 8, 10),
};

const struct SpriteTemplate sSurskitOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Surskit, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSurskitOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Surskit, UpdateSurfMonOverlay);

//=============== MASQUERAIN
extern const u32 masquerainTiles[];
extern const u16 masquerainPal[];
extern const u16 masquerainShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Masquerain[] = {
    overworld_frame(&masquerainTiles[0], 8, 8, 1),
    overworld_frame(&masquerainTiles[0], 8, 8, 0),
    overworld_frame(&masquerainTiles[0], 8, 8, 3),
    overworld_frame(&masquerainTiles[0], 8, 8, 2),
    overworld_frame(&masquerainTiles[0], 8, 8, 5),
    overworld_frame(&masquerainTiles[0], 8, 8, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Masquerain[] = {
    overworld_frame(&masquerainTiles[0], 8, 8, 7),
    overworld_frame(&masquerainTiles[0], 8, 8, 6),
    overworld_frame(&masquerainTiles[0], 8, 8, 9),
    overworld_frame(&masquerainTiles[0], 8, 8, 8),
    overworld_frame(&masquerainTiles[0], 8, 8, 11),
    overworld_frame(&masquerainTiles[0], 8, 8, 10),
};

const struct SpriteTemplate sMasquerainOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Masquerain, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sMasquerainOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Masquerain, UpdateSurfMonOverlay);

//=============== EXPLOUD
extern const u32 exploudTiles[];
extern const u16 exploudPal[];
extern const u16 exploudShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Exploud[] = {
    overworld_frame(&exploudTiles[0], 4, 4, 0),
    overworld_frame(&exploudTiles[0], 4, 4, 1),
    overworld_frame(&exploudTiles[0], 4, 4, 2),
    overworld_frame(&exploudTiles[0], 4, 4, 3),
    overworld_frame(&exploudTiles[0], 4, 4, 4),
    overworld_frame(&exploudTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Exploud[] = {
    overworld_frame(&exploudTiles[0], 4, 4, 6),
    overworld_frame(&exploudTiles[0], 4, 4, 7),
    overworld_frame(&exploudTiles[0], 4, 4, 8),
    overworld_frame(&exploudTiles[0], 4, 4, 9),
    overworld_frame(&exploudTiles[0], 4, 4, 10),
    overworld_frame(&exploudTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sExploudOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Exploud, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sExploudOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Exploud, UpdateSurfMonOverlay);

//=============== MAKUHITA
extern const u32 makuhitaTiles[];
extern const u16 makuhitaPal[];
extern const u16 makuhitaShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Makuhita[] = {
    overworld_frame(&makuhitaTiles[0], 4, 4, 0),
    overworld_frame(&makuhitaTiles[0], 4, 4, 1),
    overworld_frame(&makuhitaTiles[0], 4, 4, 2),
    overworld_frame(&makuhitaTiles[0], 4, 4, 3),
    overworld_frame(&makuhitaTiles[0], 4, 4, 4),
    overworld_frame(&makuhitaTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Makuhita[] = {
    overworld_frame(&makuhitaTiles[0], 4, 4, 6),
    overworld_frame(&makuhitaTiles[0], 4, 4, 7),
    overworld_frame(&makuhitaTiles[0], 4, 4, 8),
    overworld_frame(&makuhitaTiles[0], 4, 4, 9),
    overworld_frame(&makuhitaTiles[0], 4, 4, 10),
    overworld_frame(&makuhitaTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sMakuhitaOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Makuhita, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sMakuhitaOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Makuhita, UpdateSurfMonOverlay);

//=============== HARIYAMA
extern const u32 hariyamaTiles[];
extern const u16 hariyamaPal[];
extern const u16 hariyamaShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Hariyama[] = {
    overworld_frame(&hariyamaTiles[0], 4, 4, 0),
    overworld_frame(&hariyamaTiles[0], 4, 4, 1),
    overworld_frame(&hariyamaTiles[0], 4, 4, 2),
    overworld_frame(&hariyamaTiles[0], 4, 4, 3),
    overworld_frame(&hariyamaTiles[0], 4, 4, 4),
    overworld_frame(&hariyamaTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Hariyama[] = {
    overworld_frame(&hariyamaTiles[0], 4, 4, 6),
    overworld_frame(&hariyamaTiles[0], 4, 4, 7),
    overworld_frame(&hariyamaTiles[0], 4, 4, 8),
    overworld_frame(&hariyamaTiles[0], 4, 4, 9),
    overworld_frame(&hariyamaTiles[0], 4, 4, 10),
    overworld_frame(&hariyamaTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sHariyamaOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Hariyama, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sHariyamaOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Hariyama, UpdateSurfMonOverlay);

//=============== AGGRON
extern const u32 aggronTiles[];
extern const u16 aggronPal[];
extern const u16 aggronShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Aggron[] = {
    overworld_frame(&aggronTiles[0], 4, 4, 0),
    overworld_frame(&aggronTiles[0], 4, 4, 1),
    overworld_frame(&aggronTiles[0], 4, 4, 2),
    overworld_frame(&aggronTiles[0], 4, 4, 3),
    overworld_frame(&aggronTiles[0], 4, 4, 5),
    overworld_frame(&aggronTiles[0], 4, 4, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Aggron[] = {
    overworld_frame(&aggronTiles[0], 4, 4, 6),
    overworld_frame(&aggronTiles[0], 4, 4, 7),
    overworld_frame(&aggronTiles[0], 4, 4, 8),
    overworld_frame(&aggronTiles[0], 4, 4, 9),
    overworld_frame(&aggronTiles[0], 4, 4, 10),
    overworld_frame(&aggronTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sAggronOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Aggron, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sAggronOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Aggron, UpdateSurfMonOverlay);

//=============== CARVANHA
extern const u32 carvanhaTiles[];
extern const u16 carvanhaPal[];
extern const u16 carvanhaShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Carvanha[] = {
    overworld_frame(&carvanhaTiles[0], 8, 8, 1),
    overworld_frame(&carvanhaTiles[0], 8, 8, 0),
    overworld_frame(&carvanhaTiles[0], 8, 8, 3),
    overworld_frame(&carvanhaTiles[0], 8, 8, 2),
    overworld_frame(&carvanhaTiles[0], 8, 8, 5),
    overworld_frame(&carvanhaTiles[0], 8, 8, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Carvanha[] = {
    overworld_frame(&carvanhaTiles[0], 8, 8, 7),
    overworld_frame(&carvanhaTiles[0], 8, 8, 6),
    overworld_frame(&carvanhaTiles[0], 8, 8, 9),
    overworld_frame(&carvanhaTiles[0], 8, 8, 8),
    overworld_frame(&carvanhaTiles[0], 8, 8, 11),
    overworld_frame(&carvanhaTiles[0], 8, 8, 10),
};

const struct SpriteTemplate sCarvanhaOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Carvanha, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sCarvanhaOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Carvanha, UpdateSurfMonOverlay);

//=============== SHARPEDO
extern const u32 sharpedoTiles[];
extern const u16 sharpedoPal[];
extern const u16 sharpedoShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Sharpedo[] = {
    // Facing South
    overworld_frame(&sharpedoTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&sharpedoTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&sharpedoTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&sharpedoTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&sharpedoTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&sharpedoTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Sharpedo[] = {
    // Facing South
    overworld_frame(&sharpedoTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&sharpedoTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&sharpedoTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&sharpedoTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&sharpedoTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&sharpedoTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sSharpedoOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Sharpedo, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSharpedoOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Sharpedo, UpdateSurfMonOverlay);

//=============== WAILMER
extern const u32 wailmerTiles[];
extern const u16 wailmerPal[];
extern const u16 wailmerShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Wailmer[] = {
    // Facing South
    overworld_frame(&wailmerTiles[0], 8, 8, 0), // Bob Up
    overworld_frame(&wailmerTiles[0], 8, 8, 1), // Bob Down

    // Facing North
    overworld_frame(&wailmerTiles[0], 8, 8, 2), // Bob Up
    overworld_frame(&wailmerTiles[0], 8, 8, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&wailmerTiles[0], 8, 8, 4), // Bob Up
    overworld_frame(&wailmerTiles[0], 8, 8, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Wailmer[] = {
    // Facing South
    overworld_frame(&wailmerTiles[0], 8, 8, 6), // Bob Up
    overworld_frame(&wailmerTiles[0], 8, 8, 7), // Bob Down

    // Facing North
    overworld_frame(&wailmerTiles[0], 8, 8, 8), // Bob Up
    overworld_frame(&wailmerTiles[0], 8, 8, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&wailmerTiles[0], 8, 8, 10), // Bob Up
    overworld_frame(&wailmerTiles[0], 8, 8, 11), // Bob Down
};

const struct SpriteTemplate sWailmerOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Wailmer, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sWailmerOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Wailmer, UpdateSurfMonOverlay);

//=============== WAILORD
extern const u32 wailordTiles[];
extern const u16 wailordPal[];
extern const u16 wailordShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Wailord[] = {
    overworld_frame(&wailordTiles[0], 8, 8, 1),
    overworld_frame(&wailordTiles[0], 8, 8, 0),
    overworld_frame(&wailordTiles[0], 8, 8, 3),
    overworld_frame(&wailordTiles[0], 8, 8, 2),
    overworld_frame(&wailordTiles[0], 8, 8, 5),
    overworld_frame(&wailordTiles[0], 8, 8, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Wailord[] = {
    overworld_frame(&wailordTiles[0], 8, 8, 7),
    overworld_frame(&wailordTiles[0], 8, 8, 6),
    overworld_frame(&wailordTiles[0], 8, 8, 9),
    overworld_frame(&wailordTiles[0], 8, 8, 8),
    overworld_frame(&wailordTiles[0], 8, 8, 11),
    overworld_frame(&wailordTiles[0], 8, 8, 10),
};

const struct SpriteTemplate sWailordOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Wailord, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sWailordOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Wailord, UpdateSurfMonOverlay);

//=============== ZANGOOSE
extern const u32 zangooseTiles[];
extern const u16 zangoosePal[];
extern const u16 zangooseShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Zangoose[] = {
    // Facing South
    overworld_frame(&zangooseTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&zangooseTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&zangooseTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&zangooseTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&zangooseTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&zangooseTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Zangoose[] = {
    // Facing South
    overworld_frame(&zangooseTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&zangooseTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&zangooseTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&zangooseTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&zangooseTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&zangooseTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sZangooseOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Zangoose, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sZangooseOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Zangoose, UpdateSurfMonOverlay);

//=============== BARBOACH
extern const u32 barboachTiles[];
extern const u16 barboachPal[];
extern const u16 barboachShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Barboach[] = {
    overworld_frame(&barboachTiles[0], 8, 8, 1),
    overworld_frame(&barboachTiles[0], 8, 8, 0),
    overworld_frame(&barboachTiles[0], 8, 8, 3),
    overworld_frame(&barboachTiles[0], 8, 8, 2),
    overworld_frame(&barboachTiles[0], 8, 8, 5),
    overworld_frame(&barboachTiles[0], 8, 8, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Barboach[] = {
    overworld_frame(&barboachTiles[0], 8, 8, 7),
    overworld_frame(&barboachTiles[0], 8, 8, 6),
    overworld_frame(&barboachTiles[0], 8, 8, 9),
    overworld_frame(&barboachTiles[0], 8, 8, 8),
    overworld_frame(&barboachTiles[0], 8, 8, 11),
    overworld_frame(&barboachTiles[0], 8, 8, 10),
};

const struct SpriteTemplate sBarboachOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Barboach, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sBarboachOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Barboach, UpdateSurfMonOverlay);

//=============== WHISCASH
extern const u32 whiscashTiles[];
extern const u16 whiscashPal[];
extern const u16 whiscashShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Whiscash[] = {
    // Facing South
    overworld_frame(&whiscashTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&whiscashTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&whiscashTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&whiscashTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&whiscashTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&whiscashTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Whiscash[] = {
    // Facing South
    overworld_frame(&whiscashTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&whiscashTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&whiscashTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&whiscashTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&whiscashTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&whiscashTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sWhiscashOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Whiscash, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sWhiscashOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Whiscash, UpdateSurfMonOverlay);

//=============== CORPHISH
extern const u32 corphishTiles[];
extern const u16 corphishPal[];
extern const u16 corphishShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Corphish[] = {
    overworld_frame(&corphishTiles[0], 8, 8, 1),
    overworld_frame(&corphishTiles[0], 8, 8, 0),
    overworld_frame(&corphishTiles[0], 8, 8, 3),
    overworld_frame(&corphishTiles[0], 8, 8, 2),
    overworld_frame(&corphishTiles[0], 8, 8, 5),
    overworld_frame(&corphishTiles[0], 8, 8, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Corphish[] = {
    overworld_frame(&corphishTiles[0], 8, 8, 7),
    overworld_frame(&corphishTiles[0], 8, 8, 6),
    overworld_frame(&corphishTiles[0], 8, 8, 9),
    overworld_frame(&corphishTiles[0], 8, 8, 8),
    overworld_frame(&corphishTiles[0], 8, 8, 11),
    overworld_frame(&corphishTiles[0], 8, 8, 10),
};

const struct SpriteTemplate sCorphishOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Corphish, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sCorphishOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Corphish, UpdateSurfMonOverlay);

//=============== CRAWDAUNT
extern const u32 crawdauntTiles[];
extern const u16 crawdauntPal[];
extern const u16 crawdauntShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Crawdaunt[] = {
    // Facing South
    overworld_frame(&crawdauntTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&crawdauntTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&crawdauntTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&crawdauntTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&crawdauntTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&crawdauntTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Crawdaunt[] = {
    // Facing South
    overworld_frame(&crawdauntTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&crawdauntTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&crawdauntTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&crawdauntTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&crawdauntTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&crawdauntTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sCrawdauntOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Crawdaunt, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sCrawdauntOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Crawdaunt, UpdateSurfMonOverlay);

//=============== FEEBAS
extern const u32 feebasTiles[];
extern const u16 feebasPal[];
extern const u16 feebasShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Feebas[] = {
    overworld_frame(&feebasTiles[0], 8, 8, 1),
    overworld_frame(&feebasTiles[0], 8, 8, 0),
    overworld_frame(&feebasTiles[0], 8, 8, 3),
    overworld_frame(&feebasTiles[0], 8, 8, 2),
    overworld_frame(&feebasTiles[0], 8, 8, 5),
    overworld_frame(&feebasTiles[0], 8, 8, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Feebas[] = {
    overworld_frame(&feebasTiles[0], 8, 8, 7),
    overworld_frame(&feebasTiles[0], 8, 8, 6),
    overworld_frame(&feebasTiles[0], 8, 8, 9),
    overworld_frame(&feebasTiles[0], 8, 8, 8),
    overworld_frame(&feebasTiles[0], 8, 8, 11),
    overworld_frame(&feebasTiles[0], 8, 8, 10),
};

const struct SpriteTemplate sFeebasOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Feebas, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sFeebasOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Feebas, UpdateSurfMonOverlay);

//=============== MILOTIC
extern const u32 miloticTiles[];
extern const u16 miloticPal[];
extern const u16 miloticShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Milotic[] = {
    overworld_frame(&miloticTiles[0], 4, 4, 0),
    overworld_frame(&miloticTiles[0], 4, 4, 1),
    overworld_frame(&miloticTiles[0], 4, 4, 2),
    overworld_frame(&miloticTiles[0], 4, 4, 3),
    overworld_frame(&miloticTiles[0], 4, 4, 4),
    overworld_frame(&miloticTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Milotic[] = {
    overworld_frame(&miloticTiles[0], 4, 4, 6),
    overworld_frame(&miloticTiles[0], 4, 4, 7),
    overworld_frame(&miloticTiles[0], 4, 4, 8),
    overworld_frame(&miloticTiles[0], 4, 4, 9),
    overworld_frame(&miloticTiles[0], 4, 4, 10),
    overworld_frame(&miloticTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sMiloticOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Milotic, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sMiloticOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Milotic, UpdateSurfMonOverlay);

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

const struct SpriteFrameImage gSurfingOverlayPicTable_Spheal[] = {
    overworld_frame(&sphealTiles[0], 4, 4, 6),
    overworld_frame(&sphealTiles[0], 4, 4, 7),
    overworld_frame(&sphealTiles[0], 4, 4, 8),
    overworld_frame(&sphealTiles[0], 4, 4, 9),
    overworld_frame(&sphealTiles[0], 4, 4, 10),
    overworld_frame(&sphealTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sSphealOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Spheal, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sSphealOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Spheal, UpdateSurfMonOverlay);

//=============== AZURILL
extern const u32 azurillTiles[];
extern const u16 azurillPal[];
extern const u16 azurillShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Azurill[] = {
    overworld_frame(&azurillTiles[0], 4, 4, 0),
    overworld_frame(&azurillTiles[0], 4, 4, 1),
    overworld_frame(&azurillTiles[0], 4, 4, 2),
    overworld_frame(&azurillTiles[0], 4, 4, 3),
    overworld_frame(&azurillTiles[0], 4, 4, 4),
    overworld_frame(&azurillTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Azurill[] = {
    overworld_frame(&azurillTiles[0], 4, 4, 6),
    overworld_frame(&azurillTiles[0], 4, 4, 7),
    overworld_frame(&azurillTiles[0], 4, 4, 8),
    overworld_frame(&azurillTiles[0], 4, 4, 9),
    overworld_frame(&azurillTiles[0], 4, 4, 10),
    overworld_frame(&azurillTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sAzurillOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Azurill, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sAzurillOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Azurill, UpdateSurfMonOverlay);

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
extern const u32 clamperlTiles[];
extern const u16 clamperlPal[];
extern const u16 clamperlShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Clamperl[] = {
    // Facing South
    overworld_frame(&clamperlTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&clamperlTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&clamperlTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&clamperlTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&clamperlTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&clamperlTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Clamperl[] = {
    // Facing South
    overworld_frame(&clamperlTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&clamperlTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&clamperlTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&clamperlTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&clamperlTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&clamperlTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sClamperlOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Clamperl, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sClamperlOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Clamperl, UpdateSurfMonOverlay);

//=============== HUNTAIL
extern const u32 huntailTiles[];
extern const u16 huntailPal[];
extern const u16 huntailShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Huntail[] = {
    // Facing South
    overworld_frame(&huntailTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&huntailTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&huntailTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&huntailTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&huntailTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&huntailTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Huntail[] = {
    // Facing South
    overworld_frame(&huntailTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&huntailTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&huntailTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&huntailTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&huntailTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&huntailTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sHuntailOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Huntail, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sHuntailOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Huntail, UpdateSurfMonOverlay);

//=============== GOREBYSS
extern const u32 gorebyssTiles[];
extern const u16 gorebyssPal[];
extern const u16 gorebyssShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Gorebyss[] = {
    // Facing South
    overworld_frame(&gorebyssTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&gorebyssTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&gorebyssTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&gorebyssTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&gorebyssTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&gorebyssTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Gorebyss[] = {
    // Facing South
    overworld_frame(&gorebyssTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&gorebyssTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&gorebyssTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&gorebyssTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&gorebyssTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&gorebyssTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sGorebyssOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Gorebyss, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sGorebyssOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Gorebyss, UpdateSurfMonOverlay);

//=============== RELICANTH
extern const u32 relicanthTiles[];
extern const u16 relicanthPal[];
extern const u16 relicanthShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Relicanth[] = {
    // Facing South
    overworld_frame(&relicanthTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&relicanthTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&relicanthTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&relicanthTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&relicanthTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&relicanthTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Relicanth[] = {
    // Facing South
    overworld_frame(&relicanthTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&relicanthTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&relicanthTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&relicanthTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&relicanthTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&relicanthTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sRelicanthOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Relicanth, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sRelicanthOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Relicanth, UpdateSurfMonOverlay);

//=============== LUVDISC
extern const u32 luvdiscTiles[];
extern const u16 luvdiscPal[];
extern const u16 luvdiscShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Luvdisc[] = {
    overworld_frame(&luvdiscTiles[0], 8, 8, 1),
    overworld_frame(&luvdiscTiles[0], 8, 8, 0),
    overworld_frame(&luvdiscTiles[0], 8, 8, 3),
    overworld_frame(&luvdiscTiles[0], 8, 8, 2),
    overworld_frame(&luvdiscTiles[0], 8, 8, 5),
    overworld_frame(&luvdiscTiles[0], 8, 8, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Luvdisc[] = {
    overworld_frame(&luvdiscTiles[0], 8, 8, 7),
    overworld_frame(&luvdiscTiles[0], 8, 8, 6),
    overworld_frame(&luvdiscTiles[0], 8, 8, 9),
    overworld_frame(&luvdiscTiles[0], 8, 8, 8),
    overworld_frame(&luvdiscTiles[0], 8, 8, 11),
    overworld_frame(&luvdiscTiles[0], 8, 8, 10),
};

const struct SpriteTemplate sLuvdiscOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Luvdisc, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLuvdiscOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Luvdisc, UpdateSurfMonOverlay);

//=============== LATIAS
extern const u32 latiasTiles[];
extern const u16 latiasPal[];
extern const u16 latiasShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Latias[] = {
    // Facing South
    overworld_frame(&latiasTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&latiasTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&latiasTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&latiasTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&latiasTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&latiasTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Latias[] = {
    // Facing South
    overworld_frame(&latiasTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&latiasTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&latiasTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&latiasTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&latiasTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&latiasTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sLatiasOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Latias, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLatiasOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Latias, UpdateSurfMonOverlay);

//=============== LATIOS
extern const u32 latiosTiles[];
extern const u16 latiosPal[];
extern const u16 latiosShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Latios[] = {
    // Facing South
    overworld_frame(&latiosTiles[0], 4, 4, 0), // Bob Up
    overworld_frame(&latiosTiles[0], 4, 4, 1), // Bob Down

    // Facing North
    overworld_frame(&latiosTiles[0], 4, 4, 2), // Bob Up
    overworld_frame(&latiosTiles[0], 4, 4, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&latiosTiles[0], 4, 4, 4), // Bob Up
    overworld_frame(&latiosTiles[0], 4, 4, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Latios[] = {
    // Facing South
    overworld_frame(&latiosTiles[0], 4, 4, 6), // Bob Up
    overworld_frame(&latiosTiles[0], 4, 4, 7), // Bob Down

    // Facing North
    overworld_frame(&latiosTiles[0], 4, 4, 8), // Bob Up
    overworld_frame(&latiosTiles[0], 4, 4, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&latiosTiles[0], 4, 4, 10), // Bob Up
    overworld_frame(&latiosTiles[0], 4, 4, 11), // Bob Down
};

const struct SpriteTemplate sLatiosOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Latios, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sLatiosOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Latios, UpdateSurfMonOverlay);

//=============== KYOGRE
extern const u32 kyogreTiles[];
extern const u16 kyogrePal[];
extern const u16 kyogreShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Kyogre[] = {
    // Facing South
    overworld_frame(&kyogreTiles[0], 8, 8, 0), // Bob Up
    overworld_frame(&kyogreTiles[0], 8, 8, 1), // Bob Down

    // Facing North
    overworld_frame(&kyogreTiles[0], 8, 8, 2), // Bob Up
    overworld_frame(&kyogreTiles[0], 8, 8, 3), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kyogreTiles[0], 8, 8, 4), // Bob Up
    overworld_frame(&kyogreTiles[0], 8, 8, 5), // Bob Down
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Kyogre[] = {
    // Facing South
    overworld_frame(&kyogreTiles[0], 8, 8, 6), // Bob Up
    overworld_frame(&kyogreTiles[0], 8, 8, 7), // Bob Down

    // Facing North
    overworld_frame(&kyogreTiles[0], 8, 8, 8), // Bob Up
    overworld_frame(&kyogreTiles[0], 8, 8, 9), // Bob Down

    // Facing East/West (Mirrored)
    overworld_frame(&kyogreTiles[0], 8, 8, 10), // Bob Up
    overworld_frame(&kyogreTiles[0], 8, 8, 11), // Bob Down
};

//=============== RAYQUAZA
extern const u32 rayquazaTiles[];
extern const u16 rayquazaPal[];
extern const u16 rayquazaShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Rayquaza[] = {
    overworld_frame(&rayquazaTiles[0], 8, 8, 1),
    overworld_frame(&rayquazaTiles[0], 8, 8, 0),
    overworld_frame(&rayquazaTiles[0], 8, 8, 3),
    overworld_frame(&rayquazaTiles[0], 8, 8, 2),
    overworld_frame(&rayquazaTiles[0], 8, 8, 5),
    overworld_frame(&rayquazaTiles[0], 8, 8, 4),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Rayquaza[] = {
    overworld_frame(&rayquazaTiles[0], 8, 8, 7),
    overworld_frame(&rayquazaTiles[0], 8, 8, 6),
    overworld_frame(&rayquazaTiles[0], 8, 8, 9),
    overworld_frame(&rayquazaTiles[0], 8, 8, 8),
    overworld_frame(&rayquazaTiles[0], 8, 8, 11),
    overworld_frame(&rayquazaTiles[0], 8, 8, 10),
};

const struct SpriteTemplate sRayquazaOverworld = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Rayquaza, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sRayquazaOverlay = surf_template64x64(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Rayquaza, UpdateSurfMonOverlay);

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
        /*
         * If a shiny palette or overlay does not exist, set:
         * .shinyPalAddr = 0,
         * .overlayGfx = 0,
         */
        /*
        {
            .species = SPECIES_NAME,
            .palAddr = &namePal[0],
            .shinyPalAddr = &nameShinyPal[0],
            .overworldGfx = &sNameOverworld,
            .overlayGfx = &sNameOverlay,
        },
        */

        //=============== KANTO POKEMON
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
            .species = SPECIES_PIKACHU,
            .palAddr = &pikachuPal[0],
            .shinyPalAddr = &pikachuShinyPal[0],
            .overworldGfx = &sPikachuOverworld,
            .overlayGfx = &sPikachuOverlay,
        },
        {
            .species = SPECIES_RAICHU,
            .palAddr = &raichuPal[0],
            .shinyPalAddr = &raichuShinyPal[0],
            .overworldGfx = &sRaichuOverworld,
            .overlayGfx = &sRaichuOverlay,
        },
        {
            .species = SPECIES_NIDOQUEEN,
            .palAddr = &nidoqueenPal[0],
            .shinyPalAddr = &nidoqueenShinyPal[0],
            .overworldGfx = &sNidoqueenOverworld,
            .overlayGfx = &sNidoqueenOverlay,
        },
        {
            .species = SPECIES_NIDOKING,
            .palAddr = &nidokingPal[0],
            .shinyPalAddr = &nidokingShinyPal[0],
            .overworldGfx = &sNidokingOverworld,
            .overlayGfx = &sNidokingOverlay,
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
            .shinyPalAddr = &poliwagShinyPal[0],
            .overworldGfx = &sPoliwagOverworld,
            .overlayGfx = &sPoliwagOverlay,
        },
        {
            .species = SPECIES_POLIWHIRL,
            .palAddr = &poliwhirlPal[0],
            .shinyPalAddr = &poliwhirlShinyPal[0],
            .overworldGfx = &sPoliwhirlOverworld,
            .overlayGfx = &sPoliwhirlOverlay,
        },
        {
            .species = SPECIES_POLIWRATH,
            .palAddr = &poliwrathPal[0],
            .shinyPalAddr = &poliwrathShinyPal[0],
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
            .palAddr = &shellderPal[0],
            .shinyPalAddr = &shellderShinyPal[0],
            .overworldGfx = &sShellderOverworld,
            .overlayGfx = &sShellderOverlay,
        },
        {
            .species = SPECIES_CLOYSTER,
            .palAddr = &cloysterPal[0],
            .shinyPalAddr = &cloysterShinyPal[0],
            .overworldGfx = &sCloysterOverworld,
            .overlayGfx = &sCloysterOverlay,
        },
        {
            .species = SPECIES_KRABBY,
            .palAddr = &krabbyPal[0],
            .shinyPalAddr = &krabbyShinyPal[0],
            .overworldGfx = &sKrabbyOverworld,
            .overlayGfx = &sKrabbyOverlay,
        },
        {
            .species = SPECIES_KINGLER,
            .palAddr = &kinglerPal[0],
            .shinyPalAddr = &kinglerShinyPal[0],
            .overworldGfx = &sKinglerOverworld,
            .overlayGfx = &sKinglerOverlay,
        },
        {
            .species = SPECIES_LICKITUNG,
            .palAddr = &lickitungPal[0],
            .shinyPalAddr = &lickitungShinyPal[0],
            .overworldGfx = &sLickitungOverworld,
            .overlayGfx = &sLickitungOverlay,
        },
        {
            .species = SPECIES_RHYDON,
            .palAddr = &rhydonPal[0],
            .shinyPalAddr = &rhydonShinyPal[0],
            .overworldGfx = &sRhydonOverworld,
            .overlayGfx = &sRhydonOverlay,
        },
        {
            .species = SPECIES_KANGASKHAN,
            .palAddr = &kangaskhanPal[0],
            .shinyPalAddr = &kangaskhanShinyPal[0],
            .overworldGfx = &sKangaskhanOverworld,
            .overlayGfx = &sKangaskhanOverlay,
        },
        {
            .species = SPECIES_HORSEA,
            .palAddr = &horseaPal[0],
            .shinyPalAddr = &horseaShinyPal[0],
            .overworldGfx = &sHorseaOverworld,
            .overlayGfx = &sHorseaOverlay,
        },
        {
            .species = SPECIES_SEADRA,
            .palAddr = &seadraPal[0],
            .shinyPalAddr = &seadraShinyPal[0],
            .overworldGfx = &sSeadraOverworld,
            .overlayGfx = &sSeadraOverlay,
        },
        {
            .species = SPECIES_GOLDEEN,
            .palAddr = &goldeenPal[0],
            .shinyPalAddr = &goldeenShinyPal[0],
            .overworldGfx = &sGoldeenOverworld,
            .overlayGfx = &sGoldeenOverlay,
        },
        {
            .species = SPECIES_SEAKING,
            .palAddr = &seakingPal[0],
            .shinyPalAddr = &seakingShinyPal[0],
            .overworldGfx = &sSeakingOverworld,
            .overlayGfx = &sSeakingOverlay,
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
            .palAddr = &taurosPal[0],
            .shinyPalAddr = &taurosShinyPal[0],
            .overworldGfx = &sTaurosOverworld,
            .overlayGfx = &sTaurosOverlay,
        },
        {
            .species = SPECIES_GYARADOS,
            .palAddr = &gyaradosPal[0],
            .shinyPalAddr = &gyaradosShinyPal[0],
            .overworldGfx = &sGyaradosOverworld,
            .overlayGfx = &sGyaradosOverlay,
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
            .palAddr = &omanytePal[0],
            .shinyPalAddr = &omanyteShinyPal[0],
            .overworldGfx = &sOmanyteOverworld,
            .overlayGfx = &sOmanyteOverlay,
        },
        {
            .species = SPECIES_OMASTAR,
            .palAddr = &omastarPal[0],
            .shinyPalAddr = &omastarShinyPal[0],
            .overworldGfx = &sOmastarOverworld,
            .overlayGfx = &sOmastarOverlay,
        },
        {
            .species = SPECIES_KABUTO,
            .palAddr = &kabutoPal[0],
            .shinyPalAddr = &kabutoShinyPal[0],
            .overworldGfx = &sKabutoOverworld,
            .overlayGfx = &sKabutoOverlay,
        },
        {
            .species = SPECIES_KABUTOPS,
            .palAddr = &kabutopsPal[0],
            .shinyPalAddr = &kabutopsShinyPal[0],
            .overworldGfx = &sKabutopsOverworld,
            .overlayGfx = &sKabutopsOverlay,
        },
        {
            .species = SPECIES_SNORLAX,
            .palAddr = &snorlaxPal[0],
            .shinyPalAddr = &snorlaxShinyPal[0],
            .overworldGfx = &sSnorlaxOverworld,
            .overlayGfx = &sSnorlaxOverlay,
        },
        {
            .species = SPECIES_DRATINI,
            .palAddr = &dratiniPal[0],
            .shinyPalAddr = &dratiniShinyPal[0],
            .overworldGfx = &sDratiniOverworld,
            .overlayGfx = &sDratiniOverlay,
        },
        {
            .species = SPECIES_DRAGONAIR,
            .palAddr = &dragonairPal[0],
            .shinyPalAddr = &dragonairShinyPal[0],
            .overworldGfx = &sDragonairOverworld,
            .overlayGfx = &sDragonairOverlay,
        },
        {
            .species = SPECIES_DRAGONITE,
            .palAddr = &dragonitePal[0],
            .shinyPalAddr = &dragoniteShinyPal[0],
            .overworldGfx = &sDragoniteOverworld,
            .overlayGfx = &sDragoniteOverlay,
        },
        {
            .species = SPECIES_MEW,
            .palAddr = &mewPal[0],
            .shinyPalAddr = &mewShinyPal[0],
            .overworldGfx = &sMewOverworld,
            .overlayGfx = &sMewOverlay,
        },
        //=============== JOHTO POKEMON
        {
            .species = SPECIES_TOTODILE,
            .palAddr = &totodilePal[0],
            .shinyPalAddr = &totodileShinyPal[0],
            .overworldGfx = &sTotodileOverworld,
            .overlayGfx = &sTotodileOverlay,
        },
        {
            .species = SPECIES_CROCONAW,
            .palAddr = &croconawPal[0],
            .shinyPalAddr = &croconawShinyPal[0],
            .overworldGfx = &sCroconawOverworld,
            .overlayGfx = &sCroconawOverlay,
        },
        {
            .species = SPECIES_FERALIGATR,
            .palAddr = &feraligatrPal[0],
            .shinyPalAddr = &feraligatrShinyPal[0],
            .overworldGfx = &sFeraligatrOverworld,
            .overlayGfx = &sFeraligatrOverlay,
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
            .species = SPECIES_PICHU,
            .palAddr = &pichuPal[0],
            .shinyPalAddr = &pichuShinyPal[0],
            .overworldGfx = &sPichuOverworld,
            .overlayGfx = &sPichuOverlay,
        },
        {
            .species = SPECIES_CHINCHOU,
            .palAddr = &chinchouPal[0],
            .shinyPalAddr = &chinchouShinyPal[0],
            .overworldGfx = &sChinchouOverworld,
            .overlayGfx = &sChinchouOverlay,
        },
        {
            .species = SPECIES_LANTURN,
            .palAddr = &lanturnPal[0],
            .shinyPalAddr = &lanturnShinyPal[0],
            .overworldGfx = &sLanturnOverworld,
            .overlayGfx = &sLanturnOverlay,
        },
        {
            .species = SPECIES_AZURILL,
            .palAddr = &azurillPal[0],
            .shinyPalAddr = &azurillShinyPal[0],
            .overworldGfx = &sAzurillOverworld,
            .overlayGfx = &sAzurillOverlay,
        },
        {
            .species = SPECIES_MARILL,
            .palAddr = &marillPal[0],
            .shinyPalAddr = &marillShinyPal[0],
            .overworldGfx = &sMarillOverworld,
            .overlayGfx = &sMarillOverlay,
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
            .shinyPalAddr = &politoedShinyPal[0],
            .overworldGfx = &sPolitoedOverworld,
            .overlayGfx = &sPolitoedOverlay,
        },
        {
            .species = SPECIES_WOOPER,
            .palAddr = &wooperPal[0],
            .shinyPalAddr = &wooperShinyPal[0],
            .overworldGfx = &sWooperOverworld,
            .overlayGfx = &sWooperOverlay,
        },
        {
            .species = SPECIES_QUAGSIRE,
            .palAddr = &quagsirePal[0],
            .shinyPalAddr = &quagsireShinyPal[0],
            .overworldGfx = &sQuagsireOverworld,
            .overlayGfx = &sQuagsireOverlay,
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
            .palAddr = &qwilfishPal[0],
            .shinyPalAddr = &qwilfishShinyPal[0],
            .overworldGfx = &sQwilfishOverworld,
            .overlayGfx = &sQwilfishOverlay,
        },
        {
            .species = SPECIES_SNEASEL,
            .palAddr = &sneaselPal[0],
            .shinyPalAddr = &sneaselShinyPal[0],
            .overworldGfx = &sSneaselOverworld,
            .overlayGfx = &sSneaselOverlay,
        },
        {
            .species = SPECIES_CORSOLA,
            .palAddr = &corsolaPal[0],
            .shinyPalAddr = &corsolaShinyPal[0],
            .overworldGfx = &sCorsolaOverworld,
            .overlayGfx = &sCorsolaOverlay,
        },
        {
            .species = SPECIES_REMORAID,
            .palAddr = &remoraidPal[0],
            .shinyPalAddr = &remoraidShinyPal[0],
            .overworldGfx = &sRemoraidOverworld,
            .overlayGfx = &sRemoraidOverlay,
        },
        {
            .species = SPECIES_OCTILLERY,
            .palAddr = &octilleryPal[0],
            .shinyPalAddr = &octilleryShinyPal[0],
            .overworldGfx = &sOctilleryOverworld,
            .overlayGfx = &sOctilleryOverlay,
        },
        {
            .species = SPECIES_MANTINE,
            .palAddr = &mantinePal[0],
            .shinyPalAddr = &mantineShinyPal[0],
            .overworldGfx = &sMantineOverworld,
            .overlayGfx = &sMantineOverlay,
        },
        {
            .species = SPECIES_KINGDRA,
            .palAddr = &kingdraPal[0],
            .shinyPalAddr = &kingdraShinyPal[0],
            .overworldGfx = &sKingdraOverworld,
            .overlayGfx = &sKingdraOverlay,
        },
        {
            .species = SPECIES_MILTANK,
            .palAddr = &miltankPal[0],
            .shinyPalAddr = &miltankShinyPal[0],
            .overworldGfx = &sMiltankOverworld,
            .overlayGfx = &sMiltankOverlay,
        },
        {
            .species = SPECIES_SUICUNE,
            .palAddr = &suicunePal[0],
            .shinyPalAddr = &suicuneShinyPal[0],
            .overworldGfx = &sSuicuneOverworld,
            .overlayGfx = &sSuicuneOverlay,
        },
        {
            .species = SPECIES_TYRANITAR,
            .palAddr = &tyranitarPal[0],
            .shinyPalAddr = &tyranitarShinyPal[0],
            .overworldGfx = &sTyranitarOverworld,
            .overlayGfx = &sTyranitarOverlay,
        },
        {
            .species = SPECIES_LUGIA,
            .palAddr = &lugiaPal[0],
            .shinyPalAddr = &lugiaShinyPal[0],
            .overworldGfx = &sLugiaOverworld,
            .overlayGfx = &sLugiaOverlay,
        },
        /*
         * =============== HOENN POKEMON
          NOTE: These are listed in National Dex Order
          (Not in Internal Order for FRLG/RSE)
         */
        {
            .species = SPECIES_MUDKIP,
            .palAddr = &mudkipPal[0],
            .shinyPalAddr = &mudkipShinyPal[0],
            .overworldGfx = &sMudkipOverworld,
            .overlayGfx = &sMudkipOverlay,
        },
        {
            .species = SPECIES_MARSHTOMP,
            .palAddr = &marshtompPal[0],
            .shinyPalAddr = &marshtompShinyPal[0],
            .overworldGfx = &sMarshtompOverworld,
            .overlayGfx = &sMarshtompOverlay,
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
            .palAddr = &zigzagoonPal[0],
            .shinyPalAddr = &zigzagoonShinyPal[0],
            .overworldGfx = &sZigzagoonOverworld,
            .overlayGfx = &sZigzagoonOverlay,
        },
        {
            .species = SPECIES_LINOONE,
            .palAddr = &linoonePal[0],
            .shinyPalAddr = &linooneShinyPal[0],
            .overworldGfx = &sLinooneOverworld,
            .overlayGfx = &sLinooneOverlay,
        },
        {
            .species = SPECIES_LOTAD,
            .palAddr = &lotadPal[0],
            .shinyPalAddr = &lotadShinyPal[0],
            .overworldGfx = &sLotadOverworld,
            .overlayGfx = &sLotadOverlay,
        },
        {
            .species = SPECIES_LOMBRE,
            .palAddr = &lombrePal[0],
            .shinyPalAddr = &lombreShinyPal[0],
            .overworldGfx = &sLombreOverworld,
            .overlayGfx = &sLombreOverlay,
        },
        {
            .species = SPECIES_LUDICOLO,
            .palAddr = &ludicoloPal[0],
            .shinyPalAddr = &ludicoloShinyPal[0],
            .overworldGfx = &sLudicoloOverworld,
            .overlayGfx = &sLudicoloOverlay,
        },
        {
            .species = SPECIES_PELIPPER,
            .palAddr = &pelipperPal[0],
            .shinyPalAddr = &pelipperShinyPal[0],
            .overworldGfx = &sPelipperOverworld,
            .overlayGfx = &sPelipperOverlay,
        },
        {
            .species = SPECIES_EXPLOUD,
            .palAddr = &exploudPal[0],
            .shinyPalAddr = &exploudShinyPal[0],
            .overworldGfx = &sExploudOverworld,
            .overlayGfx = &sExploudOverlay,
        },
        {
            .species = SPECIES_SURSKIT,
            .palAddr = &surskitPal[0],
            .shinyPalAddr = &surskitShinyPal[0],
            .overworldGfx = &sSurskitOverworld,
            .overlayGfx = &sSurskitOverlay,
        },
        {
            .species = SPECIES_MASQUERAIN,
            .palAddr = &masquerainPal[0],
            .shinyPalAddr = &masquerainShinyPal[0],
            .overworldGfx = &sMasquerainOverworld,
            .overlayGfx = &sMasquerainOverlay,
        },
        {
            .species = SPECIES_MAKUHITA,
            .palAddr = &makuhitaPal[0],
            .shinyPalAddr = &makuhitaShinyPal[0],
            .overworldGfx = &sMakuhitaOverworld,
            .overlayGfx = &sMakuhitaOverlay,
        },
        {
            .species = SPECIES_HARIYAMA,
            .palAddr = &hariyamaPal[0],
            .shinyPalAddr = &hariyamaShinyPal[0],
            .overworldGfx = &sHariyamaOverworld,
            .overlayGfx = &sHariyamaOverlay,
        },
        {
            .species = SPECIES_AZURILL,
            .palAddr = &azurillPal[0],
            .shinyPalAddr = &azurillShinyPal[0],
            .overworldGfx = &sAzurillOverworld,
            .overlayGfx = &sAzurillOverlay,
        },
        {
            .species = SPECIES_AGGRON,
            .palAddr = &aggronPal[0],
            .shinyPalAddr = &aggronShinyPal[0],
            .overworldGfx = &sAggronOverworld,
            .overlayGfx = &sAggronOverlay,
        },
        {
            .species = SPECIES_CARVANHA,
            .palAddr = &carvanhaPal[0],
            .shinyPalAddr = &carvanhaShinyPal[0],
            .overworldGfx = &sCarvanhaOverworld,
            .overlayGfx = &sCarvanhaOverlay,
        },
        {
            .species = SPECIES_SHARPEDO,
            .palAddr = &sharpedoPal[0],
            .shinyPalAddr = &sharpedoShinyPal[0],
            .overworldGfx = &sSharpedoOverworld,
            .overlayGfx = &sSharpedoOverlay,
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
            .palAddr = &wailordPal[0],
            .shinyPalAddr = &wailordShinyPal[0],
            .overworldGfx = &sWailordOverworld,
            .overlayGfx = &sWailordOverlay,
        },
        {
            .species = SPECIES_ZANGOOSE,
            .palAddr = &zangoosePal[0],
            .shinyPalAddr = &zangooseShinyPal[0],
            .overworldGfx = &sZangooseOverworld,
            .overlayGfx = &sZangooseOverlay,
        },
        {
            .species = SPECIES_BARBOACH,
            .palAddr = &barboachPal[0],
            .shinyPalAddr = &barboachShinyPal[0],
            .overworldGfx = &sBarboachOverworld,
            .overlayGfx = &sBarboachOverlay,
        },
        {
            .species = SPECIES_WHISCASH,
            .palAddr = &whiscashPal[0],
            .shinyPalAddr = &whiscashShinyPal[0],
            .overworldGfx = &sWhiscashOverworld,
            .overlayGfx = &sWhiscashOverlay,
        },
        {
            .species = SPECIES_CORPHISH,
            .palAddr = &corphishPal[0],
            .shinyPalAddr = &corphishShinyPal[0],
            .overworldGfx = &sCorphishOverworld,
            .overlayGfx = &sCorphishOverlay,
        },
        {
            .species = SPECIES_CRAWDAUNT,
            .palAddr = &crawdauntPal[0],
            .shinyPalAddr = &crawdauntShinyPal[0],
            .overworldGfx = &sCrawdauntOverworld,
            .overlayGfx = &sCrawdauntOverlay,
        },
        {
            .species = SPECIES_FEEBAS,
            .palAddr = &feebasPal[0],
            .shinyPalAddr = &feebasShinyPal[0],
            .overworldGfx = &sFeebasOverworld,
            .overlayGfx = &sFeebasOverlay,
        },
        {
            .species = SPECIES_MILOTIC,
            .palAddr = &miloticPal[0],
            .shinyPalAddr = &miloticShinyPal[0],
            .overworldGfx = &sMiloticOverworld,
            .overlayGfx = &sMiloticOverlay,
        },
        {
            .species = SPECIES_SPHEAL,
            .palAddr = &sphealPal[0],
            .shinyPalAddr = &sphealShinyPal[0],
            .overworldGfx = &sSphealOverworld,
            .overlayGfx = &sSphealOverlay,
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
            .palAddr = &clamperlPal[0],
            .shinyPalAddr = &clamperlShinyPal[0],
            .overworldGfx = &sClamperlOverworld,
            .overlayGfx = &sClamperlOverlay,
        },
        {
            .species = SPECIES_HUNTAIL,
            .palAddr = &huntailPal[0],
            .shinyPalAddr = &huntailShinyPal[0],
            .overworldGfx = &sHuntailOverworld,
            .overlayGfx = &sHuntailOverlay,
        },
        {
            .species = SPECIES_GOREBYSS,
            .palAddr = &gorebyssPal[0],
            .shinyPalAddr = &gorebyssShinyPal[0],
            .overworldGfx = &sGorebyssOverworld,
            .overlayGfx = &sGorebyssOverlay,
        },
        {
            .species = SPECIES_RELICANTH,
            .palAddr = &relicanthPal[0],
            .shinyPalAddr = &relicanthShinyPal[0],
            .overworldGfx = &sRelicanthOverworld,
            .overlayGfx = &sRelicanthOverlay,
        },
        {
            .species = SPECIES_LUVDISC,
            .palAddr = &luvdiscPal[0],
            .shinyPalAddr = &luvdiscShinyPal[0],
            .overworldGfx = &sLuvdiscOverworld,
            .overlayGfx = &sLuvdiscOverlay,
        },
        {
            .species = SPECIES_LATIAS,
            .palAddr = &latiasPal[0],
            .shinyPalAddr = &latiasShinyPal[0],
            .overworldGfx = &sLatiasOverworld,
            .overlayGfx = &sLatiasOverlay,
        },
        {
            .species = SPECIES_LATIOS,
            .palAddr = &latiosPal[0],
            .shinyPalAddr = &latiosShinyPal[0],
            .overworldGfx = &sLatiosOverworld,
            .overlayGfx = &sLatiosOverlay,
        },
        {
            .species = SPECIES_KYOGRE,
            .palAddr = &kyogrePal[0],
            .shinyPalAddr = &kyogreShinyPal[0],
            .overworldGfx = &sKyogreOverworld,
            .overlayGfx = 0,
        },
        {
            .species = SPECIES_RAYQUAZA,
            .palAddr = &rayquazaPal[0],
            .shinyPalAddr = &rayquazaShinyPal[0],
            .overworldGfx = &sRayquazaOverworld,
            .overlayGfx = &sRayquazaOverlay,
        },
};
