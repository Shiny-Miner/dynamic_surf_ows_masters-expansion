
//SyncDirection = 0x80DC550 | 1;
sub_80DC588 = 0x80DC588 | 1;
sub_80DC61C = 0x80DC61C | 1;
sSpritePriorities = 0x2021780;

LogCoordsCameraRelative = 0x08063BC4 | 1;
GetMonData = 0x0803FBE8 | 1;
MapGridGetZCoordAt = 0x08058D44 | 1;

FieldEffectStart = 0x08083444 | 1;
FieldEffectFreeGraphicsResources = 0x080836B4 | 1;
FieldEffectStop = 0x080836D8 | 1;
FldEff_SurfBlob = 0x080DC3D0|1;
BindFieldEffectToSprite = 0x080DC44C | 1;

Task_WeatherMain = 0x8079e0c | 1;
GetCurrentWeather = 0x807AF98 | 1;

LoadCustomWeatherSpritePalette = 0x807ABC0 | 1;

/*Script Functions*/
VarGet = 0x806E568 | 1;
VarSet = 0x806E584 | 1;
FlagSet = 0x806E680 | 1;
FlagClear = 0x806E6A8 | 1;
GetFlagPointer = 0x806E5C0 | 1;
FlagGet = 0x806E6D0 | 1;

/*Palette Functions*/
BlendPalette = 0x8045274 | 1;
LoadCompressedPalette = 0x80703A8 | 1;
LoadPalette = 0x80703EC | 1;
FillPalette = 0x8070424 | 1;
UpdatePaletteFade = 0x80704D0 | 1;
ResetPaletteFade = 0x8070528 | 1;
ReadPlttIntoBuffers = 0x8070548 | 1;
BeginNormalPaletteFade = 0x8070588 | 1;
ResetPaletteStructByUid = 0x8070A0C | 1;
ResetPaletteStruct = 0x8070A28 | 1;
ResetPaletteFadeControl = 0x8070A84 | 1;
GetPaletteNumByUid = 0x8070B58 | 1;
UpdateNormalPaletteFade = 0x8070B8C | 1;
InvertPlttBuffer = 0x8070CCC | 1;
TintPlttBuffer = 0x8070D14 | 1;
UnfadePlttBuffer = 0x8070DE8 | 1;
BeginFastPaletteFade = 0x8070E44 | 1;
BeginFastPaletteFadeInternal = 0x8070E68 | 1;
UpdateFastPaletteFade = 0x8070EEC | 1;
BeginHardwarePaletteFade = 0x8071264 | 1;
UpdateHardwarePaletteFade = 0x8071300 | 1;
UpdateBlendRegisters = 0x807141C | 1;
IsSoftwarePaletteFadeFinishing = 0x8071470 | 1;
BlendPalettes = 0x80714D4 | 1;
BlendPalettesUnfaded = 0x8071510 | 1;
TintPalette_GrayScale = 0x8071544 | 1;
TintPalette_GrayScale2 = 0x8071594 | 1;
TintPalette_SepiaTone = 0x80715F4 | 1;
TintPalette_CustomTone = 0x8071660 | 1;
TintPalette_Switch = 0x08083598 | 1;

/*Other Functions*/
Malloc = 0x8002B9C | 1;
Calloc = 0x8002BB0 | 1;
Free = 0x8002BC4 | 1;

