#pragma once
#include <iostream>
using namespace std;

void green(){
	cout << "\033[0;32m";
}

void red(){
	cout << "\033[1;31m";
}

void blue(){
    cout << "\033[0;34m";
}

void white(){
	cout << "\033[0;37m";
}

void yellow(){
	cout << "\033[0;33m";
}