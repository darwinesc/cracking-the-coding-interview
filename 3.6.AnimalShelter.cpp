#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Animal{

    string name;
    int order;
    string type;

};

struct Cat : public Animal{

    public:
        Cat(string n){
            type = "cat";
            this->name = n;
        }
};

struct Dog : public Animal{
    public:
        Dog(string n){
            type = "dog";
            this->name = n;
        }
};

struct Shelter{
    queue<Dog> dogs;
    queue<Cat> cats;

    void enqueue(Dog d){
        dogs.push(d);
        d.order++;
    }

    void enqueue(Cat c){
        cats.push(c);
        c.order++;
    }

    Dog dequeueDog(){
        if(dogs.empty()){
            cout<<"There is no more dogs!";
            exit(0);
        }
        Dog d = dogs.front();
        dogs.pop();
        return d;
    }

    Cat dequeueCat(){
        if(cats.empty()){
            cout<<"There is no more cats!";
            exit(0);
        }
        Cat c = cats.front();
        cats.pop();
        return c;
    }

    Animal dequeueAny(){
        if(cats.size() && dogs.size()){
            Dog d = dogs.front();
            Cat c = cats.front();
            return (d.order <= c.order ? (Animal)dequeueDog() : (Animal)dequeueCat());
        }else if(dogs.size() == 0){
            return (Animal)dequeueCat();
        }else{
            return (Animal)dequeueDog();
        }
    }
};

int main(){

    Shelter s;
    Dog d1("Tommy"), d2("Buster"), d3("Oscar"), d4("Daisy");
    Cat c1("Ginger"), c2("Lily"), c3("Lucy"), c4("Silky");
    s.enqueue(d1); //Tommy
    s.enqueue(c1); //Ginger
    s.enqueue(d2); //Buster
    s.enqueue(c2); //Lily
    s.enqueue(c3); //Lucy
    s.enqueue(d3); //Oscar
    s.enqueue(d4); //Daisy
    s.enqueue(c4); //Silky
    cout << (s.dequeueAny()).name << "\n";  //Tommy
    cout << (s.dequeueDog()).name << "\n";  //Buster
    cout << (s.dequeueAny()).name << "\n";  //Ginger
    cout << (s.dequeueAny()).name << "\n";  //Lily
    cout << (s.dequeueDog()).name << "\n";  //Oscar
    cout << (s.dequeueAny()).name << "\n";  //Lucy
    cout << (s.dequeueCat()).name << "\n";  //Silky
    cout << (s.dequeueAny()).name << "\n";  //Daisy
    cout << (s.dequeueAny()).name << "\n";  //Exception thown

    return 0;
}