#include <iostream>
#include <vector>
//g++ name.cpp -o name
//./name < test.txt
//url: https://codeforces.com/problemset/problem/1255/B

/*
the idea to solve thism problem is to find the two minimum fridges
and join them, then for every other fridge, join it to the twi minimum fridges
ofcourse you have to filter the cases where u cant make the friges private
*/


int main() {
    long long t;
    std::cin>>t;

    for(long long i=0;i<t;i++){
        long long n,m;
        std::cin>>n>>m;

        long long fridges[n];

        for(long long j=0;j<n;j++){
            std::cin>>fridges[j];
        }

        if(n<=2){
            std::cout<<-1<<std::endl;
        }else if(n==3){
           if(m<3){
               std::cout<<-1<<std::endl;
           }else{
                long long min1id;
                long long min2id;
                long long min3id;

                if(fridges[0]<=fridges[1] && fridges[0]<=fridges[2]){
                    min1id=0;
                    if(fridges[1]<=fridges[2]){
                        min2id=1;
                        min3id=2;
                    }else{
                        min2id=2;
                        min3id=1;
                    }
                }else if(fridges[1]<=fridges[0] && fridges[1]<=fridges[2]){
                    min1id=1;
                    if(fridges[0]<=fridges[2]){
                        min2id=0;
                        min3id=2;
                    }else{
                        min2id=2;
                        min3id=0;
                    }
                }else if(fridges[2]<=fridges[0] && fridges[2]<=fridges[1]){
                    min1id=2;
                    if(fridges[0]<=fridges[1]){
                        min2id=0;
                        min3id=1;
                    }else{
                        min2id=1;
                        min3id=0;
                    }
                }


                long long sum=fridges[min1id]*2+fridges[min2id]*2+fridges[min3id]*2;
                if(m>3){
                    sum+=(fridges[min1id]+fridges[min2id])*(m-3);
                }
                std::cout<<sum<<std::endl;

                std::cout<<min1id+1<<" "<<min2id+1<<std::endl;
                std::cout<<min2id+1<<" "<<min3id+1<<std::endl;
                std::cout<<min3id+1<<" "<<min1id+1<<std::endl;

                if(m>3){
                    for(long long j=0;j<(m-3);j++){
                        std::cout<<min1id+1<<" "<<min2id+1<<std::endl;
                    }
                }
           }
        }else{
            if(m<(n-2)*2){
                std::cout<<-1<<std::endl;
            }else{

                //first we find the min and second min
                long long min1id=0;
                for(long long j=0;j<n;j++){
                    if(fridges[j]<=fridges[min1id]){
                        min1id=j;
                    }
                }

                long long min2id=(min1id+1)%n;
                for(long long j=0;j<n;j++){
                    if( fridges[j]<=fridges[min2id] && j!=min1id){
                        min2id=j;
                    }
                }


                long long sum=0;

                for(long long j=0;j<n;j++){
                    if(j!=min1id && j!=min2id){
                        sum+=fridges[j]*2+fridges[min1id]+fridges[min2id];
                    }
                }

                if(m>(n-2)*2){
                    sum+=(fridges[min1id]+fridges[min2id])*(m-(n-2)*2);
                }

                std::cout<<sum<<std::endl;

                for(long long j=0;j<n;j++){
                    if(j!=min1id && j!=min2id){
                        std::cout<<min1id+1<<" "<<j+1<<std::endl;
                        std::cout<<j+1<<" "<<min2id+1<<std::endl;
                    }
                }
 
                if(m>(n-2)*2){
                    for(long long j=0;j<(m-(n-2)*2);j++){
                        std::cout<<min1id+1<<" "<<min2id+1<<std::endl;
                    }
                }
            }
        }

    } 
    return 0;
}
