#ifndef __XY_H__
#define __XY_H__

class X
{
    // Forward declarations.
    class Y;

    Y* yMember;
};

class Y
{
    X xMember;
};

#endif // __XY_H__
