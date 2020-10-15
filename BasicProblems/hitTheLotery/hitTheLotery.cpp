#include <iostream>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/996/A

int main() {

    long n;
    std::cin>>n;

    long bills=0;
    long aux=n;

    bills+=aux/100;
    aux=aux%100;

    bills+=aux/20;
    aux=aux%20;
    
    bills+=aux/10;
    aux=aux%10;

    bills+=aux/5;
    aux=aux%5;

    bills+=aux;
    std::cout<<bills<<std::endl;
    return 0;
}