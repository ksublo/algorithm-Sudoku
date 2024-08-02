#include "sudoku.h"

//PRIVATE
void Sudoku::placeNumber(int row, int col, int num) {
    int blockIndex = (row / 3) * 3 + col / 3;
    grid[row][col] = num;
    rowUsed[row][num] = true;
    colUsed[col][num] = true;
    blockUsed[blockIndex][num] = true;
}

void Sudoku::removeNumber(int row, int col, int num) {
    int blockIndex = (row / 3) * 3 + col / 3;
    grid[row][col] = 0;
    rowUsed[row][num] = false;
    colUsed[col][num] = false;
    blockUsed[blockIndex][num] = false;
}

bool Sudoku::isSafe(int row, int col, int num)
{
    int blockIndex = (row / 3) * 3 + col / 3;
        bool safe = !rowUsed[row][num] && !colUsed[col][num] && !blockUsed[blockIndex][num];

    return safe;
}

pair<int, int> Sudoku::findLocation() {
    int optionsCount = 11;
    pair<int, int> bestLocation(-1, -1);

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                int options = countOptions(row, col);
                if (options < optionsCount) {
                    optionsCount = options;
                    bestLocation = make_pair(row, col);
                }
            }
        }
    }

    return bestLocation;
}

int Sudoku::countOptions(int row, int col) {

    vector<bool> opt(10, true);

    for (int i = 0; i < 9; i++) {
        if (grid[row][i] != 0) 
            opt[grid[row][i]] = false;
        if (grid[i][col] != 0) 
            opt[grid[i][col]] = false;
        if (grid[row - row % 3 + i / 3][col - col % 3 + i % 3] != 0) 
            opt[grid[row - row % 3 + i / 3][col - col % 3 + i % 3]] = false;
    }

    return count(opt.begin(), opt.end(), true);
}

//PUBLIC
Sudoku::Sudoku() : grid(9, vector<int>(9, 0)), 
                   rowUsed(9, vector<bool>(10, false)),
                   colUsed(9, vector<bool>(10, false)), 
                   blockUsed(9, vector<bool>(10, false)) {}


void Sudoku::readFile(const string &filename)
{
  ifstream file(filename);

    if (file.is_open()) {
        string line;
        for (int row = 0; row < 9 && getline(file, line); row++) {

            stringstream ss(line);
            char ch;

            for (int col = 0; col < 9 && ss >> ch; col++) {

                if (isdigit(ch)) {
                    int num = ch - '0';
                    placeNumber(row, col, num);
                }
            }
        }

        file.close();
    }
}


bool Sudoku::solve()
{
    pair<int, int> row_col = findLocation();
    
    if (row_col.first == -1)
        return true;

    int row = row_col.first;
    int col = row_col.second;

    //vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int N = 0; N <= 9; N++) {
        if (isSafe(row, col, N)) {
            placeNumber(row, col, N);

            if (solve()) 
                return true;

            removeNumber(row, col, N); 
        }
    }

    return false; 
}


void Sudoku::printGrid()
{
   for (int row = 0; row < 9; row++){
        if (row > 0 && row % 3 == 0) 
            cout << "------+-------+------" << endl;
        
        for (int col = 0; col < 9; col++){
            if (col > 0 && col % 3 == 0) 
                cout << "| ";
            
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}
