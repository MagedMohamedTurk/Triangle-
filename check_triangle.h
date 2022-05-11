#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
#include <math.h>


// Determine the ACCURACY.

float *get_sides();
bool check_triangle(float side[3]);
const char* classify_side();
const char* classify_angle(float *side);
float square(float x);
float cos_angle(float nearby_side1, float nearby_side2, float opposite_site);
bool check_obtuse(float x);