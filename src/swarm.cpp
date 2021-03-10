#include "swarm.h"
namespace myscreen
{

Swarm::Swarm()
{
    m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
    delete [] m_pParticles;
}

}
