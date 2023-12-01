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
 /*  for (unsigned int i=0;i<inputStr.size();++i)    //s.size() ist die Anzahl der Zeichen in einem Strings
    {
        if( inputStr[i] =='0' || 
            inputStr[i] =='1' ||  
            inputStr[i] =='2' ||  
            inputStr[i] =='3' ||  
            inputStr[i] =='4' ||  
            inputStr[i] =='5' ||  
            inputStr[i] =='6' ||  
            inputStr[i] =='7' ||  
            inputStr[i] =='8' ||  
            inputStr[i] =='9'  )
        {
            temp += inputStr[i];
        }
    }
 */

    regex regexp("^\\d{1,}+\\s|\\s\\d+$|\\s\\d+\\s|^\\d+$");

    // flag type for determining the matching behavior (in this case on string objects)
     smatch m; 
   
    // regex_search that searches pattern regexp in the string mystr  
    regex_search(inputStr, m, regexp); 
    cout<<"String that matches the pattern: ";
    for (auto x : m) 
    {   
        cout << x << " "; 
        temp += x;
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
  string filename = "C:\\repos\\AoC_2023\\01\\input.txt";
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

        cout << line << '\t';
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