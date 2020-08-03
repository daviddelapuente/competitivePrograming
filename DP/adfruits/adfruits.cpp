#include <iostream>

//g++ name.cpp -o name
//./name < test.txt
//url: https://www.spoj.com/problems/ADFRUITS/

std::string combineFruits(std::string f1, std::string f2){
    std::string combination1="";
    std::string combination2="";
    
    //combination1

    int i1=0;
    int i2=0;

    for(i1;i1<f1.length();i1++){
        combination1+=f1[i1];
        if(i2<f2.length()){
            if(f1[i1]==f2[i2]){
                i2++;
            }
        }
    }

    for(i2;i2<f2.length();i2++){
        combination1+=f2[i2];
    }
    
    i1=0;
    i2=0;

    for(i2;i2<f2.length();i2++){
        combination2+=f2[i2];
        if(i1<f1.length()){
            if(f2[i2]==f1[i1]){
                i1++;
            }
        }
    }

    for(i1;i1<f1.length();i1++){
        combination2+=f1[i1];
    }


    if (combination1.length()>=combination2.length()){
        return combination2;
    }else{
        return combination1;
    }
}

int main() {
    std::string f1;
    std::string f2;
    
    while(std::cin>>f1 && std::cin>>f2){

        std::cout<< combineFruits(f1,f2) <<std::endl;

    }
    return 0;
}
