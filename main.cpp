#include <iostream>
#include "Empirical/include/emp/math/Random.hpp"

class Organism {
public:

    double behavior;
    Organism(double d) : behavior(d) {}

    Organism* reproduce() {

        Organism* child = new Organism(behavior);
        return child;

    }
};

int main() {

    emp::vector<Organism> population;
    
    for (int i = 0; i < 100; i++) {
        population.push_back(*new Organism(0.5));
    }

    std::cout << "Population behavior: " << population[0].behavior << std::endl;

    Organism* child_zero = population[0].reproduce();

    std::cout << &child_zero << std::endl;
    std::cout << &population[0] << std::endl;


}