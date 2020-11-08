#include <iostream>
#include <vector>
#include <algorithm> 
//g++ name.cpp -o name
//./name < test.txt
// url: http://codeforces.com/problemset/problem/35/D

void printV(std::vector<long long> v){
    for(long long i=0;i<v.size();i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<std::endl;
}


long long f(long long days,long long food,std::vector<long long> foodPerDay) {

    std::vector<long long> totalFoodByAnimal(days);
    
    for(long long i=0;i<days;i++){
        totalFoodByAnimal[i]=(days-i)*foodPerDay[i];
    }


    std::sort(totalFoodByAnimal.begin(),totalFoodByAnimal.end());
    



    long long animalCount=0;
    long long foodSum=0;
    
    for(long long i=0;i<days;i++){
        if(foodSum+totalFoodByAnimal[i]<=food){
            animalCount++;
            foodSum+=totalFoodByAnimal[i];
        }else{
            break;
        }
    }

    return animalCount;
}


long long g(long long days,long long food,std::vector<long long> foodPerDay) {

    std::vector<long long> totalFoodByAnimal(days);
    
    for(long long i=0;i<days;i++){
        totalFoodByAnimal[i]=(days-i)*foodPerDay[i];
    }
    //printV(totalFoodByAnimal);
    std::vector<long long> candidates(0);
    long long sumCandidates=0;
    long long animalCount=0;
    for(long long i=0;i<days;i++){
        if(sumCandidates+totalFoodByAnimal[i]<=food){
            candidates.push_back(totalFoodByAnimal[i]);
            animalCount++;
            sumCandidates+=totalFoodByAnimal[i];
        }else{
            long long maximo;
            long long maximoIndex;
            for(long long j=0;j<candidates.size();j++){
                if(j==0){
                    maximo=candidates[j];
                    maximoIndex=j;
                }else{
                    if(candidates[j]>maximo){
                        maximo=candidates[j];
                        maximoIndex=j;
                    }
                }
            }
            if(candidates.size()>0 && candidates[maximoIndex]>totalFoodByAnimal[i]){
                sumCandidates-=candidates[maximoIndex];
                sumCandidates+=totalFoodByAnimal[i];
                candidates[maximoIndex]=totalFoodByAnimal[i];

            }
        }
        //printV(candidates);
    }
    return animalCount;
    

    
}

std::vector<long long> v;
void createAnimals(long long vSize){
    for(long long i=0;i<vSize;i++){
        v.push_back(rand() % 300 + 1);
    }
}

int main(){

    long long t=10000;
    long long days;
    long long food;
    for(long long i=0;i<t;i++){
        days=1;
        food=rand() % 10000 + 1;
        createAnimals(days);
        long long fvalue=f(days,food,v);
        long long gvalue=g(days,food,v);
        if(fvalue!=gvalue){
            std::cout<<"warning"<<std::endl;
            std::cout<<"days="<<days<<"  food="<<food<<"  f="<<fvalue<<"  g="<<gvalue<<std::endl;
            std::cout<<"v="<<std::endl;
            printV(v);
            break;
        }
        v.clear();
    }
    
    


    
    return 0;
}