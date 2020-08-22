#include <iostream>
#include <math.h>
//g++ name.cpp -o name
//./name < test.txt

//url: https://codeforces.com/problemset/problem/371/C

long fase1(long b, long s, long c, long * nb, long * ns, long * nc){
    long hamburgersB=__LONG_MAX__;
    long hamburgersS=__LONG_MAX__;
    long hamburgersC=__LONG_MAX__;

    if(b!=0){
        hamburgersB=*nb/b;
    }else{
        *nb=0;
    }

    if(s!=0){
        hamburgersS=*ns/s;
    }else{
        *ns=0;
    }

    if(c!=0){
        hamburgersC=*nc/c;
    }else{
        *nc=0;
    }

    long fase1Hamb=std::min(hamburgersB,std::min(hamburgersC,hamburgersS));
    if(fase1Hamb!=0){
        *nb=*nb-fase1Hamb*b;
        *ns=*ns-fase1Hamb*s;
        *nc=*nc-fase1Hamb*c;
    }
    return fase1Hamb;

}

long fase2(long b, long s, long c, long * nb, long * ns, long * nc,long pb, long ps, long pc,long r){
    while(*nb<=0 || ns<=0 || nc<=0){
        if(*nb!=0){
            if(*nb/(1.0*b)<= *ns/(1.0*s)  && *nb/(1.0*b)<= *nc/(1.0*c)){

            }
        }
    }
}


int main() {
    std::string recipe;
    std::cin>>recipe;
    
    long b=0,s=0,c=0;
    for (int i=0;i<recipe.size();i++){
        if(recipe[i]=='B'){
            b++;
        }else if(recipe[i]=='S'){
            s++;
        }else if(recipe[i]=='C'){
            c++;
        }
    }

    long nb, ns, nc;
    long pb, ps, pc;
    std::cin>>nb>>ns>>nc>>pb>>ps>>pc;

    long r;
    std::cin>>r;

    long hamburgers=0;

    hamburgers=fase1(b,s,c,&nb,&ns,&nc)+fase2(b,s,c,&nb,&ns,&nc,pb,ps,pc,r);

    std::cout<<hamburgers<<std::endl;


}