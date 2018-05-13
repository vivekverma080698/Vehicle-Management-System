#include "car.h"
#include <iostream>
using namespace std;

car_node::car_node(){}

car_node::car_node(std::string& c_name, std::string& c_color,int& c_mileage,int& c_top_speed,int& c_no_gear){
    name = c_name;
    color = c_color;
    mileage = c_mileage;
    top_speed = c_top_speed;
    no_gear = c_no_gear;
    status = false;
    link = NULL;
}
