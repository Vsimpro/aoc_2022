/* AoC day 2a
What would your total score be if
everything goes exactly according to your strategy guide?
*/
#include <fstream>
#include <sstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* Rock : 1,   Paper : 2,   Scissor : 3 */
/* Rock : A,X, Paper : B,Y, Scissor : C,Z */
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

/* return winner, 0 as player, 1 as elf, 2 as draw. */
int chooseWinner(int player_pick, int elf_pick)
{
    /* 1 wins 3, 3 wins 2, 2 wins 1 */
    if (player_pick == 1 and elf_pick == 3 or
        player_pick == 3 and elf_pick == 2 or
        player_pick == 2 and elf_pick == 1) 
        {
            return 0;
        }

    if (player_pick == elf_pick) 
    {
         return 2;
    }

    return 1;
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
            int winner = chooseWinner(player_pick, elf_pick);

            // Player wins
            if (winner == 0) 
            { 
                player_score = player_score + 6;
            }

            // Draw
            if (winner == 2)
            {  
                player_score = player_score + 3;
            }

            player_score = player_score + player_pick;

        }
    }
    cout << "Total score: " << player_score << endl;
    return 0;
}