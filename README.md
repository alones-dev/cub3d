# cub3D
cub3D is a graphics project that aims to understand and use raycasting to recreate a Wolfenstein3D like in C.

It's a group project that was carried out by two people: I did the parsing part of the game parameters file (valid map, valid information, ...) and my mate did the raycasting part.

This project use the MiniLibX, the graphical library of 42School.

## Usage
**1. Clone the repository**
```
git clone https://github.com/alones-dev/cub3d.git
```
**2. Clone the MiniLibX in the repository & rename it**
```
git clone https://github.com/42Paris/minilibx-linux.git
mv minilibx-linux mlx
```
**3. Compile the project**
```
make
```
**4. Enjoy**
```c
./cub3d maps/big.cub
```

