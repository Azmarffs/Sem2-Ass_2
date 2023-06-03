/*
Name: Azmar Kashif
Section: B
Roll no: 22i-2716
*/
#include<iostream>
using namespace std;
class Pizza{
    char* name;
    char* topping;
    char* size;
    bool is_ready;
    double price;
    public:
    Pizza(){}; //default constructor
    Pizza(char* toppingVal, double priceVal){ //parametrized constructor 1
        topping = toppingVal;
        price = priceVal;
    }
    Pizza(char* toppingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status){ //parametrized constructor 2
        topping = toppingVal;
        price = priceVal;
        name = nameVal;
        size = sizeVal;
        is_ready = ready_status;
    }
    Pizza(const Pizza& pizza){ //copy constructor
        name = pizza.name;
        topping = pizza.topping;
        size = pizza.size;
        is_ready = pizza.is_ready;
        price = pizza.price;
    }
    /*
    getter and setters
    */
    void setTopping(char* toppingVal){
        topping = toppingVal;
    }
    void setPrice(double priceVal){
        price = priceVal;
    }
    void setName(char* nameVal){
        name = nameVal;
    }
    void setSize(char* sizeVal){
        size = sizeVal;
    }
    char* getToppng(){
        return topping;
    }
    double getPrice(){
        return price;
    }
    char* getName(){
        return name;
    }
    char* getSize(){
        return size;
    }
    void makePrizza(){
        if(topping != NULL){ //checking for the toppings if its not NULL we return true
            is_ready = true;
        }
    }
    bool check_status(){ //checking if pizza ready or not
        if(is_ready){
            return true;
        }else{
            return false;
        }
    }
};
int main() {
    // Creating a Pizza object using the first constructor
    Pizza pizza1("cheese", 10.99);
    cout << "Pizza 1:" << endl;
    cout << "Topping: " << pizza1.getToppng() << endl;
    cout << "Price: $" << pizza1.getPrice() << endl;

    // Creating a Pizza object using the second constructor
    Pizza pizza2("pepperoni", 12.99, "Pepperoni Pizza", "large", false);
    cout << "\nPizza 2:" << endl;
    cout << "Name: " << pizza2.getName() << endl;
    cout << "Topping: " << pizza2.getToppng() << endl;
    cout << "Size: " << pizza2.getSize() << endl;
    cout << "Price: $" << pizza2.getPrice() << endl;
    cout << "Is ready? " << (pizza2.check_status() ? "Yes" : "No") << endl;

    // Creating a copy of pizza2 using the copy constructor
    Pizza pizza3(pizza2);
    cout << "\nPizza 3 (Copy of Pizza 2):" << endl;
    cout << "Name: " << pizza3.getName() << endl;
    cout << "Topping: " << pizza3.getToppng() << endl;
    cout << "Size: " << pizza3.getSize() << endl;
    cout << "Price: $" << pizza3.getPrice() << endl;
    cout << "Is ready? " << (pizza3.check_status() ? "Yes" : "No") << endl;

    // Modifying pizza3
    pizza3.setName("Pepperoni & Mushroom Pizza");
    pizza3.setSize("medium");
    pizza3.makePrizza();
    cout << "\nModified Pizza 3:" << endl;
    cout << "Name: " << pizza3.getName() << endl;
    cout << "Topping: " << pizza3.getToppng() << endl;
    cout << "Size: " << pizza3.getSize() << endl;
    cout << "Price: $" << pizza3.getPrice() << endl;
    cout << "Is ready? " << (pizza3.check_status() ? "Yes" : "No") << endl;

    return 0;
}
