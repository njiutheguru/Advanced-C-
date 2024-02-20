
//#include "stdafx.h"
#include <Windows.h>
#include <mmstream.h>
#include <iostream>
 #pragma comment(lib, "Winmm.lib")
 //project to be runned in vs code

  //using namespace system
 using namespace std;


int main()
{
    cout <<" Playing the sound " << endl;
    PlaySound(TEXT("thereisgrace.wav"), NULL,SND_FILENAME | SND_ASYNC);
    cout <<" Music is over" <<endl;

    return 0;
}