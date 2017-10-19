#include "Shapes.h"

#include <ctime>

Random random(time(NULL));

void drawSquare(Picture &pic, const Pixel &color, int w, int h){
     for (int x = 0; x < w; x++)
     {
          for (int y = 0; y < h; y++)
          {
               pic.paint(x, y, color);
          }
     }
}

void drawLine(Picture &pic, const Pixel &color, int w, int h){
     int x0, y0, x1, y1;
     if(random.nextInt(1)==1){
          x0=0;
          y0=0;
          x1=w-1;
          y1=h-1;
     } else{
          x0=0;
          y0=h-1;
          x1=w-1;
          y1=0;
     }

     int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
     int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
     int err = (dx>dy ? dx : -dy)/2, e2;

     for(;;)
     {
          pic.paint(x0, y0, color);
          if (x0 == x1 && y0 == y1) break;
          e2 = err;
          if (e2 > -dx)
          {
               err -= dy;
               x0 += sx;
          }
          if (e2 < dy)
          {
               err += dx;
               y0 += sy;
          }
     }
}

std::vector<ShapeInfo> shapes = {
     {
          "squares",
          [](int &w, int &h) { w = random.nextInt(2, 7); h = random.nextInt(2, 7); },
          drawSquare
     },
     {
          "large-squares",
          [](int &w, int &h) { w = random.nextInt(7, 12); h = random.nextInt(7, 12); },
          drawSquare
     },
     {
          "lines",
          [](int &w, int &h) {
               w=0; h=0;
               while(w < 25 && h< 25)
               {
                    w = 1 + (int) (random.nextDouble() * random.nextDouble() * 80);
                    h = 1 + (int) (random.nextDouble() * random.nextDouble() * 80);
               }
          },
          drawLine
     }

};
