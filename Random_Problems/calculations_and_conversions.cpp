/*
AUTHOR: Bryce Calhoun
DESCRIPTION: Various basic physics formula functions.
*/

#include <iostream>


using namespace std;


//* calculate: SPEED, TIME, DISTANCE, MASS, WEIGHT, FORCE, ACCELERATION, 
//* ENERGY, KINETIC ENERGY, POTENTIAL ENERGY(grav.)
////////////////////////////////////////

void program(const string[], int);
////////////////////////////////////////
float time();
float speed();
float distance();
float mass();
float weight();
float force();
float acceleration();
float energy();
float kin_energy();
float pot_energy();
////////////////////////////////////////

// meters/second squared
const float gravity = 9.807;

// meters/second
const float speed_of_light = 299792458.00;
////////////////////////////////////////

int main(){

    const string my_formulas[] = {"Time (given: speed, distance)","Speed (given: time, distance)",
                                "Distance (given: speed, time)","Mass (given: weight)",
                                "Weight (given: mass)","Force (given: mass, acceleration)",
                                "Acceleration (given: mass, force)","Energy (given: mass)",
                                "Kinetic Energy (given: mass, velocity)", 
                                "Gravitational Potential Energy (given: mass, height)"};
    int size = sizeof(my_formulas) / sizeof(my_formulas[0]);
    program(my_formulas, size);

};
void program(const string my_formulas[], int size){
    
    cout << "CHOOSE CALCULATION RESULT:" << endl;

    int response = 0;
    do{
        for(int x = 0; x < size; x++){
        cout << (x + 1) << ".) " << my_formulas[x] << endl;
        };
        cout << "ENTER: ";
        cin >> response;
    }while(response < 0 || response > 8);

    switch(response){
        case 2:
            speed();
            break;
        case 3:
            distance();
            break;
        case 4:
            mass();
            break;
        case 5:
            weight();
            break;
        case 6:
            force();
            break;
        case 7:
            acceleration();
            break;
        case 8:
            energy();
            break;
        case 9:
            kin_energy();
            break;
        case 10:
            pot_energy();
            break;
        default:
            time();
            break;
    };
};

float time(){
    float distance = 0.0;
    float speed = 0.0;
    

    do{
        cout << "Enter distance: ";
        cin >> distance;
    }while(distance < 0.0);
    

    do{
        cout << "Enter speed: ";
        cin >> speed;
    }while(speed < 0.0);
    
    float time = distance / speed;


    cout << "time is : " << time << endl;

    return time;
};

float speed(){
    float time = 0.0;
    float distance = 0.0;

    do{
        cout << "Enter time: ";
        cin >> time;
    }while(time < 0);
    

    do{
        cout << "Enter distance: ";
        cin >> distance;
    }while(distance < 0.0);

    float speed = distance / time;

    cout << "speed is: " << speed << endl;

    return speed;
};

float distance(){
    float time = 0.0;
    float speed = 0.0;

    do{
        cout << "Enter time: ";
        cin >> time;
    }while(time < 0);

    do{
        cout << "Enter speed: ";
        cin >> speed;
    }while(speed < 0.0);

    float distance = (speed * time);

    cout << "distance is: " << distance << endl;

    return distance;
};

float mass(){
    float weight = 0.0;

    do{
        cout << "Enter weight: ";
        cin >> weight;

    }while(weight < 0);
    

    float mass = (weight / gravity);

    cout << "mass is: " << mass << endl;

    return mass;
};

float weight(){
    float mass = 0.0;

    do{
        cout << "Enter mass: ";
        cin >> mass;
    }while(mass < 0);
    

    float weight = (mass * gravity);

    cout << "weight is: " << weight << endl;

    return weight;  
};

float force(){
    float mass = 0.0;
    float acceleration = 0.0;

    do{
        cout << "Enter mass: ";
        cin >> mass;
    }while(mass < 0);

    
    cout << "Enter acceleration: ";
    cin >> acceleration;
    
    
    float force = (mass * acceleration);

    cout << "force is: " << force << endl;

    return force;  
};

float acceleration(){
    float mass = 0.0;
    float force = 0.0;

    do{
        cout << "Enter mass: ";
        cin >> mass;
    }while(mass < 0);

    do{
        cout << "Enter force (magnitude): ";
        cin >> force;
    }while(force < 0);
    

    float acceleration = (force / mass);

    cout << "acceleration is: " << acceleration << endl;

    return acceleration;
};

float energy(){
    float mass = 0.0;

    do{
        cout << "Enter mass: ";
        cin >> mass;
    }while(mass < 0);

    float energy = mass * (speed_of_light * speed_of_light);

    cout << "energy is: " << energy << endl;

    return energy;
};

float kin_energy(){
    float mass = 0.0;
    float velocity = 0.0;

    do{
        cout << "Enter mass: ";
        cin >> mass;
    }while(mass < 0);

    cout << "Enter velocity: ";
    cin >> velocity;
    
    float kinEnergy = (mass * (velocity * velocity)) / 2;

    cout << "kinetic energy is: " << kinEnergy << endl;

    return kinEnergy;
};

float pot_energy(){
    float mass = 0.0;
    float height = 0.0;

    do{
        cout << "Enter mass: ";
        cin >> mass;
    }while(mass < 0);

    do{
        cout << "Enter height: ";
        cin >> height;
    }while(height < 0);

    float potEnergy = (mass * gravity * height);

    cout << "potential energy is: " << potEnergy << endl;

    return potEnergy;
};



