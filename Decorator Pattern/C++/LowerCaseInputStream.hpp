#ifndef LOWERCASEINPUTSTREAM
#define LOWERCASEINPUTSTREAM

#include <algorithm>
#include <string>
#include <cctype>
#include "DecoratorStream.hpp"

// Class represents a concrete Decorator, in where the class
// lowercases each letter

class LowerCaseInputStream : public DecoratorStream {
public:
    LowerCaseInputStream(InputStream& inputStream);
    virtual char read(); // lower cases a single letter
    virtual std::string getline(); // lower cases a whole string
};

LowerCaseInputStream::LowerCaseInputStream(InputStream& inputStream) : DecoratorStream() {
    setComponent(inputStream);
}


char LowerCaseInputStream::read() {
    unsigned char in = component->read(); // read from the component
    return std::tolower(in); // using the same read, "decorate" it and return it.
}

std::string LowerCaseInputStream::getline() {
    std::string in = component->getline();
    std::transform(in.begin(), in.end(), in.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return in;
}


#endif
