#include "UI.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

#define defSize 11
#define multiplierX 6
#define multiplierY 2
#define addX 2
#define addY 1
#define commandPosX 10
#define commandPosY 23
#define respondPosX 2
#define respondPosY 24
#define fpX 69
#define fpY 4
#define spX 69
#define spY 12
#define moneyX 74
#define moneyY 19
#define waterX 74
#define waterY 21

void gotoxy( int x, int y );
TCHAR getch();

void gotoxy( int x, int y ){
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  }

TCHAR getch() {
  DWORD mode, cc;
  HANDLE h = GetStdHandle( STD_INPUT_HANDLE );
  if (h == NULL) {
        return 0;
  }
  GetConsoleMode( h, &mode );
  SetConsoleMode( h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT) );
  TCHAR c = 0;
  ReadConsole( h, &c, 1, &cc, NULL );
  SetConsoleMode( h, mode );
  return c;
}

void UI::Clear(){
/*Makes all Grid as default (empty)*/
    system("cls");
        cout << "_____________________________________________________________________________________________________" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | Inventory:                       |" << endl;
        cout << "+-----+-----+-----+-----|-----|-----|-----|-----|-----|-----|-----|__________________________________|" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | Farm Product:                    |" << endl;
        cout << "+-----+-----+-----+-----|-----|-----|-----|-----|-----|-----|-----| -                                |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | -                                |" << endl;
        cout << "+-----+-----+-----+-----|-----|-----|-----|-----|-----|-----|-----| -                                |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | -                                |" << endl;
        cout << "+-----+-----+-----+-----|-----|-----|-----|-----|-----|-----|-----| -                                |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | -                                |" << endl;
        cout << "|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|__________________________________|" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | Side Product:                    |" << endl;
        cout << "+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----| -                                |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | -                                |" << endl;
        cout << "+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----| -                                |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | -                                |" << endl;
        cout << "+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----| -                                |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | -                                |" << endl;
        cout << "+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----|__________________________________|" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | Money:                           |" << endl;
        cout << "+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----|__________________________________|" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | Water:                           |" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|__________________________________|" << endl;
        cout << "|Command :                                                                                           |" << endl;
        cout << "|                                                                                                    |" << endl;
        cout << "|____________________________________________________________________________________________________|" << endl;
}

void UI::updateMap(int m, int w, Bag<SideProduct*> sp, Bag<FarmProduct*> fp, AnimalArray<Chicken>& c, AnimalArray<Cow>& s, AnimalArray<Duck>& d, AnimalArray<Rabbit>& r, 
	AnimalArray<Pig>& p, AnimalArray<Goat>& g){
/*Check what's in every grid of the map*/
	string x;
	int i,j;
	int hunger;
	int idx,type,ing1,ing2;

	/*print animal in map*/
	for (i=0; i < defSize; i++){
		for (j = 0; j < defSize; j++){
			idx = c.getNearbyAnimal(i,j);
			if (idx != -999){
				hunger = c.getMember(idx).getHunger();
				if (hunger > 5){
					gotoxy(j * multiplierX + addX, i * multiplierY + addY);
					cout << " C ";
				}else {
					cout << " c ";
				}
			}
			idx = s.getNearbyAnimal(i,j);
			if (idx != -999){
				hunger = s.getMember(idx).getHunger();
				if (hunger > 5){
					gotoxy(j * multiplierX + addX, i * multiplierY + addY);
					cout << " S ";
				} else {
					cout << " s ";
				}
			}
			idx = d.getNearbyAnimal(i,j);
			if (idx != -999){
				hunger = d.getMember(idx).getHunger();
				if (hunger > 5){
					gotoxy(j * multiplierX + addX, i * multiplierY + addY);
					cout << " D ";
				} else {
					cout << " d ";
				}
			}
			idx = r.getNearbyAnimal(i,j);
			if (idx != -999){
				hunger = r.getMember(idx).getHunger();
				if (hunger > 5){
					gotoxy(j * multiplierX + addX, i * multiplierY + addY);
					cout << " R ";
				} else {
					cout << " r ";
				}
			}
			idx = p.getNearbyAnimal(i,j);
			if (idx != -999){
				hunger = p.getMember(idx).getHunger();
				if (hunger > 5){
					gotoxy(j * multiplierX + addX, i * multiplierY + addY);
					cout << " P ";
				} else {
					cout << " p ";
				}
			}
			idx = g.getNearbyAnimal(i,j);
			if (idx != -999){
				hunger = g.getMember(idx).getHunger();
				if (hunger > 5){
					gotoxy(j * multiplierX + addX, i * multiplierY + addY);
					cout << " G ";
				} else {
					cout << " g ";
				}
			}
		}
	}

	/*print Inventory*/
	i = 0;
	while (i < fp.getSize()){
		type = fp.get(i)->getType();
		if (type == 1){
			x = "Chicken Egg";
		} else 
		if (type == 2){
			x = "Duck Egg";
		} else 
		if (type == 3){
			x = "Cow Milk";
		} else 
		if (type == 4){
			x = "Goat Milk";
		} else 
		if (type == 5){
			x = "Chicken Meat";
		} else 
		if (type == 6){
			x = "Cow Meat";
		} else 
		if (type == 7){
			x = "Pig Meat";
		} else 
		if (type == 8){
			x = "Rabbit Meat";
		}
		gotoxy(fpX,fpY +i);
		cout << x;
	}

	i =0;
	while (i < sp.getSize()){
		ing1 = sp.get(i)->getIngredient1();
		ing2 = sp.get(i)->getIngredient2();
		if (ing1 == 6 && ing2 == 2){
			x = "Beef Stew";
		} else 
		if (ing1 == 1 && ing2 == 5){
			x = "Chicken and Egg Skewer";
		} else
		if (ing1 == 1 && ing2 == 2){
			x = "Omlette";
		} else
		if (ing1 == 4 && ing2 == 7){
			x = "Pork Stew";
		}
		gotoxy(spX,spY +i);
		cout << x;
	}
	/* print money and water*/
	gotoxy(moneyX,moneyY);
	cout << m;
	gotoxy(waterX,waterY);
	cout << w;
}

