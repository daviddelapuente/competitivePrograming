#include <iostream>
#include <math.h>
//g++ name.cpp -o name
//./name < test.txt

//url: https://www.spoj.com/problems/MBEEWALK/
long f(long n){
    if(n<=0){
        return 0;
    }else if(n==1){ 
        return 1;
    }else{
        return 3*f(n-2)+2*f(n-1)+f(n-3);
    }
}

long count(long n){
    return 6*f(n-1);
}

int main() {
    std::cout<<"SAMPLE OUTPUT"<<std::endl;
    std::string s;
    std::cin>>s;
    std::cin>>s;
    int n;
    while(std::cin>>n)
    {   
        std::cout<<count(n)<<std::endl;
    } 
    return 0;
}