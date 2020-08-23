#include <iostream>
#include <map>
//g++ name.cpp -o name
//./name < test.txt

//url: http://codeforces.com/problemset/problem/335/A
int main() {
    std::string S;
    std::cin>>S;
    long long k;
    std::cin>>k;

    std::map<char, long long> abcdario;

    for(long long i=0;i<S.size();i++){
        if( abcdario.find(S[i]) == abcdario.end()){
            abcdario[S[i]]=1;
        }else{
            abcdario[S[i]]+=1;
        }
    }
    
    if(abcdario.size()<k){
        return -1;
    }

    long long c=0;
    std::string sheet="";
    for(long long i=0;i<k;i++){
        
        long long max=0;
        char letter;
        /*
        for (std::pair<char, long long> element : abcdario) {
            
            if(element.second>max;
            // Accessing VALUE from element.
            int count = element.second;
            std::cout << word << " :: " << count << std::endl;
        }
        */

    }

    
}