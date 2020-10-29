#include <iostream>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/1206/B

int main() {
    long n;
    std::cin>>n;

    if(n==0 or n==1){
        std::cout<<1<<std::endl;
    }
    else{
        long temp1=1;
        long temp2=1;

        for(int i=2;i<=n;i++){
            long aux=temp2;
            temp2+=temp1;
            temp1=aux;
        }
        std::cout<<temp2<<std::endl;
    }
    return 0;
}