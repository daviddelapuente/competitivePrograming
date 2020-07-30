#include <iostream>

//g++ name.cpp -o name
//./name < test.txt
//url: https://www.spoj.com/problems/ANARC09A/

int count(std::string S){
    int i=0;
    int d=0;
    int i2=0;
    int d2=0;

    int l=S.length();
    if(l==0){
        return i+d;
    }

    for(int j=0;j<l-1;j+=2){
        char c1=S[j];
        char c2=S[j+1];
        i2=0;
        d2=0;

        if(c1=='{' && c2=='{'){
            i2=1;
        }else if (c1=='}' && c2=='{'){
            i2=1;
            d2=1;
        }else if (c1=='}' && c2=='}'){
            d2=1;
        }

        if(i==0 && d==0){
            i+=i2;
            d+=d2;
        }else if(i>0 && d==0){
            //{{  }{
            // {{  }}
            // {{  {{
            if(d2==1){
                i--;
            }
            if(i2==1){
                i++;
            }
        }else if(i==0 && d>0){
            //}} }{
            //}} {{
            //}} }}
            if(d2==1){
                d++;
            }
            if(i2==1){
                i++;
            }
        }else if(i>0 && d>0){
            //}{  {{
            //}{  }{
            //}{  }}

            if(d2==1 && i2==0){
                i--;
            }
            if(i2==1 && d2==0){
                i++;
            }
            

        }

    }
    return i+d;
}

int main() {
    std::string S;
    int c=1;
    while(std::cin>>S){
        if(S[0]=='-'){
            break;
        }
        std::cout<< c << ". "<<count(S)<<std::endl;
        c++;
    }
    return 0;
}
