#include <vector>
#include <math.h>

template <class T> class RingCircles {
    private:
        std::vector<T *> circles; // 環状に配置する円の要素
        int x, y; // この円環群の相対的位置座標

    public:
        RingCircles (){}

        void setCircles(int n) {
            //あとでエラー処理を追加
            int i;
            for (i = 0; i < n; i++) {
	         circles.push_back(new T());
            }

            double radius = 100.0 * sin(double(M_PI/n));
            for (i = 0; i < circles.size(); i++) {
                circles[i]->setRadius(radius);
            }
	      
        } // 構築子：配置する円の個数が引数
        
        void setPosition(int x, int y) { // 相対的位置座標の設定
            this->x = x; this->y = y;
            int i;
            double Sin,Cos;
            double posX, posY;
            
            for (i = 0; i < circles.size(); i++) {
                Sin = sin((double)360/circles.size()*i*M_PI/180);
                Cos = cos((double)360/circles.size()*i*M_PI/180);
                posX = 100.0*Sin + x;
                posY = 100.0*Cos + y;
                circles[i]->setPosition(posX,posY);
            }
        }


        void draw(svg *svgObj) {
            int i;
            for (i = 0; i < circles.size(); i++) {
                circles[i]->draw(svgObj);
            } 
        } // 描画関数
    };