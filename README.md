# FdF - Wireframe 3D Map Renderer

## 🖥️ Overview

FdF (Fil de Fer) is a wireframe visualizer and an early 42 School project that involves creating a wireframe renderer using MiniLibX. The project explore fundamental graphics programming, including projection, transformations and line drawing algorithms. The program takes a 3D map representation from a file and projects it in a isometric view using the Bresenham's line algorithm.

## 🎯 Features

✅ Renders 3D maps from 2D heightmaps  
✅ Isometric and parallel projections  
✅ Allows zooming, rotation, and translation  
✅ Color support for enhanced visuals  
✅ Mouse-controlled zooming

## 🛠️ Installation

### 📥 Requirements

- macOS or Linux
- **Make** and **gcc**
- xorg
- libxext-dev
- libbsd-dev

### 📦 Build Instructions

1. Clone the repository:
   ```sh
   git clone https://github.com/hetya/fdf.git
   cd fdf
   ```
2. Compile the program:
   ```sh
   make
   ```

## 🚀 Usage
``` sh
./fdf maps/42.fdf
```
### 🕹️ Controls

| Key          | Action       |
| ------------ | ------------ |
| `W/A/S/D`    | Move the map |
| `Arrow Keys` | Move the map |
| `+/-`        | Zoom in/out  |
| `R`          | Rotate       |
| `C`          | Colors       |
| `ESC`        | Exit program |

You can also use the mouse to zoom in or out for more interactive control.

## Example

| ![image1](https://github.com/user-attachments/assets/c0165f3d-a39e-499a-a0bd-b4af06124ed8) | ![image2](https://github.com/user-attachments/assets/9994d8dc-eaf5-46eb-bfb1-6adf83491a41) |
| ----------------------------------- | ----------------------------------- |
| <p align="center"><strong>Basic Map</p> | <p align="center"><strong>Map with default colors</p> |
| ![image3](https://github.com/user-attachments/assets/1da6ed8d-a485-4a71-886b-32c7147ad3c0) |![image4](https://github.com/user-attachments/assets/e4cb51aa-aefe-4851-a4c8-0e98db06b19d) |
| <p align="center"><strong>Changing Colors</p> | <p align="center"><strong>Big map</p> |

## 📜 File Format (`.fdf`)

Each `.fdf` file represents a 3D map using space-separated integers, where:

- Each number represents a height (altitude)
- Columns and rows define the grid size

Example (`map.fdf`):

```
0  1  2  3  4
0  2  4  6  8
1  3  5  7  9
```

## 📌 Notes
- Some maps may have colors by default.
- Larger maps may take several seconds to appear due to their size.
- You can use the Makefile for further optimizations or customizations.
FdF was developed using the 42 coding standards.


