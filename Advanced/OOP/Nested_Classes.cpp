#include <iostream>
#include <vector>


// #################################### Nested Classes ####################################
// Notes:   Nested Class/Struct is construct a Class/Struct inside another Class/Struct.
//          Using nested Class/Struct depend the goal of the Class/Struct.
//          Possible to hide

// Nested Class
class ParticleSystem{
    // Particle can only be used inside ParticleSystem,
    //  but still able to access it with ParticleSystem::Particle
    //  if Particle is declared as public.
    public:
    struct Particle{
        float x{0.0f};
        float y{0.0f};
        float z{0.0f};
        float speed{1.0f};
        float lifetime{10.0f};
        void Move(){
            std::cout << "Particle called\n";
        }
    };

    void Simulation(){
        std::cout << "Simulation called\n";
    }

    private:
    std::vector<Particle> m_particles;

};

int main(){

    ParticleSystem p;
    p.Simulation();

    // Accessible only because Particle is public
    ParticleSystem::Particle pp;
    pp.Move();

    return 0;
}