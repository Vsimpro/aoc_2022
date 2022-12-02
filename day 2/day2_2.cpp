/* AoC day 2a
Following the Elf's instructions for the second column,
What would your total score be if
everything goes exactly according to your strategy guide?
*/
#include <fstream>
#include <sstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* Rock : 1,   Paper : 2,   Scissor : 3 
   Rock : A, Paper : B, Scissor : C 
New instructions: 
    X -> you must lose. 
    Y -> you must draw
    Z -> you must win. */

int pointsFromSelection(char selection) 
{
    int points = 0;
    char selection_abc [3] = {'A', 'B', 'C'};
    char selection_xyz [3] = {'X', 'Y', 'Z'};
    
    for (int i = 0; i < 3; i++) 
    {
        if (selection_abc[i] == selection or
            selection_xyz[i] == selection) 
            {
                points = i + 1;
                break;
            }
    }
    return points;
}

/* situation: 1 -> lose, 2 -> draw, 3 -> win */
int chooseTactic(int elf_pick, int situation) 
{
    int playerMustPick = 0;
    int elf_picks    [] = {1, 2, 3};
    int player_picks [] = {3, 1, 2};
    /* 1 wins 3, 3 wins 2, 2 wins 1 */

    // Lose
    if (situation == 1) 
    {
        for (int i = 0; i < 3; i++) 
        {
            if (elf_pick == elf_picks[i]) 
            {
                playerMustPick = player_picks[i];
                break;
            }
        }
    }

    // Win
    if (situation == 3) 
    {
        for (int i = 0; i < 3; i++) 
        {
            if (elf_pick == player_picks[i]) 
            {
                playerMustPick = elf_picks[i];
                break;
            }
        }
    }

    // Draw
    if (situation == 2) 
    {
        playerMustPick = elf_pick;
    }

    return playerMustPick;
}

int main() 
{
    string line;
    string file_name = "input.txt";

    int player_score = 0;

    ifstream file(file_name);
    while (getline(file, line))
    {
        string data;
        stringstream temp;

        if (line != "") 
        {
            int elf_pick =    pointsFromSelection(line[0]);
            int player_pick = pointsFromSelection(line[2]);
            
            if (player_pick == 3) 
            { 
                player_score = player_score + 6;
            }

            if (player_pick == 2)
            {  
                player_score = player_score + 3;
            }

            player_pick = chooseTactic(elf_pick, player_pick);
            player_score = player_score + player_pick;
        }
    }
    cout << "Total score: " << player_score << endl;
    return 0;
}