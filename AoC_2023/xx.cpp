#include "xx.h"

int main_xx()
{
    string filename = "in_xx.txt";
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