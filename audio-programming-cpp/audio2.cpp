//#include "pch.h"
#include <iostream>
#include <windows.h>
#include <MMSystem.h>

//using namespace System;
using namespace std;

int main()
{
    bool played = PlaySound(TEXT("thereisgrace.wav"), NULL, SND_SYNC);
    cout << " Sucess or not " << played << endl;
    system("pause");
    return 0;
}