# Cub3D

=> Project made in collaboration with [@TonUpMan](https://github.com/TonUpMan)

## Project Overview
Cub3D is a project developed as part of the 42 curriculum, inspired by the classic Wolfenstein 3D game. The goal is to create a simple 3D game using raycasting to render the environment. This project teaches fundamental concepts of graphics programming, game development, and low-level C programming using the MacroLibX library.

## Features
- Raycasting engine for 3D rendering
- Basic movement and collision detection
- Map parsing from `.cub` files
- Wall and floor/ceiling textures
- Dynamic minimap and FPS counter
- Multiple weapons (knife and pistol)

## Installation

Download the graphical library, for this project i used [MacroLibX](https://macrolibx.kbz8.me./) :
```bash
make macro
```

Clone the repository and compile the project by running the following commands:
```bash
git clone https://github.com/your-repo/cub3D.git
cd cub3D
make
```

For the bonus version, which includes additional features like mouse control, minimap and extra weapons, compile with:
```bash
make bonus
```

## Usage

Run the game by executing the binary with a map file as an argument:
```bash
./cub3D maps/map.cub or ./cub3D_bonus maps/map.cub
```

Maps are stored in .cub files and must adhere to a specific format, defining the layout of the walls, the starting position of the player, and textures for different surfaces.


## Project Structure

- images/    : Directory containing image assets
- includes/  : Header files for the project
- lib/       : Custom library files
- MacroLibX/ : Graphical library for handling graphics and events
- Makefile   : Makefile for building the project
- maps/      : Directory containing map files (.cub)
- sounds/    : Directory containing sound assets
- src/       : Source files for the base version of the game
- src_bonus/ : Source files for the bonus version of the game

## Libraries

The project relies on the following libraries:

    - MacroLibX : For handling graphics and events.
    - libft: Custom C standard library implementation used throughout the project.

## License

This project is licensed under the [MIT License](LICENSE)

And adheres to the NORM V3 coding standards as specified by 42 School. I know i know...
