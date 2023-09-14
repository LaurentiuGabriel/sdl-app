/*
 * Swarm.h
 *
 *  Created on: Aug 9, 2018
 *      Author: Laurentiu
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

class Swarm {
public:
    static const int NPARTICLES = 5000;

    Swarm();
    virtual ~Swarm();
    
    void update(int elapsed);
    const Particle* getParticles() const;

private:
    Particle* m_pParticles;
    int lastTime;
};

#endif /* SWARM_H_ */