void UI::Print(int ip, int jp, Display D){
/*Print every Grid in D.Map and what's in it with specified layout
ip and jp describes the player position*/
	int x;
    int i,j;
    Clear();
    while (i < defSize) {
        j = 0;
        while (j < defSize) {
            if (D.getMap(i,j).getLand() && D.getMap(i,j).getType() == 3 && !D.getMap(i,j).getGrassy()){
                gotoxy(j * multiplierX + addX, i * multiplierY + addY);
                cout << "[o]";
            } else 
			if (D.getMap(i,j).getLand() && D.getMap(i,j).getType() == 2 && !D.getMap(i,j).getGrassy()){
                gotoxy(j * multiplierX + addX, i * multiplierY + addY);
                cout << "[x]";
            } else 
            if (D.getMap(i,j).getLand() && D.getMap(i,j).getType() == 1 && !D.getMap(i,j).getGrassy()){
                gotoxy(j * multiplierX + addX, i * multiplierY + addY);
                cout << "[-]";
            } else 
            if  (D.getMap(i,j).getLand() && D.getMap(i,j).getType() == 3 && D.getMap(i,j).getGrassy()){
                gotoxy(j * multiplierX + addX, i * multiplierY + addY);
                cout << " = ";
            } else 
            if  (D.getMap(i,j).getLand() && D.getMap(i,j).getType() == 2 && D.getMap(i,j).getGrassy()){
                gotoxy(j * multiplierX + addX, i * multiplierY + addY);
                cout << " $ ";
            } else 
            if  (D.getMap(i,j).getLand() && D.getMap(i,j).getType() == 1 && D.getMap(i,j).getGrassy()){
                gotoxy(j * multiplierX + addX, i * multiplierY + addY);
                cout << " # ";
            }else
            if (D.getMap(i,j).getFacility() && D.getMap(i,j).getType() == 1){
                gotoxy(j * multiplierX + addX, i * multiplierY + addY);
                cout << "[W]";
            }else
            if (D.getMap(i,j).getFacility() && D.getMap(i,j).getType() == 2){
                gotoxy(j * multiplierX + addX, i * multiplierY + addY);
                cout << "[M]";
            }else
            if (D.getMap(i,j).getFacility() && D.getMap(i,j).getType() == 3){
                gotoxy(j * multiplierX + addX, i * multiplierY + addY);
                cout << "[T]";
            }
            j++;
        }
        i++;
    }
    gotoxy(jp * multiplierX + addX, ip * multiplierY + addY);
    cout << " P ";
}

