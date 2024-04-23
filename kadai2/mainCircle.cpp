#include <iostream>
#include "Circle.h"
#include <math.h>  /* M_PI */
int main() {
    svg svgObj; // SVGドキュメントを生成するオブジェクト
    int N;
    double posX, posY, radius; // 円の描画位置と半径
    
    // std::cout << "Input X Coordinate => "; // 画面にメッセージ出力
    // std::cin >> posX; // 円の座標（X）の入力
    // std::cout << "Input Y Coordinate => ";
    // std::cin >> posY; // 円の座標（Y）の入力
    // std::cout << "Input Radius => ";
    // std::cin >> radius; // 円の半径の入力
    
    //計算
    std::cout << "Input N =>";
    std::cin >> N;
    
    Circle circles[N]; // 円のオブジェクト


    // circle.setPosition(posX, posY); // 円の描画位置の指定
    // circle.setRadius(radius); // 円の半径の指定
    int i;
    double Sin,Cos;
    for(i = 0;i<N;i++){
        Sin = sin((double)360/N*i*M_PI/180);
        Cos = cos((double)360/N*i*M_PI/180);
        posX = 100.0*Sin + 320.0;
        posY = 100.0*Cos + 200.0;
        printf("%f\n",posX);
        printf("%f\n",posY);
        circles[i].setPosition(posX, posY);
        
        radius = 100.0 * sin(double(M_PI/N));
        
        printf("%f\n",radius);
        circles[i].setRadius(radius);
    }

    
    svgObj.open("circle.html", 640, 400); // ファイルを開く
    for(i=0;i<N;i++){
        circles[i].draw(&svgObj);
    }
    svgObj.close(); // ファイルを閉じる
}