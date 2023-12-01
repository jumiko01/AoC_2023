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

    //regex regexp("([0-9]+)");
//    regex regexp("([0-9 one]+)");
    regex regexp("([0-9]+)|(one)|(two)|(three)|(four)|(five)|(thix)|(seven)|(eight)|(nine)");
//    regex regexp("([0-9 one two three four five six seven eight nine]+)");

    // flag type for determining the matching behavior (in this case on string objects)
     cmatch m; 
   
    // regex_search that searches pattern regexp in the string mystr  
 /*   regex_search(inputStr, m, regexp); 
    {        cout<<"String that matches the pattern: ";
        for (auto x : m) 
        {   
            cout << x << " "; 
            temp += x;
        }

    }
*/
    const char* j = inputStr.c_str();
    string s = "";
    j = (s+j).substr( (s+j).find("two")+1, (s+j).size()-(s+j).find("two")+1 )  ;

    for( const char* i = inputStr.c_str(); regex_search( i, m, regexp ) ; i = m[0].second)
    {
        for( int i = 1; i < int(m.size()); ++i )
        {
            string match(m[i].first, m[i].second);
            cout << match << " "; 
            if(match == "one")
                match = "1";
            else if(match == "two")
                match = "2";
            else if(match == "three")
                match = "3";
            else if(match == "four")
                match = "4";
            else if(match == "five")
                match = "5";
            else if(match == "six")
                match = "6";
            else if(match == "seven")
                match = "7";
            else if(match == "eight")
                match = "8";
            else if(match == "nine")
                match = "9";
            temp += match;
        }
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

        cout << line << "";
        cout << " - ";
        istringstream inStream1(getFirstandLastNumber(line));
        
        int number;
        inStream1 >> number;
        cout << "--" << number << '\n';
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