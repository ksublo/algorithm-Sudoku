#include "sudoku.h"

int main(int argc, char *argv[])
{
    //NACITANI Z MAINU
    if(argc < 2){
    //1
    cout << "FIRST SUDOKU" << endl;
    Sudoku sudoku1;
    sudoku1.readFile("sudoku1.txt");

    if (sudoku1.solve())
        sudoku1.printGrid();
    cout << endl;
    
    //2
    cout << "SECOND SUDOKU" << endl;
    Sudoku sudoku2;
    sudoku2.readFile("sudoku2.txt");

    if (sudoku2.solve())
        sudoku2.printGrid();
    cout << endl;

    //3
    cout << "THIRD SUDOKU" << endl;
    Sudoku sudoku3;
    sudoku3.readFile("sudoku3.txt");

    if (sudoku3.solve())
        sudoku3.printGrid();
    cout << endl;
    }

    //NACITANI Z ARGV-ARGC
    else if(argc == 2){
        const char *filename = argv[1];
        Sudoku sudoku;
        sudoku.readFile(filename);

        if (sudoku.solve()) {
            cout << "SOLUTION:" << endl;
            sudoku.printGrid();
        }
    }

    return 0;
}

//g++ -o sudoku main.cpp sudoku.cpp -std=c++11
//./sudoku
//./sudoku file.txt


