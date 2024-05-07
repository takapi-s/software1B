#include "Circle.h"
#include "ColorCircle.h"
#include "DoubleCircle.h"
#include "math.h"


int main (int argc, char* argv[]) {
    //svg svgObj; // Object for generating SVG document
    int N, ratio; // 円の個数と半径  
    std::string color1, color2, color3; // 円の描画色（配置／環状円）
    
    //ColorCircle **c_circles; // 配置円
    //LineCircle *l_circles[2]; // 環状円
    
    if (argc < 4) {
        std::cout << "Lack of Arguments !";
        return 0;
    }


    N = atoi(argv[1]);
    color1 = argv[2];
    color2 = argv[3];
    color3 = argv[4];
    ratio = atoi(argv[5]);

    //ColorCircle c_circles[N];
    //DoubleCircle l_circles[2];

    Circle *circ; // 基本クラスの変数として宣言
    svg svgObj;
    svgObj.open("Circle.html", 640, 400);

    int i;
    double Sin,Cos, radius;
    double posX, posY;
    radius = 100.0 * sin(double(M_PI/N));
    for(i = 0;i<N;i++){
        //c_circles[i].setColor(color1);
        Sin = sin((double)360/N*i*M_PI/180);
        Cos = cos((double)360/N*i*M_PI/180);
        posX = 100.0*Sin + 320.0;
        posY = 100.0*Cos + 200.0;
        printf("%f\n",posX);
        printf("%f\n",posY);
        //c_circles[i].setPosition(posX, posY);
        
        
        //printf("%f\n",radius);
        //c_circles[i].setRadius(radius);
        if (i % 2 == 0){
            circ = new ColorCircle(posX, posY, radius, color1);
        }
        else {
            circ = new DoubleCircle(posX, posY, radius, color2, color3, ratio);
        }
        circ->draw (&svgObj);

    }

    // for (int i = 0; i < 10; i++) {
    //     if ((i % 2) == 0) { // i が偶数の場合
    //         circ = new ColorCircle (20*(i+1), 20, 10, "green");
    //     }
    //     else {// i が奇数の場合
    //         circ = new DoubleCircle (20*(i+1), 20, 10, "red", 3);
    //     }
    //     circ->draw (&svgObj); // ColorCircle と LineCircle が交互に呼び出される！
    // }
    svgObj.close();
}