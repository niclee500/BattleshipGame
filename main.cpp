#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector> 
#include <sstream>
#include <string>
#include <stdio.h>      
#include <stdlib.h> 
#include <algorithm>
#include <math.h>  
#include <ctime>

void board_check2( std::vector<std::vector<char> > ship_table, int ship_max_val, //main recursion function
	std::vector<int> row_val, std::vector<int> col_val,
  std::vector<int> ship_num_val, std::vector<std::vector<std::vector<char> > > &final_solution, 
  std::vector<std::vector<std::vector<char> > > sub_solution,  bool find_all);


int conversion(std::string value) {
	int return_val = atoi(value.c_str()); //converts filestream into ints
	return return_val;
}

int is_contained(int ship_len, std::vector<int> ship_num_val) { //checks if a ship len
	for (unsigned int i = 0; i < ship_num_val.size(); ++i) {	// is in the vec
		if (ship_num_val[i] == ship_len) {
			return i;
		}
	}
	return -1;
}
/*
The following function checks if a part of a ship can be placed depending on whether the adjacent
squares on the board allows for it
*/

bool validate_ship(std::vector<std::vector<char> > ship_table, std::vector<int> row_val, 
	std::vector<int> col_val, unsigned int row_pos, unsigned int col_pos, std::string pos) {
	if (pos == "none") {
		if (row_pos == 0 && col_pos == 0) {
			if (ship_table[row_pos+1][col_pos] == ' ' && ship_table[row_pos][col_pos+1] == ' '
			 && ship_table[row_pos+1][col_pos+1] == ' ') {
				return true;
			}
			return false;
		} else if (row_pos == row_val.size()-1 && col_pos == 0) {
			if (ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos-1][col_pos+1] == ' ' 
				&& ship_table[row_pos][col_pos+1] == ' ') {
				return true;
			} 
			return false;
		} else if (row_pos == row_val.size()-1 && col_pos == col_val.size()-1) {
			if (ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos-1][col_pos] == ' '
			 && ship_table[row_pos-1][col_pos-1] == ' ') {
				return true;
			}
			return false;
		} else if (row_pos == 0 && col_pos == col_val.size()-1) {
			if (ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos+1][col_pos] == ' '
			 && ship_table[row_pos+1][col_pos-1] == ' ') {
				return true;
			}
			return false;
		} else if (row_pos == 0) {
			if (ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos][col_pos+1] == ' ' 
				&& ship_table[row_pos+1][col_pos] == ' ' && ship_table[row_pos+1][col_pos+1] == ' ' 
				&& ship_table[row_pos+1][col_pos-1] == ' ') {
				return true;
			}
			return false;
		} else if (col_pos == 0) {
			if (ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos][col_pos+1] == ' '
			 && ship_table[row_pos+1][col_pos] == ' ' && ship_table[row_pos+1][col_pos+1] == ' ' 
			 && ship_table[row_pos-1][col_pos+1] == ' ') {
				return true;
			}
			return false;
		} else if (row_pos == row_val.size()-1) {
			if (ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos][col_pos+1] == ' ' 
				&& ship_table[row_pos-1][col_pos-1] == ' ' && ship_table[row_pos-1][col_pos] == ' '
				 && ship_table[row_pos-1][col_pos+1] == ' ') {
				return true;
			}
			return false;
		} else if (col_pos == col_val.size()-1) {
			if (ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos-1][col_pos-1] == ' ' 
				&& ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos+1][col_pos-1] == ' '
				 && ship_table[row_pos+1][col_pos] == ' ') {
				return true;
			}
			return false;
		} else {
			if (ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos-1][col_pos-1] == ' ' 
				&& ship_table[row_pos-1][col_pos+1] == ' ' && ship_table[row_pos][col_pos-1] == ' ' 
				&& ship_table[row_pos][col_pos+1] == ' ' && ship_table[row_pos+1][col_pos-1] == ' ' 
				&& ship_table[row_pos+1][col_pos] == ' ' && ship_table[row_pos+1][col_pos+1] == ' ') {
				return true;
			}
			return false;
		}
		
	} else if (pos == "top") {
		if (row_pos == 0 && col_pos == 0) {
			if (ship_table[row_pos+1][col_pos] == ' ' && ship_table[row_pos][col_pos+1] == ' ' 
				&& ship_table[row_pos+1][col_pos+1] == ' ') {
				return true;
			}
			return false;
		} else if (row_pos == row_val.size()-1 && col_pos == 0) {
			if (ship_table[row_pos-1][col_pos+1] == ' ' && ship_table[row_pos][col_pos+1] == ' ') {
				return true;
			} 
			return false;
		} else if (row_pos == row_val.size()-1 && col_pos == col_val.size()-1) {
			if (ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos-1][col_pos-1] == ' ') {
				return true;
			}
			return false;
		} else if (row_pos == 0 && col_pos == col_val.size()-1) {
			if (ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos+1][col_pos-1] == ' ') {
				return true;
			}
			return false;
		} else if (row_pos == 0) {
			if (ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos][col_pos+1] == ' '
			 && ship_table[row_pos+1][col_pos] == ' ' && ship_table[row_pos+1][col_pos+1] == ' '
			  && ship_table[row_pos+1][col_pos-1] == ' ') {
				return true;
			} return false;
		} else if (col_pos == 0) {
			if (ship_table[row_pos][col_pos+1] == ' ' && ship_table[row_pos+1][col_pos] == ' ' 
				&& ship_table[row_pos+1][col_pos+1] == ' ' && ship_table[row_pos-1][col_pos+1] == ' ') {
				return true;
			}return false;
		} else if (row_pos == row_val.size()-1) {
			if (ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos][col_pos+1] == ' ' 
				&& ship_table[row_pos-1][col_pos-1] == ' ' && ship_table[row_pos-1][col_pos+1] == ' ') {
				return true;
			}return false;
		} else if (col_pos == col_val.size()-1) {
			if (ship_table[row_pos-1][col_pos-1] == ' ' && ship_table[row_pos][col_pos-1] == ' ' 
				&& ship_table[row_pos+1][col_pos-1] == ' ' && ship_table[row_pos+1][col_pos] == ' ') {
				return true;
			}return false;

		} else {
			if (ship_table[row_pos-1][col_pos-1] == ' ' && ship_table[row_pos-1][col_pos+1] == ' '
			 && ship_table[row_pos][col_pos-1] == ' ' && ship_table[row_pos][col_pos+1] == ' '
				&& ship_table[row_pos+1][col_pos-1] == ' ' && ship_table[row_pos+1][col_pos] == ' ' 
				&& ship_table[row_pos+1][col_pos+1] == ' ') {
				return true;
			}return false;
		}
		return false;
	} else if (pos == "left") {
		if (row_pos == 0 && col_pos == 0) {
			if (ship_table[row_pos+1][col_pos] == ' ' && ship_table[row_pos][col_pos+1] == ' ' 
				&& ship_table[row_pos+1][col_pos+1] == ' ') {
				return true;
			}return false;
		} else if (row_pos == row_val.size()-1 && col_pos == 0) {
			if (ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos-1][col_pos+1] == ' ' 
				&& ship_table[row_pos][col_pos+1] == ' ') {
				return true;
			} return false;
		} else if (row_pos == row_val.size()-1 && col_pos == col_val.size()-1) {
			if (ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos-1][col_pos-1] == ' ') {
				return true;
			}return false;
		} else if (row_pos == 0 && col_pos == col_val.size()-1) {
			if (ship_table[row_pos+1][col_pos] == ' ' && ship_table[row_pos+1][col_pos-1] == ' ') {
				return true;
			}return false;
		} else if (row_pos == 0) {
			if (ship_table[row_pos][col_pos+1] == ' ' && ship_table[row_pos+1][col_pos] == ' ' 
				&& ship_table[row_pos+1][col_pos+1] == ' ' && ship_table[row_pos+1][col_pos-1] == ' ') {
				return true;
			}return false;
		} else if (col_pos == 0) {
			if (ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos][col_pos+1] == ' ' 
				&& ship_table[row_pos+1][col_pos] == ' ' && ship_table[row_pos+1][col_pos+1] == ' ' 
				&& ship_table[row_pos-1][col_pos+1] == ' ') {
				return true;
			}return false;
		} else if (row_pos == row_val.size()-1) {
			if (ship_table[row_pos][col_pos+1] == ' ' && ship_table[row_pos-1][col_pos-1] == ' ' 
				&& ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos-1][col_pos+1] == ' ') {
				return true;
			}return false;
		} else if (col_pos == col_val.size()-1) {
			if (ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos-1][col_pos-1] == ' ' 
				&& ship_table[row_pos+1][col_pos-1] == ' ' && ship_table[row_pos+1][col_pos] == ' ') {
				return true;
			}return false;

		} else {
			if (ship_table[row_pos-1][col_pos] == ' ' && ship_table[row_pos-1][col_pos-1] == ' ' 
				&& ship_table[row_pos-1][col_pos+1] == ' ' && ship_table[row_pos][col_pos+1] == ' '
				&& ship_table[row_pos+1][col_pos-1] == ' ' && ship_table[row_pos+1][col_pos] == ' '
				 && ship_table[row_pos+1][col_pos+1] == ' ') {
				return true;
			}return false;
		}
		
	}
	return false;
}

