#ifndef _LL_
#define _LL_

#include "car.h"
#include "bus.h"
#include "truck.h"

using namespace std;

class car_node;
class bus_node;
class truck_node;


template <typename T>
class Link1:public truck_node ,public bus_node ,public car_node 
{
  private:
      T* root;
  public:
      Link1();
     ~Link1();                  
  //Function overloading
  void addnode(std::string& name, std::string& color,int& mileage,int& top_speed,int& no_gear); 
  void addnode(std::string& name, std::string& color,int& mileage,int& top_speed,int& no_gear,int& no_seat);
  void addnode(std::string& name, std::string& color,int& mileage,int& top_speed,int& no_gear,int& w_capacity,int& v_capacity); 
  void deletenode(std::string& name,int& count);
  void printcar();
  void printbus();
  void printtruck();
 // void traversal();
  void printdetailcar(std::string& key);
  void printdetailbus(std::string& key);
  void printdetailtruck(std::string& key);
  void watermelon(int& num,int& count);
  void book(std::string& key);
  void unbook(std::string& key);
  void bookedcar();
  void bookedbus();
  void bookedtruck();
  void people(int& num,int&count);  // seat 
  
};

#endif
