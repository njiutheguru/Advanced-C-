#include <iostream>
#include <concepts>
#include <type_traits>

using namespace std;

template <typename T>
concept addition=std::is_integral_v<T>;

template <addition T>
//requires addition <T>
T add(T a, T b)
{
    return a*b;
}

//building complex concepts
template <typename T>
concept Multipliable= requires (T a, T b)
{
    a*b;
};
template <Multipliable T>
T multiply(T a, T b)
{
    return a*a*b*b;
}
template <typename T>
concept Tinytype=requires (T t)
{
    sizeof(T)<=4; //syntax requirement only
    requires sizeof(T)<=4;
};
Tinytype auto add1(Tinytype auto a, Tinytype auto b)
{
    return a/b+a*b;
}
//compound requirement
template <typename T>
concept Addable =requires (T a, T b)
{
    {a+b} noexcept -> std::convertible_to <int>; //compound requirement
    
};
Addable auto addm(Addable auto a, Addable auto b)
{
    return a/b+a*b;
}
//combinations of concepts in cpp using the or and and operator
 template <typename T>
 requires std::integral <T> || std::floating_point <T>
 T operators( T a, T b)
 {
    return a+b+a+a+b+b;
 }

int main()
{
    int x=9;
    int y=9;
    cout<<add(x,y)<<endl;
    cout<<multiply(x,y)<<endl;
    cout <<operators(x,y);
    string boy="man";
    string girl=" woman";
    cout<<endl;
    cout<<boy+girl<<endl;
    cout<<operators(boy,girl)<<endl; //brings out an error since it does not satisfy any of the two conditions 
    

    cout<<endl;
    char am{65};
    char ab{56};
    cout<<addm(am,ab)<<endl;
    return 0;
}