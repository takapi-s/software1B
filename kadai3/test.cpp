#include "LineCircle.h"
#include "math.h"
int main (int argc, char* argv[]) {
    svg svgObj; // Object for generating SVG document
    int N, width; // 円の個数と半径  
    std::string color1, color2; // 円の描画色（配置／環状円）
    //ColorCircle **c_circles; // 配置円
    //LineCircle *l_circles[2]; // 環状円
    
    if (argc < 4) {
        std::cout << "Lack of Arguments !";
        return 0;
    }


    N = atoi(argv[1]);
    color1 = argv[2];
    color2 = argv[3];
    width = atoi(argv[4]);

    ColorCircle c_circles[N];
    LineCircle l_circles[2];

    
    // circle.setPosition(posX, posY); // 円の描画位置の指定
    // circle.setRadius(radius); // 円の半径の指定

    int i;
    double Sin,Cos, radius;
    double posX, posY;
    radius = 100.0 * sin(double(M_PI/N));
    for(i = 0;i<N;i++){
        c_circles[i].setColor(color1);
        Sin = sin((double)360/N*i*M_PI/180);
        Cos = cos((double)360/N*i*M_PI/180);
        posX = 100.0*Sin + 320.0;
        posY = 100.0*Cos + 200.0;
        printf("%f\n",posX);
        printf("%f\n",posY);
        c_circles[i].setPosition(posX, posY);
        
        
        printf("%f\n",radius);
        c_circles[i].setRadius(radius);
    }

    l_circles[0].setColor(color2);
    l_circles[1].setColor(color2);
    l_circles[0].setWide(width);
    l_circles[1].setWide(width);
    
    l_circles[0].setRadius(100.0+radius);
    l_circles[1].setRadius(100.0-radius);
    l_circles[0].setPosition(320, 200);
    l_circles[1].setPosition(320, 200);
    
    

    
    svgObj.open("circle.html", 640, 400); // ファイルを開く
    for(i=0;i<N;i++){
        c_circles[i].draw(&svgObj);
    }
    l_circles[0].draw(&svgObj);
    l_circles[1].draw(&svgObj);

    svgObj.close(); // ファイルを閉じる


    return (1);
}