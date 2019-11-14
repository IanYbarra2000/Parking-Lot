/*
 * Floor.h
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*The purpose of the Floor class is to store several rows and be used by the
 * Lot class. It serves as a sort of middle point between the Row and Lot classes,
 * meaning that the Row class does most of the actual manipulation and finding
 * of things and the Lot class is where the main calls the methods to manipulate
 * the classes. All of the methods for Floor basically do the same thing. That thing is
 * iterating through the vector floor and calling row methods by the same
 * name.*/

#include<iostream>
#include<vector>
#include "Row.h"
#ifndef FLOOR_H_
#define FLOOR_H_
using namespace std;
class Floor {
public:
	vector<Row> floor;//stores all the rows on a floor
	void addRow(Row r);//adds a row to the floor
	bool parkBus();//iterates through rows and parks bus in the first available spot
	bool parkCar();//iterates through rows and parks car in the first available spot
	bool parkMotorcycle();//iterates through rows and parks motorcycle in the first available spot
	void print();//iterates through rows, calling their print methods
	bool spotsAvailable();//iterates through rows and returns true when the first available spot is found
	bool removeBus();//iterates through rows and removes first bus found
	bool removeCar();//iterates through rows and removes first car found
	bool removeMotorcycle();//iterates through rows and removes first motorcycle found
	bool checkCarParked();//iterates through rows and calls their methods of the same name until a car is found
	bool checkBusParked();//iterates through rows and calls their methods of the same name until a bus is found
	bool checkMotorcycleParked();//iterates through rows and calls their methods of the same name until a motorcycle is found
};

#endif /* FLOOR_H_ */
