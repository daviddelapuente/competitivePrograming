#include <iostream>
#include <string>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt

//http://codeforces.com/problemset/problem/520/A



int main() {
    long long n;
    std::cin>>n;
    std::string S;
    std::cin>>S;

    std::vector<int> dic(200,0);

    for(int i=97;i<123;i++){
        dic[i]=1;
    }
    for(int i=65;i<91;i++){
        dic[i]=1;
    }

    for(long long i=0;i<n;i++){
        if(int(S[i])<=90){
            //is upper case
            dic[int(S[i])]=0;
            dic[int(S[i])+32]=0;
        }else{
            //lower
            dic[int(S[i])]=0;
            dic[int(S[i])-32]=0;
        }
    }

    bool b=true;
    for(int i=0;i<200;i++){
        if(dic[i]==1){
            b=false;
            break;
        }
    }
    if(b){
        std::cout<<"YES"<<std::endl;
    }else{
        std::cout<<"NO"<<std::endl;
    }
    
    return 0;
}