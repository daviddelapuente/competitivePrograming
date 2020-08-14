#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm> 

//g++ name.cpp -o name
//./name < test.txt
//url: http://codeforces.com/problemset/problem/978/C


long long  binarySearch(std::vector<std::vector<long long > > D, long long  letter,long long  l, long long  r){
    long long  mid= l + (r-l)/2;
    
    
    if(l>r){
        return -1;
    }
    if (D[mid][0]<=letter && letter<=D[mid][1]){
        return mid;
    }else if(letter<=D[mid][0]){
        return binarySearch(D,letter, l , mid-1);
    }else{
        return binarySearch(D,letter,mid+1,r);
    }


}

int main() {
    long long n,m;
    std::cin>>n>>m;

    std::vector<long long> D(n);

    std::cin>>D[0];
    
    for(int i=1;i<n;i++){
        std::cin>>D[i];
        D[i]+=D[i-1];
    }

    

    for(int i=0;i<m;i++){
        long long letter;
        std::cin>>letter;

        //return dormitoryIndex
        long long dormitoryIndex = std::lower_bound(D.begin(), D.end(), letter)-D.begin();

        long long room;
        if(dormitoryIndex==0){
            room=letter;
        }else{
            room=letter-D[dormitoryIndex-1];
        }

        std::cout<< dormitoryIndex+1<<" "<< room <<std::endl;
    }
}