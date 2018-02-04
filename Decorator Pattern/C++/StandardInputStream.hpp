#ifndef STANDARDINPUTSTREAM
#define STANDARDINPUTSTREAM
// StandardInputStream is a concrete component
// Class is for console input

#include <functional>

#include "InputStream.hpp"

class StandardInputStream : public InputStream {
public:

    StandardInputStream() : InputStream() {}

    virtual ~StandardInputStream() { }

    virtual char read() override;
    virtual std::string getline() override;
private:
    void checkStream(); // make sure stream is ok
};

char StandardInputStream::read() { // read a character
    checkStream();
    char in = '\0';
    iStream->get() >> in;
    return in;
}

std::string StandardInputStream::getline() { // read a line
    checkStream();
    std::string userInput;
    char in;
    in = std::cin.get();
    while (static_cast<int>(in) != 10) { // while its not the enter key indicating quit
        userInput.push_back(in);
        in = std::cin.get();
    }
    return userInput;
}


void StandardInputStream::checkStream() {
    if (!hasStream()) throw std::runtime_error("Does not have a stream");
}


#endif
