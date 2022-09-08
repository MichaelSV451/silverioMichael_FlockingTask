#include "BoundedAreaRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 BoundedAreaRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Return a force proportional to the proximity of the boids with the bounds, and opposed to it
    Vector2 force = Vector2::zero(); //zero

    // todo: add here your code code here do make the boid follow the bounded box rule
    // hint: use this->world->engine->window->size() and desiredDistance
    
    ///
    //the bounds and weight of this need to be pretty high for this to be very noticeable!
    ///

    Vector2 worldBound = this->world->engine->window->size();

    //create a box based on desired distance
    //if outside of this box, apply opposite force to direct away from bounds
    if (boid->getPosition().y < 0 + desiredDistance)
    {
        force += Vector2::down();
    }
    if (boid->getPosition().y > worldBound.y - desiredDistance)
    {
        force += Vector2::up();
    }
    if (boid->getPosition().x < 0 + desiredDistance)
    {
        force += Vector2::right();
    }
    if (boid->getPosition().x > worldBound.x - desiredDistance)
    {
        force += Vector2::left();
    }


    return force;
}

bool BoundedAreaRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    auto size = this->world->engine->window->size();
    auto widthWindows = size.x;
    auto heightWindows = size.y;
    bool valueHasChanged = false;

    //We cap the max separation as the third of the min of the width.height
    auto minHeightWidth = std::min(widthWindows, heightWindows);

    if (ImGui::SliderInt("Desired Distance From Borders",
                         &desiredDistance,
                         0.0f,
                         (int)(minHeightWidth/3),
                         "%i")) {
        valueHasChanged = true;
    }

    return valueHasChanged;
}

void BoundedAreaRule::draw(const Boid& boid, SDL_Renderer* renderer) const {
    FlockingRule::draw(boid, renderer);
    auto size = this->world->engine->window->size();
    auto dist = (float)desiredDistance;

    // Draw a rectangle on the map
    Polygon::DrawLine(renderer, Vector2(dist,dist), Vector2(size.x - dist,dist), Vector3::Gray()); // TOP
    Polygon::DrawLine(renderer, Vector2(size.x - dist,dist), Vector2(size.x - dist,size.y - dist), Vector3::Gray()); // RIGHT
    Polygon::DrawLine(renderer, Vector2(size.x - dist,size.y - dist), Vector2(dist,size.y - dist), Vector3::Gray()); // Bottom
    Polygon::DrawLine(renderer, Vector2(dist,size.y - dist), Vector2(dist,dist), Vector3::Gray()); // LEFT
}