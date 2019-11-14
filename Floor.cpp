/*
 * Floor.cpp
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

#include "Floor.h"
#include<iostream>
#include<vector>
using namespace std;

void Floor:: addRow(Row r){//adds a row to the floor
	floor.insert(floor.begin(),r);
}
bool Floor:: parkBus(){//iterates through rows and parks bus in the first available spot
	for(int x=0;x<floor.size();x++){
		if(floor[x].parkBus()){
			return true;
		}
	}
	return false;
}
bool Floor:: parkCar(){//iterates through rows and parks car in the first available spot
	for(int x=0;x<floor.size();x++){
		if(floor[x].parkCar()){
			return true;
		}
	}
	return false;
}
bool Floor:: parkMotorcycle(){//iterates through rows and parks motorcycle in the first available spot
	for(int x=0;x<floor.size();x++){
		if(floor[x].parkMotorcycle()){
			return true;
		}
	}
	return false;
}
void Floor:: print(){//iterates through rows, calling their print methods
	for(int x=0;x<floor.size();x++){
		floor[x].print();
		cout<<' ';
	}
}
bool Floor::spotsAvailable(){//iterates through rows and returns true when the first available spot is found
	for(int x=0;x<floor.size();x++){
		if(floor[x].spotsAvailable()){
			return true;
		}
	}
	return false;
}
bool Floor:: removeBus(){//iterates through rows and removes first bus found
	for(int x=0;x<floor.size();x++){
		if(floor[x].removeBus()){
			return true;
		}
	}
	return false;
}
bool Floor:: removeCar(){//iterates through rows and removes first car found
	for(int x=0;x<floor.size();x++){
		if(floor[x].removeCar()){
			return true;
		}
	}
	return false;
}
bool Floor:: removeMotorcycle(){//iterates through rows and removes first motorcycle found
	for(int x=0;x<floor.size();x++){
		if(floor[x].removeMotorcycle()){
			return true;
		}
	}
	return false;
}
bool Floor:: checkCarParked(){//iterates through rows and calls their methods of the same name until a car is found
	for(int x=0;x<floor.size();x++){
		if(floor[x].checkCarParked()){
			return true;
		}
	}
	return false;
}
bool Floor:: checkBusParked(){//iterates through rows and calls their methods of the same name until a bus is found
	for(int x=0;x<floor.size();x++){
		if(floor[x].checkBusParked()){
			return true;
		}
	}
	return false;
}
bool Floor:: checkMotorcycleParked(){//iterates through rows and calls their methods of the same name until a motorcycle is found
	for(int x=0;x<floor.size();x++){
		if(floor[x].checkMotorcycleParked()){
			return true;
		}
	}
	return false;
}

