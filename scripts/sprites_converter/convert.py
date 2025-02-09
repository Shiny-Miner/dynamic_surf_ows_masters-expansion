import os 
from PIL import Image

class SpriteSheet:
    def __init__(self, path:str, Format:list, frame_size:int):
        img = Image.open(path).convert("P")
        self.image = img
        self.frame_size = frame_size
        self.Format = Format
        self.width, self.height = img.size
        self.frames = self.getFrames()
    
    def convert(self, newFormat:list):
        newImage = Image.new(mode = "P", size = (len(newFormat[0])*self.frame_size, len(newFormat)*self.frame_size))
        newImage.putpalette(self.image.getpalette())
        row_size = len(newFormat)
        column_size = len(newFormat[0])
        for row in range(row_size):
            for column in range(column_size):
                left = self.frame_size*column
                upper = self.frame_size*row
                right = left + self.frame_size
                lower = upper + self.frame_size
                newImage.paste(self.frames[newFormat[row][column]], (left, upper, right, lower))
                
        self.image = newImage
    def getFrames(self) -> dict:
        frames = dict()
        row_size = len(self.Format)
        column_size = len(self.Format[0])
        for row in range(row_size):
            for column in range(column_size):
                left = self.frame_size*column
                upper = self.frame_size*row
                right = left + self.frame_size
                lower = upper + self.frame_size
                frames[self.Format[row][column]] = self.image.crop((left, upper, right, lower))
        return frames

color__ = lambda rgb: f"\033[38;2;{rgb[0]};{rgb[1]};{rgb[2]}m"
__color = "\033[39m"

bgcolor__ =lambda rgb: f"\033[48;2;{rgb[0]};{rgb[1]};{rgb[2]}m"
__bgcolor = "\033[49m"

underline__ = "\033[4m"
__underline = "\033[24m"


bold__ = "\033[1m"
__bold = "\033[22m"

italic__ = "\033[3m"
__italic = "\033[23m"

default = "\033[0m"

# Default conversion layout (vertical inversion of each pair of frames)
invertVerticalLayout = {
    "R12_C1": [
        [1],
        [0],
        [3],
        [2],
        [5],
        [4],
        [7],
        [6],
        [9],
        [8],
        [11],
        [10]
    ],
    "R6_C6": [
        [0],
        [1],
        [2],
        [3],
        [4],
        [5],
        [6],
        [7],
        [8],
        [9],
        [10],
        [11]
    ]
}

# --- Additional preset conversion layouts ---
# Vertical to Horizontal
v2hLayout = {
    "R12_C1": [
        [0],
        [1],
        [2],
        [3],
        [4],
        [5],
        [6],
        [7],
        [8],
        [9],
        [10],
        [11]
    ],
    "R6_C6": [
        [0, 1, 2, 3, 4, 5],
        [6, 7, 8, 9, 10, 11]
    ]
}

# Horizontal to Vertical
h2vLayout = {
    "R12_C1": [
        [0, 1, 2, 3, 4, 5],
        [6, 7, 8, 9, 10, 11]
    ],
    "R6_C6": [
        [0],
        [1],
        [2],
        [3],
        [4],
        [5],
        [6],
        [7],
        [8],
        [9],
        [10],
        [11]
    ]
}

def main():
    # --- Minimal CLI handling ---
    conversion_mode = None
    if len(os.sys.argv) <= 1:
        print("Choose conversion type:")
        print("1. Invert Frames [Vertical]")
        print("2. Convert Vertical to Horizontal layout")
        print("3. Convret Horizontal to Vertical layout")
        choice = input("Enter option (1, 2, or 3): ").strip()
        if choice == "2":
            conversion_mode = "v2h"
        elif choice == "3":
            conversion_mode = "h2v"
        else:
            conversion_mode = "invert"
    # --- End CLI handling ---
    
    # Ensure the top-level exported_sprites directory exists.
    export_dir = os.path.abspath("convert_sprites").replace("convert_sprites", "exported_sprites")
    if not os.path.exists(export_dir):
        os.mkdir(export_dir)
    
    for path, dirs, files in os.walk(os.path.abspath("convert_sprites")):
        flagfile = open(os.path.join(path, "flags.txt"))
        frame_size, Format, newFormat = flagfile.readline().strip().split()
        for dir in dirs:
            out_dir = os.path.join(path, dir).replace("convert_sprites", "exported_sprites")
            if os.path.isdir(out_dir):
                continue
            os.mkdir(out_dir)
        for file in files:
            if file=="flags.txt":
                continue
            spritesheet = SpriteSheet(os.path.join(path, file), invertVerticalLayout[Format], int(frame_size))
            # If the user selected a CLI conversion option, override the invertVertical layout.
            if conversion_mode == "v2h":
                mapping = v2hLayout[Format]
            elif conversion_mode == "h2v":
                mapping = h2vLayout[Format]
            elif conversion_mode == "invert":
                mapping = invertVerticalLayout[newFormat]
            else:
                mapping = invertVerticalLayout[newFormat]
            spritesheet.convert(mapping)
            print(bold__ + f"{color__((23,23,234))}Converting{__color}", file + __bold +"...", end = "")
            spritesheet.image.save(os.path.join(path, file).replace("convert_sprites", "exported_sprites"))
            print("done")
if __name__ == "__main__":
    main()
