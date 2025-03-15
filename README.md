# Dynamic surfing overworlds for FR
## Expansion by Shiny miner, ansh, jordank

**Original thread (by ghoulslash):**
https://www.pokecommunity.com/threads/fire-red-dynamic-surf-overworlds.420665/

For any queries, ping one of us via [Discord](https://discord.gg/yKhCRrqJyX):
- anxz86
- jordank.memes
- shinyhunter08

## What Is This?

This is a feature, originally from pokeem, (see https://github.com/Slawter666/pokeemerald/tree/surfable/src), to have the surfing sprite dynamically change based on the first party pokemon or selected pokemon from the menu.

![Surfing Pikachu](example.gif)

## Improved Features

1. One master structure for all species data, so worrying about matching indexes is no longer an issue

2. The palette is directly loaded from an address rather than using a tag. A tag is still needed for tracking the palette, but there is no need to add the palette to the NPC palette table. This means you only need one tag for all surf sprites, since only one will exist at the same time.

3. Switching Pokemon mid-surf will not change the surf blob

4. Selecting a Pokemon from the pokemenu loads the correct graphics

5. The overlay frames are hidden underneath map tiles (eg. treetops over water)

### Special Sprite Handling

This repo also now supports unique West/Left-facing and East/Right-facing sprites!
In the case of Kingler, it has an asymmetric sprite, with one larger claw. Mirroring this sprite would have resulted in the claw switching sides when the player moves around; instead, we now support sprites that have a unique look for all 4 directions!

![Kingler](kingler.gif)

## Important Notes

1. This includes the dynamic overworld palette hack, as it removes the need to worry about matching palettes, and is generally just awesome. See https://github.com/Navenatox/DynamicOverworldPalettes for more details. The original source code has been modified to call some of these functions, so removing the file if you've already added this feature will not do. There is ample free-space in FR so I suggest just leaving it be unless you know what you are doing.

2. Any pokemon without art will default to the original surf blob. As art is added, either by the user or community, you can change this in src/surf_mons.h by changing the elements `.paletteTag` and `.images` of `const struct SpriteTemplate s[species]Overworld`

3. Fire Red likes vertical images, and as such the sprites have to have all their frames lined up vertically, as opposed to the pokeem images that are layered horizontally. While annoying, changing the frame ordering isn't a big deal, and I hope this won't stand in the way of community art being shared.


## TODOs:

1. Verify that each Pokemon has a matching Shiny sprite

2. Continue normalizing sprite order ([0-1] ..  [7-8]), rather than ([1-0] .. [8-7])

3. Fix template, old, and alt sprites, in accordance with #2

3. Test all sprites in-engine (see Tha Code Mining Hub's #surf-overworlds-expansion channel, and "Checking in-game" thread)

4. Apply fixes from #3.

---

# Credits:
## History Lesson
Here's a fun infographic, provided by AsparagusEduardo in the [Team Aqua Asset Repo](https://github.com/Pawkkie/Team-Aquas-Asset-Repo)'s [Discord server](https://discord.gg/hX3a63RYzZ):
![Chart showing the history of development for this project, starting with Slawter666's project for early pret/pokeemerald. This split into Ghoulslash's binary Fire Red version of the project, continued by Shiny-Miner, Ansh, and Jordank, and into surskitty's port to pokeemerald-expansion, which was continued by grunt-lucas and wally-217](history.png)

## Legacy Sprites
Various artists contributed edited sprites [Gen 1](https://www.spriters-resource.com/ds_dsi/pokemonheartgoldsoulsilver/sheet/26794/), [Gen 2](https://www.spriters-resource.com/fullview/26795/), and [Gen 3](https://www.spriters-resource.com/ds_dsi/pokemonheartgoldsoulsilver/sheet/26795/) from the Following Pokemon feature of Heart Gold and Soul Silver. Please let me know if you've contributed, and would like specific credit for specific Pokemon; This is rabbit hole to unravel, but here are the names we could verify:
- [Ghoulslash](https://github.com/ghoulslash/dynamic_surf_ows)
- [grunt-lucas](https://github.com/grunt-lucas/pokeemerald-expansion/tree/surfable/graphics/object_events/pics/pokemon/surfable)
- [Slawter666](https://github.com/Slawter666/pokeemerald/blob/surfable/graphics/event_objects/pics/pokemon/surfable/)
- [Surskitty](https://github.com/surskitty/pokeemerald/tree/surfable/graphics/object_events/pics/pokemon/surfable)
- [wally-217](https://github.com/zacwalton/pokeemerald-expansion/tree/master/graphics/object_events/pics/pokemon/surfable)

## Modern Sprites
Any sprites listed below this header are custom drawn, in the Shiny-Miner/Ansh/Jordank version of this project (the repo you're reading currently)

### [Avara](https://www.pokecommunity.com/threads/fire-red-dynamic-surf-overworlds.420665/)
- Wartortle, Tentacool, Tentacruel

### [eMMe97](https://www.pokecommunity.com/threads/fire-red-dynamic-surf-overworlds.420665/)
- Squirtle, Blastoise

### Hestia
- Wailmer

### Michelle Soto
- Dratini
- Carvanha
- Made the raft used by several smaller Pokemon

### [Nolo33LP](https://x.com/Nolo33LP)
- Pichu, Pikachu, Raichu
  - Additional editing by Jordank
- Clamperl, Huntail, Gorebyss
- Latias, Latios
- Rayquaza

### [EduarPokeN](https://x.com/EduarPokeN)
- Whiscash
- Corphish, Crawdaunt
- Improved the Raft used by several smaller Pokemon

### [Pokets](https://x.com/pokets3)
- Snorlax
  - Snoring, and 4-frame animation adjustment by [Jordank](https://github.com/jmynes/dynamic_surf_ows_masters-expansion)
- Sharpedo
- Wailord
- Barboach
- Feebas
- Relicanth
- Luvdisc
- Surskit, Masquerain
- Zangoose

### [Surskitty](https://github.com/surskitty)
- Kyogre
  - Primal Kyogre

## Edited HGSS Sprites (such as posture/redrawn parts)
### Surskitty
- Nidoking, Nidoqueen
- Kangaskhan
- Quagsire
- Swampert

# [wally-217](https://github.com/zacwalton/pokeemerald-expansion/tree/master/graphics/object_events/pics/pokemon/surfable)
- Lickitung

# Completed Pokemon
## Spriting Progress:
### Gen 1: 100%
- Squirtle - Complete (eMMe97)
- Wartortle - Complete (Avara)
- Blastoise - Complete (eMMe97)
- Pikachu - Complete ([Nolo33LP](https://x.com/Nolo33LP))
- Raichu - Complete ([Nolo33LP](https://x.com/Nolo33LP))
- Nidoqueen - Complete
- Nidoking  - Complete
- Psyduck - Complete (ghoulslash)
- Golduck - Complete (ghoulslash)
- Poliwag - Complete
- Poliwhirl  - Complete
- Poliwrath  - Complete
- Tentacool - Complete (Avara)
- Tentacruel - Complete (Avara)
- Slowpoke - Complete (ghoulslash)
- Slowbro - Complete (ghoulslash)
- Seel - Complete (ghoulslash)
- Dewgong - Complete (ghoulslash)
- Shellder - Complete
- Cloyster - Complete
- Krabby  - Complete
- Kingler - Complete (Ansh746)
- Lickitung - Complete
- Rhydon - Complete
- Kangaskhan - Complete
- Horsea  - Complete
- Seadra - Complete
- Goldeen - Complete
- Seaking - Complete
- Staryu - Complete (ghoulslash)
- Starmie - Complete (ghoulslash)
- Tauros - Complete
- Gyarados  - Complete
- Lapras - Complete (Slawter666)
- Vaporeon - Complete (ghoulslash)
- Omanyte - Complete
- Omastar - Complete
- Kabuto - Complete
- Kabutops - Complete
- Snorlax - Complete ([Pokets](https://x.com/pokets3)), with Snoring efforts from Jordank
- Dratini - Complete (michelle soto)
- Dragonair - Complete
- Dragonite - Complete
- Mew - Complete

### Gen 2: 100%
- Totodile - Complete
- Croconaw - Complete
- Feraligatr - Complete
- Sentret - Complete (gota_csm)
- Furret - Complete (gota_csm)
- Pichu - Complete ([Nolo33LP](https://x.com/Nolo33LP))
- Chinchou - Complete
- Lanturn - Complete
- Marill - Complete
- Azumarill - Complete
- Politoed - Complete
- Wooper - Complete
- Quagsire - Complete
- Slowking - Complete (ghoulslash)
- Qwilfish - Complete
- Sneasel - Complete
- Corsola - Complete
- Remoraid - Complete
- Octillery - Complete
- Mantine - Complete
- Kingdra - Complete
- Miltank - Complete
- Suicune - Complete
- Tyranitar - Complete
- Lugia - Complete (Surfing by Pokets, Flying HGSS edit by Jordank)

### Gen 3: 100%
- Mudkip - Complete
- Marshtomp - Complete
- Swampert - Complete
- Zigzagoon - Complete
- Linoone - Complete
- Lotad - Complete
- Lombre - Complete
- Ludicolo - Complete
- Pelipper - Complete
- Makuhita - Complete
- Hariyama - Complete
- Azurill - Complete
- Aggron - Complete
- Carvanha - [Complete?] Michelle Soto
- Sharpedo - Complete ([Pokets](https://x.com/pokets3))
- Wailmer - Complete (Hestia)
- Wailord - Complete ([Pokets](https://x.com/pokets3))
- Barboach - Complete ([Pokets](https://x.com/pokets3))
- Whiscash - Complete ([EduarPokeN](https://x.com/EduarPokeN))
- Corphish - Complete ([EduarPokeN](https://x.com/EduarPokeN))
- Crawdaunt - Complete ([EduarPokeN](https://x.com/EduarPokeN))
- Feebas - Complete ([Pokets](https://x.com/pokets3))
- Milotic - Complete
- Spheal - Complete (ghoulslash)
- Sealeo - Complete (ghoulslash)
- Walrein - Complete (ghoulslash)
- Clamperl - Complete ([Nolo33LP](https://x.com/Nolo33LP))
- Huntail - Complete ([Nolo33LP](https://x.com/Nolo33LP))
- Gorebyss - Complete ([Nolo33LP](https://x.com/Nolo33LP))
- Relicanth - Complete ([Pokets](https://x.com/pokets3))
- Luvdisc - Complete ([Pokets](https://x.com/pokets3))
- Latias - Complete ([Nolo33LP](https://x.com/Nolo33LP))
- Latios - Complete ([Nolo33LP](https://x.com/Nolo33LP))
- Kyogre - Complete (Surskitty)
- Rayquaza - Complete ([Nolo33LP](https://x.com/Nolo33LP))

## Tradebacks (Receives Surf in a later gen)
### Learns Surf in Gen 4: 100%
- Exploud - Complete

### Learns Surf in Gen 9: 100%
- Surskit - Complete ([Pokets](https://x.com/pokets3))
- Masquerain - Complete ([Pokets](https://x.com/pokets3))
- Zangoose - Complete ([Pokets](https://x.com/pokets3))

## Pokemon w/ Gen 4-9 Evolutions
### Gen 4: 0%
- Munchlax - Missing
- Mantyke - Missing
- Lickilicky - Missing
- Rhyperior - Missing
- Weavile - Missing

## Pokemon w/ Regional Variants and Evolutions
### Alola: 0%
- Alolan Raichu - Missing

### Galar: 0%
- Galarian Slowpoke - Missing
- Galarian Slowbro - Missing
- Galarian Slowking - Missing
- Galarian Corsola - Missing
- Cursola - Missing
- Galarian Zigzagoon - Missing
- Galarian Linoone - Missing
- Obstagoon - Missing

### Hisui: 0%
- Hisuian Qwilfish - Missing
- Overqwil - Missing

### Paldea: 0%
- Paldean Tauros (Combat Breed) - Missing
- Paldean Tauros (Aqua Breed) - Missing
- Paldean Wooper - Missing
- Clodsire - Missing

---

## How To Compile:

0. Ensure that you have Pokemon - Fire Red v1.0 (aka `1636 - Pokemon Fire Red (U)(Squirrels).gba`). If you're unsure, you can [verify](https://emn178.github.io/online-tools/md5_checksum.html) the md5sum of your ROM, which should match `e26ee0d44e809351c8ce2d73c7400cdd`

1. Rename your ROM to `rom.gba`, and add it to the root directory of this project

2. open `scripts/make.py` and modify `OFFSET_TO_PUT` to wherever you'd like to insert this code, as well as `SEARCH_FREE_SPACE` to `True` if you'd like to search for free space from said offset.

3a. download devkitPro. see this tutorial for more information: https://www.pokecommunity.com/showpost.php?p=8825585&postcount=96

3b. download python 3.7.2 (make sure `add to path` is checked), then type `python scripts/make.py` into the terminal to compile the code and images.

4. `test.gba` will be added to the folder, and the offsets will be located in `offsets.ini`

---

### Adding New Species:

If you want to add new species that can learn surf, follow these steps. I will use Popplio as an example
1. make the sprite, 32 x 384 (12 frames of 32x32). Use the existing sprites as models.

2a. add the indexed image .png file to graphics/. Eg. `popplio.png`

2b. modify the palette of said image for the sprite's shiny colors, then place this image in graphics/shiny, eg. `popplioShiny.png`. Only the palette will get inserted into the rom, so make sure it can be applied to the original image without messing up the appearance.

3. add the following to surf_mons.h
```
extern const u32 popplioTiles[];
extern const u16 popplioPal[];
extern const u16 popplioShinyPal[];

const struct SpriteFrameImage gSurfingOverworldPicTable_Popplio[] = {
    overworld_frame(&popplioTiles[0], 4, 4, 0),
    overworld_frame(&popplioTiles[0], 4, 4, 1),
    overworld_frame(&popplioTiles[0], 4, 4, 2),
    overworld_frame(&popplioTiles[0], 4, 4, 3),
    overworld_frame(&popplioTiles[0], 4, 4, 4),
    overworld_frame(&popplioTiles[0], 4, 4, 5),
};

const struct SpriteFrameImage gSurfingOverlayPicTable_Popplio[] = {
    overworld_frame(&popplioTiles[0], 4, 4, 6),
    overworld_frame(&popplioTiles[0], 4, 4, 7),
    overworld_frame(&popplioTiles[0], 4, 4, 8),
    overworld_frame(&popplioTiles[0], 4, 4, 9),
    overworld_frame(&popplioTiles[0], 4, 4, 10),
    overworld_frame(&popplioTiles[0], 4, 4, 11),
};

const struct SpriteTemplate sPopplioOverworld = surf_template(PAL_TAG_SURF_NEW, gSurfingOverworldPicTable_Popplio, UpdateSurfBlobFieldEffect);
const struct SpriteTemplate sPopplioOverlay = surf_template(PAL_TAG_SURF_NEW, gSurfingOverlayPicTable_Popplio, UpdateSurfMonOverlay);
```

4. If you do not have any overlay frames, the sprite sheet only needs to be 32x192 (6 frames), and do not need to define the `OverlayPicTable`. Also, if you want unique palette tags, `PAL_TAG_SURF_NEW` should be `PAL_TAG_POPPLIO_SURF` or whatever you want to call it, instead.

5. Finally, add the following to the `gSurfablePokemon` structure at the bottom of the page. Note that I changed the structures from the pokeemerald source so you shouldn't have to worry about matching indices, since there is one main structure that defines the surfable pokemon
```
{
  .species = SPECIES_POPPLIO,
  .palAddr = &popplioPal[0],
  .shinyPalAddr = &popplioShinyPal[0],	// or 0 if it doesn't exist
  .overworldGfx = &sPopplioOverworld,
  .overlayGfx = &sPopplioOverlay,	// or 0 if it doesn't exist
},
```
