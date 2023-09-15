/*
 * Swarm.cpp
 *
 *  Created on: Aug 9, 2018
 *      Author: Laurentiu
 */

#include <vector>
#include "Swarm.h"

Swarm::Swarm() : lastTime(0), m_pParticles(std::vector<Particle>(NPARTICLES)) {}

void Swarm::update(int elapsed) {
    int interval = elapsed - lastTime;

    for (auto& particle : m_pParticles) {
        particle.update(interval);
    }

    lastTime = elapsed;
}