std::vector<std::vector<char> > copy_table(std::vector<std::vector<char> > ship_table) {
	std::vector<std::vector<char> > ship_table_copy; // simply copys the contents of a 2d vec and returns it
	std::vector<char> ship_row_copy;
	for (unsigned int i = 0; i < ship_table.size(); ++i) {
		for (unsigned int j = 0; j < ship_table[i].size(); ++j) {
			ship_row_copy.push_back(ship_table[i][j]);
		}
		ship_table_copy.push_back(ship_row_copy);
		ship_row_copy.clear();
	}
	return ship_table_copy;
}

std::vector<int> copy_vector(std::vector<int> val) { // copys the contents of a 1d vec and returns
	std::vector<int> vector_copy;
	for (unsigned int i = 0; i < val.size(); ++i) {
		vector_copy.push_back(val[i]);
	}
	return vector_copy;
}

bool check_col(std::vector<std::vector<char> > ship_table,int ship_max_val,
	std::vector<int> row_val_copy1,std::vector<int> col_val_copy1,int row_pos,int col_pos) {
	unsigned int tmp_itr1 = 0; // checks if the max sized ship can be placed vertically on board
	int counter1 = 0;			// from given position
	while(true) {
		if (row_pos+tmp_itr1 ==row_val_copy1.size()) {
			break;
		}
		if (counter1 == ship_max_val) {
			break;
		}
		if (row_val_copy1[row_pos+tmp_itr1] != 0 && col_val_copy1[col_pos] != 0 && 
			validate_ship(ship_table,row_val_copy1,col_val_copy1,row_pos+tmp_itr1,col_pos,"top")) {
			counter1++;
			row_val_copy1[row_pos+tmp_itr1]--;
			col_val_copy1[col_pos]--;
		} else {
			break;
		}
		tmp_itr1++;
	}
	if (counter1 == ship_max_val) {
		return true;
	} else {
		return false;
	}
}

