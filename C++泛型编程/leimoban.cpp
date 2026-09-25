#include<iostream>
#include "leimoban.hpp"
using namespace std;
#include<string>

int main()
{
    Person<string ,int> p1("伞兵",18);
    p1.showPerson();
    system("pause");
    return 0;

}