
//Bryan Sugiarto CPE101-05 Program 5


#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "data.h"

struct point input_eye(int argc, char *in[]);

struct light input_light(int argc, char *in[]);

struct view input_view(int argc, char *in[]);

struct color input_ambient(int argc, char *in[]);

void input_spheres(char **argv, struct sphere s[], int c[]);

int equalToFlag(int argc, char*in[], int index);


#endif


