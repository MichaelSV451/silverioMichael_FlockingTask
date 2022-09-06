#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 averageVelocity = Vector2::zero();

    // todo: add your code here to align each boid in a neighborhood
    // hint: iterate over the neighborhood
    if (!neighborhood.empty()) {

        //get how many flockmates there are
        int countCloseFlockmates = neighborhood.size();



        // average velocity of neighbors, average the direction vector 
        for (int i = 0; i < countCloseFlockmates; i++)
        {
            averageVelocity += neighborhood[i]->getVelocity();
        }

        averageVelocity = averageVelocity.normalized();
    }

    return Vector2::normalized(averageVelocity);
}