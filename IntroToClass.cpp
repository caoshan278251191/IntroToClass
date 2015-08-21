/* 
 * File:   main.cpp
 * Author: caoshan
 *
 * Created on August 18, 2015, 2:58 PM
 */

#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

/*
 * 
 */
class Animal{
    private: 
        int height;
        int weight;
        string name;
          
        ///static int is shared by every object that created by the class;
        static int numOfAnimals;
        
    public:
        int getHight(){return height;}
        int getWeight(){return weight;}
        string getName(){ return name; }
        void setHeight(int cm){height=cm;}
        void setWeight(int kg){weight=kg;}
        void setName(string animalName){name=animalName;}
        
        void setAll(int,int, string);
        
        Animal(int, int, string);
        
        ~Animal();
        
        Animal();
        
        static int getNumberOfAnimals(){ return numOfAnimals;}
        
        void toString(); 
};

///the constructor could be put outside the class body. but be aware of the syntax.
int Animal::numOfAnimals=0;

///Constructor
Animal::Animal(int Height, int Weight, string Name){
    this->height=Height;
    this->weight=Weight;
    this->name=Name;
    Animal::numOfAnimals++;
}

//Deconstructor
Animal::~Animal(){
    cout<< " Animal " <<this->name<< " Destroyed" <<endl;
}

//Blank Constructor
Animal::Animal(){
    Animal::numOfAnimals++;
}

void Animal::toString(){
    cout<<this->name<< " is " <<this->height <<" Cm's Tall and " << this->weight
            << " Kgs in weight"<<endl;
}

int main(int argc, char** argv) {

    Animal Fred;
    Fred.setHeight(33);
    Fred.setWeight(10);
    Fred.setName("Fred");
    Fred.toString();
    Animal Tom(12,12,"Tom");
    Tom.toString();
    return 0;
}

