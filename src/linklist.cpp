#include "linklist.h"
#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

template <typename T>
Link1<T>::Link1(){
 root = new T();
 root = NULL;
 }
 
template <typename T>
Link1<T>::~Link1(){}

//Add node for car not sorted
template <typename T>
void Link1<T> :: addnode(std::string& name, std::string& color,int& mileage,int& top_speed,int& no_gear)
{ 
   T* curr = new T(name,color,mileage,top_speed,no_gear);
   int flag = 0;
   if(root == NULL){
    root = curr;
    return;}
   else{
    T* temp = root;    
    while((temp->link  != NULL)){
        if(temp->name != name){
           temp = temp->link;}
        else{
           flag = 1;
           break;
        }
    }
   if(flag == 0){     
     temp->link = curr;}
   else
     cout<<"\nVehicle already exist with same name"<<endl; 
     }
}
//sorted an bus list
template <typename T>
void Link1<T> :: addnode(std::string& name, std::string& color,int& mileage,int& top_speed,int& no_gear,int& no_seat)
{ 
   T* curr = new T(name,color,mileage,top_speed,no_gear,no_seat);
    if (root == NULL || (root)->no_seat <= curr->no_seat)
    {
        curr->link = root;
        root = curr;
    }
    else
    {
     T *current = root;
        while (current->link!=NULL && current->link->no_seat > curr->no_seat)
        {
            current = current->link;
        }
        curr->link = current->link;
        current->link = curr;
    }
}

// add node for truck sorted
template <typename T>
void Link1<T>::addnode(std::string& name,std::string& color,int& mileage,int& top_speed,int& no_gear,int& w_capacity,int& v_capacity)
{ 
   T* curr = new T(name,color,mileage,top_speed,no_gear,w_capacity,v_capacity);
	    if (root == NULL || (root)->v_capacity <= curr->v_capacity)
    {
        curr->link = root;
        root = curr;
    }
    else
    {
     T *current = root;
        while (current->link!=NULL && current->link->v_capacity > curr->v_capacity)
        {
            current = current->link;
        }
        curr->link = current->link;
        current->link = curr;
    }
}

template <typename T>
void Link1<T> :: printcar(){
  T* temp = root;
  while(temp != NULL){
      cout<<temp->name<<"  "<<temp->color<<"  "<<temp->mileage<<"  "<<temp->top_speed<<"  "<<temp->no_gear<<endl;       
     temp = temp -> link;  
  }
 if(root == NULL)
   cout<<"List is empty";  
}


template <typename T>
void Link1<T> :: printbus(){
  T* temp = root;
  while(temp != NULL){
        cout<<temp->name<<"  "<<temp->color<<"  "<<temp->mileage<<"  "<<temp->top_speed<<"  "<<temp->no_gear<<"  "<<temp->no_seat<<endl;
     temp = temp -> link;  
  }      
   if(root == NULL)
   cout<<"List is empty";  
}

template <typename T>
void Link1<T> :: printtruck(){
  T* temp = root;
  while(temp  != NULL){
     cout<<"  "<<temp->name<<"  "<<temp->color<<"  "<<temp->mileage<<"  "<<temp->top_speed<<"  "<<temp->no_gear<<"  "<<temp->v_capacity<<"  "<<temp->w_capacity<<endl;
     temp = temp -> link;  
  }
   if(root == NULL)
   cout<<"List is empty";
}

//Add node for printing whole list
/*
template <typename T>
void Link1<T>::traversal(){
 T *temp = root;
// cout<<"Kam ban gaya  : "<< typeid(T).name()<<endl;
 while(temp != NULL)
 {
   cout<<temp->name<<" "<<temp->color<<" "<<temp->mileage<<" "<<temp->top_speed<<" "<<temp->no_gear<<endl;
   temp=temp->link;
   }
}
*/
template <typename T>
void Link1<T>::deletenode(std::string& key,int& count){
 T *head = root;
 T *preNODE;
// cout<<"count = "<<count<<endl;
    for(int i=0;i<count;i++){
        if (i != (count-1)){
                if(key == head->name && key != root->name){
                        preNODE->link = head->link;
                        delete head;
                        count = count - 1;
                        break;
                }
                
                else if(key == root->name){
                        root = root->link;
                        count = count - 1;
                      break;}   
                      
                else{
                        preNODE = head;
                        head = head->link;}
                   }     
        else if (key == head->name){
                preNODE->link = NULL;
                count = count - 1;
                delete head;
              //     cout<<"Ok i found it"<<endl;
               // print(n1,head1);
        }
        else{
       cout<<"Your entered vehicle not found"<<endl;     
       }
   }
    if(root == NULL)
   cout<<"List is empty";
}





