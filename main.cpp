/*
Statement of Purpose: Creates a LinkedBag of class Point called pointBag,
inputs coordinate points from a file to fill the pointBag, asks user for
a point to compare the distance to all the points in pointBag.
Input: Coordinate points from points.txt and one point from the user.
Output: The users point and the each distance from the users point
to the points in the pointBag.
*/

// File name: main.cpp

#include<iostream>
#include<fstream>
#include"point.h"
#include"LinkedBag.h"

using namespace std;

int main()
{
	ifstream in;
	int tempX{}, tempY{}; 
	LinkedBag<Point> pointBag;

	in.open("points.txt");

	if (!in)
	{
		cerr << "Error opening file.\n";
		return -1;
	} // end if

	// Have the user input an x and y to make a userPoint.
	cout << "Enter an x coordinate: ";
	cin >> tempX;
	cout << "\nEnter a y coordinate: ";
	cin >> tempY;
	cout << "\n\n";
	Point userPoint(tempX, tempY);

	// Input points from a file to add to pointBag
	Point tempPoint;
	in >> tempX >> tempY;
	while (!in.eof())
	{
		tempPoint.setX(tempX);
		tempPoint.setY(tempY);
		pointBag.add(tempPoint);
		in >> tempX >> tempY;
	} // end while


	// Output the distances from the userPoint to the points in
	// the pointBag through a new Point vector.
	vector<Point> pointVector = pointBag.toVector();
	cout << "The distance from your point: ";
	userPoint.display();
	cout << ", to the points in the bag are: \n";
	for (int i = 0; i < pointVector.size(); i++)
	{
		cout << "Point #" << i + 1 << " ";
		pointVector[i].display();
		cout << " Distance: " << userPoint.distance(pointVector[i]);
		cout << "\n";
	} // end for

	return 0;
} // end main