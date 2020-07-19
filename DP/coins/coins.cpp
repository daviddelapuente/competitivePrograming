#include <iostream>
#include <map>
//g++ name.cpp -o name
//./name < test.txt
std::map<long, long> dp;
long dollars(long n){
    if(n<=3){
        return dp[n];
    }else{
        if( dp.find(n) == dp.end()){
            dp[n]=std::max(dollars(n/2)+dollars(n/3)+dollars(n/4),n);
        }
        return dp[n];
    }
}

int main() {
    int n;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    while(std::cin>>n)
    {
        std::cout<<dollars(n)<<std::endl;
    } 
    return 0;
}
