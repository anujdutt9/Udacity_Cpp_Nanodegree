//
//  utils.cpp
//  grid_search
//
//  Created by Anuj Dutt on 2/5/21.
//

#include <iostream>
#include <string>
// lib to open and read files
#include <fstream>
// lib to create vectors
#include <vector>
// lib to parse string to int, char etc. line by line from file
#include <sstream>
// lib for sorting
#include <algorithm>
#include "utils.hpp"

using namespace std;

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

/*
    MARK: Read and load data from file
*/

// Function to read string row by row from file
vector<State> ParseLine(string s){
    // vector variable
    vector<State> row = {};
  
    // create a istringstream temp variable
    istringstream my_stream(s);

    char c;
    int n;
    
    // Read the int into the vector
    while (my_stream >> n >> c){
        if (n == 0){
            row.push_back(State::kEmpty);
        }
        else{
            row.push_back(State::kObstacle);
        }
    }

    return row;
}


// Function to open and read board file
vector<vector<State>> ReadBoardFile(string fpath){
    cout << "RUN: ReadBoardFile" << "\n";
    
    // Declare an empty board variable here with
    // type vector<vector<int>>
    vector<vector<State>> board{};
    
    // define and open the board file
    fstream board_file (fpath);
    
    // if file is opened, returns true else false
    if (board_file){
        cout << "File opened successfully...\n";
    }
    else{
        cout << "Error opening file...\n";
    }
    
    // string variable to store data read from file
    string line;
    
    // read data from file into string variable and print it out
    while(getline(board_file, line)){
        // get data into a single vector
        vector<State> row = ParseLine(line);
        
        // push the vector with data to another vector
        board.push_back(row);
    }
    
    // close the file once done reading
    board_file.close();
    
    return board;
}


// Function to return string corresponding to cell state
string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::kStart: return "🚦   ";
    case State::kFinish: return "🏁   ";
    default: return "0   ";
  }
}


// Function to print a 2D grid
void PrintBoard(vector<vector<State>> board){
    for (int i=0; i < board.size(); ++i){
        for (int j=0; j < board[i].size(); ++j){
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}


/*
    MARK: A Star Search
*/

// Function to perform A* Search
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]){
    // Create the vector of open nodes.
    vector<vector<int>> open {};
    
    int x = init[0];
    int y = init[1];

    int g = 0;

    int h = Heuristic(x, y, goal[0], goal[1]);

    // Use AddToOpen to add the starting node to the open vector.
    AddToOpen(x, y, g, h, open, grid);
    
    while (open.size() > 0){
        // Sort the open list using CellSort, and get the current node.
        CellSort(&open);
        auto current = open.back();
        open.pop_back();
        
        // Get the x and y values from the current node,
        // and set grid[x][y] to kPath.
        x = current[0];
        y = current[1];
        grid[x][y] = State::kPath;

        // Check if you've reached the goal. If so, return grid.
        if ((x == goal[0]) && (y == goal[1])){
            grid[0][0] = State::kStart;
            grid[goal[0]][goal[1]] = State::kFinish;
            return grid;
        }
        
        // If we're not done, expand search to current node's neighbors.
        ExpandNeighbors(current, goal, open, grid);
      }
    
    return vector<vector<State>>{};
}


// Heuristics calculation using Manhattan Distance
int Heuristic(int x1, int y1, int x2, int y2){
  return abs(x2 - x1) + abs(y2 - y1);
}

// Function to Add a node to the open list and mark it as open.
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openList, vector<vector<State>> &grid){
  openList.push_back({x,y,g,h});
  grid[x][y] = State::kClosed;
}

// Function to compare the f-value of two nodes here
// where, f = g + h; input = {x,y,g,h}
bool Compare(vector<int> curr, vector<int> next){
  if ((curr[2] + curr[3]) > (next[2] + next[3])){
    return true;
  }
  return false;
}

// Sort the two-dimensional vector of ints in descending order.
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}

// Function to CheckValidCell here. Check that the
// cell is on the grid and not an obstacle (i.e. equals kEmpty).
bool CheckValidCell(int x, int y, vector<vector<State>> &grid){
  bool on_grid_x = (x >= 0 && x < grid.size());
  bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
    return grid[x][y] == State::kEmpty;
  return false;
}


// Expand current nodes's neighbors and add them to the open list.
void ExpandNeighbors(const vector<int> &current, int goal[2], vector<vector<int>> &openlist, vector<vector<State>> &grid) {

  // Get current node's data.
  int x1 = current[0];
  int y1 = current[1];
  int g1 = current[2];

  // Loop through current node's potential neighbors.
  for (int i=0; i < 4; i++){
    int x2 = x1 + delta[i][0];
    int y2 = y1 + delta[i][1];
    
    // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
    if (CheckValidCell(x2, y2, grid)){

      // Increment g value, compute h value, and add neighbor to open list.
      int g2 = g1 + 1;
      int h2 = Heuristic(x2, y2, goal[0], goal[1]);
      AddToOpen(x2, y2, g2, h2, openlist, grid);
    }
  }
}


// Function to explore istringstream
void StreamingString(){
    cout << "RUN: StreamingString" << "\n";
    
    string a("1 2 3");
    
    // create a istringstream temp variable
    istringstream my_stream(a);
    
    // variable to store values into from istringstream temp variable
    int n;
    
    // istringstream returns true if there are more chars to be read from the string,
    // else it restuns false, if at end of string.
    while (my_stream) {
        // ">>": extraction operator
        // writes the stream to the variable on the right of the operator and returns the
        // `istringstream` object which can be used as a boolean
        my_stream >> n;
        
        if (my_stream) {
            cout << "That stream was successful: " << n << "\n";
        }
        else {
            cout << "That stream was NOT successful!" << "\n";
        }
    }
}


// Function to explore istringstream in compact form
void StreamingStringCompact(){
    cout << "RUN: StreamingStringCompact" << "\n";
    
    string a("1 2 3");
    
    // create a istringstream temp variable
    istringstream my_stream(a);
    
    // variable to store values into from istringstream temp variable
    int n;

    while (my_stream >> n) {
        cout << "That stream was successful: " << n << "\n";
    }
    cout << "The stream has failed." << "\n";
}


// Function to add values to a vector
void VectorPushBack(){
    cout << "RUN: VectorPushBack" << "\n";
    
    // Initial Vector
    vector<int> v {1, 2, 3};
    
    // Print the contents of the vector
    cout << "Before: ";
    for (int i=0; i < v.size(); i++) {
      cout << v[i];
    }
    
    // Push 4 to the back of the vector
    v.push_back(4);

    // Print the contents again
    cout << "\nAfter: ";
    for (int i=0; i < v.size(); i++) {
      cout << v[i];
    }
}
