#include <iostream>
#include <vector>
#include <map>
//g++ name.cpp -o name
//./name < test.txt

//url: https://codeforces.com/problemset/problem/368/B

int main() {
    long n,m;
    std::cin>>n>>m;
    std::vector<long> A(n);

    for(int i=0;i<n;i++){
        std::cin>>A[i];
    }

    std::vector<long> L(m);

    for(int i=0;i<m;i++){
        std::cin>>L[i];
        L[i]--;
    }

    std::map<long, long> dp;
    long dist=0;
    std::vector<long> resp(m);
    for(int i=m-1;i>=0;i--){
        if( dp.find(A[L[i]]) == dp.end()){
            dp[A[L[i]]]=1;
            dist++;
        }

        resp[i]=dist;
        
    }

    for(int i=0;i<m;i++){
        std::cout<<resp[i]<<std::endl;
    }

    return 0;
}