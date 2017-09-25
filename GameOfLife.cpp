#include <iostream>
#include "GameOfLife.h"

using namespace std;

GameOfLife::GameOfLife(int pMode) {
	mode = pMode;
}

GameOfLife::~GameOfLife() { }

void GameOfLife::getMates(int r, int c) {

}

void GameOfLife::printGeneration() {
	for (int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			cout << generation[i][j];
		}
		cout << endl;
	}
}

void GameOfLife::simulateGeneration() {
	// Loop through each cell in planet
	// Find mates using getMates
	// Update nextGeneration according to mates
	// Copy nextGeneration to generation
	// Clear nextGeneration
	// increment the generationCount

}

void GameOfLife::createRandomPlanet(int pHeight, int pWidth, float density) {
	height = pHeight;
	width = pWidth;

	generation = new char*[height];
	for (int i = 0; i < height; i++) {
		generation[i] = new char[width];
		for(int j = 0; j < width; j++) {
			//TODO: get random number, if lower than density then 'X' else '-'
			generation[i][j] = '-';
		}
	}
}

void GameOfLife::createPlanetFromFile(string fileName) {
	//TODO: read the file, first lines are height and width
	// the rest are 'X' and '-'
	// Read each character from each line and fill into generation, like in createRandomPlanet

}