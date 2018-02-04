#ifndef INPUTSTREAM
#define INPUTSTREAM


#include <iostream>
#include <memory>
#include <functional>
#include <utility>

// InputStream is the Componenet every concrete component uses
// The Concrete decorators use this class to communicate to concrete component and other decorators

class InputStream {
public:
    // ios types cannot be copied, they must always be in reference
    using iType = std::reference_wrapper<std::istream>;
    virtual ~InputStream() {iStream.release();}

    virtual char read() = 0;
    virtual std::string getline() = 0;

    void setStream(std::istream& stream);

    void removeStream();

    bool hasStream();
protected:
    std::unique_ptr<iType> iStream = nullptr;
};

void InputStream::setStream(std::istream& stream) {
    iStream.release();
    iType* wrapPointer = new iType(std::ref(stream));
    iStream.reset(wrapPointer);
}

void InputStream::removeStream() {
    iStream.release();
}

bool InputStream::hasStream() {
    return iStream != nullptr;
}

#endif
