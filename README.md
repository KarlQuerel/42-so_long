<a id="top"></a>

# so_long
`so_long` is a project that involves creating a simple 2D game using the [MiniLibX library](https://github.com/42Paris/minilibx-linux). The objective of the game is for the player to navigate through a map, collect all items, and reach the exit.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)

## Introduction
The `so_long` project aims to introduce students to:
- Basic game development concepts
- Handling graphical interfaces with the MiniLibX library
- Managing game states and user inputs
- Working with 2D arrays and map design
- Handling memory leaks in case of an abrupt event

## Features
- 2D game map loaded from a file
- Player movement (up, down, left, right) using arrows or WASD
- Collectibles that the player must gather
- An exit that the player can access after collecting all items
- Collectibles and movements tracker
- Exit button (ESC)

## Requirements
- A Unix-based system (Linux or macOS)
- MiniLibX library
- `gcc` compiler

## Installation
1. Clone this repository to your local machine:
	```sh
	git clone https://github.com/KarlQuerel/42-so_long.git
	```

2. Navigate to the project directory:
	```sh
	cd 42-so_long
	```

3. Compile the project using `make`:
	```sh
	make
	```
 
## Usage
To run the game, use the following command:
```bash
./so_long maps/working_map.ber
```

## Controls
- **Arrows and/or WASD**: player movement
- **ESC**: Exit the game

For more information, refer to the [subject PDF](https://github.com/KarlQuerel/42-so_long/blob/master/docs/en.subject.pdf).

[Back to Top](#top)
