#include "Header.h"

int maxCombLen = 3;

string inputFile(string fileName)
{
    ifstream fin;

    fin.open(fileName);
    if (!fin.is_open())
    {
        printf("������ ��� �������� �����!\n");
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
        printf("���������� ����� � ����� �� ����� 1!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < line.length(); i++)
    {
        if (!((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || line[i] == ' '))
        {
            printf("� �������� ������ ���� ������������ �������!\n");
            exit(EXIT_FAILURE);
        }
    }

    cout << line << endl;

    fin.close();
    return line;
}


map<string, vector<string>>decMap;


void setDecMap() {
    decMap["a"] = { "�" };
    decMap["b"] = { "�" };
    decMap["c"] = { "�" };
    decMap["d"] = { "�" };
    decMap["e"] = { "�" };
    decMap["f"] = { "�" };
    decMap["g"] = { "�" };
    decMap["h"] = { "�" };
    decMap["i"] = { "�" };
    decMap["j"] = { "��" };
    decMap["k"] = { "�" };
    decMap["l"] = { "�" };
    decMap["m"] = { "�" };
    decMap["n"] = { "�" };
    decMap["o"] = { "�" };
    decMap["p"] = { "�" };
    decMap["q"] = { "��" };
    decMap["r"] = { "�" };
    decMap["s"] = { "�" };
    decMap["t"] = { "�" };
    decMap["u"] = { "�" };
    decMap["v"] = { "�" };
    decMap["w"] = { "�" };
    decMap["x"] = { "��" };
    decMap["y"] = { "�" };
    decMap["z"] = { "�" };
    decMap["yo"] = { "�" };
    decMap["yu"] = { "�" };
    decMap["ya"] = { "�" };
    decMap["ye"] = { "�" };
    decMap["zh"] = { "�" };
    decMap["sh"] = { "�" };
    decMap["kh"] = { "�" };
    decMap["eh"] = { "�" };
    decMap["ih"] = { "�" };
    decMap["ts"] = { "�" };
    decMap["ch"] = { "�" };
    decMap["A"] = { "�" };
    decMap["B"] = { "�" };
    decMap["C"] = { "�" };
    decMap["D"] = { "�" };
    decMap["E"] = { "�" };
    decMap["F"] = { "�" };
    decMap["G"] = { "�" };
    decMap["H"] = { "�" };
    decMap["I"] = { "�" };
    decMap["J"] = { "��" };
    decMap["K"] = { "�" };
    decMap["L"] = { "�" };
    decMap["M"] = { "�" };
    decMap["N"] = { "�" };
    decMap["O"] = { "�" };
    decMap["P"] = { "�" };
    decMap["Q"] = { "��" };
    decMap["R"] = { "�" };
    decMap["S"] = { "�" };
    decMap["T"] = { "�" };
    decMap["U"] = { "�" };
    decMap["V"] = { "�" };
    decMap["W"] = { "�" };
    decMap["X"] = { "��" };
    decMap["Y"] = { "�" };
    decMap["Z"] = { "�" };
    decMap["Yo"] = { "�" };
    decMap["Yu"] = { "�" };
    decMap["Ya"] = { "�" };
    decMap["Ye"] = { "�" };
    decMap["Zh"] = { "�" };
    decMap["Sh"] = { "�" };
    decMap["Kh"] = { "�" };
    decMap["Eh"] = { "�" };
    decMap["Ih"] = { "�" };
    decMap["Ts"] = { "�" };
    decMap["Ch"] = { "�" };
    decMap[" "] = { " " };
}

vector<vector<string>>decodes;

vector<bool>upper;


vector<string> decodeString(string& line, int pos) 
{
    if (decodes[pos].size() > 0)
        return decodes[pos];
    else 
    {
        vector<string>res;
        for (int len = 1; (len <= maxCombLen) && (pos + len <= line.size()); ++len) 
        {
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


char tolower(char ch) 
{
    return static_cast<char>(tolower(static_cast<unsigned char>(ch)));
}

char toupper(char ch) 
{
    return static_cast<char>(toupper(static_cast<unsigned char>(ch)));
}


string toupper(string line) 
{
    for (int i = 0; i < line.size(); ++i)
        line[i] = toupper(line[i]);
    return line;
}


string makeLow(string line) 
{
    upper.resize(line.size());
    for (int i = 0; i < line.size(); ++i) 
    {
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
        printf("������ ��� �������� �����!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < ru.size(); ++i)
        fout << ru[i] << endl;

    fout.close();
}