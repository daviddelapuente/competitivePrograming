#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt
//url: https://codeforces.com/problemset/problem/1418/C

int min8(int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8){
    return std::min(n1,std::min(n2,std::min(n3,std::min(n4,std::min(n5,std::min(n6,std::min(n7,n8)))))));
}

int min4(int a,int b, int c,int d){
    return std::min(a,std::min(b,std::min(c,d)));
}

//main function to run the problem
int main() {
    int t;
    std::cin>>t;

    for(int k=0;k<t;k++){
        int n;
        std::cin>>n;

        std::vector<int> boss(n);

        for(int i=0;i<n;i++){
            std::cin>>boss[i];
        }
        
        //DP[0]=me2
        //DP[1]=me1
        //DP[2]=hi2
        //DP[3]=hi3
        std::vector< std::vector<int> > DP(4,std::vector<int>(3));

        //me playing 2 times: imposible
        DP[0][0]=INT32_MAX;
        //me playing 1 time: imposible
        DP[1][0]=INT32_MAX;
        //him playing 2 time: imposible
        DP[2][0]= INT32_MAX;
        //him playing 1 time: this is the time so boss[0]
        DP[3][0]=boss[0];

        if(n==1){
            std::cout<<min4(DP[0][0],DP[1][0],DP[2][0],DP[3][0])<<std::endl;
            continue;
        }


        //me playing 2 times: imposible
        DP[0][1]=INT32_MAX;
        //me playing 1 time: him1
        DP[1][1]=DP[3][0];
        //him playing 2 time: him1 + actual
        DP[2][1]=DP[3][0]+boss[1];
        //him playing 1 time: imposible
        DP[3][1]=INT32_MAX;


        if(n==2){
            std::cout<<min4(DP[0][1],DP[1][1],DP[2][1],DP[3][1])<<std::endl;
            continue;
        }


        DP[0][2]=DP[3][0];

        DP[1][2]=DP[2][1];

        DP[2][2]=INT32_MAX;

        DP[3][2]=DP[3][0]+boss[2];

        if(n==3){
            std::cout<<min4(DP[0][2],DP[1][2],DP[2][2],DP[3][2])<<std::endl;
            continue;
        }

        for(int i=3;i<n;i++){
            DP[0][i%3]=std::min(DP[2][(i-2)%3],DP[3][(i-2)%3]);
            DP[1][i%3]=std::min(DP[2][(i-1)%3],DP[3][(i-1)%3]);
            DP[2][i%3]=std::min(DP[0][(i-2)%3],DP[1][(i-2)%3])+boss[i]+boss[i-1];
            DP[3][i%3]=std::min(DP[0][(i-1)%3],DP[1][(i-1)%3])+boss[i];
        }

        std::cout<<min4(DP[0][(n-1)%3],DP[1][(n-1)%3],DP[2][(n-1)%3],DP[3][(n-1)%3])<<std::endl;
        
        
    }
    return 0;
}
