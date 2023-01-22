//
// Created by Monem on 12/11/2022.
//

#include "NimGame.h"

///////////////////////////////////////////////////////////////////////////////////////////////

/// abstract class

void NimGame::run() {
    giveInstructions();
    while (!gameOver()){
        displayState();
        updateState(getPlayerMove());
        displayState();
        system("pause");
        system("cls");
        isComTurn = !isComTurn;
    }
    // last one played
    isComTurn = !isComTurn;

    announceWinner();
}



//////////////////////////////////////////////////////////////////////////////////////////////

/// variant 1

void NimGame_1::run() {
    NimGame::run();
}

void NimGame_1::giveInstructions() {
    cout << "Welcome to Nim.\n";
    cout << "Variant one:\n"
         << "In this game, the coins go into a pile for each player.\n"
         << "The player whose pile contains an even number of coins after the last one is taken wins the game\n";
    cout << "We start with " << nCoins << " coins"<< '\n';
    cout << "Each one picks 1 to 3 coins.\n\n";
}

void NimGame_1::displayState() {

    cout << "\n----------------\n";
    cout << "We have " << nCoins << " coins.\n\n";
    cout << "[ ";
    for (int i = 0; i < nCoins; ++i) {
        cout << 'O' << ' ';
    }
    cout << " ]" << '\n';

    cout << "\nPlayer's Pile: [ ";
    for(auto& p : pile1) cout << p << ' ';
    cout << " ]   ";
    cout << " you have: " << pile1.size() <<'\n';

    cout << "\nComputer's Pile: [ ";
    for(auto& p : pile2) cout << p << ' ';
    cout << " ]   ";
    cout << " computer have: " << pile2.size() <<'\n';

    cout << "\n----------------\n";

}

int NimGame_1::getPlayerMove() {
    int n = 1;
//    cout << (isComTurn ? "Computer" : "Human") << " plays: \n";
    if (isComTurn){
         n = getBestMove(nCoins);
         // take 1 coin if no good move
         n = (n == 0 ? 1 : n);
         cout << "\nComputer takes " << n << " coins.\n" ;
    }
    else{
        cout << "Pls pick 1 to 3 coins that is <= remaining coins: \n";
        cin >> n;
        while (n < 1 || n > 3 || n > nCoins) {
            cout << "Pls pick 1 to 3 coins that is <= remaining coins: \n";
            cin >> n;
        }
    }
    return n;
}

void NimGame_1::updateState(int n) {
    nCoins -= n;
    if (isComTurn){
        for (int i = 0; i < n; ++i) {
            pile2.push_back('O');
        }
    }
    else{
        for (int i = 0; i < n; ++i) {
            pile1.push_back('O');
        }
    }
}

bool NimGame_1::gameOver() {
    return nCoins == 0;
}

void NimGame_1::announceWinner() {
    displayState();
    // if num of coins in player's pile is even and n of coins in computer's pile is odd
    if (!(pile1.size() & 1) && (pile2.size() & 1)){
        cout << "\n###### Player1 Wins ######\n";
    }
    else if ((pile1.size() & 1) && !(pile2.size() & 1)){
        cout << "\n###### Computer Wins ######\n";
    }
    else{
        cout << "##### DRAW #####\n";
    }
}

// return num of coins leads to win, return 0 if there is no good move
int NimGame_1::getBestMove(int nCoins_){
    // var to swap turns between computer and player
    static bool comTurn = isComTurn;

    for (int n = 1; n <= 3 && (nCoins_ - n) >= 0; ++n) {
        // try to choose n coins
        for (int i = 0; i < n; ++i) {
            (comTurn ? pile2.push_back('O') : pile1.push_back('O'));
        }
        // if this move makes the opponent in bad position return it
        if (isBadPosition(nCoins_ - n, !comTurn)){
            // undo changes in pile2 and return n
            for (int i = 0; i < n; ++i) {
                (comTurn ? pile2.pop_back() : pile1.pop_back());
            }
            return n;
        }
        // undo the choice and try another one
        for (int i = 0; i < n; ++i) {
            (comTurn ? pile2.pop_back() : pile1.pop_back());
        }
    }
    // no good move
    return 0;

}


