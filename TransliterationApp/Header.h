#pragma once
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

vector<string> decodeString(string& line, int pos);

void outputFile(vector<string> ru, string outputFileName);

void setDecMap();

string toupper(string line);

char toupper(char ch);

char tolower(char ch);