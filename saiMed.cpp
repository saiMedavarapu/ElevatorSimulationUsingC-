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
    int *cnt, *floors, *priorityFloorIndex, *servingFloorAlg2, *servingFloorAlg3,*priorityFloorIndex3  ;
    float time_travel[100000], totalTime = 0;
    float time_travel2[100000], totalTime2 = 0;
    float time_travel3[100000], totalTime3 = 0;
    float timeToMove;
   

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
  time_travel[i] = fabs(noOfReq[i]-toFloor[i]) * timeToMove;
  totalTime=totalTime+time_travel[i];
  cout<<"Time to travel from floor No:"<<noOfReq[i]<<" to floor:"<<toFloor[i] <<" is = "<<totalTime<<" Seconds"<<endl;
  //totalTime=totalTime+time_travel[i];
  }
  cout<<"---------------------------\n";  
cout<<bold_on<<"\033[1;31m Total Time to travel in seconds using Algorithm 1 is : "<<totalTime<<"\033[0m"<<endl;



cout<<"--------------------------Algorithm 2 - Check the floor with high number of requests -------------\n";  
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


//----Finding the index of the highest repetetive element - Which lets you find busiest floor.*********
    int priorityFloor = max_element(floors, floors + numbOfReq) - floors;
    cout<<endl;
      cout << "Floor which has more number of people is : "
          << priorityFloor << endl;

// ****************Implementing search to find the index of priority floor *******************

      priorityFloorIndex = new int[numbOfReq];//Array to hold index values of repetitive element.
      priorityFloorIndex3 = new int[numbOfReq];//Replica Array to hold index values of repetitive element and use it in alg3
      int v= 0; //index variable for priorityFloorIndex
      for(int i=0;i<numbOfReq;i++)
        {
          if(noOfReq[i] == priorityFloor)
          { 
            priorityFloorIndex[v] = i;
            v++;
          }
        }
//**************Printing out the indexes of the repetetive values*************************

servingFloorAlg2 = new int[numbOfReq];

    for(int i=0;i<v;i++)
    {
      cout<<"Index values are : "<< priorityFloorIndex[i]<<"  "<<"and the requested floor is: ";
      for(int j=0; j<numbOfReq;j++)
      {
        if(priorityFloorIndex[i]== j)
        {
          servingFloorAlg2[i] = toFloor[j];
          cout<<servingFloorAlg2[i]<<endl;
        }
      }
    }
//*********Copying the values to other array to use it in alg3*********
servingFloorAlg3 = new int[numbOfReq];

for(int i=0;i<v; i++)
{
  servingFloorAlg3[i] = servingFloorAlg2[i];
  priorityFloorIndex3[i] = priorityFloorIndex[i];
}


//*************Now that we have index values, lets serve the requests for that floor *************
    for(int i=0; i<numbOfReq; i++)
    {
      for(int j=0; j<v;j++)
      {
        if(i==priorityFloorIndex[j])
        {
          time_travel2[j] = fabs(priorityFloor-servingFloorAlg2[j]) * timeToMove;
          totalTime2=totalTime2+time_travel2[j];
          cout<<"Floor : "<<servingFloorAlg2[j]<< " is served with time : "<< totalTime2<<" Seconds"<<endl;
         
        }
      }
    }
//For rest of the requests.
cout<<"*******************"<<endl;
    for(int i=0; i<numbOfReq; i++)
    {
     
        if(i==servingFloorAlg2[0]|| i==servingFloorAlg2[1]|| i==servingFloorAlg2[2]|| i==servingFloorAlg2[3] || i==servingFloorAlg2[4])
        {
          continue;
        }
        else
        {
          //cout<<"i value is "<<i <<endl;
          time_travel2[i] = fabs(noOfReq[i]-toFloor[i]) * timeToMove;
          totalTime2=totalTime2+time_travel2[i];
          cout<<"Time to travel from floor No:"<<noOfReq[i]<<" to floor:"<<toFloor[i] <<" is = "<<totalTime2<<" Seconds"<<endl;
          //totalTime2=totalTime2+time_travel2[i];
        }
      
    }
    cout<<"\033[1;31mTotal time taken to serve the entire requests by using Algorithm 2 is : "<< totalTime2<<"\033[0m"<<endl;
  
cout<<"--------------------------Algorithm 3 - Find the smallest distance with respect to travel by sorting and  -------------\n";  

    for(int i=0;i<v; i++)
      {
        cout<<"value for i =  "<< i<< "is :"<<servingFloorAlg3[i]<<"and the index values before sorting are: "<<priorityFloorIndex3[i]<<endl;
      }


//***************** Sorting it************************************************
cout<<"----------------Sorting the elements---------------------------"<<endl;

for (int i = 0; i < v; ++i) 
        {
 
            for (int j = i + 1; j < v; ++j)
            {
 
                if (servingFloorAlg3[i] > servingFloorAlg3[j]) 
                {
                    int temp;
                    temp =  servingFloorAlg3[i];
                    servingFloorAlg3[i] = servingFloorAlg3[j];
                    servingFloorAlg3[j] = temp;
 
                }
 
            }
 
        }

//********Printing out the sorted values*********************

for(int i=0;i<v; i++)
      {
        cout<<"Sorted value for i =  "<< i<< "is :"<<servingFloorAlg3[i]<<endl;
      }

//*************Now that we have index values, lets serve the requests for that floor *************
    for(int i=0; i<numbOfReq; i++)
    {
      for(int j=0; j<v;j++)
      {
        if(i==priorityFloorIndex3[j])
        {
          time_travel3[j] = fabs(priorityFloor-servingFloorAlg3[j]) * timeToMove;
          totalTime3=totalTime3+time_travel3[j];
          cout<<"Floor : "<<servingFloorAlg2[j]<< " is served with time : "<< totalTime3<<" Seconds"<<endl;
         
        }
      }
    }

  //For rest of the requests.
cout<<"*******************"<<endl;
    for(int i=0; i<numbOfReq; i++)
    {
     
        if(i==servingFloorAlg3[0]|| i==servingFloorAlg3[1]|| i==servingFloorAlg3[2]|| i==servingFloorAlg3[3] || i==servingFloorAlg3[4])
        {
          continue;
        }
        else
        {
          //cout<<"i value is "<<i <<endl;
          time_travel3[i] = fabs(noOfReq[i]-toFloor[i]) * timeToMove;
          totalTime3=totalTime3+time_travel3[i];
          cout<<"Time to travel from floor No:"<<noOfReq[i]<<" to floor:"<<toFloor[i] <<" is = "<<totalTime3<<" Seconds"<<endl;
          //totalTime2=totalTime2+time_travel2[i];
        }
      
    }
    cout<<"\033[1;31mTotal time taken to serve the entire requests by using Algorithm 3 is : "<< totalTime3<<"Seconds \033[0m"<<endl;


return 0;
}