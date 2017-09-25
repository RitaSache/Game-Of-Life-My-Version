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
	private:
		int mode;
		int height;
		int width;
		int generationCount;
		char** generation;
		char** nextGeneration;
		void getMates(int r, int c);
};