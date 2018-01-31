#include <iostream>

#include "duck.hpp"
#include "fly-behaviors.h"
#include "quack-behaviors.h"

void perform(RubberDuck& d) {
    d.performFly();
    d.performQuack();
}

int main() {
    RubberDuck myduck;
    perform(myduck);
    myduck.setFly(AwesomeFly());
    myduck.setQuack(AwesomeQuack());
    perform(myduck);
	return 0;
}
