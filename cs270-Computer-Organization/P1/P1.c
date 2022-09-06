// P1 Assignment
// Author: Brock Fisher
// Date:   5/18/2021
// Class:  CS270
// Email:  Brock.Fisher@colostate.edu

// Include files
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// example of a global array
double input[4];
double output[4];

void computeCircle(double radius, double *addressOfCircleArea)
{
    // Compute Area
    double result = radius * radius * 3.141593;

    // Dereference pointer to return result
    *addressOfCircleArea = result;
}
void computeTriangle(double side, double *addressOfTriangleArea)
{
    // Compute Area
    double result = 0.433013 * side * side;

    // Dereference pointer to return result
    *addressOfTriangleArea = result;
}
void computeSquare(double side, double *addressOfSquareArea)
{
    // Compute Area
    double result = side * side;

    // Dereference pointer to return result
    *addressOfSquareArea = result;
}
void computePentagon(double side, double *addressOfPentagonArea)
{
    // Compute Area
    double result = 1.720477 * side * side;

    // Dereference pointer to return result
    *addressOfPentagonArea = result;
}
int main(int argc, char *argv[])
{
    // Check number of arguments
    if (argc != 5) {
        printf("usage: ./P1 <double> <double> <double> <double>\n");
        return EXIT_FAILURE;
    }
    else {
        // Parse arguments
	input[0] = atof(argv[1]);
	input[1] = atof(argv[2]);
	input[2] = atof(argv[3]);
	input[3] = atof(argv[4]);
    }

    // Call function
    computeCircle(input[0], &output[0]);
    computeTriangle(input[1], &output[1]);
    computeSquare(input[2], &output[2]);
    computePentagon(input[3], &output[3]);
    
    // Print area
    printf("CIRCLE, radius = %.5f, area = %.5f.\n", input[0], output[0]);
    printf("TRIANGLE, length = %.5f, area = %.5f.\n", input[1], output[1]);
    printf("SQUARE, length = %.5f, area = %.5f.\n", input[2], output[2]);
    printf("PENTAGON, length = %.5f, area = %.5f.\n", input[3], output[3]);
    // Return success
    return EXIT_SUCCESS;
}
