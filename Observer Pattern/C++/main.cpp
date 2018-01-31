#include <iostream>

#include "subject.hpp"

enum class Event { RED, GREEN, BLUE, ORANGE, MAGENTA, CYAN };

void foo(int i)
{
  std::cout << "foo( " <<  i << " )\n";
}

void bar() {
  std::cout << "bar()\n";
}
template<typename T>
int enumToNum(T&& e) {
    return static_cast<int>(e);
}

int main()
{

  Subject<void()> s;
  s.registerObserver(enumToNum(Event::GREEN), bar);
  s.registerObserver(enumToNum(Event::ORANGE), std::bind(foo, 42));
  s.registerObserver(enumToNum(Event::RED), std::bind(foo, 12345));

  s.notify(enumToNum(Event::GREEN));
  s.notify(enumToNum(Event::RED));
  s.notify(enumToNum(Event::ORANGE));

}
