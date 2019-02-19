//Sai Medavarapu
//Current Trends in Programming
//HW1 - Elevator Simulation.
#include<iostream>
#include <cstdlib>
#include <ctime> 
#include <math.h>
using namespace std;

ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

int main()
{
    int noOfFloors , elevatorSize = 10,  initialLoc= 5, noOfReq[100000], toFloor[100000], numbOfReq;
    int *cnt, *floors, *priorityFloorIndex ;
    float time_travel[100000], totalTime = 0;
    float timeToMove;
   

   cout<<"The total number of floors.\n";
   cin>>noOfFloors;
   floors = new int[noOfFloors];
 // cout<<"Elevator Size?\n";
   //  cin>> elevatorSize;
cout<<"How many number of requests"<<endl;
cin>>numbOfReq;
     cnt = new int[numbOfReq];
     cout<<"What is The time it takes to move between two floors?(in seconds)\n";
     cin>> timeToMove;
//cout<<"What is the initial location of the elevator?\n";
  //  cin>>initialLoc;

cout<<"------------Generated Floor requests are---------------\n";
     
    //Random number generator for elevator request.
cout<<"From   "<<"To"<<endl;
 srand((unsigned)time(0)); 
    for(int i=0;i<numbOfReq;i++)
    {
   
    noOfReq[i] = (rand()%noOfFloors)+1; 
    toFloor[i] = (rand()%noOfFloors)+1; 
    //Just in case if the reqfloor and from floor are same, It generates different random number
    while(toFloor[i]==noOfReq[i])
    {
      toFloor[i] = (rand()%noOfFloors)+1; 
    }
    cout << noOfReq[i]<<"----->"<< toFloor[i]<<"\n";
    }



  cout<<"--------------Algorithm 1 - FCFS - Queuebased -------------\n"; 
 //Algorithm 1 
  for(int i=0;i<numbOfReq;i++)
  {
  time_travel[i] = (noOfReq[i]-toFloor[i]) * timeToMove;
  cout<<"Time to travel from floor No:"<<noOfReq[i]<<" to floor:"<<toFloor[i] <<" is = "<<fabs(time_travel[i])<<" Seconds"<<endl;
  totalTime=totalTime+fabs(time_travel[i]);
  }
  cout<<"---------------------------\n";  
cout<<bold_on<<"Total Time to travel in seconds is : "<<totalTime<<bold_off<<endl;



  cout<<"------------------Algorithm 2 - Check the floor with high number of requests -------------\n";  
  //Algorithm2
//This array stores requests from each floor.
for (int i=0;i<numbOfReq;i++) {
        floors[i] = 0;
       for (int j=0;j<numbOfReq;j++) { 
      if(noOfReq[j]==i)
      {
        floors[i]++;
      }
       }
} 
//Finding the most number of req from which floor?
   int k=0; 
   for(int i = 0; i < numbOfReq; i++)
  {
  cout<< "At floor "<<bold_on<<k++<<" There are "<<floors[i]<<bold_off<<" requests \n";
  }   


//Finding the index of the highest repetetive element - Which lets you find busiest floor.
int priorityFloor = max_element(floors, floors + numbOfReq) - floors;
cout<<endl;
  cout << "Floor which has more number of people is : "
       << priorityFloor << endl;

// Implementing search to find the index of priority floor 

      priorityFloorIndex = new int[numbOfReq];//Array to hold index values of repetitive element.
      int v= 0; //index variable for priorityFloorIndex
      for(int i=0;i<numbOfReq;i++)
        {
          if(noOfReq[i] == priorityFloor)
          { 
            priorityFloorIndex[v] = i;
            v++;
          }
        }
//Printing out the indexes of the repetetive values.

for(int i=0;i<v;i++)
{
  cout<<"Index values are : "<< priorityFloorIndex[i]<<"  "<<endl;
}
//Now that we have index values, lets serve the requests from that floor.


return 0;
}