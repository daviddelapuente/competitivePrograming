#include <iostream>
#include <vector>
//g++ helloWordl.cpp -o helloWorld
//./helloWorld < inHelloWorld.txt
std::vector < std::vector < int> > DP(100,std::vector<int> (100, 0));
int main() {
    
    int M;
    int N;
    while(std::cin>>M && std::cin>>N){
        for(int i=0;i<M;i++){
            int a;
            int b;
            std::cin>>a>>b;
            if(i==0){
                for(int j=a;j<b;j++){
                    if(a<=N && N<=b){
                        DP[i][j]=1;
                    }
                }
            }
            for(int j=a;j<b;j++){
                
            }
        }
    }
    return 0;
}
