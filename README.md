# Bingo

|Project|Linux|Windows|MacOS|
|-------|-----|-------|-----|
| Core | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/CoreLinux/badge.svg)](https://github.com/yatima1460/Bingo/actions) | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/CoreWindows/badge.svg)](https://github.com/yatima1460/Bingo/actions) | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/CoreMacOS/badge.svg)](https://github.com/yatima1460/Bingo/actions)|
| Core Test | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/TestLinux/badge.svg)](https://github.com/yatima1460/Bingo/actions) |[![Actions Status](https://github.com/yatima1460/Bingo/workflows/TestWindows/badge.svg)](https://github.com/yatima1460/Bingo/actions) | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/TestMacOS/badge.svg)](https://github.com/yatima1460/Bingo/actions)|
| CLI | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/CLILinux/badge.svg)](https://github.com/yatima1460/Bingo/actions) | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/CLIWindows/badge.svg)](https://github.com/yatima1460/Bingo/actions) | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/CLIMacOS/badge.svg)](https://github.com/yatima1460/Bingo/actions) |
| UI | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/UILinux/badge.svg)](https://github.com/yatima1460/Bingo/actions) |[![Actions Status](https://github.com/yatima1460/Bingo/workflows/UIWindows/badge.svg)](https://github.com/yatima1460/Bingo/actions) | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/UIMacOS/badge.svg)](https://github.com/yatima1460/Bingo/actions) |

## CLI

![](screenshot_cli.png)

- ~Dynamic Bingo settings~
  - ~Prize patterns add~
  - ~Prize patterns delete~
  - ~Number of balls~
  - ~Number of cards~
  - ~Card size~
- Game Statistics
  - Percentage Game
  - Pattern frequency
  - Contribution patterns
- ~Insert credits~
- ~Change numbers~
- ~Show current cards~
- ~Play One Game~
  - ~Show ExtractedBalls balls~
  - ~Show cards status~
  - ~Show prizes~
  - ~Remaining credits~
- ~Play X Games~
- ~collect~
- ~Exit game~
- Functions to print cards should be merged into one
- ncurses?

## UI

![](screenshot_ui.png)

- ~Background~
- ~balls ExtractedBalls~
- ~Cartons~
  - ~Marked~
- Buttons
  - ~Enter money~
  - ~collect money~
    - ~Disable if no money~
  - ~Change Cardboard numbers~
  - ~Play Game~
    - ~Remove credits for cards~
    - ~Update screen~
    - ~Give prizes~
    - ~Disable if no money for cards~
  - Mute audio
- ~Current credits~
- ~Exit with ESC~
- SDL_Image support for .png?
- Resize window buffer using renderToTexture
- ~Disabled button~
- Font size
- Sounds and effects
- ~Assets loader with associative string->Texture map?~
- balls different colors

## Build

### Prerequisites

#### Core and CLI

- CMake
- g++

#### UI


##### Debian
```
sudo apt install -y libsdl2-dev libsdl2-ttf-dev
```

If you have errors about not finding SDL_ttf.h try:

```
sudo ln -s /usr/include/SDL2/SDL_ttf.h /usr/local/include/SDL2/
```

##### Arch
```
sudo pacman -S sdl2 sdl2_ttf
```
