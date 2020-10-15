#include <iostream>
#include <unordered_map>
//g++ name.cpp -o name
//./name < test.txt

//url: https://codeforces.com/problemset/problem/1424/G

int main() {
    std::unordered_map<long, long> m;
    
    long n;
    std::cin>>n;
    
    long maximus;
    long y;

    for(int i=0;i<n;i++){
        long b,d;
        std::cin>>b>>d;
        if(i==0){
            maximus=1;
            y=b;
        }
        for(int j=b;j<d;j++){
            //if is not in m
            if( m.find(j) == m.end()){
                m[j]=1;
            }else{
                m[j]++;
                if(m[j]>maximus){
                    maximus=m[j];
                    y=j;
                }if(m[j]==maximus && j<y){
                    y=j;
                }
            }
        }
    }

    std::cout<<y<<" "<<maximus<<std::endl;
        
    return 0;
}