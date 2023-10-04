#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const char* userChoiceArray[3] =   {"A","B","C"};
const char* secondChoiceArray[3] = {"X","Y","Z"};

int indexFinder(string firstLetter)
{

    for (size_t i = 0; i < 3; ++i)
    {
        const string& correspondingChoice = userChoiceArray[i];
        if (firstLetter == correspondingChoice)
        {
            int choiceIndex = i;
            return choiceIndex;
        }

        const string& secondCorrespondingChoice = secondChoiceArray[i];
        if (firstLetter == secondCorrespondingChoice)
        {
            int secondChoiceIndex = i;
            return secondChoiceIndex;
        }
    }

    return -1;
}

int choiceComparer(int choiceIndex, int secondChoiceIndex, int totalScore)
{
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
    if (answer == "l")
    {
        totalScore = totalScore + 0;
    }
    else if (answer == "d")
    {
        totalScore = totalScore + 3;
    }
    else if (answer == "w")
    {
        totalScore = totalScore + 6;
    }
    return totalScore;
    cout << "   ANSWER IS: " << answer;
};

int secondChoiceScore(int secondChoiceIndex, int totalScore)
{
    if (secondChoiceIndex == 0)
    {
        totalScore = totalScore + 1;
    }
    else if (secondChoiceIndex == 1)
    {
        totalScore = totalScore + 2;
    }
    else if (secondChoiceIndex == 2)
    {
        totalScore = totalScore + 3;
    }
    return totalScore;
};

int main()
{  
    int choiceIndex;
    int secondChoiceIndex;

    int totalScore = 0;

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
                if (strcmp(pointer, "A") == 0 || strcmp(pointer, "B") == 0 || strcmp(pointer, "C") == 0)
                {
                    choiceIndex = indexFinder(pointer);
                }
                if (strcmp(pointer, "X") == 0 || strcmp(pointer, "Y") == 0 || strcmp(pointer, "Z") == 0)
                {
                    secondChoiceIndex = indexFinder(pointer);
                    totalScore = secondChoiceScore(secondChoiceIndex, totalScore);
                }
                pointer = strtok(NULL, " ");
            };
            totalScore = choiceComparer(choiceIndex, secondChoiceIndex, totalScore);
        };
    };
    cout << "\n" << "TotalScore:  " << totalScore;
    return 0;
};