#pragma once
#include "ColorCircle.h"

class DoubleCircle : public ColorCircle {
private:
    double ratio; // 内部円の半径比率
    std::string color_in;
    ColorCircle c_1, c_2;
public:
    DoubleCircle(); // デフォルトコンストラクタ
    DoubleCircle(double cx, double cy, double r, std::string c1, std::string c2, double ratio); // 別の形式のコンストラクタ

    virtual void draw(svg* svgObj) override; // draw() 関数のオーバーライド
};
