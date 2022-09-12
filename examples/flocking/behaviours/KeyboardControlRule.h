#ifndef KEYBOARDCONTROLRULE_H
#define KEYBOARDCONTROLRULE_H

#include "FlockingRule.h"

class KeyboardControlRule : public FlockingRule {
private:
	float desiredDistanceMin = 5;

public:
    explicit  KeyboardControlRule(World* pWorld, float weight = 10., bool isEnabled = false) :
        FlockingRule(pWorld, Vector3::Red(), weight, isEnabled)//, desiredDistanceMin(desiredDistance)
    {}

    std::unique_ptr<FlockingRule> clone() override {
        return std::make_unique< KeyboardControlRule>(*this);
    }

    const char* getRuleName() override {
        return "Keyboard Control Rule";
    }

    const char* getRuleExplanation() override {
        return "Move boids using arrow keys.";
    }

    virtual float getBaseWeightMultiplier() override {
        return 1.;
    }

    Vector2 computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) override;

   // bool drawImguiRuleExtra() override;

};

#endif