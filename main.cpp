//Rita (Eteri) Sachechelashvili
//1928162
//sache100@mail.chapman.edu
//CPSC-350-02
//Assignment 2
//purpose of this file is to serve as a main file for Game of Life
#include <iostream>
#include "GameOfLife.h"

using namespace std;
//main asks user for file or random world, mode, speed, height, width, density, output file
int main(int argc, char**argv) {
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
		cout << "Provide name path of your file: " << endl;
		cin >> fileName;
		cout << "Provide a mode you want: if Classic mode press (1) and enter, if Doughnut mode press (2) and enter, if Mirror mode press (3) and enter" << endl;
		cin >> mode;
		GameOfLife p (mode);
		cout << "If you want to press Enter type (1) and enter, if you want a pause between generations type (2) and enter, if you want to output into a file press (3) and enter, if none of these press (4) and enter " << endl; 
		cin >> outputOption;
		
		if(outputOption == 3) {
			cout << "please enter file name to output to" << endl;
			cin >> otherFile;
			p.createPlanetFromFile(fileName);
			p.writeGenerationIntoFile(otherFile);
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) {  
				p.simulateGeneration();
				p.writeGenerationIntoFile(otherFile);
			}
			cout << "Press enter to exit the program " << endl;
			cin.ignore();
			cin.ignore();
		}
		else if(outputOption == 1) {
			p.createPlanetFromFile(fileName);
			p.printGeneration();
			cin.get();
			cin.get();
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) {  
				p.simulateGeneration();
				p.printGeneration();
				cin.get();
			}
			cout << "Press enter to exit the program " << endl;
			cin.ignore();
			
		}
		else if(outputOption == 2) {
			p.createPlanetFromFile(fileName);
			p.printGeneration();
			system("pause");
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) {  
				p.simulateGeneration();
				p.printGeneration();
				system("pause");
			}
			cout << "Press enter to exit the program " << endl;
			cin.ignore();
			cin.ignore();
		}
		else if (outputOption == 4) {
			p.createPlanetFromFile(fileName);
			p.printGeneration();
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) {  
				p.simulateGeneration();
				p.printGeneration();
			}
			cout << "Press enter to exit the program " << endl;
			cin.ignore();
			cin.ignore();
		}
		else {
			cout << "Invalid input" << endl;
		}
	}
	else if(mapFile == "no") {
		cout << "Input the dimensions of the world " << endl;
		cout << "World height: " << endl;
		cin >> height;
		cout << "World width: " << endl;
		cin >> width;
		cout << "World density (between 0 and 1): " << endl;
		cin >> density;
		cout << "Provide a mode you want: if Classic mode press (1) and enter, if Doughnut mode press (2) and enter, if Mirror mode press (3) and enter" << endl;
		cin >> mode;
		GameOfLife p (mode);

		cout << "If you want to press Enter type (1) and enter, if you want a pause between generations type (2) and enter, if you want to output into a file press (3) and enter, if none of these press (4) and enter " << endl; 
		cin >> outputOption;
		
		if(outputOption == 3) {
			cout << "please enter file name to output to" << endl;
			cin >> otherFile;
			p.createRandomPlanet(height, width, density);
			p.writeGenerationIntoFile(otherFile);
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) {  
				p.simulateGeneration();
				p.writeGenerationIntoFile(otherFile);
			}
			cout << "Press enter to exit the program " << endl;
			cin.ignore();
			cin.ignore();
		}
		else if(outputOption == 1) {
			p.createRandomPlanet(height, width, density);
			p.printGeneration();
			cin.get();
			cin.get();
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) {  
				p.simulateGeneration();
				p.printGeneration();
				cin.get();
			}
			cout << "Press enter to exit the program " << endl;
			cin.ignore();
			
		}
		else if(outputOption == 2){
			p.createRandomPlanet(height, width, density);
			p.printGeneration();
			system("pause");
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) { 
				p.simulateGeneration();
				p.printGeneration();
				system("pause");
			}
			cout << "Press enter to exit the program " << endl;
			cin.ignore();
			cin.ignore();
		}
		else if (outputOption == 4) {
			p.createRandomPlanet(height, width, density);
			p.printGeneration();
			while(!p.isGenerationEmpty() && !p.isGenerationStable()) { 
				p.simulateGeneration();
				p.printGeneration();
			}
			cout << "Press enter to exit the program " << endl;
			cin.ignore();
			cin.ignore();
		}
		else {
			cout << "Invalid input" << endl;
		}
	}

	else {
		cout << "Not a valid response" << endl;
	}
}