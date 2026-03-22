# Flappy Bird Game

This is a classic Flappy Bird game implemented in Python using the Pygame library.

## Features

- **Classic Gameplay**: Tap to flap the bird and navigate through pipes.
- **Scoring System**: Earn points for each pipe passed.
- **Game States**: Start screen, playing mode, and game over screen.
- **Responsive Design**: Adapts to different screen sizes.

## Tech Stack

<div align="center">
  <img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white" alt="Python" />
  <img src="https://img.shields.io/badge/Pygame-F2E67C?style=for-the-badge&logo=pygame&logoColor=black" alt="Pygame" />
  <img src="https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white" alt="Git" />
</div>

## Prerequisites

- Python 3.x
- Pygame library (`pip install pygame`)

## Installation

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd -CSLT---Project-Flappy-Bird-Game
   ```

2. Install dependencies:
   ```bash
   pip install pygame
   ```

## Usage

Run the game from the terminal:

```bash
python main.py
```

## Controls

- **Spacebar** or **Up Arrow**: Flap the bird
- **Escape**: Exit the game

## Project Structure

```
-CSLT---Project-Flappy-Bird-Game/
├── main.py             # Main game entry point
├── bird.py             # Bird class and animations
├── pipe.py             # Pipe generation and movement
├── settings.py         # Game settings and constants
├── assets/             # Game assets (images, sounds)
│   ├── bird.png        # Bird sprite
│   ├── pipe.png        # Pipe sprite
│   ├── background.png  # Background image
│   ├── score.wav       # Score sound
│   └── die.wav         # Death sound
└── README.md           # Project documentation
```

## Assets

The game uses the following assets (located in the `assets/` directory):

- `bird.png`: Bird sprite
- `pipe.png`: Pipe sprite
- `background.png`: Background image
- `score.wav`: Sound effect for scoring
- `die.wav`: Sound effect for death

## License

This project is licensed under the terms of the MIT license.