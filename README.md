# cub3d
By @ElPatatin & @LAG-jara

## Description

cub3d is a simple 3D game engine project that uses the Raycasting technique. It is inspired by the classic game Wolfenstein 3D. The project is part of the 42 Network curriculum.

## Features

- Raycasting for rendering a 3D perspective
- Textured walls and sprites
- Basic movement controls (forward, backward, strafe left, strafe right)
- Basic mouse camera rotation (must mantain the mouse button 1 pressed)
- Collision detection with walls
- Support for reading map configurations from a file
- Basic error handling and reporting

## Prerequisites

- Requirements for MacOs
	- clang
	- make
	- This native version no longer uses X.org, XQuartez or X11 but uses **Mac OSX's Cocoa (AppKit)** and modern **OpenGL** features.

- Requirements for Linux
    - MinilibX only support TrueColor visual type (8,15,16,24 or 32 bits depth)
    - gcc
    - make
    - X11 include files (package xorg)
    - XShm extension must be present (package libxext-dev)
    - Utility functions from BSD systems - development files (package libbsd-dev)
    - e.g. sudo apt-get install gcc make xorg libxext-dev libbsd-dev (Debian/Ubuntu)


## Installation

1. Clone the repository:

	```bash
	git clone https://github.com/your-username/cub3d.git
	```
2. Build the project:

	```bash
	make
	```

## Usage

1. Run the cub3d executable:
	```bash
	./cub3d path/to/map.cub
	```
Replace path/to/map.cub with the path to your map configuration file.

2. Enjoy playing around with the simple 3D engine!

## Map Configuration

cub3d uses a simple map configuration file with specific parameters. Refer to the provided basic.cub file for an example.

## Controls

- W: Move forward
- S: Move backward
- A: Strafe left
- D: Strafe right
- ←: Look left
- →: Look right
- ESC: Exit the game
- Mouse:
	- ←: Look left
	- →: Look right

## Screenshots
![Dungeon.cub](https://github.com/ElPatatin/cub3d/blob/main/screenshots/1.png)
![basic1.cub](https://github.com/ElPatatin/cub3d/blob/main/screenshots/2.png)
![basic2.cub](https://github.com/ElPatatin/cub3d/blob/main/screenshots/3.png)

## Known Issues

NONE 😇

## License

This project is licensed under the MIT License.
