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
    int noOfFloors , elevatorSize = 10,  initialLoc= 5, noOfReq[10], toFloor[10], numbOfReq;
    int *cnt, *floors;
    float time_travel[5], totalTime = 0;
    float timeToMove;
    /*
        a. Your code should randomly generate a number of requests.
        b. Design and implement three different algorithms to simulate the elevator movement in order to
        response to the requests.
        c. For each algorithm, you should log the order in which the requests have been served, the time
        it takes to serve each request, and total time it takes to serve all requests.
    */
   cout<<"The total number of floors.\n";
   cin>>noOfFloors;
   floors = new int[noOfFloors];
  cout<<"Elevator Size?\n";
     cin>> elevatorSize;
cout<<"How many number of requests"<<endl;
cin>>numbOfReq;
     cnt = new int[numbOfReq];
     cout<<"What is The time it takes to move between two floors?(in seconds)\n";
     cin>> timeToMove;
cout<<"What is the initial location of the elevator?\n";
    cin>>initialLoc;

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



  cout<<"------------------Algorithm 2 - Go to highest first and pick on the go -------------\n";  
  //Algorithm2

for (int i=0;i<numbOfReq;i++) {
        floors[i] = 0;
       for (int j=0;j<numbOfReq;j++) { 
      if(noOfReq[j]==i)
      {
        floors[i]++;
      }
       }
} 
      
   for(int i = 0; i < numbOfReq; i++)
{
  cout<< floors[i];
}   
       
for(int i = 0; i < numbOfReq; i++)
{
  //cout<< cnt[i];
}


/*int largest = cnt[0];
int highRequests = 0;
   for(int i = 1;i < numbOfReq; i++) {
      
      if(largest <=cnt[i])
         {
         largest = cnt[i];
          highRequests = noOfReq[i]; 
          //cout<<"highRequests is :"<< highRequests<<endl;
          } 
   }

cout<<"At floor"<<highRequests<<"there are more number of requests"<<endl;*/

return 0;
}