#include <iostream>
#include <string>
#include <memory>

#include "fly-behaviors.h"
#include "quack-behaviors.h"

// **********
// Ducks
// **********

class Duck {
protected:
    std::unique_ptr<FlyBehavior> fly;
    std::unique_ptr<QuackBehavior> quack;
public:	
    virtual ~Duck() = 0;
    template<typename Fly, typename Quack>
    Duck(Fly f, Quack q) : fly(nullptr), quack(nullptr) {
        static_assert(isFlyBehavior<Fly> && isQuackBehavior<Quack>,"");
        fly.reset(new Fly(f));
        quack.reset(new Quack(q));
    }

	void performFly() {
        const std::string& s = fly->fly();
        if (!s.empty())
            std::cout << s << std::endl;
	}
	void performQuack() {
        const std::string& s = quack->quack();
        if(!s.empty())
            std::cout << s << std::endl;
    }
    template<typename F>
    void setFly(F n) {
        static_assert(isFlyBehavior<F>,"");
        if (fly != nullptr) {
            fly.reset(nullptr);
        }
        fly.reset(new F(n));
    }
    template<typename Q>
    void setQuack(Q n) {
        static_assert(isQuackBehavior<Q>,"");
        if (quack != nullptr) {
            quack.reset(nullptr);
        }
        quack.reset(new Q(n));
    }
};

Duck::~Duck() {
}

class RubberDuck : public Duck {
public:
    RubberDuck() : Duck(NoFly(), BasicQuack()) { }
};

class ChoppaDuck : public Duck{
public:
    ChoppaDuck() : Duck(AwesomeFly(), AwesomeQuack()) {}
};
