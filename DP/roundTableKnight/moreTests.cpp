#include <iostream>
#include <map>
#include <vector>
#include <math.h> 
#include <assert.h>
//g++ name.cpp -o name
//./name < test.txt
// url:http://codeforces.com/problemset/problem/71/C


//when i solved this problem, i think abaut rips, y dont know why
void printDp(std::vector< std::vector <long long> > dp){
    for (long long i=0;i<dp.size();i++){
        for(long long j=0;j<dp[0].size();j++){
            std::cout<<dp[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void printV(std::vector<long long> v){
    for(long long i=0;i<v.size();i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
}
std::vector< std::vector<long long> > dp;
std::string f(long long n, std::vector<long long> table) {

    
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


    dp = std::vector<std::vector<long long > > (n,std::vector<long long> (rightDivisor.size(),0));

    

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
                    
                    return "YES";
                }

            }
        }
    }
    return "NO";
}

std::string g(long long n, std::vector<long long> table) {
    long long l=floor(sqrt(n));
    std::vector< std::vector<long long> > dp(n,std::vector<long long>(l,0));
    for(long long i=0;i<n;i++){
        for(long long j=1;j<n;j++){
            if(n%j==0 && j*2!=n){
                bool good=true;
                for(long long k=0;k<n/j;k++){
                    if(table[(i+k*j)%n]==0){
                        good=false;
                    }
                }
                if(good){
                    return "YES";
                }
            }
        }
    }
    return "NO";
}

std::vector<long long> v;
void createPermutation(long long t, long long n){

    for(long long i=0;i<t;i++){
        unsigned long long bit = n & 1;
        if( bit == 1 ){
            v.push_back(1);
        }
        else {
            v.push_back(0);
        }
        n >>= 1;
    }

}

int main(){

    long long t=20;

    
    for(long long i=3;i<t;i++){
        for(long long j=0;j<pow(2,i);j++){
            createPermutation(i,j);
            if(f(i,v)!=g(i,v)){
                printV(v);
                std::cout<<"fdp="<<f(i,v)<<std::endl;
                std::cout<<"ggg="<<g(i,v)<<std::endl;
                break;
            }
            v.clear();
        }
    }

    
    return 0;
}