#include<iostream> 
#include<map>
#include<string> 
using namespace std;
int main()
{ 
  string state;
  float population;
  char ans='y';
  int choice; 
 
 map<string,float> m;
 map<string,float>::iterator i;

 do 
 { 
   cout<<"---MainMenu---"<<endl;
   cout<<"\n1.Insert state";
   cout<<"\n2.Display";
   cout<<"\n3.Search state";
   cout<<"\n4.Delete"<<endl;

   cout<<"Enter your choice:"<<endl;
   cin>>choice;
   switch(choice)
   { 
     case 1:
       cout<<"Enter name of state:";
       cin>>state;
       cout<<"\n Enter the population(Cr):";
       cin>>population;
       m.insert(pair<string,float>(state, population));
       break; 
    
     case 2:
       cout<<"State and population are:"<<endl;
       for(i=m.begin();i!=m.end();i++)
         cout<<"["<<(*i).first<<","<<(*i). second<<"]";
       break; 
    
     case 3:
       cout<<"Enter state name for searching population:"<<endl;
       cin>>state;
       if(m.count(state)!=0)
         cout<<"\n Population is"<<m.find(state)->second<<"Cr";
       else
         cout<<"The state is not present!"<<endl;
       break; 
    
     case 4:
      cout<<"Enter the state to be deleted:"<<endl;
      cin>>state;
      m.erase(state);
      cout<<"The state is deleted"<<endl;
      break;
    } 
    cout<<"Do you want to continue?(y/n)"<<endl;
    cin>>ans;
    } while(ans=='y');
    
    return 0;
 }
    
