#include "stringHelper.h"

string getNumbers(string inputStr)
{
    string temp = "";

    regex regexp("([0-9]+)|(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)");

    for (std::smatch m; regex_search(inputStr, m, regexp);)
    {
        string num = m.str();
        //        cout << "m.str(); " << m.str() << " - " ;
        int pos = inputStr.find(num) + 1;
        inputStr = inputStr.substr(pos, inputStr.size() - pos);  //m.suffix();
        //        cout << "inputStr: " << inputStr << " - " ;
        //        cout << "m.suffix(); " <<  m.suffix() << " - ";


        //            cout << "num: " << num;
        string val = "";
        if (num == "one")
            val += "1";
        else if (num == "two")
            val += "2";
        else if (num == "three")
            val += "3";
        else if (num == "four")
            val += "4";
        else if (num == "five")
            val += "5";
        else if (num == "six")
            val += "6";
        else if (num == "seven")
            val += "7";
        else if (num == "eight")
            val += "8";
        else if (num == "nine")
            val += "9";
        else
            val += num;

        temp += val;
        //            cout << ", temp: " << temp << " || ";
    }
    return temp;

}

vector<string> splitString(string input, string delimeter)
{
    vector<string> retVal;
    int pos = input.find(delimeter);
    while (pos != -1)
    {
        retVal.push_back(input.substr(0, pos));
        input = input.substr(pos + 1, input.size() - pos + 1);
        pos = input.find(delimeter);
        //        cout << input << endl;
    }

    if (input.size() > 0)
        retVal.push_back(input.substr(0, input.size()));

    return retVal;
}