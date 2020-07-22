#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt
//url:https://www.spoj.com/problems/BYTESM2/

int filterIndex(int index,int w){
    if(index<0){
        return 0;
    }else if(index>=w){
        return w-1;
    }
}

long long philCount(std::vector< std::vector <long long > > V,int h, int w){
    std::vector< std::vector <long long> > DP( h , std::vector<long long> (w, 0));
    long long maximo=0;

     for(int i=0;i<h;i++){
         for(int j=0;j<w;j++){
             if(i>0){
                 if(j==0){
                     if(j==w-1){
                         DP[i][j]=DP[i-1][j]+V[i][j];
                     }else{
                         DP[i][j]=std::max(DP[i-1][j],DP[i-1][j+1])+V[i][j];
                     }
                 }else if(j==w-1){
                     if(j==0){
                         DP[i][j]=DP[i-1][j]+V[i][j];
                     }else{
                         DP[i][j]=std::max(DP[i-1][j-1],DP[i-1][j])+V[i][j];
                     }
                 }else{
                    DP[i][j]=std::max(DP[i-1][j-1], std::max(DP[i-1][j],DP[i-1][j+1]) )+V[i][j];
                 }
             }else{
                DP[i][j]=V[i][j];
             }  
            if(DP[i][j]>maximo){
                maximo=DP[i][j];
            }
         }
     }

     return maximo;

}

int main() {
    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        int h=0,w=0;
        std::cin>>h>>w;

        std::vector< std::vector <long long> > V( h , std::vector<long long> (w, 0));

        for(int i=0;i <h;i++){
            for( int j=0;j<w;j++){
                std::cin>>V[i][j];
            }
        }
        std::cout<<philCount(V,h,w)<<std::endl;
        
    }
    return 0;
}
