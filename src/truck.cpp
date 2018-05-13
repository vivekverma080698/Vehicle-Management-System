#include "truck.h"
#include <iostream>
using namespace std;

truck_node :: truck_node(){}

truck_node::truck_node(std::string& t_name, std::string& t_color,int& t_mileage,int& t_top_speed,int& t_no_gear,int& t_w_capacity,int& t_v_capacity){
    name = t_name;
    color = t_color;
    mileage = t_mileage;
    top_speed = t_top_speed;
    no_gear = t_no_gear;
    w_capacity =  t_w_capacity;
    v_capacity =  t_v_capacity;
    status = false;
    link = NULL;
  }
