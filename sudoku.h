#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/**
 * @class Sudoku
 * @brief A class for solving Sudoku puzzles
 *
 * Sudoku class is designed to solve Sudoku puzzles using a backtracking, Constraint Satisfaction Problem (CSP) and Heuristic for Choosing Cells.
 * It reads a puzzle from a file, solves it if possible, and prints the solution.
 */
class Sudoku{
   private:

    vector<vector<int>> grid; ///< 2D vector representing the Sudoku grid
    vector<vector<bool>> rowUsed; ///< 2D vector tracking used numbers in each row
    vector<vector<bool>> colUsed; ///< 2D vector tracking used numbers in each column
    vector<vector<bool>> blockUsed; ///< 2D vector tracking used numbers in each 3x3 block

     /**
     * @brief Checks if a number can be safely placed in a given cell
     * @param row The row index of the cell
     * @param col The column index of the cell
     * @param num The number to be placed
     * @return true if the number can be placed, false otherwise
     */
    bool isSafe(int row, int col, int num);

     /**
     * @brief Finds the best unassigned location in the grid
     * @return A pair of integers representing the row and column of the chosen cell
     */
    pair<int, int> findLocation();

     /**
     * @brief Counts the number of valid options for a cell
     * @param row The row index of the cell
     * @param col The column index of the cell
     * @return The number of valid options for the cell
     */
    int countOptions(int row, int col);

    /**
     * @brief Places a number in a specified cell
     * @param row The row index of the cell
     * @param col The column index of the cell
     * @param num The number to be placed
     */
    void placeNumber(int row, int col, int num);

    /**
     * @brief Removes a number from a specified cell
     * @param row The row index of the cell
     * @param col The column index of the cell
     * @param num The number to be removed
     */
    void removeNumber(int row, int col, int num);

   public:
   
    /**
     * @brief Constructor for Sudoku class
     *
     * Initializes the Sudoku grid and the tracking vectors for rows, columns, and blocks.
     */
    Sudoku();

    /**
     * @brief Reads a Sudoku puzzle from a file
     * @param filename The name of the file containing the Sudoku puzzle
     */
    void readFile(const string& filename);

    /**
     * @brief Solves the Sudoku puzzle
     * @return true if the puzzle is solved, false otherwise
     */
    bool solve();

    /**
     * @brief Prints the Sudoku grid
     */
    void printGrid();
};

