#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt
//url: https://www.spoj.com/problems/SHUB1307/

int limSum(int lim,int a,int b){
    if(a+b>lim || (a==-1 || b==-1)){
        return -1;
    }else{
        return a+b;
    }
}

int vodkaCount(std::vector< std::vector <int > > V, int K,int n, int m){
    std::vector< std::vector <std::vector <int> > > DP( n , std::vector<std::vector < int> > (m, std::vector<int> (K+1,0) ));
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                if(V[i][j]<=K){
                    DP[i][j][V[i][j]]=1;
                }
            }
            else if(i==0){
                for(int k=0;k<K;k++){
                    if(DP[i][j-1][k]!=0){
                        if(V[i][j] + k<=K ){
                            DP[i][j][V[i][j]+k]=1;
                        }
                    }
                }
            }else if(j==0){
                for(int k=0;k<K;k++){
                    if(DP[i-1][j][k]!=0){
                        if(V[i][j]+k<=K){
                            DP[i][j][V[i][j] + k]=1;
                        }
                    }
                }
            }else{
                //[i][j-1]
                for(int k=1;k<K;k++){
                    if(DP[i][j-1][k]==1){
                        if(V[i][j]+k<=K){
                            DP[i][j][V[i][j]+k]=1;
                        }
                    }
                }
                //[i-1][j]
                for(int k=1;k<K;k++){
                    if(DP[i-1][j][k]==1){
                        if(V[i][j]+k<=K){
                            DP[i][j][V[i][j]+k]=1;
                        }
                    }
                }
                //[i-1][j-1]
                for(int k=1;k<K;k++){
                    if(DP[i-1][j-1][k]==1){
                        if(V[i][j]+k<=K){
                            DP[i][j][V[i][j]+k]=1;
                        }
                    }
                }
            }
        }
    }

    int r=-1;
    for(int k=1;k<=K;k++){
        if(DP[n-1][m-1][k]==1){
            r=k;
        }
    }
    return r;
     




}

int main() {
    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        int n, m, k;
        std::cin>>n>>m>>k;

        std::vector< std::vector <int> > V( n , std::vector<int> (m, 0));

        for(int i=0;i <n;i++){
            for( int j=0;j<m;j++){
                std::cin>>V[i][j];
            }
        }
        std::cout<<vodkaCount(V,k,n,m)<<std::endl;
        
    }
    return 0;
}
