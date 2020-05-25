#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"
#include <iostream>

class Circle:public Shape
{
private:
    virtual void doDraw()
    {
        std::cout<<"Circle: doDraw()"<<std::endl;
    }
};

#endif //_CIRCLE_H