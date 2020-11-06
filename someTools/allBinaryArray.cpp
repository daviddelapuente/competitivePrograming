#include <iostream>
#include <vector>
#include <math.h>

//this functions, takes two numbers t, k
//and create the k-th binary number of length t
//for example f(3,0)=[0,0,0] and f(4,2)=[0,0,0,0]

std::vector<int> f(int t, int n){
    std::vector<int> ans;

    for(int i=0;i<t;i++){
        unsigned int bit = n & 1;
        if( bit == 1 ){
            ans.push_back(1);
        }
        else {
            ans.push_back(0);
        }
        n >>= 1;
    }
    return ans;
}

int main(){
    int t=3;
    for(int k=0;k<pow(2,t);k++){
        std::vector<int> v=f(t,k);
        for(int i=0;i<t;i++){
            std::cout<<v[i]<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}