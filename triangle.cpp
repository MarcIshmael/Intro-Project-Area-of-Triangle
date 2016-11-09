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

/*
 * Data Abstraction:
 * 		Input file stream opened.
 *      6 variables declared to represent points.
 *      5 variables declared to handle area related calculations.
 * Input:
 * 		The program prompts user to input a file name.
 *      The program reads input from file as coordinates.
 * Process:
 * 		Check to make sure file is opened properly.
 *      Skips first line of file.
 *      Uses sideLength and areaOfTriangle functions to calculate
 *      areas of triangles using the given coordinates.
 * Output:
 * 		The coordinates for each triangle and its area are output.
 *      The min, max, and average areas are output.
 * Assumptions:
 * 		It is assumed that the user eventually enters a valid
 *      file name.
 *      It is assumed the file opened contains appropriate data
 *      to be used by the program.
 */
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double sideLength(double x1, double y1, double x2, double y2)
{
    double length = 0;
    double a, b;
    a = abs((x1 * 1.0) - x2) * abs((x1 * 1.0)- x2);
    b = abs((y1 * 1.0) - y2) * abs((y1 * 1.0)- y2);
    length = sqrt(a + b);

    return length;
}

double areaOfTriangle(double a, double b, double c)
{
    double area = 0;
    double perim = (a + b + c) / 2;
    area = sqrt(perim*(perim-a)*(perim-b)*(perim-c));

    return area;
}
