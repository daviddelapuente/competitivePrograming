#include <iostream>
#include <map>
#include <vector>
#include <math.h> 
//g++ name.cpp -o name
//./name < test.txt
// url:http://codeforces.com/problemset/problem/71/C


//when i solved this problem, i think abaut rips, y dont know why
int main() {
    long long n;
    std::cin>>n;
    std::vector<long long> table(n);
    for(long long i=0;i<n;i++){
        std::cin>>table[i];
    }

    long long l=n/3;
    
    std::vector< std::vector<long long> > dp(n,std::vector<long long>(l,0));
    for(long long i=0;i<n;i++){
        for(long long j=1;j<=l;j++){
            if(n%j==0 && j*2!=n && dp[i][j-1]==0){
                
                bool good=true;
                
                for(long long k=0;k<n/j;k++){
                    
                    if(table[i+k*j]==0){
                        good=false;
                    }
                    dp[i+k*j][j-1]=1;
                    //std::cout<<"i="<<i<<"  j="<<j<<"  k="<<k<<"  good="<<good<<std::endl;
                }
                if(good){
                    std::cout<<"YES"<<std::endl;
                    return 0;
                }

            }
        }
    }
    
    std::cout<<"NO"<<std::endl;
    return 0;
}
