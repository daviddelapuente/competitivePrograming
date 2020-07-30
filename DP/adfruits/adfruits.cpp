#include <iostream>

//g++ name.cpp -o name
//./name < test.txt
//url: https://www.spoj.com/problems/ADFRUITS/

int main() {
    std::string S;
    int c=1;
    while(std::cin>>S){
        if(S[0]=='-'){
            break;
        }
        std::cout<< c << ". "<<count(S)<<std::endl;
        c++;
    }
    return 0;
}