void UI::printSentences(std::string x){
/*Print any sentences from the game that's need to be printed in a specified area
e.g : print sound of the animals*/
    int i;
    gotoxy(respondPosX,respondPosY);
    if (x.size() <= 91){
        cout << x;
    } else {
        gotoxy(respondPosX, respondPosY);
        for (i = 0; i < 91; i++){
            cout << x[i];
        }
        if (x.size() >= 91 && x.size() < 191){
            gotoxy(respondPosX + 1, respondPosY + 1);
            for (i = 91; i < 191; i++){
                cout << x[i];
            }
        }
    }
}

std::string UI::getCommand(){
/*read User input*/
	int x;
	string str;
	gotoxy(commandPosX,commandPosY);
	cin >> str;
	return str;
}

void UI::printTitle(){
/*print Title*/
	system("cls");
    cout << endl;
    cout << "	 (`-')  _<-. (`-')_             _          (`-').->" << endl;
	cout << "	 ( OO).-/   \\( OO) )    .->    (_)    ,--. ( OO)_" << endl;
	cout << "	(,------.,--./ ,--/  ,---(`-') ,-(`-')\\  |(_)--\\_)" << endl;
	cout << "	 |  .---'|   \\ |  | '  .-(OO ) | ( OO) `-'/    _ /" << endl;
	cout << "	(|  '--. |  . '|  |)|  | .-, \\ |  |  )    \\_..`--." << endl;
	cout << "	 |  .--' |  |\\    | |  | '.(_/(|  |_/     .-._)   \\" << endl;
	cout << "	 |  `---.|  | \\   | |  '-'  |  |  |'->    \\       /" << endl;
	cout << "	 `------'`--'  `--'  `-----'   `--'        `-----'" << endl;
	cout << endl;
	cout << "	               (`-')  _    (`-') <-. (`-')" << endl;
	cout << "	       <-.     (OO ).-/ <-.(OO )    \\(OO )_" << endl;
	cout << "	    (`-')-----./ ,---.  ,------,),--./  ,-.)" << endl;
	cout << "	    (OO|(_\\---'| \\ /`.\\ |   /`. '|   `.'   |" << endl;
	cout << "	     / |  '--. '-'|_.' ||  |_.' ||  |'.'|  |" << endl;
	cout << "	     \\_)  .--'(|  .-.  ||  .   .'|  |   |  |" << endl;
	cout << "	      `|  |_)  |  | |  ||  |\\  \\ |  |   |  |" << endl;
	cout << "	       `--'    `--' `--'`--' '--'`--'   `--'" << endl;

	cout << endl;
    cout << "		    Press enter to continue...";
	getch();
    system("cls");
}

void UI::printOver(){
/*print for game over*/
	system("cls");
	cout <<"            (`-')  _ <-. (`-')   (`-')  _" << endl;
	cout <<"    .->    (OO ).-/    \\(OO )_  ( OO).-/" << endl;
	cout <<" ,---(`-') / ,---.  ,--./  ,-.)(,------." << endl;
	cout <<"'  .-(OO ) | \\ /`.\\ |   `.'   | |  .---'" << endl;
	cout <<"|  | .-, \\ '-'|_.' ||  |'.'|  |(|  '--. " << endl;
	cout <<"|  | '.(_/(|  .-.  ||  |   |  | |  .--' " << endl;
	cout << "|  '-'  |  |  | |  ||  |   |  | |  `---." << endl;
	cout << " `-----'   `--' `--'`--'   `--' `------'" << endl;

	cout << "	                 (`-') (`-')  _   (`-')" << endl;
	cout << "     .->        _(OO ) ( OO).-/<-.(OO )" << endl;
	cout << "(`-')----. ,--.(_/,-.\\(,------.,------,)" << endl;
	cout << "( OO).-.  '\\   \\ / (_/ |  .---'|   /`. '" << endl;
	cout << "( _) | |  | \\   /   / (|  '--. |  |_.' |" << endl;
	cout << " \\|  |)|  |_ \\     /_) |  .--' |  .   .'" << endl;
	cout << "  '  '-'  '\\-'\\   /    |  `---.|  |\\  \\ " << endl;
	cout << "   `-----'     `-'     `------'`--' '--'" << endl;
}