template <typename T>
void Link1<T> :: printdetailcar(std::string& key){
 T* temp = root;
 int flag = 0;
while(temp != NULL){
   if(temp->name == key){
         cout<<"\n"<<"name "<<temp->name<<"\ncolor "<<temp->color<<"\nmileage "<<temp->mileage<<"\ntop speed "<<temp->top_speed<<"\nno. of gear "<<temp->no_gear<<endl;
         flag = 1;
         break;} 
    else
        temp = temp->link;        
     }
  if(flag ==0)
     cout<<key<<" not found!!!"<<endl;
  if(root == NULL)
   cout<<"List is empty";
}              

template <typename T>
void Link1<T> :: printdetailbus(std::string& key){
 T* temp = root;
 int flag = 0;
while(temp != NULL){
   if(temp->name == key){
      cout<<"\n"<<"name "<<temp->name<<"\ncolor "<<temp->color<<"\nmileage "<<temp->mileage<<"\ntop speed "<<temp->top_speed<<"\nno. of gear "<<temp->no_gear<<"\nno. of seat "<<temp->no_seat<<endl;
         flag = 1;
         break;} 
    else
        temp = temp->link;        
     }
       if(flag ==0)
     cout<<key<<" not found!!!"<<endl;
 if(root == NULL)
   cout<<"List is empty";    
}              


template <typename T>
void Link1<T> :: printdetailtruck(std::string& key){
 T* temp = root;
 int flag = 0;
while(temp != NULL){
   if(temp->name == key){
      cout<<"\n"<<"name "<<temp->name<<"\ncolor "<<temp->color<<"\nmileage "<<temp->mileage<<"\ntop speed "<<temp->top_speed<<"\nno. of gear "<<temp->no_gear<<"\nvolume capacity "<<temp->v_capacity<<"\nweight capacity "<<temp->w_capacity<<endl;
             flag = 1;
         break;} 
    else
        temp = temp->link;        
     }
       if(flag ==0)
     cout<<key<<" not found!!!"<<endl;
  if(root == NULL)
   cout<<"List is empty";
}  
template <typename T>
void Link1<T> :: bookedcar(){
  T* temp = root;
  int flag = 0;
  while(temp != NULL){
     if(temp->status == true){
       cout<<temp->name<<" "<<temp->color<<" "<<temp->mileage<<" "<<temp->top_speed<<" "<<temp->no_gear<<endl;       
     flag =1;
     }temp = temp -> link;  
  }
   if(flag ==0)
    cout<<"No car is booked"<<endl;
}



template <typename T>
void Link1<T> :: bookedbus(){
  T* temp = root;
  int flag = 0;
  while(temp != NULL){
     if(temp->status == true){
        cout<<temp->name<<" "<<temp->color<<" "<<temp->mileage<<" "<<temp->top_speed<<" "<<temp->no_gear<<" "<<temp->no_seat<<endl;
        flag =1;}
     temp = temp -> link;  
  }        
  if(flag ==0)
    cout<<"No bus is booked"<<endl;
}

template <typename T>
void Link1<T> :: bookedtruck(){
  T* temp = root;
  int flag = 0;
  while(temp != NULL){
     if(temp->status == true){
     cout<<" "<<temp->name<<" "<<temp->color<<" "<<temp->mileage<<" "<<temp->top_speed<<" "<<temp->no_gear<<" "<<temp->v_capacity<<" "<<temp->w_capacity<<endl;
     flag = 1;}
     temp = temp -> link;  
  }
   if(flag ==0)
    cout<<"No  is booked"<<endl;
}


