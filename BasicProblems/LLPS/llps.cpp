#include <iostream>
#include <math.h>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/202/A

int main() {
    std::string s;
    std::cin>>s;

    char cmax='a';

    for(int i=0;i<s.size();i++){
        if(s[i]>cmax){
            cmax=s[i];
        }
    }

    for(int i=0;i<s.size();i++){
        if(s[i]==cmax){
            std::cout<<cmax;
        }
    }
    std::cout<<std::endl;
}