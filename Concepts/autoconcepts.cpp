#include <iostream>
#include <concepts>
#include <type_traits>

using namespace std;
//demonstrating how to use concepts and the auto keyword
 integral auto add(integral auto x, integral auto y)
 {
    return x*y+x+y;

 }

//template <typename T>

int main()
{
    cout<<add(54,76)<<endl;
   // cout<<add(23.2,10)<<endl;  

    return 0;

}