#ifndef GRID_HPP
#define GRID_HPP

class Grid {
	public :
		//Getter and setter
		int getType();
		bool getGrassy();

		int setType();
		bool setGrassy();

    private:
        int Type;       // 1. Grassland, 2. Barn, 3. Coop, 0. Facility
        bool Grassy;    // for non-Facility grids

};
#endif
