//Bryan Sugiarto Program 2 Section 5
#ifndef DATA_H
#define DATA_H

struct point{
double x;
double y;
double z;
};

struct point create_point(double x, double y, double z);


struct vector{
double x;
double y;
double z;
};

struct vector create_vector(double x, double y, double z);


struct ray{
struct point p;
struct vector dir;
};

struct ray create_ray(struct point p, struct vector dir);


struct color{
   double r;
   double g;
   double b;
};

struct color create_color(double r, double g, double b);


struct finish{
   double ambient;
   double diffuse;
   double specular;
   double roughness;
};

struct finish create_finish(double ambient, double diffuse,
                            double s, double r);


struct light{
   struct point p;
   struct color color;
};

struct light create_light(struct point p, struct color color);


struct sphere{
struct point center;
double radius;
struct color c;
struct finish finish;
};

struct sphere create_sphere(struct point p, double radius, 
      struct color c,struct finish f);


struct view{
   double min_x;
   double min_y;
   double max_x;
   double max_y;
   int width;
   int height;
};

struct view create_view(double min_x,double max_x,double min_y,double max_y,
                        int width,int height);


#endif


