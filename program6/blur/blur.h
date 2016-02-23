//Bryan Sugiarto cpe 101-05

#ifndef BLUR_H
#define BLUR_H

struct point{
   int row;
   int col;
};

struct point create_point(int x, int y);


struct color{
   int r;
   int g;
   int b;
};

struct color create_color(int r, int g, int b);

int arrparam;

#endif

