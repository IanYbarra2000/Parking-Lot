/*
 * InputHelper.h
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*The main purpose of the InputHelper class is attain a valid
 *input and return it once it is receives the valid input. It
 *helps insure that strings that are strictly not numeric do
 *not cause the code to fail but instead loop and request a
 *valid input.*/

#ifndef INPUTHELPER_H_
#define INPUTHELPER_H_
#include<string>
#include<iostream>
using namespace std;

class InputHelper {
public:
	int accountForString(string output);//This method helps account for string responses in places where one would expect integers
	int accountForStringP(string output);//This method has almost the same function as accountForString except that it accepts 0 as an appropriate response. It's name includes the P because it is meant to help with the percentage inputs.
};



#endif /* INPUTHELPER_H_ */
