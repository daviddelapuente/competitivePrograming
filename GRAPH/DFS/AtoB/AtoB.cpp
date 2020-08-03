#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt
//url: https://codeforces.com/problemset/problem/727/A


void aTob(long long a,long long b){
    std::vector<long long> G;
    std::vector<int> Gstate;

    //a<b

    G.push_back(a);
    Gstate.push_back(2);

    while(G.size()>0){
        if(G.back()==b){
            break;
        }else if(G.back()>b){
            G.pop_back();
            Gstate.pop_back();
        }

        if(Gstate.back()==2){
            //2 means go to 2a
            Gstate.pop_back();
            Gstate.push_back(1);
            G.push_back(2*G.back());
            Gstate.push_back(2);
            
        }else if(Gstate.back()==1){
            Gstate.pop_back();
            Gstate.push_back(0);
            G.push_back(10*G.back()+1);
            Gstate.push_back(2);
            //1 means go to 10a+1
        }else if(Gstate.back()==0){
            //0 means go back
            G.pop_back();
            Gstate.pop_back();
        }
    }
    
    if(G.size()>0){
        std::cout<<"YES"<<std::endl;
        std::cout<<G.size()<<std::endl;
        for(int i=0;i<G.size();i++){
            if(i==0){
                std::cout<<G[i];
            }else{
                std::cout<<" "<<G[i];
            }
            
        }
        std::cout<<std::endl;
    }else{
        std::cout<<"NO"<<std::endl;
    }

}

int main() {
    long long a,b;
    std::cin>>a>>b;
    aTob(a,b); 
    return 0;
}
