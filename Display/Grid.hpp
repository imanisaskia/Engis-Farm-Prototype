#ifndef GRID_HPP
#define GRID_HPP

class Grid {
	public :
		//Getter and setter
		int getType();
		bool getGrassy();
		bool getLand();
		bool getFacility();
		int getUsedTruck();

		void setType(int T);
		void setGrassy(bool G);
		void setLand(bool L);
		void setFacility(bool F);
		void setUsedTruck(int UT);

		//Mengurangi nilai variabel UsedTruck jika nilai UsedTruck > 0
		void lessenTruck();

		//Menambah nilai variabel UsedTruck saat Truck dipakai
		bool useTruck();

    private:
			bool Land; //bernilai True jika petak merupakan Land
			bool Facility; //bernilai True jika petak merupakan Facility
      		int Type;       // Jika Land , maka artinya : 1. Grassland, 2. Barn, 3. Coop
							// Jika Facility, maka artinya : 1. Well, 2. Mixer, 3. Truck
      		bool Grassy;    // for non-Facility grids
			int UsedTruck; // for Facility dengan type Truck, Truck dapat dipakai jika bernial > 0
};
#endif
