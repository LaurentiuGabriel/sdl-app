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
public:
    static constexpr int SCREEN_WIDTH = 800;
    static constexpr int SCREEN_HEIGHT = 600;

    Screen();

    bool init();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvents();
    void close();
    void boxBlur();

private:
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    SDL_Texture* m_texture = nullptr;
    Uint32* m_buffer1 = nullptr;
    Uint32* m_buffer2 = nullptr;
};

#endif /* SCREEN_H_ */
