#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood

    
    if (!neighborhood.empty()) {
        //get how many flockmates there are
        int countCloseFlockmates = neighborhood.size();

        //center of mass variable
        Vector2 centerOfMass = Vector2::zero();

        //get center of mass of each boid in neighborhood (average position)
        for (int i = 0; i < countCloseFlockmates; i++)
        {
            centerOfMass += neighborhood[i]->getPosition();
        }

        //average the center of mass
        centerOfMass = centerOfMass / countCloseFlockmates;

        //then apply force in direction of center of mass
        cohesionForce = (boid->getPosition() - centerOfMass).normalized();
    }

    return cohesionForce;
}