#ifndef QUACKBEHAVIORS_H
#define QUACKBEHAVIORS_H

#include <type_traits>

// **************
// QuackBehaviors
// **************

struct QuackBehavior;

template<typename T>
constexpr bool isQuackBehavior = std::is_base_of<QuackBehavior, T>::value;

struct QuackBehavior {
    virtual std::string quack() = 0;
    virtual ~QuackBehavior() = 0;
};

QuackBehavior::~QuackBehavior() {

}

struct NoQuack : public QuackBehavior {
    virtual std::string quack() override {
        return "";
    }
};

struct BasicQuack : public QuackBehavior {
    virtual std::string quack() override {
        return "Quack!";
    }
};

struct AwesomeQuack : public QuackBehavior {
    virtual std::string quack() override {
        return "QQQQQQQQQQQUUUUUUUUUUUUAAAAAAAACCCCCCCCCCCCCKKKKKKKKK!!!!!!!!!!!!";
    }
};


#endif // QUACKBEHAVIORS_H
