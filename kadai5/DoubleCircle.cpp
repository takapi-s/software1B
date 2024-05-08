#include "DoubleCircle.h"

DoubleCircle::DoubleCircle() : c_1(0, 0, 100, "black"), c_2(0, 0, 50, "red") {
    // 内部円の半径比率をデフォルト値に設定
}

DoubleCircle::DoubleCircle(double cx, double cy, double r, std::string c1, std::string c2, double ratio)
    : c_1(cx, cy, r, c1), c_2(cx, cy, r * ratio /100,c2) {
    // 内部円の半径比率を指定された値に設定
}

void DoubleCircle::setPosition (double x, double y) { 
    c_1.setPosition(x,y);
    c_2.setPosition(x,y);
}

void DoubleCircle::setRadius (double r){
    c_1.setRadius(r);
    c_2.setRadius(r);
}

void DoubleCircle::draw(svg* svgObj) {
    c_1.draw(svgObj);
    c_2.draw(svgObj);
}
