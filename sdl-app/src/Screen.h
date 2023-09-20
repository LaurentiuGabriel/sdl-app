/*
 * Screen.h
 *
 *  Created on: Aug 9, 2018 🥲
 *      Author: Laurentiu
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

class Screen {
private:
    // SDL-related member variables
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    SDL_Texture* m_texture = nullptr;

    // Buffers for pixel manipulation
    Uint32* m_buffer1 = nullptr;
    Uint32* m_buffer2 = nullptr;

public:
    // Constants for screen dimensions
    struct Dimensions {
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
    };

    Screen();

    // Lifecycle methods
    bool init();
    void close();

    // Rendering methods
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void boxBlur();

    // Event handling method
    bool processEvents();
};

#endif /* SCREEN_H_ */
