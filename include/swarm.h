#ifndef SWARM_H
#define SWARM_H

#include "particle.h"
namespace myscreen{

class Swarm
{
    public:
        const static int NPARTICLES = 1000;
        Swarm();
        virtual ~Swarm();

    protected:

    private:
        Particle * m_pParticles;

    public:
        void update();
        const Particle * const getParticles() {return m_pParticles;};
};
}
#endif // SWARM_H

