#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class game
{
private:
    int choice, comp_choice, player;
    char C1;
    string chose_1, chose_2, result;
    bool game_end = false;

public:
    void game_start();
    void menu();
    void comp_allot();
    void player_allot();
    string logic();
    void game_play();
};

void game::menu()
{
    cout << "\t choose your opton " << endl;
    cout << "1. ROCK " << endl;
    cout << "2. PAPPER " << endl;
    cout << "3. SICSSOR " << endl;
}
void game::comp_allot()
{
    comp_choice = ((rand() % 3) + 1);
    switch (comp_choice)
    {
    case 1:
        chose_2 = "ROCK";
        break;
    case 2:
        chose_2 = "PAPPER";
        break;
    case 3:
        chose_2 = "SCISSOR";
        break;

    default:
        break;
    }
}
void game::player_allot()
{
jump:
    cout << "enter your choice ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        chose_1 = "ROCK";
        break;
    case 2:
        chose_1 = "PAPER";
        break;
    case 3:
        chose_1 = "SCISSOR";
        break;
    default:
        cout << "INVALID CHOCIE TRY AGAIN " << endl;
        goto jump;
        break;
    }
}
string game::logic()
{
    if (chose_1 == chose_2)
    {
        cout << "both chose " << chose_1 << ", its a draw try again " << endl;
        game_play();
    }
    else
    {
        if (comp_choice > choice)
        {
            if ((comp_choice - choice) == 2)
            {
                cout << chose_1 << " beats " << chose_2 << endl;
                cout << "palyer wins !! ";
                game_end = true;
                getch();
                exit(0);
            }
            else
            {
                cout << chose_2 << " beats " << chose_1 << endl;
                cout << "computer wins!! ";
                game_end = true;
                getch();
                exit(0);
            }
        }
        else
        {
            if ((choice - comp_choice) == 2)
            {
                cout << chose_2 << " beats " << chose_1 << endl;
                cout << " computer wins!! ";
                game_end = true;
                getch();
                exit(0);
            }
            else
            {
                cout << chose_1 << " beats " << chose_2 << endl;
                cout << "palyer wins!! ";
                game_end = true;
                getch();
                exit(0);
            }
        }
    }
}
void game::game_start()
{
    while (game_end == false)
    {
    here:
        cout << "wanna play ROCK PAPPER AND SICSSOR!!! (Y/N) ";
        cin >> C1;
        if (C1 == 'N')
        {
            cout << "see you next time ";
            getch();

            exit(0);
        }
        else if (C1 != 'Y' && C1 != 'N')
        {
            cout << "INVALID INPUT, try again .....  " << endl;
            getch();
            goto here;
        }
        else
        {
            cout << " lets begin :) \n";
        }
        game_play();
    }
}
void game::game_play()
{
    menu();
    player_allot();
    cout << "you chose  " << chose_1 << endl;
    comp_allot();
    cout << "computer chose " << chose_2 << endl;
    logic();
}

int main()
{
    cout << "Welcome! ";
    game g1;
    g1.game_start();
    return 0;
}
