#define POPULARITY_CAP 15
#define MAX_TRIES 3

namespace SimulationEngine {

	typedef std::vector< std::vector< Object* > > grid_type;

	void setup_grid(grid_type& grid, 
					const unsigned int& num_boys,
					const unsigned int& num_girls,
					const unsigned int& num_tables,
					const unsigned int& grid_size)
	{
		unsigned int tmp_x, tmp_y, i, tries;
		
		tmp_x = rand() % grid_size;
		tmp_y = rand() % grid_size;

		for (i = 0; i < num_boys + num_girls; i++) {
			// y,x because row,col
			tries = 0;
			while (grid[tmp_y][tmp_x]) {
				tmp_x = rand() % grid_size;
				tmp_y = rand() % grid_size;
				if (tries++ >= MAX_TRIES)
					break;
			}

			if (tries < MAX_TRIES) {				
				grid[tmp_y][tmp_x] = new Person(i < num_boys, 
											bool(rand() % 2),
											int(rand() % POPULARITY_CAP));
			}
		}


		for (i = 0; i < num_tables; i++) {
			tries = 0;
			while (grid[tmp_y][tmp_x]) {
				tmp_x = rand() % grid_size;
				tmp_y = rand() % grid_size;
				if (tries++ >= MAX_TRIES)
					break;
			}

			if (tries < MAX_TRIES) {
				grid[tmp_y][tmp_x] = new Table;
			}
		}
	}

	void run(grid_type& grid, const unsigned int& runs) {
		for (unsigned int i = 0; i < runs; i++) {
			std::cout << "Run #" << i << "..." << std::endl;

			/* Scan grid to make changes... */
			for (unsigned int j = 0, n = grid.size(), k; j < n; j++) {
				for (k = 0; k < n; k++) {
					/*
						Here, I need to do something with probabilities.
					*/
				}
			}


		}
	}

	void cleanup(grid_type& grid) {
		for (std::vector<Object*>& row : grid) {
			for (Object* o : row) {
				if (o != nullptr)
					delete o;
			}
		}
	}
};