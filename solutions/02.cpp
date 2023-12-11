#include "02.h"

int checkCubes(string input, int redLimit, int greenLimit, int blueLimit)
{
    int retVal = 0;
    istringstream inStream1(input);
    int num = 0;
    inStream1 >> num;
    string color = "";
    inStream1 >> color;

    if (color == "red")
    {
        if (num > redLimit)
            retVal = 1;
    }
    else if (color == "green")
    {
        if (num > greenLimit)
            retVal = 1;
    }
    else if (color == "blue")
    {
        if (num > blueLimit)
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

    for (auto cubes : cubesPerGame)
    {
        int retVal = 0;
        istringstream inStream1(cubes);
        int num = 0;
        inStream1 >> num;
        string color = "";
        inStream1 >> color;

        if (color == "red")
        {
            if (num > *redCnt)
                *redCnt = num;
        }
        else if (color == "green")
        {
            if (num > *greenCnt)
                *greenCnt = num;
        }
        else if (color == "blue")
        {
            if (num > *blueCnt)
                *blueCnt = num;
        }
    }
    return retVal;
}


int main_02()
{
    string filename = "C:\\repos\\AoC_2023\\solutions\\in_02.txt";
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

        int pos = line.find(":") + 1;
        string gameStr = line.substr(pos, line.size() - pos);  //m.suffix();

        cout << "ID: " << gameNo << " -> " << gameStr << endl;

        vector<string> qubes = splitString(gameStr, ";");

        int redMax = 0;
        int greenMax = 0;
        int blueMax = 0;

        for (auto s : qubes)
        {

            cout << s << endl;
            vector<string> colors = splitString(s, ",");
            for (auto s1 : colors)
            {
                cout << s1;
                cout << " - checkColor: " << checkCubes(s1, 12, 13, 14) << endl;
                if (checkCubes(s1, 12, 13, 14) == 1)
                    cubesCheckOk = 0;
            }

            setMaxQubeCnt(s, &redMax, &greenMax, &blueMax);
        }

        if (cubesCheckOk)
            result1 += gameNo;

        cout << "redMax: " << redMax << ", blueMax: " << blueMax << " ,greenMax:" << greenMax << ", GamePower: " << redMax * greenMax * blueMax << endl;
        result2 += (redMax * greenMax * blueMax);

        gameNo++;
    }

    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl;

    input.close();

    return 0;
}

