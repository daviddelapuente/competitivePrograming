#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt
//url: https://www.spoj.com/problems/SHUB1307/

//count the max (if posible) of vodka shots gupta can drink after reach his limit (k)
int vodkaCount(std::vector< std::vector <int > > V, int K,int n, int m){
    
    //3D dp n=row,m=cols,K+1=height
    //is k+1 because we want to access DP[i][j][K]
    std::vector< std::vector <std::vector <int> > > DP( n , std::vector<std::vector < int> > (m, std::vector<int> (K+1,0) ));
    
    //i==0 and j==0
    //if V[0][0] is a drinkable number, mark DP at its place
    if(V[0][0]<=K){
        DP[0][0][V[0][0]]=1;
    }

    //i==0
    //iter for each column j
    for(int j=1;j<m;j++){
        //for each column we iter for each height
        //this is because we want to reach all the posible shots gupta can have in each col in the first row
        for(int k=0;k<K;k++){
            //if there exist a reachable drink in the previous col (this will be only 1 in this case)
            if(DP[0][j-1][k]!=0){
                //then we mark the new reachable drink (if posible), and is only 1
                if(V[0][j] + k<=K ){
                    DP[0][j][V[0][j]+k]=1;
                }
            }
        }
    }

    //j==0
    //iter for each row
    for(int i=1;i<n;i++){
        //for each row we iter for each height
        //this is because we want to reach all the posible shots gupta can have in each row in the first col
        for(int k=0;k<K;k++){
            //if there exist a reachable drink in the previous row (this will be only 1 in this case)
            if(DP[i-1][0][k]!=0){
                if(V[i][0]+k<=K){
                    //then we mark the new reachable drink (if posible), and is only 1
                    DP[i][0][V[i][0] + k]=1;
                }
            }
        }
    }

    //iter the matrix
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){   
            //then we iter for the 3 posible heights-cols from were gupta can reach [i][j]: [i][j-1]  [i-1][k]  [i-1][j-1] 
            for(int k=1;k<K;k++){
                //[i][j-1]
                if(DP[i][j-1][k]==1){
                    if(V[i][j]+k<=K){
                        DP[i][j][V[i][j]+k]=1;
                    }
                }
            
                //[i-1][j]
                if(DP[i-1][j][k]==1){
                    if(V[i][j]+k<=K){
                        DP[i][j][V[i][j]+k]=1;
                    }
                }
            
                //[i-1][j-1]
                if(DP[i-1][j-1][k]==1){
                    if(V[i][j]+k<=K){
                        DP[i][j][V[i][j]+k]=1;
                    }
                }
            }
        }
    }

    //we want the max k that holds DP[n-1][m-1][k]==1
    int r=-1;
    for(int k=1;k<=K;k++){
        if(DP[n-1][m-1][k]==1){
            r=k;
        }
    }
    return r;
}

int main() {

    //tests number
    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        
        //n=row,m=cols,k=limit
        int n, m, k;
        std::cin>>n>>m>>k;

        //create the matrix
        std::vector< std::vector <int> > V( n , std::vector<int> (m, 0));
        for(int i=0;i <n;i++){
            for( int j=0;j<m;j++){
                std::cin>>V[i][j];
            }
        }

        //output the result
        std::cout<<vodkaCount(V,k,n,m)<<std::endl;    
    }

    return 0;
}
