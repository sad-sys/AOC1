#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <int> elfCalorieTotals;
    vector <int> elfCalorie;

    fstream new_file;
    new_file.open("AOCInput1Processed.txt", ios::in);
    
    if (new_file.is_open())
    {
        string elf;
        int elfInt;

        int elfCalorie;
        int elfCalorieTotal;

        while (getline(new_file, elf))
        {   
            if(elf == "ERROR")
            {
                elfCalorieTotals.push_back(elfCalorieTotal);
                elfCalorieTotal = 0;
            }
            else
            {
                elfInt = stoi(elf);
                elfCalorieTotal += elfInt;
            }
        }
        elfCalorieTotals.push_back(elfCalorieTotal);

        new_file.close();

        int highestCalorie = 0;
        int index = 0;

        for (size_t i = 0; i < elfCalorieTotals.size(); ++i)
        {
            const int& number = elfCalorieTotals[i];
            if (number > highestCalorie)
            {
                highestCalorie = number;
                index  = i;
            }
        }
        cout << highestCalorie;
        return 0;
    }
}
