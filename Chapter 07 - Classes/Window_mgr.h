#ifndef __WINDOW_MGR_H__
#define __WINDOW_MGR_H__

#include "Screen.h"
#include <vector>
#include <ostream>

class Window_mgr
{
    // Forward declarations.

    // Friends.

public:
    // Type aliases.

    // Constructors.
    inline Window_mgr() = default;
    inline Window_mgr(int numOfScreens) : screens(numOfScreens, Screen(5, 5, 'X')) {}

    // Function members.
    inline Window_mgr &clear(void);
    inline Window_mgr &display(std::ostream &out);
private:
    // Data members.
    std::vector<Screen> screens;
};

// Non member functions declarations.

// Inline functions.
inline Window_mgr &Window_mgr::clear(void)
{
    for (auto &scr : this->screens)
    {
        for (auto &row : scr.screenData)
        {
            for (auto &clm : row)
            {
                clm = 'C';
            }
        }
    }

    return *this;
}

inline Window_mgr &Window_mgr::display(std::ostream &out)
{
    for (auto &a : this->screens)
    {
        a.display(out);
    }

    return *this;
}

#endif // __WINDOW_MGR_H__
