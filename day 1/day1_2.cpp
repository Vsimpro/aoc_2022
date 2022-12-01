/* AoC Day 1b;
Find the top three Elves carrying the most Calories.
How many Calories are those Elves carrying in total?
*/
#include <fstream>
#include <sstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string line;
    string file_name = "puzzle_input.txt";
    
    int elves = 0;
    int line_value = 0;
    int calorie_sum = 0;
    long int calories = 0;
    
    /* Calculate the amount of elves. */
    ifstream file(file_name);
    while (getline(file, line)) 
    {
        if (line == "") 
        {
            elves++; 
        } 
    }
    file.close();

    /* Prepare variables for calculating the calories */
    long int elf_calories [elves];
    elves = 0;
    line = "";

    ifstream file2(file_name);
    while (getline(file2, line)) 
    {
        /* Get all the calories and store them.*/
        stringstream temp;    
        temp << line;
        temp >> line_value;
        calories = calories + line_value;
        /* This didn't recognise the last \n so I added 'eof' */
        if (line == "" or line == "eof") 
        {
            //cout << "Calories: " << calories << endl;
            elf_calories[elves] = calories;
            elves++;
            calories = 0;
            //cout << "-- ELF " << elves << endl;
        } 
        line_value = 0;
    }
    file2.close();

    /* Sort the array. */
    sort(elf_calories, elf_calories + elves);
    
    /* Read the 3 highest caloriecounts and sum them */   
    for (int i = elves - 1; i >= elves - 3; i--) {
        calorie_sum = calorie_sum + elf_calories[i];
    }

    cout << calorie_sum << endl;
    return 0;
}