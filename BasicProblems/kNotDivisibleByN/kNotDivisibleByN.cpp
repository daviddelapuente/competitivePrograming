#include <iostream>
#include <math.h>
//g++ name.cpp -o name
//./name < test.txt

//url: https://codeforces.com/problemset/problem/1352/C

long kNotDivisibleByN(long n, long k){
    int d=k/(n-1);
    int r=k%(n-1);

    if(r!=0){
        d++;
    }
    d--;
    if(r==0){
        return d*(n-1)+d+(n-1);
    }else{
        return d*(n-1)+d+r;
    }
    
}

int main() {
    int t;
    std::cin>>t;

    for(int i=0;i<t;i++){
        long n,k;
        std::cin>>n>>k;

        std::cout<<kNotDivisibleByN(n,k)<<std::endl;
    }
}