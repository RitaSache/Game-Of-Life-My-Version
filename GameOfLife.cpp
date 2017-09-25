#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameOfLife.h"

using namespace std;

GameOfLife::GameOfLife(int pMode) {
	mode = pMode;
	srand(time(NULL));
}

GameOfLife::~GameOfLife() { }

int GameOfLife::getMates(int r, int c) {
	if (mode == 1) {
		return getMatesClassic(r, c);
	} else if (mode == 2) {
		return getMatesDoughnut(r, c);
	} else {
		return getMatesMirror(r, c);
	}
}

int GameOfLife::getMatesClassic(int r, int c) {
	int sum = 0;

	if (r - 1 >= 0 && c - 1 >= 0 && generation[r - 1][c - 1] == 'X') {
		sum++;
	}

	if (r - 1 >= 0 && generation[r - 1][c] == 'X') {
		sum++;
	}

	if (r - 1 >= 0 && c + 1 < width && generation[r - 1][c + 1] == 'X') {
		sum++;
	}

	if (c - 1 >= 0 && generation[r][c - 1] == 'X') { 
		sum++;
	}

	if (c + 1 < width && generation[r][c + 1] == 'X') {
		sum++;
	}

	if (r + 1 < height && c - 1 >= 0 && generation[r + 1][c - 1] == 'X') {
		sum++;
	}

	if (r + 1 < height && generation[r + 1][c] == 'X') {
		sum++;
	}

	if (r + 1 < height && c + 1 < width && generation[r + 1][c + 1] == 'X') {
		sum++;
	}	

	return sum;
}

int GameOfLife::getMatesDoughnut(int r, int c) {
	return 0;
}

int GameOfLife::getMatesMirror(int r, int c) {
	return 0;
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
	float randNum;

	generation = new char*[height];
	for (int i = 0; i < height; i++) {
		generation[i] = new char[width];
		for(int j = 0; j < width; j++) {
			randNum = rand()/float(RAND_MAX);
			generation[i][j] = randNum < density ? 'X' : '-';
		}
	}
}

void GameOfLife::createPlanetFromFile(string fileName) {
	//TODO: read the file, first lines are height and width
	// the rest are 'X' and '-'
	// Read each character from each line and fill into generation, like in createRandomPlanet

}