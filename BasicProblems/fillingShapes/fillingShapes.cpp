#include <iostream>
//g++ name.cpp -o name
//./name < test.txt

//url: https://codeforces.com/problemset/problem/1182/A

int main() {
    long n;
    std::cin>>n;
    
    if(n%2!=0 || n==0){
        std::cout<<0<<std::endl;
    }else{
        long potencia=2;
        for(int i=1;i<(n/2);i++){
            potencia*=2;
        }
        std::cout<<potencia<<std::endl;
    }
    return 0;
}