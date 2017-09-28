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
	int outputOption;
	string otherFile;

	cout << "Would you like to provide a map file? (yes),(no)" << endl;
	cin >> mapFile;

	if (mapFile == "yes") {
		cout << "Provide name of your file: " << endl;
		cin >> fileName;
		cout << "Provide a mode you want: if Classic mode press (1) and enter, if Doughnut mode press (2) and enter, if Mirror mode press (3) and enter" << endl;
		cin >> mode;
		GameOfLife p (mode);
		cout << "If you want to press Enter type (1), if you want a pause between generations type (2), if you want to output into a file press (3)" << endl; 
		cin >> outputOption;
		
		if(outputOption == 3) {
			cout << "please enter file name to output to" << endl;
			cin >> otherFile;
			p.createPlanetFromFile(fileName);
			p.writeGenerationIntoFile(otherFile);
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) { //these should return false the first time 
			p.simulateGeneration();
			p.writeGenerationIntoFile(otherFile);
			}
		}
		else if(outputOption == 1) {
			p.createPlanetFromFile(fileName);
			p.printGeneration();
			cin.get();
			cin.get();
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) { //these should return false the first time 
				p.simulateGeneration();
				p.printGeneration();
				cin.get();
			}
		}
		else {
			p.createPlanetFromFile(fileName);
			p.printGeneration();
			system("pause");
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) { //these should return false the first time 
				p.simulateGeneration();
				p.printGeneration();
				system("pause");
			}
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