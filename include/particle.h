#ifndef PARTICLE_H
#define PARTICLE_H
namespace myscreen{

struct Particle
{
    double m_x;
    double m_y;

	double m_speed;
	double m_direction;



    public:
        Particle();
        virtual ~Particle();
        void update(int interval);
        void init();

    protected:



};

}
#endif // PARTICLE_H

