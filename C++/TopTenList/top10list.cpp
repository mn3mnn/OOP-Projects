//
// Created by Monem on 10/13/2022.
//

#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;


struct Player{
    int score;
    string name;
    Player* next;
    Player* prev;

public:
    Player() : score(0), next(nullptr), prev(nullptr) {}
    Player(int sc, string nm) : score(sc), name(nm), next(nullptr), prev(nullptr) {}
};


class Top_ten{
    // top = player with the highest score
    Player* top;
    // last = last player in the list (when we reached TOP_SIZE only), otherwise is nullptr
    Player* last;
    //
    const int TOP_SIZE = 10;
    // counter variable
    int size;
    // take valid input between 0 and 3
    int get_choice();
    // if we reached the TOP_SIZE, free memory allocated for the last player
    void del_last_player();

public:
    Top_ten() : top(nullptr), last(nullptr), size(0), TOP_SIZE(10) {}
    //
    void add_new_player(int score, string name);
    void show_top_ten();
    void get_score(string name);
    // shows menu and gets input
    void start_menu_sys();
    // free all the allocated memory
    void del_all_list();

};


// if we reached the TOP_SIZE, free memory allocated for the last player
void Top_ten::del_last_player() {
    last->prev->next = nullptr;
    delete last;
    last = nullptr;
    size--;
}


// free all the allocated memory
void Top_ten::del_all_list(){
    Player* tmp = top;
    while (tmp != nullptr){
        tmp = top->next;
        delete top;
        top = tmp;
    }
}


// insert player to the list
void Top_ten::add_new_player(int score, string name) {

    // if the topTen is empty, create new player
    if (top == nullptr){
        top = new Player(score, name);
        size++;
    }
    // if there is one player or more
    else {
        // if we reached TOP_SIZE, delete last player
        if (last){
            del_last_player();
        }
        // if the score is greater than the top score
        if (score >= top->score){
            Player* nextPlayer = top;
            top = new Player(score, name);
            top->next = nextPlayer;
            top->next->prev = top;
            size++;
        }
        // if the score isn't greater than the top score and there is only one player
        else if (score < top->score && !top->next){
            top->next = new Player(score, name);
            top->next->prev = top;
            size++;
        }
        // else traverse and insert the score into its correct order
        else{
            Player* tmp = top;
            while (tmp->next != nullptr){
                if (score < tmp->score && score >= tmp->next->score){
                    Player* nextPlayer = tmp->next;
                    tmp->next = new Player(score, name);
                    tmp->next->prev = tmp;
                    tmp->next->next = nextPlayer;
                    tmp->next->next->prev = tmp->next;
                    size++;
                    break;
                }
                tmp = tmp->next;
            }
            // if the score is the least score, add it to the end of list
            if (tmp->next == nullptr){
                tmp->next = new Player(score, name);
                tmp->next->prev = tmp;
                size++;
            }
        }
    }

    // if we reached TOP_SIZE, make last = the last player
    if (size == TOP_SIZE){
        Player* tmp = top;
        while (tmp->next != nullptr){
            tmp = tmp->next;
        }
        last = tmp;
    }
    cout << "score added successfully.\n\n";
}


void Top_ten::show_top_ten() {
    cout << "Top ten:\n";
    int n = 1;
    for (Player* i = top; i != nullptr; i = i->next) {
        cout << "#" << n++ << "  " << i->name << "  " << i->score << '\n';
    }
    cout << "\n";
}


// print the highest score for a player
void Top_ten::get_score(string name) {
    bool found = false;
    for (Player* i = top; i != nullptr; i = i->next) {
        if (i->name == name){
            found = true;
            cout << name << ":  " << i->score << "\n\n";
            break;
        }
    }
    if (!found){
        cout << "Player isn't in the list!\n\n";
    }
}


// take valid input between 0 and 3
int Top_ten::get_choice(){
    string menu = "select option to execute:\n"
                  "(1) add a new score\n"
                  "(2) show top ten\n"
                  "(3) show player's score\n"
                  "(0) exit \n";
    cout << menu;
    try {
        int choice = 0;
        cin >> choice;
        if (!cin){
            cin.clear();
            cin.ignore(100, '\n');
            throw invalid_argument("enter numbers only! try again:\n");
        }
        else if (choice > 3 || choice < 0){
            cin.clear();
            cin.ignore(100, '\n');
            throw invalid_argument("enter numbers from 0 to 3 only! try again:\n");
        }

        return choice;
    }
    catch (invalid_argument& e){
        cerr << e.what();
    }
}


// run the program
void Top_ten::start_menu_sys() {
    int c = get_choice();
    while (c != 0){
        if (c == 1){
            string name;
            int score = 0;
            cout << "enter player name: ";
            cin >> name;
            cout << "enter player score: ";
            cin >> score;
            add_new_player(score, name);
        }
        else if (c == 2){
            show_top_ten();
        }
        else if (c == 3){
            string name;
            cout << "enter player name: ";
            cin >> name;
            get_score(name);
        }

        c = get_choice();
    }
    // if choice = 0, free all the allocated memory
    del_all_list();
}


int main() {
    Top_ten topTen;
    topTen.start_menu_sys();
}

