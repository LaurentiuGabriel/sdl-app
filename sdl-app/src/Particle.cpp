/*
 * Particle.cpp
 *
 *  Created on: Aug 9, 2018 - long time ago
 *      Author: Laurentiu
 */

#include "Particle.h"
#include <cstdlib> // Include for rand()
#include <cmath>   // Include for M_PI

class Particle {
private:
    double m_x;
    double m_y;
    double m_direction;
    double m_speed;

public:
    Particle() : m_x(0), m_y(0) {
        init();
    }

    ~Particle() = default;

    void init() {
        m_x = 0;
        m_y = 0;
        m_direction = (2.0 * M_PI * std::rand()) / RAND_MAX;
        m_speed = (0.04 * std::rand()) / RAND_MAX;
        m_speed *= m_speed;
    }

    void update(int interval) {
        m_direction += interval * 0.0003;
        double xspeed = m_speed * std::cos(m_direction);
        double yspeed = m_speed * std::sin(m_direction);
        m_x += xspeed * interval;
        m_y += yspeed * interval;

        if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1 || std::rand() < RAND_MAX / 100) {
            init();
        }
    }
};
