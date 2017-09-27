#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
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
	int sum = 0;
	if (generation[getVerticalDoughnutCell(r - 1)][getHorizontalDoughnutCell(c - 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalDoughnutCell(r - 1)][getHorizontalDoughnutCell(c)] == 'X') {
		sum++;
	}
	if (generation[getVerticalDoughnutCell(r - 1)][getHorizontalDoughnutCell(c + 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalDoughnutCell(r)][getHorizontalDoughnutCell(c - 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalDoughnutCell(r)][getHorizontalDoughnutCell(c + 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalDoughnutCell(r + 1)][getHorizontalDoughnutCell(c - 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalDoughnutCell(r + 1)][getHorizontalDoughnutCell(c)] == 'X') {
		sum++;
	}
	if (generation[getVerticalDoughnutCell(r + 1)][getHorizontalDoughnutCell(c + 1)] == 'X') {
		sum++;
	}
	return sum;
}

int GameOfLife::getVerticalDoughnutCell(int r) {
	return (r % height + height) % height;

}

int GameOfLife::getHorizontalDoughnutCell(int c) {
	return (c % width + width) % width;
}

int GameOfLife::getMatesMirror(int r, int c) {
	int sum = 0;
	if (generation[getVerticalMirrorCell(r - 1)][getHorizontalMirrorCell(c - 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalMirrorCell(r - 1)][getHorizontalMirrorCell(c)] == 'X') {
		sum++;
	}
	if (generation[getVerticalMirrorCell(r - 1)][getHorizontalMirrorCell(c + 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalMirrorCell(r)][getHorizontalMirrorCell(c - 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalMirrorCell(r)][getHorizontalMirrorCell(c + 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalMirrorCell(r + 1)][getHorizontalMirrorCell(c - 1)] == 'X') {
		sum++;
	}
	if (generation[getVerticalMirrorCell(r + 1)][getHorizontalMirrorCell(c)] == 'X') {
		sum++;
	}
	if (generation[getVerticalMirrorCell(r + 1)][getHorizontalMirrorCell(c + 1)] == 'X') {
		sum++;
	}
	return sum;
	
}

int GameOfLife::getHorizontalMirrorCell(int c) {
	if(c < 0) {
		return 0;
	}
	else if(c == width) {
		return width - 1;
	}
	else {
		return c;
	}
}

int GameOfLife::getVerticalMirrorCell(int r) {
	if(r < 0) {
		return 0;
	}
	else if(r == height) {
		return height - 1;
	}
	else {
		return r;
	}
}

void GameOfLife::printGeneration() {
	cout << generationCount << endl;
	for (int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			cout << generation[i][j];
		}
		cout << endl;
	}
}

void GameOfLife::simulateGeneration() {
	// Loop through each cell in planet
	for (int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			//cout << "For[" << i << "]" << "[" << j << "]" << ": " << getMates(i,j) << endl;
			if(getMates(i,j) <= 1) {
				nextGeneration[i][j] = '-';
			}
			if(getMates(i,j) == 2) {
				nextGeneration[i][j] = generation[i][j];
			}
			if(getMates(i,j) == 3) {
				nextGeneration[i][j] = 'X';
			}
			if(getMates(i,j) >= 4) {
				nextGeneration[i][j] = '-';
			}
		}

	}
	char** tempGeneration = generation;
	generation = nextGeneration;
	nextGeneration = tempGeneration;
	generationCount++;
}

void GameOfLife::createRandomPlanet(int pHeight, int pWidth, float density) {
	height = pHeight;
	width = pWidth;
	float randNum;
	generationCount = 0;

	generation = new char*[height]; // making an array of pointers to pointers to chars. when you make an array we make a pointer to first element in an array.
	//when you make an array of arrays you make a pointer to pointers
	nextGeneration = new char*[height];
	for (int i = 0; i < height; i++) { //for each row we create an array of chars
		generation[i] = new char[width];
		nextGeneration[i] = new char[width];
		for(int j = 0; j < width; j++) {
			randNum = rand()/float(RAND_MAX);
			generation[i][j] = randNum < density ? 'X' : '-';
			nextGeneration[i][j] = randNum < density ? 'X' : '-';
		} //initialize arrays with 0 first before putting generation tghere
	}
}

void GameOfLife::createPlanetFromFile(string fileName) {
	//TODO: read the file, first lines are height and width
	// the rest are 'X' and '-'
	// Read each character from each line and fill into generation, like in createRandomPlanet

}
bool GameOfLife::isGenerationEmpty(){
	bool isEmpty;
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(generation[i][j] == 'X')  {
				isEmpty = false;
			}
		}
	}
	return isEmpty;
}

/*bool GameOfLife::isGenerationStable() {
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {

		}
	}
}*/













