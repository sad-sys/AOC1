#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> lines;

    fstream new_file;
    new_file.open("AOC1Input.txt", ios::in);

    if (new_file.is_open())
    {
        string sa;
        while (getline(new_file, sa))
        {

            if (sa.empty())
            {
                lines.push_back("ERROR");
                sa += "\n";
                lines.push_back(sa);
            }
            else
            {
                sa += "\n";
                lines.push_back(sa);
            }
        }
    }
    new_file.close();
    for (const string& line : lines)
    {
        cout << line;
    }
    
    return 0;
}