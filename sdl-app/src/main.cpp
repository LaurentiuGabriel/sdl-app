//============================================================================
// Name        : sdl-app.cpp
// Author      : Laurentiu Raducu
// Version     : 1.0
//============================================================================

#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Screen.h"
#include "Swarm.h"

const double FREQUENCY_FACTOR_GREEN = 0.0001;
const double FREQUENCY_FACTOR_RED = 0.0002;
const double FREQUENCY_FACTOR_BLUE = 0.0003;
const double SIN_OFFSET = 1.0;
const double COLOR_SCALING = 128;

unsigned char calculateColor(int elapsed, double frequencyFactor) {
    return static_cast<unsigned char>((SIN_OFFSET + sin(elapsed * frequencyFactor)) * COLOR_SCALING);
}

void updateScreenColors(Screen &screen, Swarm &swarm, int elapsed) {
    unsigned char green = calculateColor(elapsed, FREQUENCY_FACTOR_GREEN);
    unsigned char red = calculateColor(elapsed, FREQUENCY_FACTOR_RED);
    unsigned char blue = calculateColor(elapsed, FREQUENCY_FACTOR_BLUE);

    const Particle * const pParticles = swarm.getParticles();

    for (int i = 0; i < Swarm::NPARTICLES; i++) {
        Particle particle = pParticles[i];

        int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
        int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

        screen.setPixel(x, y, red, green, blue);
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    Screen screen;

    if (!screen.init()) {
        std::cerr << "Error initialising SDL." << std::endl;
        return 1; // Exit with an error code
    }

    Swarm swarm;

    while (true) {
        int elapsed = SDL_GetTicks();

        swarm.update(elapsed);
        updateScreenColors(screen, swarm, elapsed);

        screen.boxBlur();
        screen.update();

        if (!screen.processEvents()) {
            break;
        }
    }

    screen.close();
    return 0;
}
