#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <regex> 

using namespace std;


string getNumbers(string inputStr)
{
    string temp = "";

    regex regexp("([0-9]+)|(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)");

    for (std::smatch m; regex_search(inputStr, m, regexp);)
    {   
        string num = m.str();
//        cout << "m.str(); " << m.str() << " - " ;
        int pos = inputStr.find(num)+1;
        inputStr = inputStr.substr(pos, inputStr.size()- pos );  //m.suffix();
//        cout << "inputStr: " << inputStr << " - " ;
//        cout << "m.suffix(); " <<  m.suffix() << " - ";


//            cout << "num: " << num;
            string val = "";
            if(num == "one")
                val += "1";
            else if(num == "two")
                val += "2";
            else if(num == "three")
                val += "3";
            else if(num == "four")
                val += "4";
            else if(num == "five")
                val += "5";
            else if(num == "six")
                val += "6";
            else if(num == "seven")
                val += "7";
            else if(num == "eight")
                val += "8";
            else if(num == "nine")
                val += "9";
            else
                val += num;
           
            temp += val;
//            cout << ", temp: " << temp << " || ";
    
    
    }

    
    return temp;
}

string getFirstandLastNumber(string inputStr)
{
    string tempNumbers = getNumbers(inputStr);
    string result = "";
    if(tempNumbers.size() == 0)
        result += "0";
    else if(tempNumbers.size() == 1)
    {
        result += tempNumbers[0];
        result += tempNumbers[0];
    }
    else
    {
        result += tempNumbers[0];
        result += tempNumbers[tempNumbers.size()-1];
    }

    return result;
}


int main()
{
  string filename = "D:\\projekte\\repos\\AoC_2023\\01\\input.txt";
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
    for (const auto &i : numbers) {
        cout << i << "; ";
        result+=i;
    }

    cout << "result: " <<result;
    return 0;
}