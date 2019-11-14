/*
 * Spot.h
 *
 *  	Class: CS2336.001
 *      Author: Ian Ybarra
 */

/*The spot class serves as the most basic component of
 *the Lot structure. It merely holds two public character
 *values, one holding the type of spot it is and the other
 *holding the type of vehicle in the spot currently.
 *If there is no vehicle in the spot currently, the
 *If vehicleInSpot character stores the type of spot present.*/

#ifndef SPOT_H_
#define SPOT_H_

using namespace std;

class Spot {
public:
	Spot();
	char spotType;//holds the type of spot for use in remove methods
	char vehicleInSpot;//holds the current displayed character
};
#endif /* SPOT_H_ */