bool check_row(std::vector<std::vector<char> > ship_table,int ship_max_val,
	std::vector<int> row_val_copy1,std::vector<int> col_val_copy1,int row_pos,int col_pos) {
	unsigned int tmp_itr2 = 0; // checks if max sized ship can be placed horizontally on board
	int counter2 = 0;			// from given position
	while(true) {
		if (col_pos+tmp_itr2 ==col_val_copy1.size()) {
			break;
		}
		if (counter2 == ship_max_val) {
			break;
		}
		if (row_val_copy1[row_pos] != 0 && col_val_copy1[col_pos+tmp_itr2] != 0
		 && validate_ship(ship_table,row_val_copy1,col_val_copy1,row_pos,col_pos+tmp_itr2,"left")) {
			counter2++;
			row_val_copy1[row_pos]--;
			col_val_copy1[col_pos+tmp_itr2]--;
		} else {
			break;
		}
		tmp_itr2++;
	}
	if (counter2 == ship_max_val) {
		return true;
	} else {
		return false;
	}
}

bool is_same_as_final(std::vector<std::vector<std::vector<char> > > final_solution,  
	std::vector<std::vector<char> > ship_table) { // checks if a 2d vector is in a 3d vector
	bool testcase = false;							// or at least has same contents.
	std::vector<bool> same_sol(final_solution.size(),true); // this prevents repeats ofboards
	for (unsigned int i = 0; i < final_solution.size(); ++i) {
		for (unsigned int j = 0; j < ship_table.size(); ++j) {
			for (unsigned int k = 0; k < ship_table[j].size(); ++k) {
				if (ship_table[j][k] != ' ') {
					if (ship_table[j][k] != final_solution[i][j][k]) {
						same_sol[i] = false;
					}	
				}
			} 
		}
	}
	for (unsigned int i = 0; i < same_sol.size(); ++i) {
		if (same_sol[i] == true) {
			testcase = true;
		}
	}
	return testcase;
}