template <typename T>
void Link1<T>::book(std::string& key){
   T* temp = root;
   int flag = 0;
    while(temp != NULL){
        if(temp -> name == key){
           flag = 1;
           if(temp->status == false)
          {
            temp -> status = true;
            cout<<"Booked "<<key<<endl;

            break;
            }
           else
             cout<<key<<" is already booked!!"<<endl;
        }
        temp = temp -> link; 
    }
 if(flag == 0)
   cout<<"Vehicle is not present in data"<<endl;  
  
  if(root == NULL)
   cout<<"List is empty";
}

template <typename T>
void Link1<T>::unbook(std::string& key){
   T* temp = root;
   int flag = 0;
    while(temp != NULL){
        if(temp -> name == key){
           flag = 1;
           if(temp->status == true)
          {
            temp -> status = false;
            cout<<"Un Booked "<<key<<endl;
            break;
            }
           else{
             cout<<key<<" is already un booked!!"<<endl;
             break;}
        }
       else 
        temp = temp -> link; 
    }
 if(flag == 0)
   cout<<"Vehicle is not present in data"<<endl;  
  
  if(root == NULL)
   cout<<"List is empty";
}

template <typename T>
void Link1<T> :: people(int& num,int& count){
 int A[count];
 T* temp = root;
 int i = 0;
 int sum = 0;
 while(temp != NULL ){
  A[i] = temp -> no_seat;
//	sum = sum + temp->no_seat;
  temp = temp -> link;
  i++;
}
//cout<<"  "<<sum<<endl;
 int t_volume = num;
// int C[count];
 int k = 0;
 int index = 0;
 int y = 0;
 int flag1 = 0; 
while(t_volume > 0)
{  
	if(k<count){
     index++;
      t_volume = t_volume - A[k];
       k++;
      //  cout<<"hello"<<k<<endl;
     if(1<= t_volume &&  t_volume <=5){
        y = y + 1;
        t_volume = t_volume - 5;
       }
    }  
      if( k == count)
        flag1 =1; 
      if((k == (count)) && (t_volume >0)){
           y = y + 1;
    	   t_volume = t_volume - 5;
    	}
}
 cout<<"Minimun vehicles required are: "<<endl;
 T* temp1 = root;
 
 for(int j =0;j < index;j++){
        cout <<temp1->name<<" "<<temp1->color<<" "<<temp1->mileage<<" "<<temp1->top_speed<<" "<<temp1->no_gear<<" "<<temp1->no_seat<<endl;
        temp1 = temp1->link;
   }
   
 if(flag1 == 1)
       cout<<"\nSorry!!! Buses not sufficient"<<endl; 
  
cout<< " "<<y<<" Car more. You can check the availability in car section!"<<endl;

 if(root == NULL)
   cout<<"List is empty";
}

template <typename T>
void Link1<T> :: watermelon(int& num,int& count){
 int A[count];
//  cout<<count;

 //string B[count];
 T* temp = root;
 int i = 0;
 while(temp != NULL ){
  A[i] = temp -> v_capacity;
  temp = temp -> link;
  i++;
}
 int t_volume = num * 30;
 int C[count];
 int k = 0;
 int index = 0;
 int y = 0;
 int flag1 = 0; 
 int left_over = 0;
while(t_volume > 0)
{  
	if(k<count){
     index++;
      t_volume = t_volume - A[k];
       k++;
       }
    if( k == count && t_volume > 30){
      flag1 =1; 
 //     cout<<t_volume<<endl;
      left_over = t_volume;        
      break; 
     } 
     if( k == count && t_volume > 0)
      t_volume = -1;
       
}
 cout<<"Minimun Trucks required are: "<<endl;
 T* temp1 = root;
 for(int j =0;j < index;j++){
 cout <<temp1->name<<" "<<temp1->color<<" "<<temp1->mileage<<" "<<temp1->top_speed<<" "<<temp1->no_gear<<" "<<temp1->v_capacity<<" "<<temp1->w_capacity<<endl;
    temp1 = temp1->link;
   }
   
 if(flag1 == 1)
       cout<<"\nSorry!!! Trucks not sufficient. Left over watermelon are "<<left_over/30<<endl; 
  
 if(root == NULL)
   cout<<"List is empty";
   }

