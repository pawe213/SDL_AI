#ifndef PARTICLE_H
#define PARTICLE_H
namespace myscreen
{

struct Particle
{
    double m_x;
    double m_y;

    double m_xspeed;
    double m_yspeed;

    public:
        Particle();
        virtual ~Particle();
        void update();

    protected:



};

}
#endif // PARTICLE_H
