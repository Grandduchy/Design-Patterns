#ifndef FLYBEHAVIORS_H
#define FLYBEHAVIORS_H

#include <type_traits>

// ************
// FlyBehaviors
// ************

struct FlyBehavior;

template<typename T>
constexpr bool isFlyBehavior = std::is_base_of<FlyBehavior, T>::value;


struct FlyBehavior {
    virtual std::string fly() = 0;
    virtual ~FlyBehavior() = 0;
};


FlyBehavior::~FlyBehavior() {

}

struct NoFly : public FlyBehavior {
    virtual std::string fly() override {
        return "";
    }
};

struct BasicFly : public FlyBehavior {
    virtual std::string fly() override {
        return "Fly!";
    }

};

struct AwesomeFly : public FlyBehavior {
    virtual std::string fly() override {
        return "I AM FLYING TO INFENITY AND BEYOND!";
    }
};


#endif // FLYBEHAVIORS_H
