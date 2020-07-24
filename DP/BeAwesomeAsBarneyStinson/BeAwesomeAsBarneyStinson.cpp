#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < name.txt
//url: https://www.spoj.com/problems/BEHAPPY/

int main() {
    
    int M;
    int N;
    while(std::cin>>M && std::cin>>N){
        if(M==0 && N==0){
            break;
        }
        int numPaths=0;
        std::vector < std::vector < int> > DP(M,std::vector<int> (100, 0));
        for(int i=0;i<M;i++){
            int a;
            int b;
            std::cin>>a>>b;

            if(){
                for(int j=a;j<=b;j++){
                    
                }
            }
            
        }
    }
    return 0;
}
