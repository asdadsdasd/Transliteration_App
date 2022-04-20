#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <locale.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

string inputFile(string fileName);

vector<string> translit(string eng);

void outputFile(vector<string> ru, string outputFileName);

void setDecMap();

string toupper(string line);

char toupper(char ch);

char tolower(char ch);

int maxCombLen = 3;

int main()
{
    setlocale(LC_ALL, "ru");
    setDecMap();
    string line;

    printf("Input name of txt file with english text: ");
    string inputFileName;
    cin >> inputFileName;

    line = inputFile(inputFileName);
    vector<string> ru = translit(line);

    printf("\nInput name of txt file you would like to record the translited version: ");
    string outputFileName;
    cin >> outputFileName;

    outputFile(ru, outputFileName);

    return 0;
}


string inputFile(string fileName)
{
    ifstream fin;

    fin.open(fileName);
    if (!fin.is_open())
    {
        printf("Ошибка при открытии файла!\n");
        exit(EXIT_FAILURE);
    }

    string line;

    int count = 0;
    while (!fin.eof())
    {
        getline(fin, line);
        count++;
    }
    if (count > 1)
    {
        printf("Количество строк в файле не равно 1!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < line.length(); i++)
    {
        if (!((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || line[i] == ' '))
        {
            printf("В исходной строке есть недопустимые символы!\n");
            exit(EXIT_FAILURE);
        }
    }

    cout << line << endl;

    fin.close();
    return line;
}


map<string, vector<string>>decMap;


void setDecMap() {
    decMap["a"] = { "а" };
    decMap["b"] = { "б" };
    decMap["c"] = { "ц" };
    decMap["d"] = { "д" };
    decMap["e"] = { "е" };
    decMap["f"] = { "ф" };
    decMap["g"] = { "г" };
    decMap["h"] = { "х" };
    decMap["i"] = { "и" };
    decMap["j"] = { "дж" };
    decMap["k"] = { "к" };
    decMap["l"] = { "л" };
    decMap["m"] = { "м" };
    decMap["n"] = { "н" };
    decMap["o"] = { "о" };
    decMap["p"] = { "п" };
    decMap["q"] = { "ку" };
    decMap["r"] = { "р" };
    decMap["s"] = { "с" };
    decMap["t"] = { "т" };
    decMap["u"] = { "у" };
    decMap["v"] = { "в" };
    decMap["w"] = { "в" };
    decMap["x"] = { "кс" };
    decMap["y"] = { "й" };
    decMap["z"] = { "з" };
    decMap["yo"] = { "ё" };
    decMap["yu"] = { "ю" };
    decMap["ya"] = { "я" };
    decMap["ye"] = { "е" };
    decMap["zh"] = { "ж" };
    decMap["sh"] = { "ж" };
    decMap["kh"] = { "х" };
    decMap["eh"] = { "э" };
    decMap["ih"] = { "ы" };
    decMap["ts"] = { "ц" };
    decMap["ch"] = { "ч" };
    decMap["A"] = { "А" };
    decMap["B"] = { "Б" };
    decMap["C"] = { "Ц" };
    decMap["D"] = { "Д" };
    decMap["E"] = { "Е" };
    decMap["F"] = { "Ф" };
    decMap["G"] = { "Г" };
    decMap["H"] = { "Х" };
    decMap["I"] = { "И" };
    decMap["J"] = { "Дж" };
    decMap["K"] = { "К" };
    decMap["L"] = { "Л" };
    decMap["M"] = { "М" };
    decMap["N"] = { "Н" };
    decMap["O"] = { "О" };
    decMap["P"] = { "П" };
    decMap["Q"] = { "Ку" };
    decMap["R"] = { "Р" };
    decMap["S"] = { "С" };
    decMap["T"] = { "Т" };
    decMap["U"] = { "У" };
    decMap["V"] = { "В" };
    decMap["W"] = { "В" };
    decMap["X"] = { "Кс" };
    decMap["Y"] = { "Й" };
    decMap["Z"] = { "З" };
    decMap["Yo"] = { "Ё" };
    decMap["Yu"] = { "Ю" };
    decMap["Ya"] = { "Я" };
    decMap["Ye"] = { "Е" };
    decMap["Zh"] = { "Ж" };
    decMap["Sh"] = { "Ш" };
    decMap["Kh"] = { "Х" };
    decMap["Eh"] = { "Э" };
    decMap["Ih"] = { "Ы" };
    decMap["Ts"] = { "Ц" };
    decMap["Ch"] = { "Ч" };
    decMap[" "] = { " " };
}

vector<vector<string>>decodes;

vector<bool>upper;


vector<string> decodeString(string& line, int pos) {
    if (decodes[pos].size() > 0)
        return decodes[pos];
    else {
        vector<string>res;
        for (int len = 1; (len <= maxCombLen) && (pos + len <= line.size()); ++len) {
            vector<string>& curVars = decMap[line.substr(pos, len)],
                leftVars = decodeString(line, pos + len);
            if (upper[pos])
                for (int i = 0; i < curVars.size(); ++i)
                    curVars[i] = toupper(curVars[i]);
            for (int i = 0; i < curVars.size(); ++i)
                for (int j = 0; j < leftVars.size(); ++j)
                    res.push_back(curVars[i] + leftVars[j]);
        }
        decodes[pos] = res;
        return res;
    }
}


char tolower(char ch) {
    return static_cast<char>(tolower(static_cast<unsigned char>(ch)));
}

char toupper(char ch) {
    return static_cast<char>(toupper(static_cast<unsigned char>(ch)));
}


string toupper(string line) {
    for (int i = 0; i < line.size(); ++i)
        line[i] = toupper(line[i]);
    return line;
}


string makeLow(string line) {
    upper.resize(line.size());
    for (int i = 0; i < line.size(); ++i) {
        char c = tolower(line[i]);
        upper[i] = (c != line[i]);
        line[i] = c;
    }
    return line;
}


vector<string> translit(string eng)
{
    string copy = makeLow(eng);
    decodes.resize(copy.size() + 1);
    decodes[copy.size()] = { "" };
    vector<string>ru = decodeString(copy, 0);
    return ru;
}


void outputFile(vector<string> ru, string outputFileName)
{
    ofstream fout;

    fout.open(outputFileName);
    if (!fout.is_open())
    {
        printf("Ошибка при открытии файла!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < ru.size(); ++i)
        fout << ru[i] << endl;

    fout.close();
}