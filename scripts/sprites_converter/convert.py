import os 
from PIL import Image

# Flags settings (formerly in flags.txt: "32 before after")
FRAME_SIZE = 32
ORIGINAL_FORMAT = "before"
TARGET_FORMAT = "after"

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

bgcolor__ = lambda rgb: f"\033[48;2;{rgb[0]};{rgb[1]};{rgb[2]}m"
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
    "before": [
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
    "after": [
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
    "before": [
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
    "after": [
        [0, 1, 2, 3, 4, 5],
        [6, 7, 8, 9, 10, 11]
    ]
}

# Horizontal to Vertical
h2vLayout = {
    "before": [
        [0, 1, 2, 3, 4, 5],
        [6, 7, 8, 9, 10, 11]
    ],
    "after": [
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

def display_main_menu(frame_size: int) -> None:
    """Prints the main conversion menu."""
    print(f"Choose conversion method [{frame_size}x{frame_size}px frames]:")
    print("1. Invert Frames [Vertical]")
    print("2. Convert Vertical to Horizontal layout")
    print("3. Convert Horizontal to Vertical layout")
    if frame_size == 32:
        print("4. Switch to 64x64px frames")
    else:
        print("4. Switch to 32x32px frames")
    print("\nEnter option, 'h' for help, or 'q' to exit:", end=" ")

def display_help_menu() -> None:
    """Prints the help menu to choose a conversion schema."""
    print("Which conversion type would you like to see the schema of?")
    print("1. Invert Frames [Vertical]")
    print("2. Vertical to Horizontal layout")
    print("3. Horizontal to Vertical layout")
    print("\nEnter option:", end=" ")

def display_schema(title: str, layout: dict) -> None:
    """Prints out the conversion schema given a title and layout mapping."""
    print(f"\nHere's how the {title} schema works:")
    keys = list(layout.keys())
    print("\nBefore:")
    for row in layout[keys[0]]:
        print(row, end=",\n")
    print("\nAfter:")
    for row in layout[keys[1]]:
        print(row, end=",\n")
    print()

def handle_help() -> None:
    """Handles help requests by displaying the appropriate schema."""
    display_help_menu()
    help_choice = input().strip()
    print()
    if help_choice == "1":
        display_schema("Invert Frames [Vertical]", invertVerticalLayout)
    elif help_choice == "2":
        display_schema("Vertical to Horizontal layout", v2hLayout)
    elif help_choice == "3":
        display_schema("Horizontal to Vertical layout", h2vLayout)
    else:
        print("Invalid help option.\n")

def main():
    # --- Minimal CLI handling ---
    current_frame_size = FRAME_SIZE
    conversion_mode = None
    if len(os.sys.argv) <= 1:
        while True:
            display_main_menu(current_frame_size)
            choice = input().strip()
            print()
            if choice.lower() == "q":
                exit(0)
            if choice.lower() == "h":
                handle_help()
                continue
            elif choice == "4":
                current_frame_size = 64 if current_frame_size == 32 else 32
                continue
            elif choice in ["1", "2", "3"]:
                break
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
        frame_size, Format, newFormat = current_frame_size, ORIGINAL_FORMAT, TARGET_FORMAT
        for dir in dirs:
            out_dir = os.path.join(path, dir).replace("convert_sprites", "exported_sprites")
            if not os.path.isdir(out_dir):
                os.mkdir(out_dir)
        for file in files:
            spritesheet = SpriteSheet(os.path.join(path, file), invertVerticalLayout[Format], int(frame_size))
            if conversion_mode == "v2h":
                mapping = v2hLayout[Format]
            elif conversion_mode == "h2v":
                mapping = h2vLayout[Format]
            elif conversion_mode == "invert":
                mapping = invertVerticalLayout[newFormat]
            else:
                mapping = invertVerticalLayout[newFormat]
            spritesheet.convert(mapping)
            print(bold__ + f"{color__((23,23,234))}Converting{__color}", file + __bold + "...", end=" ")
            spritesheet.image.save(os.path.join(path, file).replace("convert_sprites", "exported_sprites"))
            print("done")
            
if __name__ == "__main__":
    main()
