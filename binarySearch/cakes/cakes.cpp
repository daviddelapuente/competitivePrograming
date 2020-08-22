#include <iostream>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/911/B

long f(long N,long a, long b){
    long minimo=0;

    long i=1,j=N;
    long mid;
    while(i<=j){
        mid=i+(j-i)/2;
        long na=a/mid;
        if(mid==N){
            break;
        }
        long nb=b/(N-mid);

        minimo=std::max(minimo,std::min(na,nb));

        if(na==nb){
            break;
        }else if(na>nb){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }

    return minimo;
}


int main() {
    long N,a,b;
    std::cin>>N>>a>>b;

    std::cout<<f(N,a,b)<<std::endl;

    return 0;
}