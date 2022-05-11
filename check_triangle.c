// This module will check if the user input of 
// triangle side lengths can construct a valid triangle.
#include "check_triangle.h"

const float ACCURACY = 0.0000000001;
float *get_sides() 
    {
        // Prompt the user for the lengths returning them in an array.
        // Declare variables
        const int X = 3; //  For triangle
        static float length[X]; // Array should be static to be able to return its address value outside the function.

        // Prompt user for input
        for (int i = 0; i < X; i++)
        {
            do
            {
                length[i] = get_float("Enter a positive number for the length of side %i of the triangle\n", i+1);

                // Check that the input is positive 
            } while (length[i] <= 0);
        }
        return length;
    }




bool check_triangle(float *side)
{
    // check triangle condition if any any two lengths is greater than the third.
    if ((side[0]+side[1]) > side[2] && 
        (side[0]+side[2]) > side[1] && 
        (side[1]+side[2]) > side[0])
    {
        return true;        
    }
    else
    {
        return false;
    }
}



const char* classify_side(float *side)
{
    // TODO
    if ((side[0] == side[1]) && (side[1] == side[2]))
    {
        return "Equilateral Triangle";
    }

    else if ((side[0] == side[1]) || (side[1] == side[2]) || side[0] == side[2])
    {
       return "Isosceles Triangle";
    }
    return "Scalene Triangle";
}


const char* classify_angle(float *side)
{
    // Test if the triangle whether is Acute angle, Right-angled Triangle, Obtuse-angled Triangle or Equiangular Triangle
    // Get angles using the law of cosines.
    float cos_alpha = cos_angle(side[0], side[1], side[2]);
    float cos_beta = cos_angle(side[1], side[2], side[0]);
    float cos_gamma = cos_angle(side[0], side[2], side[1]);




    // If the cosine of all angles are equal then it equiangular triangle.
    if ((cos_alpha == cos_beta) &&
        (cos_alpha == cos_gamma) &&
        (cos_beta == cos_gamma))

    {
        return "Equiangular Triangle";
    }

    // If cosine any angle is less than ACCURACY (0) then it is right-handed triangle.
    else if ((fabs(cos_alpha) < ACCURACY) ||  // Using fabs from math.h to get the absolute of float number.
            (fabs(cos_beta) < ACCURACY) ||
            (fabs(cos_gamma) < ACCURACY))
    {
       return "Right-angled Triangle";
    }

    // IF cosine of any angle is obtuse.
   else if (check_obtuse(cos_alpha) ||
        check_obtuse(cos_alpha) ||
        check_obtuse(cos_gamma))
   {
       return "Obtuse Triangle";
   } 
   else
   {
       return "Acute Triangle";
   }

    return 0;
}


float square(float x)
{
    return x * x;
}

float cos_angle(float nearby_side1, float nearby_side2, float opposite_site)
{
    return (square(nearby_side1) + square(nearby_side2) - square(opposite_site)) / 2 * (nearby_side1 * nearby_side2);
}

bool check_obtuse(float x)
// Check angle to be between 90 and 180 by checking 
// if the cosine of the angle is greater than -1 and more than 0 
{
    if (x+1 > ACCURACY &&
        x < ACCURACY)
        {
            return true;
        }
    return false;
}