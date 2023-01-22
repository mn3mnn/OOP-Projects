//
// Created by Monem on 12/11/2022.
//

#ifndef A1_SHEETPB03_20210220_CPP_NIMGAME_H
#define A1_SHEETPB03_20210220_CPP_NIMGAME_H
#include <string>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;


/// abstract class
class NimGame {
protected:
    int nCoins = 0;
    bool isComTurn = false;
    virtual void giveInstructions() = 0;
    virtual void displayState() = 0;
    virtual int getPlayerMove() = 0;
    virtual void updateState(int n) = 0;
    virtual bool gameOver() = 0;
    virtual void announceWinner() = 0;

public:
    NimGame(int nCoins) : nCoins(nCoins) {}
    virtual ~NimGame() {}

    // start the game
    virtual void run();
};


/////////////////////////////////////////////////////////////////////////////////////


/// variant 1
class NimGame_1 : public NimGame{
    // pile1 for player coins
    vector<char> pile1;
    // pile2 for computer coins
    vector<char> pile2;

    void giveInstructions() override;
    void displayState() override;
    int getPlayerMove() override;
    void updateState(int n) override;
    bool gameOver() override;
    void announceWinner() override;
    int getBestMove(int nCoins_);
    bool isBadPosition(int nCoins_, bool comTurn);

public:
    NimGame_1(int nCoins) : NimGame(nCoins) {}
    virtual ~NimGame_1() {}
    void run() override;

};


///////////////////////////////////////////////////////////////////////////////


/// variant 2
class NimGame_2 : public NimGame{
    // coinPiles[i] = pile for row i
    vector<vector<char>> coinPiles;

    // vector to store how many coins from which row
    // mv[row_i] = num of coins to pick from row_i
    // mv is updated after each turn
    vector<int> mv;

    vector<int> NO_GOOD_MOVE = {0, 0, 0};

    void giveInstructions() override;
    void displayState() override;
    int getPlayerMove() override;
    void updateState(int n) override;
    void announceWinner() override;
    bool gameOver() override;
    // compute all valid moves for coinPiles
    void getPossibleMoves(const vector<int>& nums, vector<vector<char>> coinPiles_,
                          vector<vector<int>>& validMvs, vector<int> tmp_mv = {}, int depth = 0);
    // try all available moves until find a good one then return it
    vector<int> findGoodMove(vector<vector<char>> coinPiles_);
    // return true if coinPiles_ has only one coin, DO mutual recursion
    bool isBadPosition(vector<vector<char>> coinPiles_);
    // apply mv_ on coinPiles
    void do_move(vector<vector<char>> & coinPiles_, const vector<int> & mv_);
    // undo mv_
    void undo_move(vector<vector<char>> & coinPiles_, const vector<int> & mv_);


public:
    /// nCoins must be divisible by 3
    NimGame_2(int nCoins) : NimGame(nCoins), coinPiles(3, vector<char>()) {
        // init coin piles
        if (nCoins % 3 != 0){
            cerr << "nCoins must be divisible by 3 !\n";
            exit(1);
        }
        for (int i = 0; i < coinPiles.size(); ++i) {
            for (int j = 0; j < (nCoins / 3) - ((-1*i) + 1); ++j) {
                coinPiles[i].push_back('O');
            }
        }
    }

    virtual ~NimGame_2() {}

    void run() override;

};


#endif //A1_SHEETPB03_20210220_CPP_NIMGAME_H
