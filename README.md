# Bingo

|Project|Build|
|-------|-----|
| Core | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/Core/badge.svg)](https://github.com/yatima1460/Bingo/actions) |
| Core Test | TODO |
| CLI | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/CLI/badge.svg)](https://github.com/yatima1460/Bingo/actions) |
| UI | [![Actions Status](https://github.com/yatima1460/Bingo/workflows/UI/badge.svg)](https://github.com/yatima1460/Bingo/actions) |

## CLI

![](screenshot_cli.png)

- Dynamic Bingo settings
  - Prize patterns config
  - ~Number of balls~
  - ~Number of Cards~
  - ~Card size~
- Game Statistics
  - Percentage Game
  - Pattern frequency
  - Contribution patterns
- ~Insert Credits~
- ~Change numbers~
- ~Show current Cards~
- Play One Game
  - ~Show ExtractedBalls balls~
  - ~Show Cards status~
  - Show prizes
  - ~Remaining Credits~
- Play X Games
- ~Collect~
- ~Exit game~

## UI

![](screenshot_ui.png)

- ~Background~
- ~Balls ExtractedBalls~
- ~Cartons~
  - ~Marked~
- Buttons
  - ~Enter money~
  - ~Collect money~
    - ~Disable if no money~
  - ~Change Cardboard numbers~
  - ~Play Game~
    - ~Remove Credits for Cards~
    - ~Update screen~
    - ~Give prizes~
    - ~Disable if no money for Cards~
  - Mute audio
- ~Current Credits~
- ~Exit with ESC~
- SDL_Image support for .png?
- Resize window buffer using renderToTexture
- ~Disabled button~
- Font size
- Sounds and effects
- ~Assets loader with associative string->Texture map?~
- Balls different colors

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

##### Arch
```
sudo pacman -S sdl2 sdl2_ttf
```


## System used:

```
                   -`                    yatima1460@arch-desktop 
                  .o+`                   ----------------------- 
                 `ooo/                   OS: Arch Linux x86_64 
                `+oooo:                  Kernel: 4.19.75-1-lts 
               `+oooooo:                 Uptime: 1 hour, 16 mins 
               -+oooooo+:                Packages: 1102 (pacman) 
             `/:-:++oooo+:               Shell: bash 5.0.9 
            `/++++/+++++++:              Resolution: 1920x1080, 1366x768 
           `/++++++++++++++:             DE: Xfce 
          `/+++ooooooooooooo/`           WM: Xfwm4 
         ./ooosssso++osssssso+`          WM Theme: Default 
        .oossssso-````/ossssss+`         Theme: Adwaita [GTK2], deepin [GTK3] 
       -osssssso.      :ssssssso.        Icons: Papirus-Light [GTK2], deepin [G 
      :osssssss/        osssso+++.       Terminal: xfce4-terminal 
     /ossssssss/        +ssssooo/-       Terminal Font: Noto Sans Mono Light 11 
   `/ossssso+/:-        -:/+osssso+-     CPU: AMD FX-8350 (8) @ 4.000GHz 
  `+sso+:-`                 `.-/+oso:    GPU: NVIDIA GeForce GTX 980 Ti 
 `++:.                           `-/+/   Memory: 5712MiB / 16002MiB 
 .`                                 `/
```

## Software used:

```
CLion 2019.2.3
g++ (GCC) 9.1.0
```
