/*
 * Lot.cpp
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
#include "Lot.h"
using namespace std;

void Lot:: addFloor(Floor f){//adds floor f to the lot
	lot.insert(lot.begin(),f);
	//sLot.insert(lot.begin(),f);
}
bool Lot:: parkBus(){//iterates through floors and parks bus in the first available spot
	for(int x=0;x<lot.size();x++){
		if(lot[x].parkBus()){
			return true;
		}
	}
	return false;
}
bool Lot:: parkCar(){//iterates through floors and parks car in the first available spot
	for(int x=0;x<lot.size();x++){
		if(lot[x].parkCar()){
			return true;
		}
	}
	return false;
}
bool Lot:: parkMotorcycle(){//iterates through floors and parks motorcycle in the first available spot
	for(int x=0;x<lot.size();x++){
		if(lot[x].parkMotorcycle()){
			return true;
		}
	}
	return false;
}
void Lot:: print(){//iterates through floors, calling their print methods
	for(int x=0;x<lot.size();x++){
		cout<< "level";
		cout<<x;
		cout<<": ";
		lot[x].print();
		cout<<"\n";
	}
}
bool Lot:: spotsAvailable(){//iterates through floors and returns true when the first available spot is found
	for(int x=0;x<lot.size();x++){
		if(lot[x].spotsAvailable()){
			return true;
		}
	}
	return false;
}
bool Lot:: removeBus(){//iterates through floors and removes first bus found
	for(int x=0;x<lot.size();x++){
		if(lot[x].removeBus()){
			return true;
		}
	}
	return false;
}
bool Lot:: removeCar(){//iterates through floors and removes first car found
	for(int x=0;x<lot.size();x++){
		if(lot[x].removeCar()){
			return true;
		}
	}
	return false;
}
bool Lot:: removeMotorcycle(){//iterates through floors and removes first motorcycle found
	for(int x=0;x<lot.size();x++){
		if(lot[x].removeMotorcycle()){
			return true;
		}
	}
	return false;
}
bool Lot:: checkCarParked(){//iterates through floors and calls their methods of the same name until a car is found
	for(int x=0;x<lot.size();x++){
		if(lot[x].checkCarParked()){
			return true;
		}
	}
	return false;
}
bool Lot:: checkBusParked(){//iterates through floors and calls their methods of the same name until a bus is found
	for(int x=0;x<lot.size();x++){
		if(lot[x].checkBusParked()){
			return true;
		}
	}
	return false;
}
bool Lot:: checkMotorcycleParked(){//iterates through floors and calls their methods of the same name until a motorcycle is found
	for(int x=0;x<lot.size();x++){
		if(lot[x].checkMotorcycleParked()){
			return true;
		}
	}
	return false;
}
