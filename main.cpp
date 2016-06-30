#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#include "./objects.cpp"
#include "./simulation-engine.cpp"

int main(int argc, char* argv[]) {

	if (argc != 6) {
		std::cout << "usage: ./simulation <num_boys> <num_girls> <num_tables> <grid size> <runs>" << std::endl;
		exit(1);
	}

	const unsigned int num_boys = atoi(argv[1])
						, num_girls = atoi(argv[2])
						, num_tables = atoi(argv[3])
						, grid_size = atoi(argv[4])
						, runs = atoi(argv[5]);

	if (grid_size * grid_size <= num_boys + num_girls + num_tables) {
		std::cout << "Too many objects to fit in grid" << std::endl;
		exit(2);
	}

	/* Now we will make a grid of objects*/
	SimulationEngine::grid_type grid(grid_size, std::vector< Object* >(grid_size, nullptr));

	/* Populate Grid*/
	SimulationEngine::setup_grid(grid, num_boys, num_girls, num_tables, grid_size);

	/* Simulate... */
	SimulationEngine::run(grid, runs);

	/* cleanup */
	SimulationEngine::cleanup(grid);

	return 0;
}