#include "ColorCircle.h"

class LineCircle : public ColorCircle {
private:
    int w; // 線幅
public:
    LineCircle();
    LineCircle(double cx, double cy, double r, std::string c, double cw); // 違う形式の構築子
    //void draw (svg* svgObj); // Circle クラスの draw () を上書き（オーバーライド）する
    virtual void draw (svg*); // 仮想関数をオーバーライド
    void setWide (double cw);
};