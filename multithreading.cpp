#include <iostream>
#include <thread>

using namespace std;

void myfunc()
{
    cout <<"This is mutithreading in CPP" << endl;
}

int main()
{
    thread ti(myfunc);
   // ti.join();//waits for the ti thread to be terminated

    //creating a daemon thread
    //for(size_t i = 0; i < 2;i++)//loop can only go for one value hence useless in this context 
    
        //ti.detach(); //gonna results in an error
        ti.join(); //waits for the thread to finish
    
    
    return 0;
}