*This project has been created as part of the 42 curriculum by ervsahin, bkinali.*

# cub3D

## Description

cub3D is a raycasting engine inspired by Wolfenstein 3D, the first FPS ever created.
The goal of the project is to create a "realistic" 3D graphical representation of the
inside of a maze from a first-person perspective, using the ray-casting technique and
the MiniLibX library.

The program takes a scene description file (`.cub`) as its only argument. The file
contains the four wall textures (one per cardinal direction), the floor and ceiling
colors, and the map itself. The map is built from `0` (empty space), `1` (wall) and
one player spawn (`N`, `S`, `E` or `W`). The map must be closed/surrounded by walls,
otherwise the program exits with an explicit error message.

Features:

- Wall textures that vary depending on the side the wall is facing (N/S/E/W)
- Independently configurable floor and ceiling colors
- Movement with `W`, `A`, `S`, `D` and camera rotation with the left/right arrow keys
- Clean exit with `ESC` or by clicking the red cross of the window
- Robust parser: invalid configuration, invalid characters, open maps, multiple
  players, duplicated identifiers, out-of-range colors, etc. all produce
  `Error: <message>` and a clean exit
- Bonus: wall collisions (the player cannot walk through walls)

## Instructions

### Requirements

- Linux (or macOS) with X11
- `gcc`/`cc`, `make`
- MiniLibX: clone the official [minilibx-linux](https://github.com/42Paris/minilibx-linux)
  repository into the `minilibx/` directory (it is git-ignored):

```sh
git clone https://github.com/42Paris/minilibx-linux.git minilibx
```

### Compilation

```sh
make            # builds ./cub3D
make clean      # removes object files
make fclean     # removes objects and the binary
make re         # fclean + all
make norm       # runs norminette on all project files
```

### Usage

```sh
./cub3D maps/valid/basic.cub
```

Controls:

| Key            | Action           |
| -------------- | ---------------- |
| `W` / `S`      | move forward/backward |
| `A` / `D`      | strafe left/right |
| `←` / `→`      | rotate the camera |
| `ESC`          | quit the game    |

### Maps

Example scene file structure:

```
NO ./textures/wall.xpm
SO ./textures/greenwall.xpm
WE ./textures/fire.xpm
EA ./textures/greenwall2.xpm

F 220,100,0
C 225,30,0

111111
100001
10N001
100001
111111
```

Valid maps live in `maps/valid/`, invalid ones (each triggering a specific error) in
`maps/invalid/`.

## Resources

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — the classic
  reference for the DDA-based raycasting algorithm
- [Wolfenstein 3D (playable)](http://users.atw.hu/wolf3d/) — the original game
- [MiniLibX docs](https://harm-smits.github.io/42docs/libs/minilibx) — MiniLibX reference
- 42 cub3D subject
