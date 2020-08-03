#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt
//url: https://codeforces.com/problemset/problem/1020/B

int lastHole(std::vector<int> P,int i,int n){
    
    std::vector<int> h(n,0);
    int last=i;
    //121

    while(true){
        if (h[i]>0){
            last=i;
            break;
        }
        h[i]++;
        i=P[i];
    }

    return last;
}

int main() {
    int n;
    std::cin>>n;

    std::vector<int> P(n);
    std::vector<int> B(n);

    for(int i=0;i<n;i++){
        std::cin>>P[i];
        P[i]--;
    }

    for(int i=0;i<n;i++){
        B[i]=lastHole(P,i,n)+1;
    }

    for(int i=0;i<n;i++){
        if(i==0){
            std::cout<<B[i];
        }else{
            std::cout<<" "<<B[i];
        }
        
    }
    std::cout<<std::endl;
    
    return 0;
}