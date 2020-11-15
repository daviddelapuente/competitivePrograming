#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt
//url: https://codeforces.com/problemset/problem/1418/C

int min4(int a,int b, int c,int d){
    return std::min(a,std::min(b,std::min(c,d)));
}

//main function to run the problem
int main() {

    //number of tests
    int t;
    std::cin>>t;

    //for each test solve problem
    for(int k=0;k<t;k++){
        
        //number of bosses
        int n;
        std::cin>>n;
        
        //receive the bosses level
        std::vector<int> boss(n);
        for(int i=0;i<n;i++){
            std::cin>>boss[i];
        }
        
        //DP[0]=me2
        //DP[1]=me1
        //DP[2]=he2
        //DP[3]=he3
        std::vector< std::vector<int> > DP(4,std::vector<int>(n));

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

        //me playing 2 times: he played the first time. and only once 
        DP[0][2]=DP[3][0];
        //me playing 1 time: he played the first move and the second move
        DP[1][2]=DP[2][1];
        //him playing 2 times: imposible
        DP[2][2]=INT32_MAX;
        //him playing 1 time:he played the first move and this one (not the second)
        DP[3][2]=DP[3][0]+boss[2];

        if(n==3){
            std::cout<<min4(DP[0][2],DP[1][2],DP[2][2],DP[3][2])<<std::endl;
            continue;
        }

        //here ocurrs the DP        
        for(int i=3;i<n;i++){
            //me playing 2 times: min between him playing 1 time and him playing 2 times (2 turns ago) 
            DP[0][i]=std::min(DP[2][i-2],DP[3][i-2]);
            //me playing 1 time: min between him playing 1 time and him playing 2 times (1 turn ago) 
            DP[1][i]=std::min(DP[2][i-1],DP[3][i-1]);
            //him playing 2 times: min between me playing 1 time and me playing 2 times (2 turns ago)
            DP[2][i]=std::min(DP[0][i-2],DP[1][i-2])+boss[i]+boss[i-1];
            //him playinh 1 time: min between me playing 1 time and me playing 2 times (1 turn ago)
            DP[3][i]=std::min(DP[0][i-1],DP[1][i-1])+boss[i];
        }
        //print the min in the last level
        std::cout<<min4(DP[0][n-1],DP[1][n-1],DP[2][n-1],DP[3][n-1])<<std::endl;
                
    }
    return 0;
}
