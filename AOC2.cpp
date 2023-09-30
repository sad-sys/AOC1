#include <iostream>
#include <fstream>
#include <string>

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
    new_file.open("AOC2Input.txt");
    if (new_file.is_open())
    {
        
    }

    int secondChoiceIndex;

    for (size_t i = 0; i < 3; ++i)
    {
        const string& correspondingChoice = secondChoiceArray[i];
        if (secondLetter == correspondingChoice)
        {
            secondChoiceIndex = i;
        }
    }

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