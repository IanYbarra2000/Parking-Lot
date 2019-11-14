/*
 * Lot.h
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*The purpose of the Lot class is to store all of the different parts of the parking lot,
 * and it should also serve as the point where you call methods to manipulate and find out
 * information about the parking lot. All of the methods for Lot basically do the same thing.
 * That thing is iterating through the vector lot and calling floor methods by the same name.*/

#include<iostream>
#include<vector>
#include "Row.h"
#include "Floor.h"
#ifndef LOT_H_
#define LOT_H_
using namespace std;

class Lot {
public:
	vector<Floor> lot;//stores all of the floors in the lot
	void addFloor(Floor f);//adds floor f to the lot
	bool parkBus();//iterates through floors and parks bus in the first available spot
	bool parkCar();//iterates through floors and parks car in the first available spot
	bool parkMotorcycle();//iterates through floors and parks motorcycle in the first available spot
	void print();//iterates through floors, calling their print methods
	bool spotsAvailable();//iterates through floors and returns true when the first available spot is found
	bool removeBus();//iterates through floors and removes first bus found
	bool removeCar();//iterates through floors and removes first car found
	bool removeMotorcycle();//iterates through floors and removes first motorcycle found
	bool checkCarParked();//iterates through floors and calls their methods of the same name until a car is found
	bool checkBusParked();//iterates through floors and calls their methods of the same name until a bus is found
	bool checkMotorcycleParked();//iterates through floors and calls their methods of the same name until a motorcycle is found

};

#endif /* LOT_H_ */