void board_check2( std::vector<std::vector<char> > ship_table, int ship_max_val,  // main recursion function
	std::vector<int> row_val, std::vector<int> col_val,
  std::vector<int> ship_num_val, std::vector<std::vector<std::vector<char> > > &final_solution, 
  std::vector<std::vector<std::vector<char> > > sub_solution,  bool find_all) {
	if (is_same_as_final(final_solution,ship_table) == true) { // return if duplicate board
		return;
	} 
	if (!find_all) {
				if(final_solution.size() == 1) {
					return;
				}
			}
	if (ship_num_val.size() == 0) { //if no ships left, pushback to 3d vec and return
		if (is_same_as_final(final_solution,ship_table) == false){
			final_solution.push_back(ship_table);
			
		}

		return;
	} 
	std::vector<std::vector<char> > ship_table_copy1 = copy_table(ship_table);
	std::vector<std::vector<char> > ship_table_copy2 = copy_table(ship_table);
	std::vector<int> row_val_copy1 = copy_vector(row_val);
	std::vector<int> col_val_copy1 = copy_vector(col_val); 
	std::vector<int> row_val_copy2 = copy_vector(row_val);
	std::vector<int> col_val_copy2 = copy_vector(col_val);
	std::vector<int> ship_num_val1 = copy_vector(ship_num_val);
	std::vector<int> ship_num_val2 = copy_vector(ship_num_val);
	for (unsigned int i = 0; i < ship_table.size(); ++i) {	// checks through the whole board to see
		for (unsigned int j = 0; j < ship_table[i].size(); ++j) { // if ships can be placed. if yes, then board is
			if (row_val[i] != 0 && col_val[j] != 0 && validate_ship(ship_table,row_val,col_val,i,j,"none")) { //recursively
				if (check_row(ship_table_copy1,ship_max_val,row_val_copy1,col_val_copy1,i,j)) { // called for following ship
					for(int k = 0; k < ship_max_val; ++k) {
						if (ship_max_val == 1) {
							ship_table_copy1[i][j+k] = 'o';
						} else if (k == 0) {
							ship_table_copy1[i][j+k] = '<';
						} else if (k == ship_max_val-1) {
							ship_table_copy1[i][j+k] = '>';
						} else {
							ship_table_copy1[i][j+k] = 'X';
						}
						
						row_val_copy1[i]--;
						col_val_copy1[j+k]--;
					}
					
					ship_num_val1.pop_back();
					board_check2(ship_table_copy1,ship_num_val1[ship_num_val1.size()-1],
					row_val_copy1,col_val_copy1,ship_num_val1, final_solution, sub_solution, find_all);
					ship_num_val1 = copy_vector(ship_num_val);
					row_val_copy1 = copy_vector(row_val);
					col_val_copy1 = copy_vector(col_val);
					ship_table_copy1 = copy_table(ship_table);
				}
				if (check_col(ship_table_copy2,ship_max_val,row_val_copy2,col_val_copy2,i,j)) { //need to check
					for (int k = 0; k < ship_max_val; ++k) {								//vertical and horizontal 
						if (ship_max_val == 1) {
							ship_table_copy2[i+k][j] = 'o';
						} else if (k == 0) {
							ship_table_copy2[i+k][j] = '^';
						} else if (k == ship_max_val-1) {
							ship_table_copy2[i+k][j] = 'v';
						} else {
							ship_table_copy2[i+k][j] = 'X';
						}
						
						row_val_copy2[i+k]--;
						col_val_copy2[j]--;
					}
					ship_num_val2.pop_back();
					board_check2(ship_table_copy2,ship_num_val2[ship_num_val2.size()-1],
					row_val_copy2,col_val_copy2,ship_num_val2,final_solution, sub_solution, find_all);
					ship_num_val2 = copy_vector(ship_num_val);
					row_val_copy2 = copy_vector(row_val);
					col_val_copy2 = copy_vector(col_val);
					ship_table_copy2 = copy_table(ship_table);
				}
			}
		}
	}	
}

