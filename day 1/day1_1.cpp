/* AoC Day 1a;
Find the Elf carrying the most Calories. 
How many total Calories is that Elf carrying?
*/
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main() 
{
    string line;
    
    int elves = 0;
    int calories = 0;
    int line_value = 0;
    int most_calories = 0;
    int elf_with_most_calories = 0;

    /* Open the data from a text file */
    ifstream file("puzzle_input.txt");
    while (getline(file, line)) 
    {
        /* Convert the line into integer */
        stringstream temp;    
        temp << line;
        temp >> line_value;
        calories = calories + line_value;
        /* \n\n == end of elf*/
        if (line == "") 
        {
            //cout << "-- ELF --" << endl;
            if (calories > most_calories) 
            {
                elf_with_most_calories = elves + 1;
                most_calories = calories;
            }
            //cout << "Calories: " << calories << endl;
            elves++;
            calories = 0;
        } 
        line_value = 0;
    }

    //cout << "Elves:" << elves << endl;
    cout << "Most calories: " << most_calories << endl;
    cout << "Elf with most calories: " << elf_with_most_calories << endl;
    file.close();
    return 0;
}