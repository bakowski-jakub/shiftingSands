#include "RenderHandler.h"
#include "settings.h"
#include "iostream"
#include "vec3.h"

void RenderHandler::init()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == nullptr) {
        throw std::runtime_error("Failed to create renderer!");
    }
    SDL_RenderSetScale(renderer, SCALE, SCALE);
}


void RenderHandler::draw()
{
    clear();

    for (uint16_t x = 0; x < ROWS; x++) {
        for (uint16_t y = 0; y < COLS; y++) {
            Cell* value = grid[x][y];

            if (value != 0) {
                vec3 color = value->getColor();

                SDL_SetRenderDrawColor(renderer, color.getX(), color.getY(), color.getZ(), 0xFF);
                SDL_RenderDrawPoint(renderer, x, y);
            }
            else {
                //SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
                //SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
    SDL_RenderPresent(renderer);
}


void RenderHandler::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(renderer);
}
