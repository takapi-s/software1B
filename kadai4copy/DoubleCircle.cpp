#include "DoubleCircle.h"

DoubleCircle::DoubleCircle() : ColorCircle(), ratio(0.5) {
    // 内部円の半径比率をデフォルト値に設定
}

DoubleCircle::DoubleCircle(double cx, double cy, double r, std::string c1, std::string c2, double ratio)
    : c_1(cx, cy, r, c1), c_2(cx, cy, r * ratio /100,c2) {
    // 内部円の半径比率を指定された値に設定
}

void DoubleCircle::draw(svg* svgObj) {
    // 外側の円を描画
    // ColorCircle::draw(svgObj);
    // c_
    
    // // 内部の円を描画
    // double innerRad = ratio * rad / 100; // 内部円の半径を計算
    // svgObj->drawCircle(x, y, innerRad, color_in); // 内部円を描画
    c_1.draw(svgObj);
    c_2.draw(svgObj);
}