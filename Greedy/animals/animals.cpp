#include <iostream>
#include <vector>
#include <algorithm> 
#include <fstream>

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
    std::ifstream input;
    input.open("input.txt");

    std::ofstream output;
    output.open("output.txt");
    
    long long days, food;
    input>>days>>food;

    std::vector<long long> foodPerDay(days);

    for(long long i=0;i<days;i++){
        input>>foodPerDay[i];
    }

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
    

    output<<animalCount;
    input.close();
    output.close();
    return 0;
}
