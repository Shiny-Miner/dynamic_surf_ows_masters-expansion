# SpriteSheet Converter

This Python script converts spritesheets by rearranging frames according to a selected conversion strategy and frame size. It supports multiple conversion layouts, such as inverting frames vertically, converting a vertical spritesheet to a horizontal layout, and vice versa. The tool can be run in both interactive mode and via command-line arguments.

## Features

- **Interactive Mode:**  
  Displays a menu that allows you to choose the conversion strategy and toggle between 32×32px and 64×64px frames.
  
- **Command-Line Arguments:**  
  Run the script non-interactively by specifying the conversion strategy and frame size in any order.  
  For example:
  - `python3 convert.py invert 64`
  - `python3 convert.py 64 h2v`
  - `python3 convert.py v2h`

- **Multiple Conversion Layouts:**  
  - **Invert Frames [Vertical]:** Inverts pairs of frames vertically.
  - **Vertical to Horizontal Layout:** Converts a vertically arranged spritesheet into a horizontal layout.
  - **Horizontal to Vertical Layout:** Converts a horizontally arranged spritesheet into a vertical layout.

- **ANSI Color Output:**  
  Uses ANSI escape codes for colored and formatted console output during conversion.

- **Recursive Directory Handling:**  
  Processes all spritesheet files within the `convert_sprites` directory (including subdirectories) and outputs converted spritesheets into an `exported_sprites` directory.

## Prerequisites

- **Python 3.x**

- **Pillow:**  
  The Python Imaging Library fork is required for image manipulation. Install it via pip:

  ```bash
  pip install pillow
