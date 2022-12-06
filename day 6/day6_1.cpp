/* AoC day 2a
How many characters need to be processed
before the first start-of-packet marker is detected?
*/
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int allUnique(char characters []) 
{
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            if (i == j) { continue; }

            if (characters[i] == characters[j]) 
            {
                return 0; // False
            }
        } 
    }
    return 1; // True
}

/* Back with the c++ babyyyy */
int main() 
{
    string line;
    string file_name = "input.txt";

    ifstream file(file_name);
    while (getline(file, line))
    {
        char recentCharacters [4];
        for (int i = 0; i < line.length(); i++) 
        { 
            if (allUnique(recentCharacters) == 1 &&  i >= 4) 
            {
                cout << "First character that does not repeat; "
                << i;
                break;
            } 
            // Very unelegant.
            recentCharacters[3] = recentCharacters[2];
            recentCharacters[2] = recentCharacters[1];
            recentCharacters[1] = recentCharacters[0];
            recentCharacters[0] = line[i];
        }

        cout << endl;
    }
    return 0;
}