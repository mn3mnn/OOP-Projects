# NimGame OOP

## using :

- **an abstract class and Inheritance** to implement different variants of the game.

- **Backtracking** to implement a non-defeatable computer player.




## PB statement:
Abdelrahman Mohamed is bored of the simple Nim game we developed in the lecture. He decided to make new variants of it but not sure how. His friend Salaheldeen Salah suggested these two different games with different rules. Help them implement them with a computer player. (If you can, make the code generic and structured into functions or modules using OOP techniques. If possible, make a parent abstract class that defines the required behavior of the game and then its children are different variants of the game.)

•	Variant one. In the simple Nim game we developed, the player who takes the last coin loses and the coins the players took away were simply ignored. In this game, the coins go into a pile for each player. The player whose pile contains an even number of coins after the last one is taken wins the game.

•	Variant two. In the simple Nim game we developed, all the coins where put in one pile. In this variant the money is divided to 3 piles as in picture. Each player takes 1, 2 or 3 coins from any pile he likes. The player that takes the last coin loses. 


## header file:

```
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
```
