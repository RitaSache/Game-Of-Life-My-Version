//Rita (Eteri) Sachechelashvili
//1928162
//sache100@mail.chapman.edu
//CPSC-350-02
//Assignment 2
//purpose of this file is to serve as implementation file for Game of Life
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>
#include "GameOfLife.h"

using namespace std;

//constructor for Game of Life
GameOfLife::GameOfLife(int pMode) {
	mode = pMode;
	srand(time(NULL));
}

//deconstructor for Game of life
GameOfLife::~GameOfLife() { }
//get neighbours of cells with getMates method depending on the mode of the game
int GameOfLife::getMates(int r, int c) {
	if (mode == 1) {
		return getMatesClassic(r, c);
	} else if (mode == 2) {
		return getMatesDoughnut(r, c);
	} else {
		return getMatesMirror(r, c);
	}
}
//gets neighbours if there is an X in a neighbour cell in Classic mode
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
//gets neighbours if there is an X in a neighbour cell in Doughnut (Torus) mode
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

//takes care of vertical Doughnut grid shape 
int GameOfLife::getVerticalDoughnutCell(int r) {
	return (r % height + height) % height;

}
//takes care of horizontal Doughnut grid shape 
int GameOfLife::getHorizontalDoughnutCell(int c) {
	return (c % width + width) % width;
}
//gets neighbours if there is an X in a neighbour cell in Mirror mode
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
//takes care of vertical Mirror grid shpe
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
//takes care of horizontal Mirror grid shpe
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
//prints current generation
void GameOfLife::printGeneration() {
	cout << generationCount << endl;
	for (int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			cout << generation[i][j];
		}
		cout << endl;
	}
}
//simulates next generation based on number of neighbours for each cell, then assigns
//next generation to current generation and increments generation count 
void GameOfLife::simulateGeneration() {
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
//creates random planet (world) from user given height, width, and density and populates generation
void GameOfLife::createRandomPlanet(int pHeight, int pWidth, float density) {
	height = pHeight;
	width = pWidth;
	float randNum;
	generationCount = 0;

	generation = new char*[height]; // making an array of pointers to pointers to chars. 
	nextGeneration = new char*[height];
	for (int i = 0; i < height; i++) { //for each row creating an array of chars
		generation[i] = new char[width];
		nextGeneration[i] = new char[width];
		for(int j = 0; j < width; j++) {
			randNum = rand()/float(RAND_MAX);
			if(randNum < density) {
				generation[i][j] = 'X';
			}
			else {
				generation[i][j] = '-';
			}
			nextGeneration[i][j] = '-';
		} 
	}
}
//creates planet from a given file with height and width. then populates generation based on what's in the file
void GameOfLife::createPlanetFromFile(string fileName) {
	ifstream inputFile;
	inputFile.open(fileName);
	string line;
	char ch;
	generationCount = 0;


	if(!inputFile) {
		cout << "File not found" << endl;
		exit(0);
	}

	getline(inputFile,line);
	istringstream issHeight(line);
	issHeight >> height;
	getline(inputFile,line);
	istringstream issWidth(line);
	issWidth >> width;


	generation = new char*[height];
	nextGeneration = new char*[height];
	for (int i = 0; i < height; i++) {
		generation[i] = new char[width];
		nextGeneration[i] = new char[width];
			for(int j = 0; j < width; j++) {
				inputFile >> ch;
				if (ch == 'X') {
					generation[i][j] = 'X';
				}
				else {
					generation[i][j] = '-';
				}
				nextGeneration[i][j] = '-';
			}
			
			
	}
	inputFile.close();
}
//checks if current generation is empty 
bool GameOfLife::isGenerationEmpty(){
	bool isEmpty = true;
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(generation[i][j] == 'X')  {
				isEmpty = false;
			}
		}
	}
	return isEmpty;
}
//checks if generation is table
bool GameOfLife::isGenerationStable() {
	bool isStable = true;
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(generation[i][j] != nextGeneration[i][j]) {
				isStable = false;
			}
		}
	}
	return isStable;
}
//outputs generations and count into a file 
void GameOfLife::writeGenerationIntoFile(string otherFile){
	ofstream outputFile;
	outputFile.open(otherFile, ios::out | ios::app);
	outputFile << generationCount << endl;
	for (int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			outputFile << generation[i][j];
		}
		outputFile << endl;
	}
	outputFile.close();
}













