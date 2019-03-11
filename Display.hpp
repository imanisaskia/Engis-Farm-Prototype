#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

class Display {
    private:
        Grid Map[100][100]; // size? design? external file or hardcoded?
        string Command;     // user input
    
};

class Grid {
    private:
        int Type;       // 1. Grassland, 2. Barn, 3. Coop, 0. Facility
        bool Grassy;    // for non-Facility grids

};

#endif