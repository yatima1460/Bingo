// Example program:
// Using SDL2 to create an application window

#include <SDL.h>
#include <cstdio>

#undef main






int main(int argc, char* argv[])
{

    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
            "Bingo",                  // window title
            SDL_WINDOWPOS_CENTERED,           // initial x position
            SDL_WINDOWPOS_CENTERED,           // initial y position
            1920,                               // width, in pixels
            1080,                               // height, in pixels
            SDL_WINDOW_OPENGL                 // flags - see below
    );

    // Check that the window was successfully created
    if (window == nullptr) {
        // In the case that the window could not be made...
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}