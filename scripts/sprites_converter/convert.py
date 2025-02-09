import os
from PIL import Image

# Flags settings (formerly in flags.txt: "32 before after")
FRAME_SIZE = 32
ORIGINAL_FORMAT = "before"
TARGET_FORMAT = "after"

class SpriteSheet:
    def __init__(self, path: str, Format: list, frame_size: int):
        img = Image.open(path).convert("P")
        self.image = img
        self.frame_size = frame_size
        self.Format = Format
        self.width, self.height = img.size
        self.frames = self.getFrames()
    
    def convert(self, newFormat: list):
        newImage = Image.new(
            mode="P",
            size=(len(newFormat[0]) * self.frame_size, len(newFormat) * self.frame_size)
        )
        newImage.putpalette(self.image.getpalette())
        row_size = len(newFormat)
        column_size = len(newFormat[0])
        for row in range(row_size):
            for column in range(column_size):
                left = self.frame_size * column
                upper = self.frame_size * row
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
                left = self.frame_size * column
                upper = self.frame_size * row
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

# Layout definitions with metadata
invertVerticalLayout = {
    "label": "Invert Vertical Frames",
    "help_text": "This strategy inverts each pair of frames in a vertical spritesheet.",
    "arg": "invert",
    "strategy": {
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
}

v2hLayout = {
    "label": "Vertical to Horizontal",
    "help_text": "This strategy converts a vertically arranged spritesheet into a horizontal layout.",
    "arg": "v2h",
    "strategy": {
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
}

h2vLayout = {
    "label": "Horizontal to Vertical",
    "help_text": "This strategy converts a horizontally arranged spritesheet into a vertical layout.",
    "arg": "h2v",
    "strategy": {
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
}

# List of all layouts
layouts = [invertVerticalLayout, v2hLayout, h2vLayout]

def display_main_menu(frame_size: int) -> None:
    """Prints the main conversion menu with layout descriptions."""
    print(f"Choose conversion method [{frame_size}x{frame_size}px frames]:")
    for i, layout in enumerate(layouts, start=1):
        print(f"{i}. {layout['label']} [{layout['arg']}]")
    # The last menu option toggles the frame size.
    toggle_option = len(layouts) + 1
    if frame_size == 32:
        print(f"{toggle_option}. Switch to 64x64px frames")
    else:
        print(f"{toggle_option}. Switch to 32x32px frames")
    print("\nEnter option, 'h' for help, or 'q' to exit:", end=" ")

def display_help_menu() -> None:
    """Prints the help menu to choose a conversion schema."""
    print("Which conversion type would you like to see the schema of?")
    for i, layout in enumerate(layouts, start=1):
        print(f"{i}. {layout['label']}")
    print("\nEnter option:", end=" ")

def display_schema(layout: dict) -> None:
    """Prints out the conversion schema for a given layout."""
    print(f"\n{layout['label']}:")
    print(layout['help_text'])
    print("\nBefore:")
    for row in layout["strategy"]["before"]:
        print(row, end=",\n")
    print("\nAfter:")
    for row in layout["strategy"]["after"]:
        print(row, end=",\n")
    print()

def handle_help() -> None:
    """Handles help requests by displaying the appropriate schema."""
    display_help_menu()
    help_choice = input().strip()
    print("\n############################################")
    try:
        index = int(help_choice) - 1
        if 0 <= index < len(layouts):
            display_schema(layouts[index])
            print("############################################\n")
        else:
            print("Invalid help option.\n")
    except ValueError:
        print("Invalid help option.\n")

def main():
    # --- Command-line Argument Handling ---
    # If arguments are provided, they can include the conversion strategy
    # ("invert", "v2h", or "h2v") and/or a frame size (an integer).
    # They can be provided in any order.
    args = os.sys.argv[1:]
    conversion_mode = None
    current_frame_size = FRAME_SIZE  # Default frame size: 32

    if args:
        for arg in args:
            arg_lower = arg.lower()
            if arg_lower in [layout["arg"] for layout in layouts]:
                conversion_mode = arg_lower
            else:
                try:
                    current_frame_size = int(arg)
                except ValueError:
                    pass  # Ignore any argument that isn't a known strategy or an integer
        if conversion_mode is None:
            conversion_mode = invertVerticalLayout["arg"]
    else:
        # --- Interactive Mode ---
        while True:
            display_main_menu(current_frame_size)
            choice = input().strip()
            print()
            if choice.lower() == "q":
                exit(0)
            if choice.lower() == "h":
                handle_help()
                continue
            try:
                choice_num = int(choice)
            except ValueError:
                continue
            # If user selects the last option for switching frame size:
            if choice_num == len(layouts) + 1:
                current_frame_size = 64 if current_frame_size == 32 else 32
                continue
            # If a valid layout option is chosen:
            if 1 <= choice_num <= len(layouts):
                conversion_mode = layouts[choice_num - 1]["arg"]
                break
        # End interactive mode
    # --- End CLI handling ---

    # Choose the layout based on conversion_mode
    chosen_layout = None
    for layout in layouts:
        if layout["arg"] == conversion_mode:
            chosen_layout = layout
            break
    if chosen_layout is None:
        chosen_layout = invertVerticalLayout

    # Ensure the top-level exported_sprites directory exists.
    export_dir = os.path.abspath("convert_sprites").replace("convert_sprites", "exported_sprites")
    if not os.path.exists(export_dir):
        os.mkdir(export_dir)
    
    for path, dirs, files in os.walk(os.path.abspath("convert_sprites")):
        # Create directories in exported_sprites as needed
        for dir in dirs:
            out_dir = os.path.join(path, dir).replace("convert_sprites", "exported_sprites")
            if not os.path.isdir(out_dir):
                os.mkdir(out_dir)
        for file in files:
            # Use the 'before' mapping for reading and the 'after' mapping for conversion.
            sheet_before = chosen_layout["strategy"][ORIGINAL_FORMAT]
            sheet_after = chosen_layout["strategy"][TARGET_FORMAT]
            spritesheet = SpriteSheet(os.path.join(path, file), sheet_before, int(current_frame_size))
            spritesheet.convert(sheet_after)
            print(bold__ + f"{color__((23,23,234))}Converting{__color}", file + __bold + "...", end=" ")
            spritesheet.image.save(os.path.join(path, file).replace("convert_sprites", "exported_sprites"))
            print("done")
            
if __name__ == "__main__":
    main()
