#include "WindRule.h"
#include <imgui.h>
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 WindRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    // todo: add a wind force here
    // hint: use the windAngle variable

    //create wind force
    Vector2 windForce = Vector2::zero();

    //to get direction of force, convert angle into a vector
    windForce.x = cos(windAngle);
    windForce.y = sin(windAngle);
    
    //apply force
    return windForce;
}

bool WindRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valueHasChanged = false;

    if (ImGui::SliderAngle("Wind Direction", &windAngle, 0)) {
        valueHasChanged = true;
    }

    return valueHasChanged;
}