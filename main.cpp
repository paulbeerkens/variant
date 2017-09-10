#include <iostream>

#include <boost/variant.hpp>
#include <vector>


class times_two_generic: boost::static_visitor <>
{
public:
    template <typename T>
            void operator () (T& operand) const
    {
        operand += operand;
    }
};

int main()
{
    boost::variant<int,std::string> v;
    v="Hello";
    v=3;
    std::cout << "Hello, World! " << boost::get<int>(v) << std::endl;

    std::vector <boost::variant <int,std::string>> vec;
    vec.push_back(21);
    vec.push_back("Nice");


    //one way of applying to all
    times_two_generic visitor;
    std::for_each (vec.begin (), vec.end (), boost::apply_visitor (visitor));


    //another way to applying to all
    for (auto& a: vec)
    {
        boost::apply_visitor (times_two_generic (), a);
    }

    //print the after situation
    for (const auto& a: vec)
    {
        std::cout<<a<<std::endl;
    }

    return 0;
}