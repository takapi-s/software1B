#pragma once
#include "Circle.h"

class ColorCircle : public Circle {
protected:
    std::string color; // 描画色
public:
    ColorCircle (); // 構築子
    ColorCircle (double cx, double cy, double r, std::string c); // 違う形式の構築子

    //void draw (svg* svgObj); // Circle クラスの draw () を上書き（オーバーライド）する
    virtual void draw (svg*); // 仮想関数をオーバーライド
    void setColor (std::string c); // 色の設定

};