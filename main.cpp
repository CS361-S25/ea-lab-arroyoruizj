// File: main.cpp
// Created on: April 7th, 2025
// Author: Jared Arroyo Ruiz

// This code is a simple implementation of an evolutionary algorithm
// using a population of organisms that can reproduce and mutate.

// All code was created following Anya E. Vostinar's First Evolutionary Algorithm Lab

// Setting up Environment
#include <iostream>
#include "Empirical/include/emp/math/Random.hpp"

// Setting up Organism
class Organism {
public:

    // Organism's behavior
    // This is a double value that represents the organism's behavior
    double behavior;
    Organism(double d) : behavior(d) {}

    // Reproduction Function
    // This function creates a new organism with a mutated behavior
    // It takes a random number generator as an argument
    // and returns a pointer to the new organism 
    Organism* reproduce(emp::Random random) {

        Organism* offspring = new Organism(behavior);
        offspring->mutate(random);
        return offspring;
        

    }

    // Mutation Function
    // This function mutates the organism's behavior
    // It takes a random number generator as an argument
    // and adds a random value to the organism's behavior
    void mutate(emp::Random random) {
        
        double mutation = random.GetRandNormal(0.0, 0.02);
        behavior += mutation;

    }
};

int main() {

    // Setting up random number generator
    emp::Random random(444);

    // Setting up population
    emp::vector<Organism> population;
    
    // Creating 1000 organisms with random behavior
    // and adding them to the population
    for (int i = 0; i < 1000; i++) {

        Organism* new_org = new Organism(0.5);
        new_org->mutate(random);
        population.push_back(*new_org);
    
    }

    //Update Loop
    for (int j = 0; j < 1000; j++) {

        Organism* max_behavior_org = new Organism(0.0);
        
        for (Organism j : population) {

            if (j.behavior > max_behavior_org->behavior) {

                max_behavior_org = &j;

            }
    
        }

        // Reproduce the organism with the highest behavior
        // and replace a random organism in the population
        // with the new organism
        Organism* new_org = max_behavior_org->reproduce(random);
        int overwrite = random.GetUInt(0,100);
        population[overwrite] = *new_org;
    }

    std::cout << "Population behavior: " << population[0].behavior << std::endl;

    // Testing reproduction
    Organism* offspring_zero = population[0].reproduce(random);
    std::cout << &offspring_zero << std::endl;
    std::cout << &population[0] << std::endl;

    // Finding the max behavior in final population
    Organism* max_behavior_org = new Organism(0.0);
        
        for (Organism j : population) {

            if (j.behavior > max_behavior_org->behavior) {

                max_behavior_org = &j;

            }
        }

    std::cout << "Max behavior: " << max_behavior_org->behavior << std::endl;
}