#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt

int limSum(int lim,int a,int b){
    if(a+b>lim || (a==-1 || b==-1)){
        return -1;
    }else{
        return a+b;
    }
}

int vodkaCount(std::vector< std::vector <int > > V, int k,int n, int m){
     std::vector< std::vector <int> > DP( n , std::vector<int> (m, 0));

     DP[0][0]==V[0][0];

     for(int i=1;i<m;i++){
         DP[0][i]=limSum(k,DP[0][i-1],V[0][i]);
     }

    for(int i=1;i<n;i++){
         DP[i][0]=limSum(k,DP[i-1][0],V[i][0]);
     }

     

     




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
