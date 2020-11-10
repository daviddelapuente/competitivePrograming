#include <iostream>
#include <vector>

//g++ name.cpp -o name
//./name < test.txt
//url: https://codeforces.com/problemset/problem/1221/D

long long minPrice(std::vector<long long> fence, std::vector<long long> price){
    std::vector<long long> change(fence.size());
    std::vector<long long> notChange(fence.size());
    if(fence.size()==1){
        return 0;
    }

    change[0]=price[0];
    notChange[0]=0;

    for(long long i=1;i<fence.size();i++){
        if(fence[i]==fence[i-1]){
            //need to pay the price
            change[i]=price[i]+notChange[i-1];
            notChange[i]=change[i-1];
        }else{
            //if the are not equal
            if(fence[i]+1==fence[i-1]){
                change[i]=std::min(price[i]*2+notChange[i-1] ,price[i]+change[i-1]);
            }else{
                change[i]=price[i]+notChange[i-1];
            }

            if(fence[i]-1==fence[i-1]){
                notChange[i]=std::min(price[i-1]*2+(change[i-1]-price[i-1]),notChange[i-1]);
            }else{
                notChange[i]=notChange[i-1];
            }
            
        }
    }

    return std::min(change[(fence.size()-1)], notChange[(fence.size()-1)]);
}

int main() {
    long long Q;
    std::cin>>Q;

    for(long long q=0;q<Q;q++){
        long long n;
        std::cin>>n;

        std::vector<long long> fence(n);
        std::vector<long long> price(n);
        for(int i=0;i<n;i++){
            std::cin>>fence[i]>>price[i];
        }

        std::cout<<minPrice(fence,price)<<std::endl;
    }
    return 0;
}
