/*
 * Builder.h
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*The purpose of the Builder class is mainly to do most of
 *the iteration required to build the Lot. This helped to
 *the declutter the main method and make the main easier to
 *the understand.*/

#include "Spot.h"
#include "Row.h"
#include "Floor.h"
#include "Lot.h"
#include<vector>
#ifndef BUILDER_H_
#define BUILDER_H_

class Builder {
public:

	Floor BuildFloor(int spotsPerLevel, int PL,int PM, int spotsPerRow);//takes parameters and builds a floor and returns it
	Lot BuildLot(int levels, Floor f);//takes a floor and number of levels and adds that number of floors to a lot and returns said lot

};

#endif /* BUILDER_H_ */
