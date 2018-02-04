#include <iostream>
#include <string>
#include <memory>
#include "InputStream.hpp"
#include "StandardInputStream.hpp"
#include "LowerCaseInputStream.hpp"
#include "ReplaceInputStream.hpp"

// Decorator Pattern Demonstration
// Each concrete decorater adds some kind of functionality
// to the original concrete component

// Note - unique_ptrs can be used instead of a raw pointer
int main() {
    InputStream* input = new StandardInputStream();
    input->setStream(std::cin);
    input = new ReplaceInputStream('a','z',*input);
    input = new LowerCaseInputStream(*input);
    std::string in = input->getline();
    std::cout << "\n" << in << std::endl;
    delete input;
    return 0;
}
