#include "03.h"

int main_03()
{
    string filename = "in_03.txt";
    //  string filename = "D:\\projekte\\repos\\AoC_2023\\01\\input.txt";
    //  cout << "Datei: ";
    //  cin >> filename;

    ifstream input(filename);

    if (!input)
    {
        cerr << "Fehler beim Oeffnen der Datei " << filename << "\n";
        return 1;
    }

    string line;
    vector<int> numbers;

    int gameNo = 1;
    int result1 = 0;
    int result2 = 0;

    while (getline(input, line))
    {
        //        cout << line << "\n";
        //        cout << " - ";

    }

    return 0;
}