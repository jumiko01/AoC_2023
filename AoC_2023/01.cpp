#include "01.h"


string getFirstandLastNumber(string inputStr)
{
    string tempNumbers = getNumbers(inputStr);
    string result = "";
    if (tempNumbers.size() == 0)
        result += "0";
    else if (tempNumbers.size() == 1)
    {
        result += tempNumbers[0];
        result += tempNumbers[0];
    }
    else
    {
        result += tempNumbers[0];
        result += tempNumbers[tempNumbers.size() - 1];
    }

    return result;
}


int main_01()
{
 //   string filename = "D:\\projekte\\repos\\AoC_2023\\AoC_2023\\input_01.txt";
    string filename = "input_01.txt";
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

    while (getline(input, line))
    {

        cout << line << "\n";
        cout << " - ";
        istringstream inStream1(getFirstandLastNumber(line));

        int number;
        inStream1 >> number;
        cout << number << '\n';
        numbers.push_back(number);
    }

    int result = 0;
    for (const auto& i : numbers) {
        cout << i << "; ";
        result += i;
    }

    cout << "result: " << result;
    return 0;
}