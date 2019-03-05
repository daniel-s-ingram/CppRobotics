#include "filter.h"

void ParticleFilter::resample(const vector<float>& weights, vector<Robot>& particles)
{
    vector<Robot> p = particles;
    particles.clear();
    int index = std::rand() % nParticles;
    float beta = 0;
    float maxWeight = *std::max_element(weights.begin(), weights.end());
    for (int i = 0; i < nParticles; i++)
    {
        beta += 2 * maxWeight * (double)std::rand() / RAND_MAX;
        while (beta > weights[index])
        {
            beta -= weights[index];
            index = (index + 1) % nParticles;
        }
        particles.push_back(p[index]);
    }
}