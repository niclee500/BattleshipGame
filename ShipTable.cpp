#include "ShipTable.h"
#include <vector>
#include <string>
#include <iostream>


ShipTable::ShipTable() {
	std::vector<std::vector<char> > empty;
	std::vector<int> empty1;
	std::vector<int> empty2;
	std::vector<int> empty3;
	ship_table = empty;
	ship_num_val = empty1;
	row_val = empty2;
	col_val = empty3;
}
ShipTable::ShipTable(std::vector<std::vector<char> > ship_table_c, std::vector<int> ship_num_val_c, std::vector<int> row_val_c, std::vector<int> col_val_c) {
	ship_table = ship_table_c;
	ship_num_val = ship_num_val_c;
	col_val = col_val_c;
	row_val = row_val_c;
}

	
