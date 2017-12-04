#include "Screen.h"

Screen& Screen::display(std::ostream &out)
{
    for (const auto &i : this->screenData)
    {
        for (const auto &a : i)
        {
            out << a;
        }
        out << std::endl;
    }
}

