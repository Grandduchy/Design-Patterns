#ifndef DECORATOR
#define DECORATOR

#include "InputStream.hpp"

// Class represents the abstract Decorator
// Can be thought of, each decorator must use the pure virtual functions
// (and modify them someway) to be a decorator

class DecoratorStream : public InputStream {
public:
    // The functions are where the decorators "decorate" the object, so it must be a pure virtual.
    virtual char read() = 0;
    virtual std::string getline() = 0;
    ~DecoratorStream();
protected:
    // Pointer to the base class
    // Used to allow type matching and communication between components and decorators
    std::unique_ptr<InputStream> component;
    void setComponent(InputStream& inputStream);
};

DecoratorStream::~DecoratorStream() {
    component.release();
}

void DecoratorStream::setComponent(InputStream &inputStream) {
    component.release();
    component.reset(&inputStream);
}

#endif
