#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Grid.hpp"
#include <string>
#include <iostream>

class Display {
	public:
		Display(std::string);
		/*Fill Map from an external file
		string input is the name of the external file
		Command is set to ""*/

		Grid getMap(int i, int j);

		bool checkLand(int i, int j, int type);
		/*Check Land or not*/
	
		bool checkFacility(int i, int j, int type);
		/*Check Facility*/
	
		bool checkGrassy(int i, int j);
		/*Check Grassy*/
	
		bool checkUsedTruck(int i, int j);
		/*Check UsedTruck*/
	
		void modifyGrassy(int i, int j);
		/*modify Grassy*/
	
		void modifyUsedTruck(int i, int j);
		/*mengubah nilai usedTruck saat dilakukan pemakain*/

		void lessenTruck();
		/*Mengurangi nilai variabel UsedTruck jika nilai UsedTruck > 0*/

  private:
		Grid **Map; /*From external file */
		int iTruck; /*Truck position*/
		int jTruck; /*Truck position*/
};

#endif
