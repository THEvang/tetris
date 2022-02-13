#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int main() {
    

    if (SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL ERROR\t%s", SDL_GetError());
        return 1;
    }

    int aspect_ratio = 2;

    SDL_Window* window = SDL_CreateWindow("Tetris",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 800 * aspect_ratio,
        SDL_WINDOW_ALLOW_HIGHDPI
    );
    if (!window) {
        printf("SDL ERROR\t%s", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        printf("SDL ERROR\t%s", SDL_GetError());
        return 1;
    }


    SDL_Rect grid[10*20];
    for (int i = 0; i < 10 * 20; i++) {
        grid[i] = (SDL_Rect) {
            .x = i % 10 * 80,
            .y = i / 10 * 80,
            .w = 80,
            .h = 80
        };
    }

    bool should_quit = false;
    while (!should_quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                should_quit = true;
                break;
            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawRects(renderer, &grid[0], 10*20);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return 0;
}