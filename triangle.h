/*
* Author: Marc Ishmael
* Assignment Title: Program 15
* Assignment Description: This program reads data points from
* a file, and returns information of the areas of the triangles
* formed by the points.
* Due Date: 10/17/2016
* Date Created: 10/17/2016
* Date Last Modified: 10/17/2016
*/
#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
/*
 * description: calculate side length given two points
 * return: double
 * precondition: two valid points given
 * postcondition: returns side length resulting from points
 *
*/
double sideLength(double x1, double y1, double x2, double y2);

/*
 * description: calculate area of a triangle
 * return: double
 * precondition: three valid side lengths given
 * postcondition: returns area of triangle that results
 * from given side lengths
 *
*/
double areaOfTriangle(double a, double b, double c);

#endif // MYFUNCTIONS_H_INCLUDED
