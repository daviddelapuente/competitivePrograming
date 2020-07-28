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
        std::vector < std::vector < int> > DP(M,std::vector<int> (N+1, 0));
        for(int i=0;i<M;i++){
            int a;
            int b;
            std::cin>>a>>b;

            if(i==0){
                for(int j=a;j<=b;j++){
                    DP[i][j]=1;
                }
            }else{
                for(int j=0;j<N;j++){
                    for(int k=a;k<=b;k++){
                        int tentativeN=k+j;
                        if (tentativeN<=N){
                            DP[i][tentativeN]+=DP[i-1][j];
                        }
                    }
                }

            }
            
        }
        std::cout<< DP[M-1][N] <<std::endl;
    }
    return 0;
}
