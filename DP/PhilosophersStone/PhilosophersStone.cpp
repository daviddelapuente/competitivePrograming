#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt
//url:https://www.spoj.com/problems/BYTESM2

long long philCount(std::vector< std::vector <long long > > M,int h, int w){

    //init DP matrix with 0
    std::vector< std::vector <long long> > DP( h , std::vector<long long> (w, 0));
    
    //some particular cases:

    //if h==1, that means 1 row
    if(h==1){
        long long maximo=0;
        for(int j=0;j<w;j++){
            if (M[0][j]>maximo){
                maximo=M[0][j];
            }
        }
        return maximo; 
    }

    //if w==1, that mean 1 col
    if(w==1){
        long long sum=0;
        for(int i=0;i<h;i++){
            sum+=M[i][0];
        }
        return sum;
    }

    //we fill the first row of DP
    for(int j=0;j<w;j++){
        DP[0][j]=M[0][j];
    }
    
    //we fill the rest of DP
    for(int i=1;i<h;i++){
        for(int j=0;j<w;j++){
            if(j==0){
                DP[i][j]=std::max(DP[i-1][j],DP[i-1][j+1])+M[i][j];
            }else if(j==w-1){
                DP[i][j]=std::max(DP[i-1][j-1],DP[i-1][j])+M[i][j];
            }else{
                DP[i][j]=std::max(DP[i-1][j-1], std::max(DP[i-1][j],DP[i-1][j+1]) )+M[i][j];
            }
        }
    }

    //check the last row to search the result
    long long maximo=0;
    for(int j=0;j<w;j++){
        if(DP[h-1][j]>maximo){
            maximo=DP[h-1][j];
        }
    }

    return maximo;

}

//main function to run the problem
int main() {

    // Number of problems
    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){

        //matrix dimension
        int h,w;
        std::cin>>h>>w;
        
        //init the matrix
        std::vector< std::vector <long long> > M( h , std::vector<long long> (w, 0));
        
        //fill the matrix
        for(int i=0;i <h;i++){
            for( int j=0;j<w;j++){
                std::cin>>M[i][j];
            }
        }

        //calculate max stones
        std::cout<<philCount(M,h,w)<<std::endl;
    }
    return 0;
}
