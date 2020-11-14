#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt

//https://codeforces.com/problemset/problem/115/A



int main() {
    long long n;
    std::cin>>n;
    std::vector<int> employes(n+1,0);

    for(long long i=1;i<n+1;i++){
        std::cin>>employes[i];
    }

    int maxCount=0;
    for(long long i=1;i<n+1;i++){
        int count=0;
        int auxI=i;
        while(employes[auxI]!=-1){
            count++;
            auxI=employes[auxI];

        }
        count++;
        maxCount=std::max(maxCount,count);
    }
    std::cout<<maxCount<<std::endl;
    return 0;
}