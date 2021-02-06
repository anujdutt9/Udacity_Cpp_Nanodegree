//
//  main.cpp
//  grid_search
//
//  Created by Anuj Dutt on 2/5/21.
//

#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // MARK: Open and read board file
    vector<vector<State>> grid = ReadBoardFile("/Users/anujdutt/Downloads/Development/C++ Programming/grid_search/grid_search/grid_search/data.board");
    
    cout << "grid number of rows: " << grid.size() << endl;
    cout << "grid number of cols: " << grid[0].size() << endl;
    
    // MARK: Perform A Star Search
    int init[2] = {0, 0};
    int goal[2] = {4, 5};
    vector<vector<State>> solution = Search(grid, init, goal);
    
    // Print the board
    PrintBoard(grid);
    cout << "\n";
    
    PrintBoard(solution);
    
    return 0;
}
