#include <iostream>
#include <math.h>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/1138/A

int main() {
    int n;
    std::cin>>n;

    int tuna=0;
    int eel=0;
    int m=0;

    bool tunaBool, eelBool;

    int t;
    for(int i=0;i<n;i++){
        std::cin>>t;

        if(i==0){
            if(t==1){
                tunaBool=true;
                eelBool=false;
                tuna++;
            }else{
                tunaBool=false;
                eelBool=true;
                eel++;
            }
        }else{
            if(t==1 && tunaBool){
                tuna++;
            }else if(t==2 && eelBool){
                eel++;
            }else{
                if(t==2){
                    tunaBool=false;
                    eelBool=true;
                    m=std::max(m,std::min(tuna,eel));
                    eel=1;
                }else{
                    tunaBool=true;
                    eelBool=false;
                    m=std::max(m,std::min(tuna,eel));
                    tuna=1;
                }
            }
        }
    }

    m=std::max(m,std::min(tuna,eel));
    std::cout<<m*2<<std::endl;
}