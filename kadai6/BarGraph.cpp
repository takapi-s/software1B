
#include <vector>
#include "svg.h"
#include "Population.h"


int main () {
    svg svgObj;

    Population pop;

    pop.read("Aichi.txt");

    svgObj.open("BarGraph.html", 1280, 400);

    std::size_t i;
    int y;
    y = 0;
    for(i = 0 ; i < pop.getLabels().size(); i++){
        
        y = y + 30;
        //printf("%s\n", pop.getLabels()[i].c_str());
        //printf("%d\n", pop.getValues()[i]);

        svgObj.drawText(0 , y, pop.getLabels()[i].c_str());
        svgObj.drawRect(100 , y-12, pop.getValues()[i], 10);
    }

    svgObj.close();

}