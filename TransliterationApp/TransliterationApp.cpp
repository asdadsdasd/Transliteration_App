#include "Header.h"

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