#include <iostream>
//g++ name.cpp -o name
//./name < test.txt

//url: https://codeforces.com/problemset/problem/1426/C

double f(long y,long z){
    return (y-1)+(1.0*z/y);
}

long g(long y,long z){
    if(y*(z/y)>=z){
        return (y-1)+((z/y)-1);    
    }else{
        return (y-1)+(z/y);
    }    
}


void increaseAndCopy(long z){
    if (z==1){
        std::cout<<0<<std::endl;
        return;
    }
    if(z==2){
        std::cout<<1<<std::endl;
        return;
    }
    if(z==3){
        std::cout<<2<<std::endl;
        return;
    }
    long i=0;
    long j=z;
    long mid;
    double p1;
    double p;
    double p2;
    while(i<=j){
        //here ocurrs the binary search
        mid=i+(j-i)/2;
        p1=f(mid-1,z);
        p=f(mid,z);
        p2=f(mid+1,z);
        /*
        std::cout<<"-------------------"<<std::endl;
        std::cout<<"i="<<i<<std::endl;
        std::cout<<"j="<<j<<std::endl;
        std::cout<<"mid="<<mid<<std::endl;
        std::cout<<"p1="<<p1<<std::endl;
        std::cout<<"p="<<p<<std::endl;
        std::cout<<"p2="<<p2<<std::endl;
        std::cout<<"-------------------"<<std::endl;
        */
        if(p<p1 && p<p2){
            break;
        }else if(p1<=p && p<=p2){
            j=mid-1;
        }else{
            i=mid+1;
        }

    }
    std::cout<<g(mid,z)<<std::endl;

}

int main() {
    long t;
    std::cin>>t;
    for (int i=0;i<t;i++){
        long z;
        std::cin>>z;
        increaseAndCopy(z);
    }
    return 0;
}