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


int main() {
    long long days, food;
    std::cin>>days>>food;

    std::vector<long long> foodPerDay(days);

    for(long long i=0;i<days;i++){
        std::cin>>foodPerDay[i];
    }

    printV(foodPerDay);
    std::vector<long long> totalFoodByAnimal(days);
    
    for(long long i=0;i<days;i++){
        totalFoodByAnimal[i]=(days-i)*foodPerDay[i];
    }
    printV(totalFoodByAnimal);
    std::sort(totalFoodByAnimal.begin(),totalFoodByAnimal.end());
    
    printV(totalFoodByAnimal);


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
    

    std::cout<<animalCount<<std::endl;

    return 0;
}
