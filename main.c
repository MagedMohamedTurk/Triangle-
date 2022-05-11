// This module will check if the user input of 
// triangle side lengths can construct a valid triangle.
#include "check_triangle.h"


int main(void)
{
    float *side = get_sides(); // Declare a pointer to the array address returned from the get_sides() function.

    // Validate it can construct a triangle.
    if (check_triangle(side))
    {
        printf("True\n");
    }
    else
    {
        printf("Lengths (%5f, %5f, %5f) can not construct a triangle!\n", side[0], side[1], side[2]);
        return 1; // Exit.
    }


    // Classify triangle by sides.
    printf("%s\n", classify_side(side));


    // Classify triangle by angle.
    printf("%s\n", classify_angle(side));

}
