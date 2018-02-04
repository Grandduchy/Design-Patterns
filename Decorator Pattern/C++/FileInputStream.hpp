#ifndef FIELINPUTSTREAM
#define FILEINPUTSTREAM

#include "InputStream.hpp"
// Class is a concrete component that handles files
// Class handles std::fstreams NOT FILE*

class FileInputStream : public InputStream {
public:
    virtual char read() override;
    virtual std::string getline() override;
    void reset();
    bool isValid();
};

char FileInputStream::read() {
    if (isValid())
        return this->iStream->get();
}

std::string FileInputStream::getline() {
    std::string fileInput;
    if (isValid()) {
        char in = '\0';
        in = this->iStream->get();
        while(static_cast<int>(in) != '\n') { // while it hasn't reached a new line
            fileInput.push_back(in);
            in = this->iStream->get();
        }

    }
    return fileInput;
}

void FileInputStream::reset() {
    this->iStream->seekg(std::ios_base::beg);
}

bool FileInputStream::isValid() {
    std::ios_base::seekdir currentPos = this->iStream->tellg(), // get the current position of the stream
            end = std::ios_base::end;
    this->iStream->seekg(std::ios_base::end);
    end = this->iStream-> tellg(); // get the end of the file
    this->iStream->seekg(currentPos);
    return hasStream() && currentPos < end; // if it hasn't reached the end of the file
}

#endif
