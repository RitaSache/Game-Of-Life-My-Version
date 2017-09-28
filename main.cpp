#include <iostream>
#include "GameOfLife.h"

using namespace std;

int main() {
	int height;
	int width;
	float density;
	int mode;
	string mapFile;
	string fileName;

	cout << "Would you like to provide a map file? (yes),(no)" << endl;
	cin >> mapFile;

	if (mapFile == "yes") {
		cout << "Provide name of your file: " << endl;
		cin >> fileName;
		cout << "Provide a mode you want: if Classic mode press (1) and enter, if Doughnut mode press (2) and enter, if Mirror mode press (3) and enter" << endl;
		cin >> mode;
		GameOfLife p (mode);
		p.createPlanetFromFile(fileName);
		p.printGeneration();
		while(!p.isGenerationEmpty() && !p.isGenerationStable()) { //these should return false the first time 
			p.simulateGeneration();
			p.printGeneration();
		
		}

	}
	else if(mapFile == "no") {
		cout << "Input the dimensions of the world " << endl;
		cout << "World height: " << endl;
		cin >> height;
		cout << "World width: " << endl;
		cin >> width;
		cout << "World density: " << endl;
		cin >> density;
		cout << "Provide a mode you want: if Classic mode press (1) and enter, if Doughnut mode press (2) and enter, if Mirror mode press (3) and enter" << endl;
		cin >> mode;
		GameOfLife p (mode);
		p.createRandomPlanet(height, width, density);
		p.printGeneration();
		while(!p.isGenerationEmpty() && !p.isGenerationStable()) { //these should return false the first time 
			p.simulateGeneration();
			p.printGeneration();
		
		}
	}

	else {
		cout << "Not a valid response" << endl;
	}
}