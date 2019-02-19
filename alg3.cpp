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
    int noOfFloors , elevatorSize = 10,  initialLoc= 5, noOfReq[100000], toFloor[100000], dist[100000],numbOfReq, noOfReqs[100000][100000][100000];
    int *cnt, *floors, *priorityFloorIndex, *servingFloorAlg2, *requestsAlg3 ;
    float time_travel[100000], totalTime = 0;
    float time_travel2[100000], totalTime2 = 0;
    float timeToMove;
   

   cout<<"The total number of floors.\n";
   cin>>noOfFloors;
  // floors = new int[noOfFloors];
 // cout<<"Elevator Size?\n";
   //  cin>> elevatorSize;
cout<<"How many number of requests"<<endl;
cin>>numbOfReq;
     //cnt = new int[numbOfReq];
     cout<<"What is The time it takes to move between two floors?(in seconds)\n";
     cin>> timeToMove;
//cout<<"What is the initial location of the elevator?\n";
  //  cin>>initialLoc;

cout<<"------------Generated Floor requests are---------------\n";
     
    //Random number generator for elevator request.
cout<<"From   "<<"To"<<  "  Distance"<<endl;
 srand((unsigned)time(0)); 
    for(int k=0;k<numbOfReq;k++)
    {
        for(int j=0;j<numbOfReq;j++)
        {
            for(int i=0;i<numbOfReq;i++)
            {
                noOfReqs[i][j][k] = (rand()%noOfFloors)+1; 
            }

        }
    }


    for(int k=0;k<numbOfReq;k++)
    {
        for(int j=0;j<numbOfReq;j++)
        {
            for(int i=0;i<numbOfReq;i++)
            {
                cout<<noOfReqs[i][j][k] <<endl;
            }

        }
    }
   /* noOfReqs[i] = (rand()%noOfFloors)+1; 
    toFloor[i] = (rand()%noOfFloors)+1; 
    dist[i] = abs(noOfReq[i] - toFloor[i] );
    //Just in case if the reqfloor and from floor are same, It generates different random number
    while(toFloor[i]==noOfReq[i])
    {
      toFloor[i] = (rand()%noOfFloors)+1; 
    }
    cout << noOfReq[i]<<"----->"<< toFloor[i]<<"----->"<<dist[i]<<"\n";
    }*/

return 0;

}