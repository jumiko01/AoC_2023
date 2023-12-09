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

vector<string> splitString(string input, string delimeter)
{
    vector<string> retVal;
    int pos = input.find(delimeter);
    while(pos != -1)
    {
        retVal.push_back(input.substr(0, pos));
        input = input.substr(pos+1, input.size() - pos+1);
        pos = input.find(delimeter);
//        cout << input << endl;
    }

    if(input.size() > 0)
        retVal.push_back(input.substr(0, input.size()));

    return retVal;
}

int checkCubes(string input, int redLimit, int greenLimit, int blueLimit)
{
    int retVal = 0;
    istringstream inStream1(input);
    int num = 0;
    inStream1 >> num;
    string color = ""; 
    inStream1 >> color;

    if(color == "red")
    {
        if(num > redLimit)
        retVal = 1;
    }
    else if(color == "green")
    {   
        if(num > greenLimit)
        retVal = 1;
    }
    else if(color == "blue")
    {
        if(num > blueLimit)
        retVal = 1;
    }
    else
        retVal = -1;

    return retVal;
}

int setMaxQubeCnt(string input, int* redCnt, int* greenCnt, int* blueCnt)
{
    int retVal = 0;
    vector<string> cubesPerGame = splitString(input, ",");

    for(auto cubes : cubesPerGame)
    {
        int retVal = 0;
        istringstream inStream1(cubes);
        int num = 0;
        inStream1 >> num;
        string color = ""; 
        inStream1 >> color;

        if(color == "red")
        {
            if(num > *redCnt)
            *redCnt = num;
        }
        else if(color == "green")
        {   
            if(num > *greenCnt)
            *greenCnt = num;
        }
        else if(color == "blue")
        {
            if(num > *blueCnt)
            *blueCnt = num;
        }
    }
    return retVal;
}


int main()
{
    string filename = "C:\\repos\\AoC_2023\\03\\input.txt";
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

        int cubesCheckOk = 1;

        int pos = line.find(":")+1;
        string gameStr = line.substr(pos, line.size()- pos );  //m.suffix();

        cout << "ID: " << gameNo << " -> " << gameStr << endl;

        vector<string> qubes = splitString(gameStr, ";");
    
        int redMax = 0;
        int greenMax = 0;
        int blueMax = 0;

        for(auto s : qubes)
        {

            cout << s << endl;
            vector<string> colors = splitString(s, ",");
            for(auto s1: colors)
            {
                cout << s1 ;
                cout << " - checkColor: " << checkCubes(s1, 12,13,14) << endl;
                if(checkCubes(s1, 12,13,14) == 1)
                    cubesCheckOk = 0;
           }

           setMaxQubeCnt(s, &redMax, &greenMax, &blueMax);
        }

        if (cubesCheckOk)
            result1 += gameNo;

        cout << "redMax: " << redMax << ", blueMax: " << blueMax << " ,greenMax:" << greenMax << ", GamePower: " << redMax*greenMax*blueMax << endl;
        result2 += (redMax*greenMax*blueMax);

        gameNo++;
    }  

    cout << "result1: " <<result1 << endl;
    cout << "result2: " <<result2 << endl;

    input.close();

    return 0;
}