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
* Функция выполняет открытие файла с английсим текстом и считывает его содержимое в строку
* \return - возвращает введенныую пользователем строку
* Если файл открыть не удаось, то приводит к остановке программы
*/
string inputFile(string fileName);

/*!
* Функция заменяет первое входнеие слова в строке на точки
* \param [in] eng - введенная пользователем строка
* \return - возвращает строку после транслитерации на русский язык
*/
vector<string> translit(string eng);

/*!
* Функция заменяет первое входнеие слова в строке на точки
* \param [in] line - введенная пользователем строка
* \param [in] pos - позиция, с которой нужно начать перевод строки
* \return - возвращает строку после транслитерации на русский язык
*/
vector<string> decodeString(string& line, int pos);

/*!
* Функция выводит результат транслитерации в txt файл
* \param [in] ru - строка после транслитерации на русский язык
*/
void outputFile(vector<string> ru, string outputFileName);

/*!
* Функция инициализирует карту перевода DecMap
*/
void setDecMap();

/*!
* Функция заменяет все символы строки на большие по регистру
* \param [in] line - строка с символами
* \return - возвращает строку символов в верхнем регистре
*/
string toupper(string line);

/*!
* Функция заменяет все символы строки на нижние по регистру
* \param [in] line - строка с символами
* \return - возвращает строку символов в нижнем регистре
*/
string makeLow(string line);

/*!
* Функция заменяет символ на большой
* \param [in] ch - переданный в функцию символ
* \return - возвращает символ в верхнем регистре
*/
char toupper(char ch);

/*!
* Функция заменяет символ на маленький
* \param [in] ch - переданный в функцию символ
* \return - возвращает символ в нижнем регистре
*/
char tolower(char ch);