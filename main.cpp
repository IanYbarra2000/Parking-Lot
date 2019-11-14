/*
 * main.cpp
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*To run this project, open it in eclipse and run the
 *project. As the console prompts, give appropriate
 *inputs to build the parking lot, and then park and
 *remove vehicles from it.*/

#include <iostream>
#include <string>
#include <vector>
#include "Row.h"
#include "Floor.h"
#include "Lot.h"
#include "InputHelper.h"
#include "Builder.h"
using namespace std;

int main(){
	int NUM_OF_LEVELS=0;//integer storing the number of levels in the lot
	int SPOTS_PER_LEVEL=0;//integer storing the number of spots on each level of the lot
	int SPOTS_PER_ROW=0;//integer storing the number of spots in each row
	int PERCENT_LARGE=0;//integer storing the percentage of the spots that should be large
	int PERCENT_MOTORCYCLE=0;//integer storing the percentage of the spots that should be for motorcycles


	Row row;//an object row to store the rows while the floor is being built
	Floor floor;//a floor object to store the floor while the lot is being built
	Lot Lot;//an object to store the entire lot


	InputHelper help;//object of InputHelper class helps deal with unexpected inputs such as alphabetic characters
	NUM_OF_LEVELS=help.accountForString("How many levels? (please give answer in the form of an integer)\n");//uses method from InputHelper class to assign integer
	SPOTS_PER_LEVEL=help.accountForString("How many spots per level? (please give answer in the form of an integer)\n");//uses method from InputHelper class to assign integer
	SPOTS_PER_ROW=help.accountForString("How many spots per row? (Please give answer in the form of an integer)\n");//uses method from InputHelper class to assign integer
	while(SPOTS_PER_LEVEL%SPOTS_PER_ROW!=0){//The while loop helps to ensure that the number of spots on every level is divisible by the number of spots per row.
		cout<<"The number of spots per level is not divisible by the number of spots per row.\nPlease choose a new number of spots per row.\n";
		SPOTS_PER_ROW=help.accountForString("How many spots per row? (please give answer in the form of an integer)\n");
	}
	PERCENT_LARGE=help.accountForStringP("What percentage of the spots are large? (Please give answer in the form of an integer)\n");//uses method from InputHelper class to assign integer
	while(PERCENT_LARGE>100){//uses while loop to ensure that the user does not create an impossible situation in which the number of large spots exceeds the total number of spots
		cout<< "The percentage of the spots that are large exceeds 100.\nPlease choose a new percentage.\n";
		PERCENT_LARGE=help.accountForStringP("What percentage of the spots are large? (Please give answer in the form of an integer)\n");
	}
	PERCENT_MOTORCYCLE=help.accountForStringP("What percentage of the spots are Motorcycle spots? (please give answer in the form of an integer)\n");//uses method from InputHelper class to assign integer
	while(PERCENT_LARGE+PERCENT_MOTORCYCLE>100){//uses while loop to ensure that the user does not create an impossible situation in which the number of large spots and the number of motorcycle spots exceed the total number of spots
		cout<<"The sum of the percent of spots that are large and the percent of spots that are for Motorcycles exceeds 100.\nPlease choose a new percentage of Motorcycle spots.\n";
		PERCENT_MOTORCYCLE=help.accountForStringP("What percentage of the spots are Motorcycle spots? (please give answer in the form of an integer)\n");
	}

	Builder build;//creates object of class build to help build the lot
	floor=build.BuildFloor(SPOTS_PER_LEVEL, PERCENT_LARGE, PERCENT_MOTORCYCLE, SPOTS_PER_ROW);//builds a floor using the values previously inputed
	Lot=build.BuildLot(NUM_OF_LEVELS, floor);//uses previously built floor to build the lot
	Lot.print();//displays entire lot

	/*This whole next section is basically divided into layers depending on which level of input the user is on. Each level gets more specific than the next.
	 So there is a layer where the user is asked if they want to park a car or remove one. If they choose remove, they move on to the layer in which the user
	 selects which type of vehicle they would like to remove. That is just one chain of layers, there are others depending on which selections the user makes.*/
	while(true){//loop iterates until a break is called
		string vehicle;//holds the vehicle choice of the user
		string choice;//holds the choice of whether the user would like to park, remove, or exit
		while(choice!="remove"&&choice!="park"){//this loop iterates until the string choice is either "remove" or "park" when it reaches the end of an iteration.
			cout<<"Would you like to park, remove, or exit?\n";
			cin>>choice;//user inputs their choice
			if(choice=="remove"&&(Lot.checkBusParked()||Lot.checkCarParked()||Lot.checkMotorcycleParked())){//checks if user's choice was "remove" and if there are any cars parked to be removed
				while(vehicle!="Car"&&vehicle!="Bus"&&vehicle!="Motorcycle"){//This loop iterates until the user makes a valid selection
					cout<< "What type of vehicle should be removed? (Car, Bus, or Motorcycle)\n";
					cin>>vehicle;//user inputs their choice of vehicle type
					if(vehicle!="Car"&&vehicle!="Bus"&&vehicle!="Motorcycle"){//detects if the user input is invalid and if so it prompts the user to chose a valid input
						cout<<"Choose a valid vehicle type.\n";
						vehicle="";
					}
					else if(vehicle=="Car"){//checks if the user selected car
						if(!Lot.removeCar()){//calls remove car. If a car is found the method returns true and the car is removed. If a car is not found, the method, removeCar(), returns false and goes through the if statement.
							cout<<"There are no Cars to remove.\n";
						}
						else
							Lot.print();//prints entire lot for user to see
					}
					else if(vehicle=="Bus"){//checks if the user selected bus
						if(!Lot.removeBus()){//calls remove bus. If a bus is found the method returns true and the bus is removed. If a bus is not found, the method,removeBus(), returns false and goes through the if statement.
							cout<<"There are no Buses to remove.\n";
						}
						else
							Lot.print();//prints entire lot for user to see
					}
					else if(vehicle=="Motorcycle"){//checks if the user selected motorcycle
						if(!Lot.removeMotorcycle()){//calls remove motorcycle. If a motorcycle is found the method returns true and the motorcycle is removed. If a Motorcycle is not found, the method, removeMotorcycle(), returns false and goes through the if statement.
							cout<<"There are no Motorcycles to remove.\n";
						}
						else
							Lot.print();//prints entire lot for user to see
					}
				}
			}
			else if(choice=="remove"&&!(Lot.checkBusParked()||Lot.checkCarParked()||Lot.checkMotorcycleParked())){//This if statement is checking if the user selected remove, but there are no vehicles in the lot.
				cout<<"There are no vehicles to remove.\n";
				choice="";
			}
			else if(choice=="park"){//This if statement is checking if the user chose to park a car
				//build.chooseVehicleP(vehicle, Lot);
				while(vehicle!="Motorcycle"&&vehicle!="Car"&&vehicle!="Bus"){//this loop iterates until a valid selection is made by the user
					cout<<"Park which type of vehicle? (Car, Bus, or Motorcycle)\n";
					cin>>vehicle;//the user inputs their selection
					if(vehicle!="Motorcycle"&&vehicle!="Car"&&vehicle!="Bus"){//This checks if the users selection is valid. If it is not valid, the user is told to make a valid selection.
						cout<<"Choose a valid vehicle type.\n";
					}
				}
				if(vehicle=="Motorcycle"){//checks if user selected Motorcycle to park
					if(!Lot.parkMotorcycle()){//This calls method to park a Motorcycle. If there is no spot to park a Motorcycle in and it is unable to park, the method returns false and tells the user that the vehicle could not be parked. If the vehicle can be parked, the vehicle is then parked and the method returns true.
						cout<<"There are no spaces available for Motorcycles.\n";
					}
				}
				else if(vehicle=="Car"){//checks if user selected car to park
					if(!Lot.parkCar()){//This calls method to park a car. If there is no spot to park a car in and it is unable to park, the method returns false and tells the user that the vehicle could not be parked. If the vehicle can be parked, the vehicle is then parked and the method returns true.
						cout<<"There are no spaces available for Cars.\n";
					}
				}
				else if(vehicle=="Bus"){//checks if user selected bus to park
					if(!Lot.parkBus()){//This calls method to park a bus. If there is no spot to park a bus in and it is unable to park, the method returns false and tells the user that the vehicle could not be parked. If the vehicle can be parked, the vehicle is then parked and the method returns true.
						cout<<"There are no spaces available for Buses.\n";
					}
				}
				Lot.print();//prints entire lot for user to see
			}
			else if(choice=="exit"){//if the user chooses exit, a break is called to exit from this loop.
				break;
			}
		}
		if(choice=="exit"){//If the user chooses exit, a break is called to exit from this loop, ending the code.
			break;
		}
	}
}
