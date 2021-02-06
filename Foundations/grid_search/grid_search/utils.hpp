//
//  read_file.hpp
//  grid_search
//
//  Created by Anuj Dutt on 2/5/21.
//

#ifndef utils_hpp
#define utils_hpp

using namespace std;

enum class State {
    kEmpty,
    kObstacle,
    kClosed,
    kStart,
    kFinish,
    kPath
};

#include <stdio.h>

vector<State> ParseLine(string s);
vector<vector<State>> ReadBoardFile(string fpath);
void PrintBoard(vector<vector<State>> board);
void StreamingString();
void StreamingStringCompact();
void VectorPushBack();


vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]);
int Heuristic(int x1, int y1, int x2, int y2);
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openList, vector<vector<State>> &grid);
void CellSort(vector<vector<int>> *v);
bool CheckValidCell(int x, int y, vector<vector<int>> &grid);
void ExpandNeighbors(const vector<int> &current, int goal[2], vector<vector<int>> &openlist, vector<vector<State>> &grid);

#endif /* utils_hpp */
