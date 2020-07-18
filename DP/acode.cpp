#include <iostream>
//g++ name.cpp -o name
//./name < test.txt
long long ante=0;
long long anteante=0;

bool sePue(std::string s){
    if(s[0]=='1'){
        return true;
    }else if(s[0]=='2' && s[1]!='7' && s[1]!='8' && s[1]!='9'){
        return true;
    }
    return false;
}

int posibilities(std::string s){
    if( s[0]=='1' && s[1]!='0'){
        return 2;
    }else if(s[0]=='2'){
        if(s[1]!='7' && s[1]!='8' && s[1]!='9' && s[1]!='0'){
            return 2;
        }
    }
    return 1;
}

long long count(std::string s){
    for(int i=0;i<s.size();i++){
        if(i==0){
            ante=1;
        }else if(i==1){
            anteante=ante;
            ante=posibilities(s.substr(0,2));
        }else{
            if(sePue(s.substr(i-1,2))){
                int aux=posibilities(s.substr(i-1,2));
                if(aux==2){
                    long long temp=ante;
                    ante=ante+anteante;
                    anteante=temp;
                }else{
                    long long temp=ante;
                    ante=anteante;
                    anteante=temp;
                }
            }else{
                anteante=ante;
            }
            
        }
    }
    return ante;
}

int main() {
    std::string s;
    while(std::cin>>s)
    {   
        if(s[0]=='0'){
            break;
        }
        
        std::cout<<count(s)<<std::endl;
    } 
    return 0;
}
