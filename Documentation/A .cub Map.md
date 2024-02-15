The extension .cub is a light and fast format, which content is in plain text, consisting of a basic **header** at the top, and it's **body** below.

The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.

# Header - Metadata of the file
At minimum, there are 6 elements. Each element firsts information is the type identifier (composed by one or two character(s)), followed by all specific information for each object **in a strict order** such as :
- **North** texture:
	``NO ./path_to_the_north_texture``
	- Identifier: NO
	- Path to the north texture
* **South** texture:
	``SO ./path_to_the_south_texture``
	- Identifier: SO
	- Path to the south texture
 - **West** texture:
	``WE ./path_to_the_west_texture``
	- Identifier: WE
	- Path to the west texture
- **East** texture:
	``EA ./path_to_the_east_texture``
	- Identifier: EA
	- Path to the east texture
 - **Floor** color:
	``F 220,100,0``
	- Identifier: F
	- R,G,B colors in range 0 to 255: 0, 255, 255
- **Ceiling** color:
	``C 225,30,0``
	- Identifier: C
	- R,G,B colors in range 0 to 255: 0, 255, 255

# Body - Map to be render

 - The map must be composed of only 6 possible characters: 
	 - 0 for an empty space.
	- 1 for a wall.
	- N, S, E or W for the player’s start position and spawning orientation.
	
 - The map must be closed/surrounded by walls, if not the program must return an error.
 - Except for the map content, each type of element can be separated by one or more empty line(s).
- Except for the map content which always has to be the last, each type of element can be set in any order in the file.
 - Except for the map, each type of information from an element can be separated by one or more space(s).

## A valid .cub file
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

In a valid .cub file, or map, it will have its metadata at the top, and consider the contents of a map as its body.

## An invalid .cub map

```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
SO ./path_to_the_south_texture
EA ./path_to_the_east_texture

P 220,100,0
C 225,30,0

Asassas3920

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
1100000111010101111101111000111
11110111 1110101 101111010001
11111111 1111111 111111111111

1111
1001
1111

SO ./path_to_the_south_texture
```

This map have the following errors:
- The **metadata:**
	- A texture is missing.
	- A texture is repeated.
	- A color is missing.
	- Trash have been found at the header

- At the **body:**
	- Trash have been found at the body.
	- There are multiple maps.
	- There is no player, the simulation cannot start.
		- Also, it can be multiple players stating point, so that is also to care about.
	- A texture is at the body.