#pragma once

#include "config.h"
#include "../include/global.h"
#include "../include/pokedex.h"
#include "../include/task.h"
#include "../include/sprite.h"
#include "../include/palette.h"
#include "../include/event_data.h"

#define IS_EVEN(val) (umodsi(val, 2) == 0)
#define IS_ODD(val) (umodsi(val, 2) != 0)

#define uBYTE0_16(value)(( (u8) (((u16)(value) & (0x000000FF)) >> 0x00)))
#define uBYTE1_16(value)(( (u8) (((u16)(value) & (0x0000FF00)) >> 0x08)))

// Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

// Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

#define EOS 0xFF

#define ColorFilter *((u8*)0x2036E28)
#define gPlttBufferUnfaded ((u16*) 0x20371F8)
#define gPlttBufferUnfaded2 ((u16*) 0x20373F8)
#define gPaletteFade ((struct PaletteFadeControl*) 0x2037AB8)
#define gWeatherPtr ((struct Weather*) 0x2037F34)
#define gPlttBufferFaded ((u16*) 0x20375F8)
#define gPlttBufferFaded2 ((u16*) 0x20377F8)
#define AlphaBlendingCoeffA *((u8*)0x3000052)
#define PalTags ((u16*)0x3000DE8)
#define PalTagsStart *((u8*)0x3003E58)

#define gBrmData ((struct BrmData*)  ((u32*) 0x203b0a0))

#define sPlttBufferTransferPending (*((u32*) 0x2037AC8))

#define gBitTable ((u32*) 0x825E45C)

#define gSaveBlock1 ((struct SaveBlock1*) *((u32*) 0x3005008))
#define gSaveBlock2 ((struct SaveBlock2*) *((u32*) 0x300500C))
#define gSaveBlock3 ((struct SaveBlock3*) *((u32*) 0x3005010))
#define gEnemyParty ((struct Pokemon*) 0x202402C)
#define gPlayerParty ((struct Pokemon*) 0x2024284)
#define gSprites ((struct Sprite*) 0x202063C)

#define gPlayerAvatar ((struct PlayerAvatar*) 0x02037078)
#define gEventObjects ((struct MapObject*) 0x2036E38)
#define gMenuChoices ((struct MenuChoiceStruct*) 0x0203ADE4)
#define gBrmBoxes ((struct BrmBoxes*) (*(u32*) 0x0203B09C))

#define AFFINEANIMCMD_FRAME(_xScale, _yScale, _rotation, _duration) \
    {.frame = {.xScale = _xScale, .yScale = _yScale, .rotation = _rotation, .duration = _duration}}
#define AFFINEANIMCMD_LOOP(_count) \
    {.loop = {.type = AFFINEANIMCMDTYPE_LOOP, .count = _count}}
#define AFFINEANIMCMD_JUMP(_target) \
    {.jump = {.type = AFFINEANIMCMDTYPE_JUMP, .target = _target}}
#define AFFINEANIMCMD_END \
    {.type = AFFINEANIMCMDTYPE_END}
#define AFFINEANIMCMD_LOOP(_count) \
    {.loop = {.type = AFFINEANIMCMDTYPE_LOOP, .count = _count}}
#define AFFINEANIMCMD_JUMP(_target) \
    {.jump = {.type = AFFINEANIMCMDTYPE_JUMP, .target = _target}}
	
#define gEventObjectBaseOam_32x32 ((struct OamData*) 0x83A3718)
#define gSurfablePokemonAnimTable ((const union AnimCmd* const*) 0x83A555C)
#define gDummySpriteAffineAnimTable (const union AffineAnimCmd* const*) 0x8231CFC
#define sDefaultSurfBlob ((const struct SpriteTemplate*) 0x83A556C)

#define PalTypeUnused 0
#define PalTypeNPC 1
#define PalTypeAnimation 2
#define PalTypeWeather 3
#define PalTypeReflection 4
#define PalTypeOther 5

