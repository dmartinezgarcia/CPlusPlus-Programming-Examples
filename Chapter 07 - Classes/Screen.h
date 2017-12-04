#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <vector>
#include <ostream>

class Screen
{
    // Friends.
    friend class Window_mgr;

public:
    // Type aliases.
    using sizeType = unsigned int;
    using screenType = unsigned char;

    // Constructors.
    inline Screen() = default;
    inline Screen(sizeType screenHeight, sizeType screenWidth) : height(screenHeight), width(screenWidth), screenData(screenHeight, std::vector<screenType>(screenWidth, ' ')) {}
    inline Screen(sizeType screenHeight, sizeType screenWidth, screenType defaultChar) : height(screenHeight), width(screenWidth), screenData(screenHeight, std::vector<screenType>(screenWidth, defaultChar)) {}

    // Function members.
    inline Screen& move(sizeType w, sizeType h) { this->cursorHeight = w; this->cursorWidth = h; return *this; }
    inline Screen& set(screenType chr) {  this->screenData[this->cursorHeight][this->cursorWidth] = chr; return *this; }
    Screen& display(std::ostream& out);
private:
    // Data members.
    sizeType cursorHeight = 0, cursorWidth = 0;
    sizeType height = 0, width = 0;
    std::vector<std::vector<screenType>> screenData;
};

// Non member functions declarations.


// Inline functions.


#endif // __SCREEN_H__
