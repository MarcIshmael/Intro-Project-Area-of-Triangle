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
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

double sideLength(double x1, double y1, double x2, double y2);
double areaOfTriangle(double a, double b, double c);

int main()
{
    /*Data Abstraction*/
    ifstream inputFile;
    string fileName;
    double x1, y1, x2, y2, x3, y3;
    double area, counter = 0.0, maxArea = 0.0, minArea = 0.0, avgArea = 0.0;

    /*Input*/
    //Gets name of data file from user
    cout << "Enter Name Of Data File: ";
    getline(cin, fileName);
    cout << fileName << endl;

    inputFile.open(fileName.c_str());

    /*Process and Output*/
    //Test to see if file opened
    if (inputFile.fail())
    {
        cout << "ERROR: File Not Open." << endl;
        do
        {
            inputFile.close();
            cout << "Enter Name Of Data File: ";
            getline(cin, fileName);
            cout << fileName << endl;
            inputFile.open(fileName.c_str());
        } while (inputFile.fail());
    }

    //Skips first line of file
    getline(inputFile, fileName);

    //Assigns data from file to variables
    while(inputFile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        double a, b, c;
        //Initializes a, b, and c as side lengths for use
        //in area calculation
        a = sideLength(x1, y1, x2, y2);
        b = sideLength(x2, y2, x3, y3);
        c = sideLength(x3, y3, x1, y1);
        //Initializes area using areaOfTriangle function
        area = areaOfTriangle(a, b, c);
        //Outputs coordinates and area of each triangle
        cout << fixed << setprecision(2) <<
        "( " << x1 << ", " << y1 << ") "
        << "( " << x2 << ", " << y2 << ") " <<
        "( " << x3 << ", " << y3 << ")   area = " <<
        area << endl;
        //Adds one for counter needed for avgArea
        counter++;
        //Handles check for min and max area
        if (area > maxArea)
        {
            maxArea = area;
        }
        if(minArea == 0)
        {
            minArea = maxArea;
        }
        if (area <= minArea)
        {
            minArea = area;
        }
        //Adds area to total for later calculation of average
        avgArea += area;
    }

    //Self-explainitory just read it out loud
    cout << "Maximum area = " << maxArea << endl;
    cout << "Minimum area = " << minArea << endl;
    cout << "Average area = " << avgArea/counter << endl;

    return 0;
}
