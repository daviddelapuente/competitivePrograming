#include <iostream>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/1328/B

std::string buildString(long long i,long long j, long long n){
    std::string s="";
    for(int k=0;k<n;k++){
        if(k==i || k==j){
            s+="b";
        }else{
            s+="a";
        }
    }
    return s;
}

long long combinations(long long i, long long n){
    long long j=n-i;
    return (j*(j-1))/2;
}
/*
n=5
k=2 b1=2

i=2
j=3
mid=2;
b1=2
combinations(2,5)=3*2/2=3

*/


long long firstb(long long n,long long k){
    long long i=0,j=n-2;
    long long mid=i+(j-i)/2;
    long long b1=mid;
    while(i<=j){
        mid=i+(j-i)/2;
        if(combinations(mid,n)>=k){
            b1=mid;
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    return b1;

}

/*

b1=2;
parteInferior=1
candidatos=2
r=2-1=1
return 2+1
*/

long long secondb(long long n, long long k, long long b1){
    if(b1==n-2){
        return n-1;
    }

    long long parteInferior=combinations(b1+1,n);
    long long candidatos=combinations(b1,n)-parteInferior;
    long long r=k-parteInferior-1;
    return b1+((n-1-b1)-r);

}

std::string f(long long n, long long k){


    long long b1=firstb(n,k);
    long long b2=secondb(n,k,b1);

    return buildString(b1,b2,n);
}

int main() {
    long long t;
    std::cin>>t;

    for(int i=0;i<t;i++){
        long long n,k;
        std::cin>>n>>k;

        std::cout<<f(n,k)<<std::endl;
    }
    return 0;
}