#include <stdio.h>
#include "svg.h"
#pragma once

#include <iostream>

class Circle { 
protected:
    double x, y;
    double rad;
    

public:
    Circle (); // 関数の内容は記述しない
    Circle (double cx, double cy, double r = 10.0);
    void setPosition (double x, double y);
    void setRadius (double rad);
    int getRadius ();
    int getPositionX ();
    int getPositionY ();
    //void draw (svg* svgObj); // 引数はポインタ渡し
    virtual void draw (svg*) = 0; // 0を代入すると、純粋仮想関数となる！
};