bool NimGame_1::isBadPosition(int nCoins_, bool comTurn){
    if (comTurn){
        // if there is 1 coin left and computer's pile has even-number of coins
        if (nCoins_ == 1 && !(pile2.size() & 1)){
            return true;
        }
    }
    else{
        // if there is 1 coin left and player's pile has even-number of coins
        if (nCoins_ == 1 && !(pile1.size() & 1)){
            return true;
        }
    }
    return getBestMove(nCoins_) == 0;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////

/// variant 2


void NimGame_2::run() {
    NimGame::run();
}

void NimGame_2::giveInstructions() {
    cout << "Welcome to Nim.\n";
    cout << "Variant two.\n"
         << "In this variant the money is divided to 3 piles.\n"
         <<   "Each player takes 1, 2 or 3 coins from any pile he likes.\n"
         <<   "The player that takes the last coin loses.\n\n";

}

void NimGame_2::displayState() {
    for (int i = 0; i < coinPiles.size(); ++i) {
        cout << "Row "<< i<< ": [ ";
        for (int j = 0; j < coinPiles[i].size(); ++j) {
            cout << coinPiles[i][j] << ' ';
        }
        cout << "]\n";
    }
    cout << '\n';
}

int NimGame_2::getPlayerMove() {
    // n = total picked coins
    int sum = 0;
    mv.erase(mv.begin(), mv.end());

    if (isComTurn){
        // mv = best move we can get
        mv = findGoodMove(coinPiles);
        // if no good move choose any valid move
        if (mv == NO_GOOD_MOVE){
            vector<vector<int>> validMoves;
            getPossibleMoves({0, 1, 2,3}, coinPiles, validMoves);
            mv = validMoves[0];
        }
        for (int i : mv) {
            sum += i;
        }
    }
    else{
        cout << "Pls pick 1 to 3 coins that is <= remaining coins in each row: \n";
        while (sum < 1 || sum > 3) {
            sum = 0;
            mv.erase(mv.begin(), mv.end());
            for (int i = 0; i < 3 && sum < 3; ++i) {
                cout << "num of coins to pick from row" << i << " : ";
                int n = 0;
                cin >> n;
                // take valid n of coins
                while (n < 0 || n > 3 || n > coinPiles[i].size()) {
                    cout << "Pls pick 1 to 3 coins that is <= remaining coins in each row :\n";
                    cout << "num of coins to pick from row" << i << " : ";
                    cin >> n;
                }
                mv.push_back(n);
                sum += n;
            }
            if (sum == 0 || sum > 3){
                cout << "invalid input try again\n";
            }
        }
        while (mv.size() < 3){
            mv.push_back(0);
        }
        cout << '\n';

    }
    return sum;
}

void NimGame_2::updateState(int n) {
    nCoins -= n;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < mv[i]; ++j) {
            coinPiles[i].pop_back();
        }
    }

}

void NimGame_2::announceWinner() {
    displayState();
    // isComTurn = 1, if the computer is the last one played
    if (isComTurn){
        cout << "\n###### Player1 Wins ######\n";
    }
    else{
        cout << "\n###### Computer Wins ######\n";
    }
}


bool NimGame_2::gameOver() {
    for (int i = 0; i < coinPiles.size(); ++i) {
        if (!coinPiles[i].empty()){
            return false;
        }
    }
    return true;
}


/// compute all valid moves for coinPiles
// nums = {0, 1, 2, 3} , n of coins we can pick
// validMvs = the resulting vector
// coinPiles = the piles which we compute the valid moves for
void NimGame_2::getPossibleMoves(const vector<int>& nums, vector<vector<char>> coinPiles_,
                      vector<vector<int>>& validMvs, vector<int> tmp_mv, int depth){

    if (depth == 3){
        // sum = sum of the curr move
        int sum = 0;
        for (auto& n : tmp_mv){
            sum += n;
        }
        // if sum > 3 ignore this move
        if (sum > 0 && sum <= 3){
            // if mv[i] > the available coins ignore this move
            for (int i = 0; i < tmp_mv.size(); ++i) {
                if (tmp_mv[i] > coinPiles_[i].size()){
                    tmp_mv.pop_back();
                    return;
                }
            }
            // add curr move to the valid moves
            validMvs.push_back(tmp_mv);
        }
        tmp_mv.pop_back();
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        tmp_mv.push_back(nums[i]);
        getPossibleMoves(nums, coinPiles_, validMvs, tmp_mv, depth + 1);
        tmp_mv.pop_back();
    }
    tmp_mv.pop_back();
}


// try all available moves until find a good one then return it else return NO_GOOD_MOVE
vector<int> NimGame_2::findGoodMove(vector<vector<char>> coinPiles_){
    // validMoves = all moves valid moves for current coinPiles_
    vector<vector<int>> validMoves;
    getPossibleMoves({0,1,2,3}, coinPiles_, validMoves);
    // try to perform this moves
    for (int i = 0; i < validMoves.size(); ++i) {
        // try this move
        do_move(coinPiles_, validMoves[i]);
        // if this move puts the opponent in bad position return it
        if (isBadPosition(coinPiles_)){
            return validMoves[i];
        }
        // undo move and try another one
        undo_move(coinPiles_, validMoves[i]);
    }

    // return no good move {0, 0, 0}
    return NO_GOOD_MOVE;
}

// return true if coinPiles_ has only one coin
// DO mutual recursion
bool NimGame_2::isBadPosition(vector<vector<char>> coinPiles_) {

    for (int i = 0; i < coinPiles_.size(); ++i) {
        for (int j = i + 1; j < coinPiles_.size(); ++j) {
            if (coinPiles_[i].empty() && coinPiles_[j].empty()) {
                for (int r = 0; r < 3; ++r) {
                    if (r != i && r != j){
                        // return true if the only non-empty pile has one coin
                        if (coinPiles_[r].size() == 1) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    // if it's not the final pos do recursion to get another move
    return findGoodMove(coinPiles_) == NO_GOOD_MOVE;

}


void NimGame_2::undo_move(vector<vector<char>> &coinPiles_, const vector<int> &mv_){

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < mv_[i]; ++j) {
            coinPiles_[i].push_back('O');
        }
    }
}

void NimGame_2::do_move(vector<vector<char>> &coinPiles_, const vector<int> &mv_) {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < mv_[i]; ++j) {
            coinPiles_[i].pop_back();
        }
    }
}

