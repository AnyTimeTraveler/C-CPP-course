#include <iostream>
#include <typeinfo>


//======================================

class Vehicle {
protected:
    int _numSeats;
public:
    Vehicle(int numSeats=0);// may serve as default ctor (i.e. no arguments)
    virtual ~Vehicle();
    virtual int payload() = 0;
    int numSeats();         // a 'getter' method to get a value; no 'setter' here
};

//======================================

class Car : public Vehicle {
protected:
    int _maxWeight;     // german: zulässiges Gesamtgewicht
public:
    Car(int numSeats, int maxWeight);
    virtual int payload();
    
};

//======================================

class Truck : public Vehicle {
protected:
    int _payload;
public:
    Truck(int numSeats, int payload);
    virtual int payload();
};

//======================================

Vehicle::Vehicle(int numSeats){
    _numSeats = numSeats;
}

Vehicle::~Vehicle(){
    std::cout << "destroying a Vehicle" << std::endl;
}

int Vehicle::numSeats(){
    return _numSeats;
}

//======================================

Car::Car(int numSeats, int maxWeight){
    _numSeats = numSeats;
    _maxWeight = maxWeight;
}

int Car::payload(){
    return _maxWeight - (_numSeats*75);
}

//======================================

Truck::Truck(int numSeats, int payload){
    _numSeats = numSeats;
    _payload = payload;
}

int Truck::payload(){
    return _payload;
}

//======================================


void printVehicleInfo(Vehicle* v){
    std::cout << "typeid=`" << typeid(*v).name() << "`"
    << " numSeats=" << v->numSeats()
    << " payload=" << v->payload() << std::endl;
}

int main(int argc, const char * argv[]) {

    Car* c   = new Car(5, 1000);    // create a new object of class Car in free store
    Truck* t = new Truck(3, 7500);
    
    std::cout << "1" << std::endl;
    std::cout << "c: numSeats=" << c->numSeats() << " payload=" << c->payload() << std::endl;
    std::cout << "t: numSeats=" << t->numSeats() << " payload=" << t->payload() << std::endl;
    
    std::cout << std::endl << "2" << std::endl;
    Vehicle* v = c;             // a Car `is a` Vehicle => implicitly convertible
    printVehicleInfo(v);
    v = t;                      // a Truck `is a` Vehicle => implicitly convertible
    printVehicleInfo(v);
    
    
    // release memory occupied by t,c for use by future objects created by `new`
    // do NOT release v. it is only an alias
   delete t;
    delete c;
    
    return 0;
}
