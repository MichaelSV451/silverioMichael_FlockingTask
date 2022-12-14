#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Try to avoid boids too close
    Vector2 separatingForce = Vector2::zero();

    float desiredDistance = desiredMinimalDistance;

    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
    if (!neighborhood.empty()) {
        Vector2 position = boid->transform.position;

        //get how many flockmates there are
        int countCloseFlockmates = neighborhood.size();

        //for each flockmate, add to desired distance
        for (int i = 0; i < countCloseFlockmates; i++)
        {
            //get distance from this boid to neighbordhood boid
            Vector2 check = boid->transform.position - neighborhood[i]->transform.position;

            float distance = check.getDistance(boid->transform.position, neighborhood[i]->transform.position);
            //add force if boid is within range
            if (distance < desiredDistance)
            {
                separatingForce += check;
            }
            
        }

    }

    separatingForce = Vector2::normalized(separatingForce);

    return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
