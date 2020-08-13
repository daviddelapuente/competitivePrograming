#include <iostream>
#include <math.h>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/750/A

int main() {
    int n,k;
    std::cin>>n>>k;
    int aux=(240-k)/5;
    if(aux>=55 && n>=10){
        std::cout<<10<<std::endl;
    }else if(aux>=45 && n>=9){
        std::cout<<9<<std::endl;
    }else if(aux>=36 && n>=8){
        std::cout<<8<<std::endl;
    }else if(aux>=28 && n>=7){
        std::cout<<7<<std::endl;
    }else if(aux>=21 && n>=6){
        std::cout<<6<<std::endl;
    }else if(aux>=15 && n>=5){
        std::cout<<5<<std::endl;
    }else if(aux>=10 && n>=4){
        std::cout<<4<<std::endl;
    }else if(aux>=6 && n>=3){
        std::cout<<3<<std::endl;
    }else if(aux>=3 && n>=2){
        std::cout<<2<<std::endl;
    }else if(aux>=1 && n>=1){
        std::cout<<1<<std::endl;
    }else{
        std::cout<<0<<std::endl;
    }
}