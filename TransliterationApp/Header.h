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

/*!
* ������� ��������� �������� ����� � ��������� ������� � ��������� ��� ���������� � ������
* \return - ���������� ���������� ������������� ������
* ���� ���� ������� �� ������, �� �������� � ��������� ���������
*/
string inputFile(string fileName);

/*!
* ������� �������� ������ �������� ����� � ������ �� �����
* \param [in] eng - ��������� ������������� ������
* \return - ���������� ������ ����� �������������� �� ������� ����
*/
vector<string> translit(string eng);

/*!
* ������� �������� ������ �������� ����� � ������ �� �����
* \param [in] line - ��������� ������������� ������
* \param [in] pos - �������, � ������� ����� ������ ������� ������
* \return - ���������� ������ ����� �������������� �� ������� ����
*/
vector<string> decodeString(string& line, int pos);

/*!
* ������� ������� ��������� �������������� � txt ����
* \param [in] ru - ������ ����� �������������� �� ������� ����
*/
void outputFile(vector<string> ru, string outputFileName);

/*!
* ������� �������������� ����� �������� DecMap
*/
void setDecMap();

/*!
* ������� �������� ��� ������� ������ �� ������� �� ��������
* \param [in] line - ������ � ���������
* \return - ���������� ������ �������� � ������� ��������
*/
string toupper(string line);

/*!
* ������� �������� ��� ������� ������ �� ������ �� ��������
* \param [in] line - ������ � ���������
* \return - ���������� ������ �������� � ������ ��������
*/
string makeLow(string line);

/*!
* ������� �������� ������ �� �������
* \param [in] ch - ���������� � ������� ������
* \return - ���������� ������ � ������� ��������
*/
char toupper(char ch);

/*!
* ������� �������� ������ �� ���������
* \param [in] ch - ���������� � ������� ������
* \return - ���������� ������ � ������ ��������
*/
char tolower(char ch);