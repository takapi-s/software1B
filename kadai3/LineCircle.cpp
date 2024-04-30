#include "LineCircle.h"

LineCircle::LineCircle () : ColorCircle () { // 構築子
    w = 1;
}

LineCircle::LineCircle (double cx, double cy, double r, std::string c, int cw) : ColorCircle (cx, cy, r, c) { // 属性を指定する構築子
     w = cw;
}

void LineCircle::draw (svg* svgObj) { // Circle クラスの draw () を上書き（オーバーライド）する
    svgObj->drawCircle(x, y, rad, color, w);
} 

void LineCircle::setWide (int cw) { // 色の設定
    w = cw;
}