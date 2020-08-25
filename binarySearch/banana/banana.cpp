#include <iostream>
#include <map>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/335/A

long long ceil(long long a, long long b){
    if(a%b>0){
        return a/b + 1;
    }
    return a/b;
}

int main() {
    std::string S;
    std::cin>>S;
    long long k;
    std::cin>>k;

    std::map<char, long long[2]> abcdario;

    for(long long i=0;i<S.size();i++){
        if( abcdario.find(S[i]) == abcdario.end()){
            abcdario[S[i]][0]=1;
        }else{
            abcdario[S[i]][0]+=1;
        }
    }
    
    if(abcdario.size()>k){
        std::cout<<-1<<std::endl;
        return 0;
    }

    std::string sheet="";

    for (std::pair<const char, long long[2]> element : abcdario) {
        sheet+=element.first;
        abcdario[element.first][1]=1;
        k--;
    }

    for(long long i=0;i<k;i++){
        double max=0;
        char letter;
        for (std::pair<const char, long long[2]> element : abcdario){
            if(element.second[0]*1.0/element.second[1]>=max){
                max=element.second[0]*1.0/element.second[1];
                letter=element.first;
            }
        }

        sheet+=letter;
        abcdario[letter][1]++;
    }

    double max=0;
    char letter;
    for (std::pair<const char, long long[2]> element : abcdario){
        if(element.second[0]*1.0/element.second[1]>=max){
            max=element.second[0]*1.0/element.second[1];
            letter=element.first;
        }
    }

    std::cout<< ceil(abcdario[letter][0],abcdario[letter][1]) <<std::endl;
    std::cout<<sheet<<std::endl;
    
    return 0;

    
}