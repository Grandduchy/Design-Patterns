#ifndef REPLACEINPUTSTREAM
#define REPLACEINPUTSTREAM

#include "InputStream.hpp"
#include "DecoratorStream.hpp"

// Class acts as a concrete Decorator
// Class will replace all characters of x by y.

class ReplaceInputStream : public DecoratorStream {
public:
    ReplaceInputStream(char seek, char replace, InputStream& inputstream);

    virtual char read() override;
    virtual std::string getline() override;

private:
    char seek;
    char replace;
};

ReplaceInputStream::ReplaceInputStream(char seek, char replace, InputStream& inputStream)
    : DecoratorStream() {
    this->setComponent(inputStream);
    this->seek = seek;
    this->replace = replace;
}

char ReplaceInputStream::read() {
    char in = component->read();
    if (in == seek) in = replace;
    return in;
}

std::string ReplaceInputStream::getline() {
    std::string in = component->getline();
    std::transform(in.begin(), in.end(), in.begin(), [this](char c) {
       return c == seek ? replace : c;
    });
    return in;
}

#endif
