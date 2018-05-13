/* --------------------------------------------------------------------------------------------------------------
 Author : Vivek Kumar Verma
 EntryNo: 2016csb1064
 Project: Online Vehicle management System
 Dated  :
 
 -----------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "linklist.cpp"
#include "car.h"
#include "bus.h"
#include "truck.h"
#include "linklist.h"
#include <climits>
#define CLS (cout << "\033[2J")

using namespace std;

int main(int argc,char* argv[]){
cout<<"-------------------------------------------------------------------\n"<<endl;
cout<<"*****************  Vehicle Management System  *********************"<<endl;
cout<<"\n-------------------------------------------------------------------"<<endl;

   ifstream car_file,bus_file,truck_file;
   car_file.open("Files/car.txt");
   bus_file.open("Files/bus.txt");
   truck_file.open("Files/truck.txt");



string line,name,color ;
int mileage = 0, top_speed = 0,no_gear = 0, no_seat = 0,w_capacity = 0,v_capacity = 0,count1 = 0,count2 = 0,count3 =0;
Link1<car_node>  CAR;   // link list object is made with has all node o car type
Link1<bus_node>  BUS;   // link list object is made with has all node o bus type
Link1<truck_node>  TRUCK;// link list object is made with has all node o truck type

// here data is read from the file and link list is prepared

while(car_file>>name>>color>>mileage>>top_speed>>no_gear){
     CAR.addnode(name,color,mileage,top_speed,no_gear);
     count1++;
   } 
while(bus_file>>name>>color>>mileage>>top_speed>>no_gear>>no_seat){	 
     BUS.addnode(name,color,mileage,top_speed,no_gear,no_seat);
     count2++;
         }
while(truck_file>>name>>color>>mileage>>top_speed>>no_gear>>w_capacity>>v_capacity){
	 TRUCK.addnode(name,color,mileage,top_speed,no_gear,w_capacity,v_capacity);
	 count3++;
     }
//user interface

char a = 'Y';
while(a == 'Y'){
 L1:
  cout<<"\n\n\nMAIN MENU";
  cout<<"\nEnter digit:"<<endl;
  cout<<"	1: CAR"<<endl;
  cout<<"	2: BUS"<<endl;
  cout<<"	3: TRUCK"<<endl;
char input1;
cin>>input1;
  switch(input1){	
  	case '1' :{
  			string line,name,color ;
			int mileage = 90, top_speed = 105,no_gear = 6,flag =1;
 		      while(1){
    		     cout<<"\n\nWelcome to the CAR sections\nEnter : "<<endl;
    		     cout<<"	1:Show avaible car"<<endl;
    		     cout<<"	2:Remove car"<<endl;
    		     cout<<"	3:Add car"<<endl;
    		     cout<<"	4:Book car"<<endl;  
    		     cout<<"	5:Print detail"<<endl;
    		     cout<<"	6:show booked car"<<endl;
    		     cout<<"	7:Un book a car"<<endl;
    		     cout<<"	8:Exit"<<endl;
    		     cout<<"Your choice is :   ";
    		     char input2;
    		     cin>>input2;
    		     switch(input2){
    		       case '1': {cout<<"Available cars are\n\n";
    		                CAR.printcar();
    		                break;}
    		       case '2': {
    		       		    cout<<"\n Enter the car name.\n\n";
    		       		    cin>>name;
    		       		    CAR.deletenode(name,count1);
    		       		   break;
    		       		   }
    		       case '3': {cout<<"\n Enter the car name,color,mileage,top speed,no. of gear\n\n";
    		                cin>>name>>color>>mileage>>top_speed>>no_gear;
    		                CAR.addnode(name,color,mileage,top_speed,no_gear);
    		                count1++;
    		               break;}
    		       case '4': {cout<<"Enter the name to book the car : \n\n";
    		                cin>>name;
    		                CAR.book(name);}
    		               break;
    		       case '5': {cout<<"Enter the car name to get details : \n\n";
    		                cin>>name;
    		                CAR.printdetailcar(name);
    		                break;}
    		       case '6':{
    		          		CAR.bookedcar();
    		          		break;}
    		       case '7':{cout<<"Enter the name to un book the car : \n\n";
    		               cin>>name;
    		               CAR.unbook(name); 
    		               break;}
    		       case '8':
    		       		   break;
    		       default:{
    		               cout<<"\nWrong choice!!!";
    		               break; }         
    		       }
    		     if(input2=='8'){break;} 
     		    }
    		    break;
    		 }
 
    case '2':{
    		string line,name,color ;
			int mileage = 90, top_speed = 105,no_gear = 6, no_seat =0,flag =1;
 		      while(1){
    		     cout<<"\n\nWelcome to the BUS section\nEnter : "<<endl;
    		     cout<<"	1:Show avaible Buses"<<endl;
    		     cout<<"	2:Remove bus"<<endl;
    		     cout<<"	3:Add bus"<<endl;    		 
    		     cout<<"	4:Book bus"<<endl;  
    		     cout<<"	5:Print detail"<<endl;
    		     cout<<"	6:Accomodate people"<<endl;
    		     cout<<"	7:Show booked buses"<<endl;
    		     cout<<"	8:Un book a car"<<endl;
    		     cout<<"	9:EXIT!!!"<<endl;
    		     cout<<"Your choice is :   ";
    		     char input2;
    		     cin>>input2;
    		     switch(input2){
    		       case '1': {cout<<"Available buses are\n\n";
    		               BUS.printbus();
    		               break;}
    		       case '2': {//cout<<"Do you really want to remove bua OK!!!";
    		       		   cout<<"\n Enter the bus name.\n\n";
    		       		   cin>>name;
    		       		   BUS.deletenode(name,count2);
    		       		   break;}
    		       case '3': {cout<<"\n Enter the bus name,color,mileage,top speed,no. of gear,no. of seat\n\n";
    		               cin>>name>>color>>mileage>>top_speed>>no_gear>>no_seat;
    		               BUS.addnode(name,color,mileage,top_speed,no_gear,no_seat);
    		               count2++;
    		               break;}
    		       case '4': {cout<<"\nEnter the name to book the bus : \n\n";
    		               cin>>name;
    		               BUS.book(name);}
    		               break;
    		       case '5': {cout<<"\nEnter the bus name to get details : \n\n";
    		               cin>>name;
    		               BUS.printdetailbus(name);
    		               break;}
    		       case '6':{cout<<"Enter the number of people\n\n";
    		       		   int num=0;
    		       		   cin>>num;
    		       		   BUS.people(num,count2);
    		       			break;	}
    		       case '7':{
    		               BUS.bookedbus();
    		               break;}
    		       case '8':{cout<<"Enter the name to book the bus : \n\n";
    		               cin>>name;
    		               BUS.unbook(name); 
    		               break;}
    		       case '9':{ break;}	
    		       default:{
    		               cout<<"\nWrong choice!!!";
    		               break; }         
    		       }
    		    if(input2 == '9')
    		     break;
    		    
    		    }
    		   break;} 
    		    
   case '3':{
    		string line,name,color ;
			int mileage = 0, top_speed = 0,no_gear = 0, no_seat = 0,w_capacity,v_capacity,flag =1;
 		      while(1){
    		     cout<<"\n\nWelcome to the TRUCK section\nEnter : "<<endl;
    		     cout<<"1:Show avaible Trucks"<<endl;
    		     cout<<"	2:Remove Truck"<<endl;
    		     cout<<"	3:Add Truck"<<endl;    		 
    		     cout<<"	4:Book Truck"<<endl;  
    		     cout<<"	5:Print detail"<<endl;
    		     cout<<"	6Show booked Trucks"<<endl;
    		     cout<<"	7:Watermelon problem"<<endl;
    		     cout<<"	8:Un book a car"<<endl;
    		     cout<<"	9:EXIT!!!"<<endl;
    		     cout<<"Your choice is :   ";
    		     char input2;
    		     cin>>input2;
    		     switch(input2){
    		       case '1': {cout<<"Available Trucks are\n\n";
    		               TRUCK.printtruck();
    		               break;}
    		       case '2': {
    		       		   cout<<"\n Enter the Truck name.\n\n";
    		       		   cin>>name;
    		       		   TRUCK.deletenode(name,count3);
    		       		   break;}
    		       case '3': {cout<<"\n Enter the truck name,color,mileage,top speed,no. of gear,w_capacity,v_capacity\n\n";
    		               cin>>name>>color>>mileage>>top_speed>>no_gear>>w_capacity,v_capacity;
    		               TRUCK.addnode(name,color,mileage,top_speed,no_gear,w_capacity,v_capacity);
    		               count3++;
    		               break;}
    		       case '4': {cout<<"\nEnter the name to book the truck : \n\n";
    		               cin>>name;
    		               TRUCK.book(name);}
    		               break;
    		       case '5': {cout<<"\nEnter the truck name to get details : \n\n";
    		               cin>>name;
    		               TRUCK.printdetailtruck(name);
    		               break;}
    		       case '6': {
    		               TRUCK.bookedtruck();}	    		               			
    		       case '7': {
    		                cout<<"Enter the number of Watermelon"<<endl;
    		                int num = 0;
    		                cin>>num;
    		                TRUCK.watermelon(num,count3);
    		                 break;}
    		       case '8': {cout<<"Enter the name to book the truck : \n\n";
    		                cin>>name;
    		                TRUCK.book(name);
    		                break;}
    		       case '9':  break;
    		       default:{
    		                cout<<"\nWrong choice!!!\n";
    		                break; }         
    		       }
    		//     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    		  if(input2 == '9')
    		     break;  
    		    }
    		break;
    		}    	    
  
  default:{
         cout<<"\nWrong choice!!";
         break;}
  }  
     do{    
       cout<<"\nEnter Y for MAIN menu and N for exit!!! "; 
       cin>>a;      
     }while(a!='Y' && a!= 'N');
 }
cout<<"Thank You"<<endl;

car_file.close();
bus_file.close();
truck_file.close();   

 return 0;
}
