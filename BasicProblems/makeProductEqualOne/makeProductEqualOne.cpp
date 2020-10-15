#include <iostream>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/1206/B

int main() {

    long long n;
    std::cin>>n;
    long long zeros=0;
    long long menos1=0;
    long long op=0;
    for(long long i=0;i<n;i++){
        long long a;
        std::cin>>a;
        if(a==0){
            zeros++;
        }else if(a<0){
            menos1++;
            op+=-1*a-1;
        }else{
            op+=a-1;
        }
    }


    if(menos1%2==0){
        op+=zeros;
    }else if(zeros>0){
        op+=zeros;
    }else{
        op+=2;
    }
    std::cout<<op<<std::endl;

    return 0;
}