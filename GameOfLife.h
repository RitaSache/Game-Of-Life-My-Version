//Rita (Eteri) Sachechelashvili
//1928162
//sache100@mail.chapman.edu
//CPSC-350-02
//Assignment 2
//purpose of this file is to serve as a header file for Game of Life
#include <iostream>
using namespace std;

class GameOfLife {
	public:
		GameOfLife(int pMode);
		~GameOfLife();
		void createRandomPlanet(int pHeight, int pWidth, float density);
		void createPlanetFromFile(string fileName);
		void printGeneration();
		void simulateGeneration();
		bool isGenerationEmpty();
		bool isGenerationStable();
		void writeGenerationIntoFile(string otherFile);
	private:
		int mode;
		int height;
		int width;
		int generationCount;
		char** generation;
		char** nextGeneration;
		int getMates(int r, int c);
		int getMatesClassic(int r, int c);
		int getMatesDoughnut(int r, int c);
		int getMatesMirror(int r, int c);
		int getHorizontalDoughnutCell(int c);
		int getVerticalDoughnutCell(int r);
		int getHorizontalMirrorCell(int c);
		int getVerticalMirrorCell(int r);
};