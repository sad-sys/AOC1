#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    const char* userChoiceArray[3] = {"A","B","C"};
    const char* secondChoiceArray[3 ] = {"X","Y","Z"};

    const string firstLetter = "B";
    const string secondLetter = "X";

    int choiceIndex;

    for (size_t i = 0; i < 3; ++i)
    {
        const string& correspondingChoice = userChoiceArray[i];
        if (firstLetter == correspondingChoice)
        {
            choiceIndex = i;
        }
    }

    fstream new_file;
    new_file.open("AOC2Input.txt", ios::in);
    if (new_file.is_open())
    {
        string line;
        while (getline(new_file, line))
        {
            char processedLine[1024];
            strcpy(processedLine, line.c_str());
            char *pointer;
            pointer = strtok(processedLine," ");

            while (pointer != NULL)
            {
                cout << pointer != NULL;
                pointer = strtok(NULL, " ");
            };
        }
    };

    int secondChoiceIndex;

    for (size_t i = 0; i < 3; ++i)
    {
        const string& correspondingChoice = secondChoiceArray[i];
        if (secondLetter == correspondingChoice)
        {
            secondChoiceIndex = i;
        }
    };

    cout << choiceIndex;

    //Instead of using a crap ton of if statements lets use a mutlidimentional array
    const int rows = 3;
    const int columns = 3;

    string choicesArray[rows][columns] =
    {
        {"d","w","l"},
        {"l","d","w"},
        {"w","l","d"}
    };

    string answer = choicesArray[choiceIndex][secondChoiceIndex];
    
    cout << answer;

    return 0;
}