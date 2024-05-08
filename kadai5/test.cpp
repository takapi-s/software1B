#include "Circle.h"
#include "ColorCircle.h"
#include "LineCircle.h"
#include "DoubleCircle.h"
#include "RingCircles.h"
#include "math.h"

int main (int argc, char* argv[]) {

    svg svgObj;
    int n = atoi(argv[1]);
    int offsetX = 400;
    int x = 150,y=200;
    RingCircles<ColorCircle> cc; // 円環(ColorCircle)クラスの生成
    cc.setCircles(n);
    cc.setPosition(x, y); // 円環の位置の設定
    RingCircles<LineCircle> lc; // 円環(LineCircle)クラスの生成
    lc.setCircles(n);
    lc.setPosition(x+offsetX, y); // 円環の位置の設定
    RingCircles<DoubleCircle> dc;    
    dc.setCircles(n);
    dc.setPosition(x+offsetX*2, y); // 円環の位置の設定
    
    svgObj.open("RingCircles.html", 1280, 400); // ファイルを開く
    cc.draw(&svgObj); // 円環(ColorCircle)の描画
    lc.draw(&svgObj); // 円環(LineCircle)の描画
    dc.draw(&svgObj); // 円環(LineCircle)の描画
    svgObj.close();
}