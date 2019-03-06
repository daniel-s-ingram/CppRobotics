#ifndef PARTICLE_H
#define PARTICLE_H

#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

#include "robot.h"

class ParticleFilter
{
    public:
        ParticleFilter() {};
        ParticleFilter(int nParticles) : nParticles(nParticles) {};
        int resample(const vector<float>&, vector<Robot>&);

    private:
        int nParticles;
};

#endif