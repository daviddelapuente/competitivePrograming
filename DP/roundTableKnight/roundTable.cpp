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

    std::vector<long long> rightDivisor;

    for(long long i=l;i>0;i--){
        if(n%i==0){
            bool b=true;
            for(long long j=0;j<rightDivisor.size();j++){
                if(rightDivisor[j]%i==0){
                    b=false;
                    break;
                }
            }
            if(b){
                rightDivisor.push_back(i);
            }
        }
    }
    
    std::vector< std::vector<long long> > dp(n,std::vector<long long>(rightDivisor.size(),0));
    
    for(long long i=0;i<n;i++){
        for(long long j=0;j<rightDivisor.size();j++){
            if(rightDivisor[j]*2!=n && dp[i][j]==0){
                
                bool good=true;
                
                for(long long k=0;k<n/rightDivisor[j];k++){

                    if(table[i+k*rightDivisor[j]]==0){
                        good=false;
                    }
                   
                    dp[i+k*rightDivisor[j]][j]=1;
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
