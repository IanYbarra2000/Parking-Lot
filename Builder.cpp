/*
 * Builder.cpp
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*The purpose of the Builder class is mainly to do most of
 *the iteration required to build the Lot. This helped to
 *the declutter the main method and make the main easier to
 *the understand.*/

#include "Builder.h"


Floor Builder:: BuildFloor(int spotsPerLevel, int PL,int PM, int spotsPerRow){//takes parameters and builds a floor and returns it
	vector<char> spotsOnFloor;//char array to store all the spots on a floor before they are separated into rows
	for(int x=0;x<spotsPerLevel;x++){
		if(x<spotsPerLevel*PL/100){//this ensures the first spots will be the large spots and that the number of spots will correspond with the percentage the user chose
			spotsOnFloor.insert(spotsOnFloor.begin(),'l');
		}
		else if(x>=spotsPerLevel*PL/100&&x<(spotsPerLevel*PL/100)+(spotsPerLevel*PM/100)){//this ensures that the next spots will be the motor cycle spots and that the number of spots will correspond with the percentage the user chose
			spotsOnFloor.insert(spotsOnFloor.begin(),'m');
		}
		else{//this ensures that all other spots will be compact spots
			spotsOnFloor.insert(spotsOnFloor.begin(),'c');
		}
	}
	//distributes all of the values in spotsOnFloor across
	//all of the rows on a floor and then adds each row to said floor
	Row r1;
	Floor f1;
	int rowPerLevel=spotsPerLevel/spotsPerRow;
	int pos=0;
	for(int x=0;x<rowPerLevel;x++){//This section uses nested for loops to divide spotsOnFloor into rows of equal size and then adds said rows to a floor
		for(int i=0;i<spotsPerRow;i++){
			r1.addSpot(spotsOnFloor.at(pos));
			pos++;
		}
		f1.addRow(r1);
		r1.clear();//clears row for the next iteration

	}
	return f1;//returns floor
}
Lot Builder::BuildLot(int levels, Floor f){//takes a floor and number of levels and adds that number of floors to a lot and returns said lot
	Lot l1;
	for(int x=0;x<levels;x++){
		l1.addFloor(f);
	}
	return l1;
}