int horizontal_length(std::vector<std::vector<char> > ship_table,int row_pos,int col_pos) {
	int counter = 0;
	int tmp_itr = 0;
	while (true) {
		if (ship_table[row_pos][col_pos+tmp_itr] == '>') { //finds horizontal length of ship
			counter++;										// at given pos
			break;
		}
		counter++;
		tmp_itr++;
	} 
	return counter;
}

int vertical_length(std::vector<std::vector<char> > ship_table,int row_pos,int col_pos) {
	int counter = 0;
	int tmp_itr = 0;
	while (true) {
		if (ship_table[row_pos+tmp_itr][col_pos] == 'v') { // self-explanatory
			counter++;
			break;
		}
		counter++;
		tmp_itr++;
	} 
	return counter;
}

void stat_info(std::vector<std::vector<char > >  ship_table, std::vector<int> &row_pos_val, 
	std::vector<int> &col_pos_val, std::vector<int> &size_ship, std::vector<std::string> &alignment) {
	for (unsigned int i = 0; i < ship_table.size(); ++i) {
		for (unsigned int j = 0; j < ship_table[i].size(); ++j) {
			if (ship_table[i][j] == '<') {
				size_ship.push_back(horizontal_length(ship_table,i,j));
				row_pos_val.push_back(i);
				col_pos_val.push_back(j);
				alignment.push_back("horizontal");		//essentially the statistics function
			} else if (ship_table[i][j] == '^') {
				size_ship.push_back(vertical_length(ship_table,i,j));
				row_pos_val.push_back(i);
				col_pos_val.push_back(j);
				alignment.push_back("vertical");
			} else if (ship_table[i][j] == 'o') {
				size_ship.push_back(1);
				row_pos_val.push_back(i);
				col_pos_val.push_back(j);
				alignment.push_back("");
			}
		}
	}
}

