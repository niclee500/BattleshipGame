#include <iostream>
#include <vector>
#include <string>

class ShipTable {
public:
	ShipTable();
	ShipTable(std::vector<std::vector<char> > ship_table_c, std::vector<int> ship_num_val_c, std::vector<int> row_val_c, std::vector<int> col_val_c);
	
private:
	std::vector<std::vector<char> > ship_table;
	std::vector<int> ship_num_val;
	std::vector<int> row_val;
	std::vector<int> col_val;
};