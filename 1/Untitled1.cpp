#include <iostream>
#include <string>
using namespace std;
class Animal {
protected:
    int age;
    long uniqueID;
    bool alive;
    pair<double, double> location;
public:
    Animal() : age(0), uniqueID(rand()), alive(true), location(make_pair(0.0, 0.0)) {}
    Animal(int age, double x, double y) : age(age), uniqueID(rand()), alive(true), location(make_pair(x, y)) {}
    virtual void move(double x, double y) {
        location.first = x;
        location.second = y;
        cout << "Animal has moved to location: (" << location.first << ", " << location.second << ")" << endl;
    }
    Animal(const Animal& other) {
        age = other.age;
        uniqueID = other.uniqueID;
        alive = other.alive;
        location = other.location;
    }
    virtual ~Animal() {}
    virtual void sleep() {
        cout << "Animal is sleeping" << endl;
    }
    virtual void eat() {
        cout << "Animal is eating" << endl;
    }
    void setAlive(bool isAlive) {
        alive = isAlive;
    }
    friend ostream& operator<<(ostream& os, const Animal& animal) {
        os << "Animal ID: " << animal.uniqueID << endl;
        os << "Age: " << animal.age << endl;
        os << "Alive: " << (animal.alive ? "Yes" : "No") << endl;
        os << "Location: (" << animal.location.first << ", " << animal.location.second << ")" << endl;
        return os;
    }
};
class Bird : public Animal {
public:
    Bird() : Animal() {}
    Bird(int age, double x, double y) : Animal(age, x, y) {}
    virtual void move(double x, double y) override {
        location.first = x;
        location.second = y;
        cout << "Bird has flown to location: (" << location.first << ", " << location.second << ")" << endl;
    }
    virtual void sleep() override {
        cout << "Bird is sleeping" << endl;
    }
    virtual void eat() override {
        cout << "Bird is eating seeds" << endl;
    }
};
class Canine : public Animal {
public:
    Canine() : Animal() {}
    Canine(int age, double x, double y) : Animal(age, x, y) {}
    virtual void move(double x, double y) override {
        location.first = x;
        location.second = y;
        cout << "Canine has walked to location: (" << location.first << ", " << location.second << ")" << endl;
    }

    virtual void sleep() override {
        cout << "Canine is sleeping" << endl;
    }

    virtual void eat() override {
        cout << "Canine is eating meat" << endl;
    }
};

int main() {
    Animal animal1(5, 1.0, 2.0);
    Bird bird1(2, 3.0, 4.0);
    Canine canine1(3, 5.0, 6.0);

    cout << "Animal Details:" << endl << animal1 << endl;
    cout << "Bird Details:" << endl << bird1 << endl;
    cout << "Canine Details:" << endl << canine1 << endl;

    cout << "Moving the animals..." << endl;

    animal1.move(7.0, 8.0);
    bird1.move(9.0, 10.0);
    canine1.move(11.0, 12.0);

    cout << "Animal Details after move:" << endl << animal1 << endl;
    cout << "Bird Details after move:" << endl << bird1 << endl;
    cout << "Canine Details after move:" << endl << canine1 << endl;

    cout << "Making the animals sleep and eat..." << endl;

    animal1.sleep();
    animal1.eat();

    bird1.sleep();
    bird1.eat();

    canine1.sleep();
    canine1.eat();

    cout << "Setting the animals to dead..." << endl;

    animal1.setAlive(false);
    bird1.setAlive(false);
    canine1.setAlive(false);

    cout << "Animal Details after setAlive:" << endl << animal1 << endl;
    cout << "Bird Details after setAlive:" << endl << bird1 << endl;
    cout << "Canine Details after setAlive:" << endl << canine1 << endl;

return 0;
}
