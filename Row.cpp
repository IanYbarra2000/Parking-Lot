/*
 * Row.cpp
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*The Row class has the most complex methods out of all of the
 *classes that make up the parking lot. The manipulation of
 *the parking lot, things like parking vehicles and removing
 *them, are actually inacted within this class. It is the
 *second most basic component of the Lot structure.*/

#include "Row.h"
#include<vector>
#include<iostream>
using namespace std;


void Row::addSpot(char c){//This creates a new spot object and assigns the character c to the spot's type and the type of vehicle in the spot
	Spot temp;
	temp.spotType=c;//keeps track of spot type seperate from the vehicle in spot for use in the remove methods
	temp.vehicleInSpot=c;
	row.insert(row.begin(),temp);
}
void Row::clear(){//erases all the values stored in the vector row
	row.clear();
}
bool Row:: parkBus(){//parks a bus in the row
	if(row.size()<5)
		return false;
	for(int x=0;x<row.size()-4;x++){//uses loop to iterate through every value in the row except for the last four
		if(row[x].vehicleInSpot=='l'&&row[x+1].vehicleInSpot=='l'&&row[x+2].vehicleInSpot=='l'&&row[x+3].vehicleInSpot=='l'&&row[x+4].vehicleInSpot=='l'){//detects if the next 5 spots are large
			row[x].vehicleInSpot='B';//parks bus in next 5 spots
			row[x+1].vehicleInSpot='B';
			row[x+2].vehicleInSpot='B';
			row[x+3].vehicleInSpot='B';
			row[x+4].vehicleInSpot='B';
			return true;//when the vehicle is successfully parked the method ends with it returning true
		}
	}
	return false;
}
bool Row:: parkCar(){//parks a car in the row
	for(int x=0;x<row.size();x++){//uses loop to iterate through every value in row
		if(row[x].vehicleInSpot=='c'||row[x].vehicleInSpot=='l'){//checks if the current spot can be parked in by this vehicle
			row[x].vehicleInSpot='C';
			return true;//when the vehicle is successfully parked the method ends with it returning true
		}
	}
	return false;
}
bool Row:: parkMotorcycle(){//parks a motorcycle in the row
	for(int x=0;x<row.size();x++){//uses loop to iterate through every value in row
		if(row[x].vehicleInSpot=='c'||row[x].vehicleInSpot=='l'||row[x].vehicleInSpot=='m'){//checks if the current spot can be parked in by this vehicle
			row[x].vehicleInSpot='M';
			return true;//when the vehicle is successfully parked the method ends with it returning true
		}
	}
	return false;
}
void Row:: print(){//outputs the entire row
	for(int x=0;x<row.size();x++){//uses loop to iterate through every value in row
		cout<<row[x].vehicleInSpot;
	}
}
bool Row:: spotsAvailable(){//checks if there are any spots without vehicles in them
	for(int x=0;x<row.size();x++){//uses loop to iterate through every value in row
		if(row[x].vehicleInSpot=='l'||row[x].vehicleInSpot=='c'||row[x].vehicleInSpot=='m'){//checks if spots don't have vehicles in them
			return true;//ends search when one is found with the return true
		}
	}
	return false;
}
bool Row:: removeBus(){//iterates through the row until it finds a spot with a bus in it then removes the bus from all the spots it takes up
	for(int x=0;x<row.size()-4;x++){//uses loop to iterate through every value in the row except for the last four
		if(row[x].vehicleInSpot=='B'&&row[x+1].vehicleInSpot=='B'&&row[x+1].vehicleInSpot=='B'&&row[x+2].vehicleInSpot=='B'&&row[x+3].vehicleInSpot=='B'){
			row[x].vehicleInSpot='l';//when the bus is found, all the spots it took up are changed to large spots because that is the only type of space it could park in
			row[x+1].vehicleInSpot='l';
			row[x+2].vehicleInSpot='l';
			row[x+3].vehicleInSpot='l';
			row[x+4].vehicleInSpot='l';
			return true;//when the vehicle is successfully removed the method ends with it returning true
		}
	}
	return false;

}
bool Row:: removeCar(){//iterates through the row until it finds a spot with a car in it then it removes said car
	for(int x=0;x<row.size();x++){//uses loop to iterate through every value in row
		if(row[x].vehicleInSpot=='C'){
			row[x].vehicleInSpot=row[x].spotType;
			return true;//when the vehicle is successfully removed the method ends with it returning true
		}
	}
	return false;
}
bool Row:: removeMotorcycle(){//iterates through the row until it finds a spot with a motorcycle in it then it removes said motorcycle
	for(int x=0;x<row.size();x++){//uses loop to iterate through every value in row
		if(row[x].vehicleInSpot=='M'){
			row[x].vehicleInSpot=row[x].spotType;
			return true;//when the vehicle is successfully removed the method ends with it returning true
		}
	}
	return false;
}
bool Row:: checkCarParked(){//iterates through the row until it finds a spot with a car in it and then returns true if one is found and false if not
	for(int x=0;x<row.size();x++){//uses loop to iterate through every value in row
		if(row[x].vehicleInSpot=='C'){
			return true;//when vehicle is successfully found, the method ends with a return true
		}
	}
	return false;
}
bool Row:: checkBusParked(){//iterates through the row until it finds a spot with a bus in it and then returns true if one is found and false if not
	for(int x=0;x<row.size();x++){//uses loop to iterate through every value in row
		if(row[x].vehicleInSpot=='B'){
			return true;//when vehicle is successfully found, the method ends with a return true
		}
	}
	return false;
}
bool Row:: checkMotorcycleParked(){//iterates through the row until it finds a spot with a motorcycle in it and then returns true if one is found and false if not
	for(int x=0;x<row.size();x++){//uses loop to iterate through every value in row
		if(row[x].vehicleInSpot=='M'){
			return true;//when vehicle is successfully found, the method ends with a return true
		}
	}
	return false;
}

