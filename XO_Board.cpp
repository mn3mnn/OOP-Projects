// Class definition for XO_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1


// Contributor: AbdelMonem Tarek
// Date: 7/11/2022

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "XO_Classes.hpp"
using namespace std;

// Return true  if move is valid and put it on board_ptr
// within board_ptr boundaries in empty cell
// Return false otherwise
bool Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
       board[x][y] = toupper(mark);
       n_moves++;
      return true;
   }
   // undo a move
   else if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] != 0) && mark == 0){
       board[x][y] = mark;
       n_moves--;
       return true;
   }
   else{
      return false;
   }
}


bool Board::is_empty_pos(int x, int y){
    return !(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0);
}


void Board::undo_move(int x, int y){
    if (!is_empty_pos(x, y)){
        update_board(x, y, 0);
    }
}

// Display the board_ptr and the pieces on it
void Board::display_board() {
    int n = 0;
    cout << endl;
   for (int i: {0,1,2}) {
      cout << "\n| ";
      for (int j: {0,1,2}) {
         cout << '(' << n++ << ')';
         cout << setw(3) << board [i][j] << " |";
      }
      cout << "\n--------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board[i][0])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
            {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
        {return true;}
    return false;
}

// Return true if 9 moves are done and no winner
bool Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}


int Board::get_n_moves() const {
    return n_moves;
}

