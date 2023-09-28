#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <int> elfCaloryTotals;
    vector <int> elfCalory;

    fstream new_file;
    new_file.open("AOCInput1Processed.txt", ios::in);
    
    if (new_file.is_open())
    {
        string elf;
        int elfInt;
        while (getline(new_file, elf))
        {   
            if(elf == "ERROR")
            {
                cout << "I'm Spartacus";
            }
            else
            {
                elfInt = stoi(elf);
            }
        }
    }
}
