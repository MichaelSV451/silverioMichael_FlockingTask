#include "KeyboardControlRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 KeyboardControlRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {

    ImGui::SetCurrentContext(world->engine->imGuiContext);
    ImGuiIO& io = ImGui::GetIO();

    Vector2 keyboardForce = Vector2::zero();

    //move in direction of arrow keys
    if (io.KeysDown[ImGuiKey_::ImGuiKey_RightArrow])
    {
        keyboardForce += Vector2::right();
    }
    if (io.KeysDown[ImGuiKey_::ImGuiKey_LeftArrow])
    {
        keyboardForce += Vector2::left();
    }
    if (io.KeysDown[ImGuiKey_::ImGuiKey_UpArrow])
    {
        keyboardForce += Vector2::up();
    }
    if (io.KeysDown[ImGuiKey_::ImGuiKey_DownArrow])
    {
        keyboardForce += Vector2::down();
    }
    

    

	return keyboardForce;
}

//bool KeyboardControlRule::drawImguiRuleExtra() {
//    ImGui::SetCurrentContext(world->engine->imGuiContext);
//    bool valusHasChanged = false;
//
//    if (ImGui::DragFloat("Desired Follow Distance", &desiredDistanceMin, 0.05f)) {
//        valusHasChanged = true;
//    }
//
//    return valusHasChanged;
//}