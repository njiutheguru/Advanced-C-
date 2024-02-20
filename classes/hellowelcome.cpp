#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    time_t timevariable=time(NULL);
    tm *timepointer=localtime(&timevariable);
    cout <<timepointer->tm_mday<<"/";
    cout <<timepointer->tm_mon<<"/";
    cout <<1900+timepointer->tm_year<<endl;

    //printing time
    cout << timepointer->tm_hour <<":"<<timepointer->tm_min<<":"<<timepointer->tm_sec<<endl;
    



    return 0;
}