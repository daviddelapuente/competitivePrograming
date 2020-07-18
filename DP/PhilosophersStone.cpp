#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt

int filterIndex(int index,int w){
    if(index<0){
        return 0;
    }else if(index>=w){
        return w-1;
    }
}

long philCount(std::vector< std::vector <int > > V,int h, int w){
     std::vector< std::vector <long> > DP( h , std::vector<long> (w, 0));

     for(int i=0;i<w;i++){
         DP[0][i]=V[0][i];
     }

     for(int i=1;i<h;i++){
         for(int j=0;j<w;j++){
             DP[i][j]=std::max(DP[i-1][filterIndex(j-1,w)], std::max(DP[i-1][j],DP[i-1][filterIndex(j+1,w)]) )+V[i][j];
         }
     }

     long maximo=0;
     for(int i=0;i<w;i++){
         if(DP[h-1][i]>maximo){
             maximo=DP[h-1][i];
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

        std::vector< std::vector <int> > V( h , std::vector<int> (w, 0));

        for(int i=0;i <h;i++){
            for( int j=0;j<w;j++){
                std::cin>>V[i][j];
            }
        }
        std::cout<<philCount(V,h,w)<<std::endl;
        
    }
    return 0;
}
