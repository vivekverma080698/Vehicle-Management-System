#include "bus.h"
#include <iostream>
using namespace std;

bus_node::bus_node(){}

bus_node::bus_node(std::string& b_name, std::string& b_color,int& b_mileage,int& b_top_speed,int& b_no_gear,int& b_no_seat){
    name = b_name;
    color = b_color;
    mileage = b_mileage;
    top_speed = b_top_speed;
    no_gear = b_no_gear;
    no_seat = b_no_seat;
    status = false;
    link = NULL;
  }
 
