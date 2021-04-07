#include <iostream>
#include <map>
//g++ name.cpp -o name
//./name < test.txt
// url: https://codeforces.com/problemset/problem/525/A

std::map<long, long> H;

int main() {
    
    int n;
    std::cin>>n;
    n--;
    char rooms[2*n];
    std::cin>>rooms;
    
    long ks=0;

    for(int i=0;i<2*n;i=i+2){
        
        char key=rooms[i];
        char lock=rooms[i+1]+32;
        
        if( H.find(key) == H.end()){
            //if we havent see the key before
            H[key]=1;
        }else{
            //we add the key to our hash
            H[key]++;
        }

        

        //now check the lock


        if(H.find(lock) == H.end()){
            //we havent seen the lock, we need to buy a key
            H[lock]=0;
            ks++;

        }else{
            
            //if we have seen the lock in our hash

            if(H[lock]>0){
                //if we have keys to use
                H[lock]--;
            }else{
                //if we dont have keys we buy one
                ks++;
            }
        }

    }

    std::cout<<ks<<std::endl;


    return 0;
}