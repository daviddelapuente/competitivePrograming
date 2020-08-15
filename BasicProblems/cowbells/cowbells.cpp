#include <iostream>
#include <math.h>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt

//url: https://codeforces.com/problemset/problem/604/B


int main() {
    long n,k;
    std::cin>>n>>k;

    std::vector<long> cb(n);
    for(long i=0;i<n;i++){
        std::cin>>cb[i];
    }
    long m=0;
    for(long i=0;i<(n-k);i++){
        m=std::max(m,cb[n-k+i]+cb[(n-k)-i-1]);
    }

    std::cout<< std::max(m,cb[n-1])<<std::endl;
}