/*Sprite Functions*/
ResetSpriteData = 0x8006B10 | 1;
AnimateSprites = 0x8006B5C | 1;
BuildOamBuffer = 0x8006BA8 | 1;
UpdateOamCoords = 0x8006BF4 | 1;
BuildSpritePriorities = 0x8006CB8 | 1;
SortSprites = 0x8006CF8 | 1;
CopyMatricesToOamBuffer = 0x8006EB8 | 1;
AddSpritesToOamBuffer = 0x8006F04 | 1;
CreateSprite = 0x8006F8C | 1;
CreateSpriteAtEnd = 0x8006FE0 | 1;
CreateInvisibleSprite =0x800704C | 1;
CreateSpriteAt = 0x8007094 | 1;
CreateSpriteAndAnimate = 0x80071EC | 1;
DestroySprite = 0x8007280 | 1;
ResetOamRange = 0x80072E8 | 1;
LoadOam = 0x8007320 | 1;
ClearSpriteCopyRequests = 0x8007350 | 1;
ResetOamMatrices = 0x8007390 | 1;
SetOamMatrix = 0x80073BC | 1;
ResetSprite = 0x80073DC | 1;
CalcCenterToCornerVec = 0x080073F0 | 1;
AllocSpriteTiles = 0x8007434 | 1;
SpriteCallbackDummy = 0x800760C | 1;
ProcessSpriteCopyRequests = 0x8007610 | 1;
RequestSpriteFrameImageCopy = 0x800766C | 1;
RequestSpriteCopy = 0x80076D0 | 1;
CopyFromSprites = 0x8007720 | 1;
CopyToSprites = 0x8007748 | 1;
ResetAllSprites = 0x8007770 | 1;
FreeSpriteTiles = 0x80077AC | 1;
FreeSpritePalette = 0x80077C8 | 1;
FreeSpriteOamMatrix = 0x80077D8 | 1;
DestroySpriteAndFreeResources = 0x8007804 | 1;
AnimateSprite = 0x8007824 | 1;
BeginAnim = 0x800786C | 1;
ContinueAnim = 0x800795C | 1;
AnimCmd_frame = 0x80079FC | 1;
AnimCmd_end = 0x8007AA8 | 1;
AnimCmd_jump = 0x8007AC0 | 1;
AnimCmd_loop = 0x8007B88 | 1;
BeginAnimLoop = 0x8007BA8 | 1;
ContinueAnimLoop = 0x8007BE0 | 1;
JumpToTopOfAnimLoop = 0x8007C00 | 1;
BeginAffineAnim = 0x8007C74 | 1;
ContinueAffineAnim = 0x8007D08 | 1;
AffineAnimDelay = 0x8007DBC | 1;
AffineAnimCmd_loop = 0x8007DF0 | 1;
BeginAffineAnimLoop = 0x8007E24 | 1;
ContinueAffineAnimLoop = 0x8007E60 | 1;
JumpToTopOfAffineAnimLoop = 0x8007E90 | 1;
AffineAnimCmd_jump = 0x8007EFC | 1;
AffineAnimCmd_end = 0x8007F48 | 1;
AffineAnimCmd_frame = 0x8007F84 | 1;
CopyOamMatrix = 0x8007FBC | 1;
GetSpriteMatrixNum = 0x8007FDC | 1;
obj_update_pos2 = 0x8008038 | 1;
SetSpriteOamFlipBits = 0x80080D4 | 1;
AffineAnimStateRestartAnim = 0x8008148 | 1;
AffineAnimStateStartAnim = 0x8008164 | 1;
AffineAnimStateReset = 0x800818C | 1;
ApplyAffineAnimFrameAbsolute = 0x80081B4 | 1;
DecrementAnimDelayCounter = 0x80081D8 | 1;
DecrementAffineAnimDelayCounter = 0x8008200 | 1;
ApplyAffineAnimFrameRelativeAndUpdateMatrix = 0x8008230 | 1;
ConvertScaleParam = 0x80082C8 | 1;
GetAffineAnimFrame = 0x80082E0 | 1;
ApplyAffineAnimFrame = 0x800834C | 1;
StartSpriteAnim = 0x800838C | 1;
StartSpriteAnimIfDifferent = 0x80083A4 | 1;
SeekSpriteAnim = 0x80083C0 | 1;
StartSpriteAffineAnim = 0x800843C | 1;
StartSpriteAffineAnimIfDifferent = 0x8008468 | 1;
ChangeSpriteAffineAnim = 0x800849C | 1;
ChangeSpriteAffineAnimIfDifferent = 0x80084D4 | 1;
SetSpriteSheetFrameTileNum = 0x8008508 | 1;
ResetAffineAnimData = 0x8008560 | 1;
AllocOamMatrix = 0x8008594 | 1;
FreeOamMatrix = 0x80085CC | 1;
InitSpriteAffineAnim = 0x800860C | 1;
SetOamMatrixRotationScaling = 0x800865C | 1;
LoadSpriteSheet = 0x80086DC | 1;
LoadSpriteSheets = 0x8008720 | 1;
FreeSpriteTilesByTag = 0x800874C | 1;
FreeSpriteTileRanges = 0x80087C4 | 1;
GetSpriteTileStartByTag = 0x8008804 | 1;
IndexOfSpriteTileTag = 0x8008830 | 1;
GetSpriteTileTagByTileStart = 0x800885C | 1;
AllocSpriteTileRange = 0x80088A8 | 1;
FreeAllSpritePalettes = 0x80088F0 | 1;
LoadSpritePalette = 0x8008928 | 1;
LoadSpritePalettes = 0x8008974 | 1;
DoLoadSpritePalette = 0x80089A0 | 1;
AllocSpritePalette = 0x80089B8 | 1;
IndexOfSpritePaletteTag = 0x80089E8 | 1;
GetSpritePaletteTagByPaletteNum = 0x8008A20 | 1;
FreeSpritePaletteByTag = 0x8008A30 | 1;
SetSubspriteTables = 0x8008A58 | 1;
AddSpriteToOamBuffer = 0x8008A64 | 1;
AddSubspritesToOamBuffer = 0x8008AD0 | 1;

FieldEffectActiveListRemove = 0x080837fc | 1;
gFieldEffectObjectTemplatePointers = 0x083a0010;
UpdateSurfBlobFieldEffect = 0x80DC4F8 | 1;
BindObj = 0x080DC44C | 1;
gFieldEffectArguments = 0x20386E0;
surfBlobTiles = 0x8396b08;
surfBlobPal = 0x835b968;

FuncIsActiveTask = 0x8077650 | 1;

MonHasMove = 0x08125AC0 | 1;

/* Math Functions */
Sine = 0x8044E30 | 1;
Cosine = 0x8044E4C | 1;
Random = 0x8044EC8 | 1;
SeedRng2 = 0x8044EE8 | 1;
CountTrailingZeroBits = 0x8045190 | 1;
Random2 = 0x808322C | 1;
Sqrt = 0x81E3B9C | 1;
__divsi3 = 0x81E4018 | 1;
__modsi3 = 0x81E40F4 | 1;
__udivsi3 = 0x81E460C | 1;
udivsi = 0x81E460C | 1;
__umodsi3 = 0x81E4684 | 1;
umodsi = 0x81E4684 | 1;

Memcpy = 0x81E5E78 | 1;
memcpy_ = 0x81E5E78 | 1;
Memset = 0x81E5ED8 | 1;
memset_ = 0x81E5ED8 | 1;

MallocInit = 0x8002B80 | 1;
Malloc = 0x8002B9C | 1;
malloc_ = 0x8002B9C | 1;
Calloc = 0x8002BB0 | 1;
AllocZeroed = 0x8002BB0 | 1;
calloc_ = 0x8002BB0 | 1;
Free = 0x8002BC4 | 1;
free_ = 0x8002BC4 | 1;

CpuSet = 0x81E3B64 | 1;

sSurfBlobAnim_FaceSouth = 0x83a552c;
sSurfBlobAnim_FaceNorth = 0x83a5538;
sSurfBlobAnim_FaceWest = 0x83a5544;

