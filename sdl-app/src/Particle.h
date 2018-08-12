/*
 * Particle.h
 *
 *  Created on: Aug 9 2018
 *      Author: Laurentiu
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

struct Particle {
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

#endif /* PARTICLE_H_ */
