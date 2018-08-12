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
	const static int NPARTICLES = 5000;

private:
	Particle * m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const Particle * const getParticles() { return m_pParticles; };
};

#endif /* SWARM_H_ */
