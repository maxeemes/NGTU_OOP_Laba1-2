// laba1-2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << Firm().GetMain();
	getchar(); 
    return 0;
}

