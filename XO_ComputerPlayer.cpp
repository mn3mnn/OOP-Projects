//// This class represents AI computer player
// Created by Monem on 11/7/2022.
//

#include "XO_Classes.hpp"
#include "iostream"
using namespace std;


ComputerPlayer::ComputerPlayer(char symbol, Board & board): Player(symbol) {
    this->name = "Computer Player";
    this->curr_board = &board;
    cout << "My names is " << name << endl;
}


void ComputerPlayer::get_move(int &x, int &y) {
    // get Computer's best move using minimax algo
    get_best_move(x, y);
}

///////////////////////////////////////////////////////////////////////////////

// calculates the best score we can obtain
// maximizing computer score, minimizing human player score
int ComputerPlayer::minimax(int depth, bool isMaximizing){
    static char human_symbol = (symbol == 'o' ? 'x' : 'o');
    /// base case
    // if there is a winner
    if (curr_board->is_winner()){
        // if the human player had won , and it is computer's turn
        if (isMaximizing){
            return -1;
        }
        // if the computer had won , and it is human's turn
        else{
            return 1;
        }
    }
    // if tie
    if (depth > 9){
        return 0;
    }

    int score = 0;
    int best_score = 0;

    /// Maximizing score (computer's turn)
    if (isMaximizing){
        best_score = -1000;

        // Traverse empty cells and evaluate best score for each move
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (curr_board->is_empty_pos(i, j)){
                    // make a move
                    curr_board->update_board(i, j, symbol);
                    // Call minimax recursively and choose the maximum value
                    score = minimax(depth + 1, !isMaximizing);
                    curr_board->undo_move(i, j);
                    best_score = max(best_score, score);
                }
            }
        }
        return best_score;
    }

    /// Minimizing score (human's turn)
    else{
        best_score = 1000;

        // Traverse empty cells and evaluate best score for each move
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (curr_board->is_empty_pos(i, j)){
                    // make a move
                    curr_board->update_board(i, j, human_symbol);
                    // Call minimax recursively and choose the minimum value
                    score = minimax(depth + 1, !isMaximizing);
                    curr_board->undo_move(i, j);
                    best_score = min(best_score, score);
                }
            }
        }
        return best_score;
    }
}


void ComputerPlayer::get_best_move(int& x, int& y){
    int score = 0;
    int best_score = -1000;

    // Traverse all empty cells, calculate score for each one, choose the max score
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (curr_board->is_empty_pos(i, j)){
                // make a move
                curr_board->update_board(i, j, symbol);
                // Call minimax and get the best score
                score = minimax(curr_board->get_n_moves() + 1, false);
                curr_board->undo_move(i, j);
                // choose max score from all empty cells
                if (score > best_score){
                    best_score = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
}

