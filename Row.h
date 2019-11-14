/*
 * Row.h
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*The Row class has the most complex methods out of all of the
 *classes that make up the parking lot. The manipulation of
 *the parking lot, things like parking vehicles and removing
 *them, are actually inacted within this class. It is the
 *second most basic component of the Lot structure.*/

#ifndef ROW_H_
#define ROW_H_
#include<iostream>
#include<vector>
#include "Spot.h"
using namespace std;
class Row {
public:

	vector<Spot> row;
	void addSpot(char c);//This creates a new spot object and assigns the character c to the spot's type and the type of vehicle in the spot
	void clear();//erases all the values stored in the vector row
	bool parkBus();//parks a bus in the row
	bool parkCar();//parks a car in the row
	bool parkMotorcycle();//parks a motorcycle in the row
	void print();//outputs the entire row
	bool spotsAvailable();//checks if there are any spots without vehicles in them
	bool removeBus();//iterates through the row until it finds a spot with a bus in it then removes the bus from all the spots it takes up
	bool removeCar();//iterates through the row until it finds a spot with a car in it then it removes said car
	bool removeMotorcycle();//iterates through the row until it finds a spot with a motorcycle in it then it removes said motorcycle
	bool checkCarParked();//iterates through the row until it finds a spot with a car in it and then returns true if one is found and false if not
	bool checkBusParked();//iterates through the row until it finds a spot with a bus in it and then returns true if one is found and false if not
	bool checkMotorcycleParked();//iterates through the row until it finds a spot with a motorcycle in it and then returns true if one is found and false if not
};

#endif /* ROW_H_ */
