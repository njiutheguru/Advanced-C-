#include <iostream>
#include <concepts>

//concepts are used to put constraint in templates and allow only the defined values to be 
//passed to the template functions
template <typename T>
void print_number(T n)
{
    static_assert(std::is_integral<T>::value, "Must pass in an integral argument");
    std::cout<<"n: " << n << std::endl;
}
//implementing concepts 

//syntax 1
/*
template <typename T>
requires std::integral <T> 
T add(T a, T b)
{
    return a+b;
}

//SYNTAX TWO
template <std::integral T>
//requires std::integral <T> 
T add(T a, T b)

{
    return a+b;
}

//SYNTAX THREE
auto add(std::integral auto a, std::integral auto b)
{
    return a+b;
}
*/
//syntac four
template <typename T>
T add(T a, T b) requires std::floating_point<T> {
    return a*b;
}


int main()
{
    print_number(29990);
    print_number(222);
    print_number(-990);
   // print_number(445.889);
    //print_number("tkre"); //prints out an error 

    //likewise, we are going to build the same function working in concepts
     /*
     char a{11};
     char b{90};
     auto result_ab=add(a,b);
     std::cout <<"result_ab:" << static_cast <int>(result_ab) <<std::endl;
     int c=54;
     int d= 89;
    auto result_cd=add(c,d);
     std::cout <<"result_cd:" <<result_cd <<std::endl;
     */
    double f=88.99;
    double g=99.998;
        auto result_fg=add(f,g);
     std::cout <<"result_fg:" <<result_fg <<std::endl;


    return 0;
}