void Solution(std::vector<std::vector<std::vector<char> > > final_solution,std::vector<std::vector<int> > final_row, 
	std::vector<std::vector<int> > final_col, std::vector<std::vector<int> > final_ship, std::vector<int> row_val, 
	std::vector<int> col_val, std::vector<std::vector<std::string> > final_alignment, bool find_all) {
	for (unsigned int i = 0; i < final_solution.size(); ++i) {
		std::cout << "Solution:" << std::endl;
		for (unsigned int j = 0; j < final_row[i].size(); ++j) {
			if (final_ship[i][j] == 1)
				std::cout << "submarine ";
			if (final_ship[i][j] == 2)
				std::cout << "destroyer ";
			if (final_ship[i][j] == 3)
				std::cout << "cruiser ";
			if (final_ship[i][j] == 4)
				std::cout << "battleship "; // essentially the printed solution function
			if (final_ship[i][j] == 5)
				std::cout << "carrier ";
			if (final_ship[i][j] == 6)
				std::cout << "cargo ";
			if (final_ship[i][j] == 7)
				std::cout << "tanker ";
			std::cout << final_row[i][j] << " ";
			std::cout << final_col[i][j] << " ";
			std::cout << final_alignment[i][j] << std::endl;
		}
		std::cout<<"+";
		for (unsigned int j = 0; j < col_val.size(); ++j) {
			std::cout << '-';
		}
		std::cout << "+\n";

		for (unsigned int j = 0; j < final_solution[i].size(); ++j) {
			std::cout << "|";
			for (unsigned int k = 0; k < final_solution[i][j].size(); ++k) {
				std::cout << final_solution[i][j][k];
			}
			std::cout << "|" << row_val[j] << std::endl;
		}
		std::cout<<"+";
		for (unsigned int j = 0; j < col_val.size(); ++j) {
			std::cout << '-';
		}
		std::cout << "+\n";
		std::cout << " ";
		for (unsigned int j = 0; j < col_val.size(); ++j) {
			std::cout << col_val[j];
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	if (final_solution.size() == 0) {
		std::cout << "No Solutions" << std::endl;
	} else if (find_all) {
		std::cout << "Found " << final_solution.size() << " solution(s)" << std::endl;
	}
}

int main(int argc, char *argv[]) {

	bool find_all = false;
	if (argc >= 3) {
		std::string arg_str(argv[2]);
		if (arg_str == "find_all_solutions" || arg_str == "find_all_solutions ") {
			find_all = true; //check if 1 solution or all solutions
		}
	}
	std::ifstream puzzle(argv[1]);
	std::string word;
	std::vector<int> board_val;
	std::vector<int> row_val;
	std::vector<int> col_val;
	std::vector<std::string> ship_val;
	std::vector<std::string> constraint_char;
	std::vector<int> constraint_row;
	std::vector<int> constraint_col;
	int num_conv;
	int ship_list = 0;
	bool row_and_col = true;
	bool unknown_yes = false;
	bool is_constrained = false; //takes a file and creates vectors of values
	while (puzzle >> word) { // to be used for the table
		if (word == "board") {
			ship_list = 0;
			continue;
		}
		else if (word == "rows") {
			ship_list = 1;
			continue;
		}
		else if (word == "cols") {
			ship_list = 2;
			continue;
		}
		else if (word == "submarine" || word == "cruiser" || word == "destroyer" ||
			word == "tanker" || word == "cargo" || word == "battleship" || word == "carrier" ||
			 word == "unknown") {
			ship_list = 3;
		} else if (word == "constraint") {
			ship_list = 4;
			is_constrained = true;
			continue;
		}
		if (ship_list == 0) {
			num_conv = conversion(word);
			board_val.push_back(num_conv);
		}
		else if (ship_list == 1) {
			if (word == "?") {
				row_val.push_back(-1);
				unknown_yes = true;
			} else {
				num_conv = conversion(word);
				row_val.push_back(num_conv);
			}
		}
		else if (ship_list == 2) {
			if (word == "?") {
				col_val.push_back(-1);
				unknown_yes = true;
			} else {
				num_conv = conversion(word);
			col_val.push_back(num_conv);
			}
		}
		else if (ship_list == 3) {
			ship_val.push_back(word);
		} else if (ship_list == 4) {
			if (word == "<" || word == ">" || word == "v" || word == "^" || word == "X" || word == "o") {
				constraint_char.push_back(word);
			} else {
				if (row_and_col) {
					num_conv = conversion(word);
					constraint_row.push_back(num_conv);
					row_and_col = false;
				} else {
					num_conv = conversion(word);
					constraint_col.push_back(num_conv);
					row_and_col = true;
				}
			}
		}
	} 
	std::vector<std::vector<char> > ship_table;
	std::vector<char> bool_row;
	for (int i = 0; i < board_val[0]; ++i) {
		for (int j = 0; j < board_val[1]; ++j) { //empty ship table
			bool_row.push_back(' ');
		}
		ship_table.push_back(bool_row);
		bool_row.clear();
	}
	std::vector<int> ship_num_val;
	int unknown_pos;
	for (unsigned int i = 0; i < ship_val.size(); ++i) {
		if (ship_val[i] == "submarine")
			ship_num_val.push_back(1);
		if (ship_val[i] == "destroyer")
			ship_num_val.push_back(2);
		if (ship_val[i] == "cruiser")
			ship_num_val.push_back(3);
		if (ship_val[i] == "battleship") //ship lengths
			ship_num_val.push_back(4);
		if (ship_val[i] == "carrier")
			ship_num_val.push_back(5);
		if (ship_val[i] == "cargo")
			ship_num_val.push_back(6);
		if (ship_val[i] == "tanker")
			ship_num_val.push_back(7);
		if (ship_val[i] == "unknown") {
			ship_num_val.push_back(-1);
			unknown_yes = true;
		}
	}
std::sort(ship_num_val.begin(),ship_num_val.end()); 
	
	std::vector<std::vector<std::vector<char> > > final_solution;
	std::vector<std::vector<std::vector<char> > > sub_solution;
	std::vector<std::vector<int> > spot_taken(7);
	if (is_constrained) {
		find_all = true;
	}

	if (unknown_yes == false) { //main start of recursion function, final solutions
		board_check2(ship_table, ship_num_val[ship_num_val.size()-1], row_val, //will be appended to
			col_val, ship_num_val, final_solution, sub_solution, find_all);// with the correct
	}																		// ship tables
	
	if (is_constrained) {
		find_all = false;
	}
	std::vector<char> constraint_char2;
	for (unsigned int i = 0; i < constraint_char.size(); ++i) {
		char data = constraint_char[i][0];
		constraint_char2.push_back(data);
	} //constraint positions
	int row_pos_q;
	for (unsigned int i = 0; i < row_val.size(); ++i) {
		if (row_val[i] == -1) {
			row_pos_q = i;
			
		}
	}
	int col_pos_q;
	for (unsigned int i = 0; i < col_val.size(); ++i) {
		if (col_val[i] == -1) {
			col_pos_q = i;	
		}
	}
	for (unsigned int i = 0; i < ship_num_val.size(); ++i) {
		if (ship_num_val[i] == -1) {
			unknown_pos = i;
		}
	} //the above functions are for unknowns
	std::vector<int> ship_val_copy = copy_vector(ship_num_val);
	bool continuation = true;
	int correct_row;
	int correct_col;
	int correct_ship;
	if (unknown_yes == true) { //tests all possibilites for unknown cases
		for (unsigned int i = 0; i < col_val.size() && continuation; ++i) {
			for (unsigned int j = 0; j < row_val.size() && continuation; ++j) {
				for (unsigned int k = 0; k < 7 && continuation; ++k) {
					row_val[row_pos_q] = i;
					col_val[col_pos_q] = j;
					ship_num_val[unknown_pos] = k;
					bool val = false;
					board_check2(ship_table, ship_num_val[ship_num_val.size()-1], row_val, col_val, ship_num_val, sub_solution, final_solution, val);
					if (final_solution.size() > 0) {
						correct_row = i;
						correct_col = j;
						correct_ship = k;
							for (unsigned int l = 0; l < final_solution.size(); ++l) {
								if (final_solution[l][constraint_row[l]][constraint_col[l]] != constraint_char2[l]) {
									final_solution.erase(final_solution.begin() + l );
									l = 0;
								}
							}
						
						if (final_solution.size() > 0) {
							continuation = false;
							break;
						}
						
					}
					ship_num_val = ship_val_copy;
				}
			}

		}
		row_val[row_pos_q] = correct_row;
		col_val[col_pos_q] = correct_col;
		ship_num_val[unknown_pos] = correct_ship;
	}
	if (is_constrained) {
		for (unsigned int i = 0; i < final_solution.size(); ++i) {
			if (final_solution[i][constraint_row[i]][constraint_col[i]] != constraint_char2[i]) {
				final_solution.erase(final_solution.begin() + i );
				i = 0;
			}
		}
	}
	std::vector<std::vector<int> > final_row;
	std::vector<std::vector<int> > final_col; //the following code is for
	std::vector<std::vector<int> > final_ship; // finding statistics of final boards
	std::vector<std::vector<std::string> > final_alignment;
	std::vector<int> row_pos_val_s;
	std::vector<int> col_pos_val_s;
	std::vector<int> size_ship_s;
	std::vector<std::string> alignment_s;
	std::vector<int> row_pos_val;
	std::vector<int> col_pos_val;
	std::vector<int> size_ship;
	std::vector<std::string> alignment;
	for (unsigned int i = 0; i < final_solution.size(); ++i) {
		stat_info(final_solution[i],row_pos_val,col_pos_val,size_ship,alignment);
		for (unsigned int i = 0; i < row_pos_val.size(); ++i) {
			row_pos_val_s.push_back(row_pos_val[i]);
			col_pos_val_s.push_back(col_pos_val[i]);
			size_ship_s.push_back(size_ship[i]);
			alignment_s.push_back(alignment[i]);
		}
		final_row.push_back(row_pos_val_s);
		final_col.push_back(col_pos_val_s);
		final_ship.push_back(size_ship_s);
		final_alignment.push_back(alignment_s);
		row_pos_val.clear();
		col_pos_val.clear();
		size_ship.clear();
		alignment.clear();
		row_pos_val_s.clear();
		col_pos_val_s.clear();
		size_ship_s.clear();
		alignment_s.clear();
	}
	Solution(final_solution,final_row,final_col,final_ship,row_val,col_val,final_alignment,find_all);
	
} // the above function finally prints all solutions/1 solutions