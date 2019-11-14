/*
 * InputHelper.cpp
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*The main purpose of the InputHelper class is attain a valid
 *input and return it once it is receives the valid input. It
 *helps insure that strings that are strictly not numeric do
 *not cause the code to fail but instead loop and request a
 *valid input.*/

#include "InputHelper.h"

using namespace std;


int InputHelper::accountForString(string output){//This method helps account for string responses in places where one would expect integers
	string holder;//holds input until it is converted to an int
	int answer;//holds input once it is converted to an int
	while(true){
		cout <<output;//statement or question to request input
		cin>>holder;//input taken
		try{//try and catch is used here in case a string is entered
			answer=stoi(holder);
			if(answer>0)//if the input is valid it breaks out of the loop
				break;
			cout<<"Please enter a positive integer.\n";
		}
		catch(invalid_argument e){//if something other than numbers are entered it will go here and the loop will continue
			cout<<"Please enter an integer.\n";
			continue;
		}
	}
	return answer;//returns the int from the input
}
int InputHelper::accountForStringP(string output){//This method has almost the same function as accountForString except that it accepts 0 as an appropriate response.
	string holder;
	int answer;
	while(true){
		cout <<output;
		cin>>holder;
		try{
			answer=stoi(holder);
			if(answer>=0)
				break;
			cout<<"Please enter a non-negative integer.\n";
		}
		catch(invalid_argument e){
			cout<<"Please enter an integer.\n";
			continue;
		}
	}
	return answer;
}

