#ifndef _bus_
#define _bus_ 
#include "vehicle.h"
#include <iostream>

template <typename T>
class Link1;

class bus_node : public base{
  private:
     int no_seat;
     bool status;
  protected:
     bus_node* link;  
  public:    
     bus_node(void);
     ~bus_node(){}
     bus_node(std::string& name, std::string& color,int& mileage,int& top_speed,int& no_gear,int& no_seat);
template <typename T>
friend class Link1;
};
#endif
