General Description

The objective of this is to simulate an elevator service. Your simulator should take as input the following parameters:

• The total number of ﬂoors.

• The size of the elevator(number of people).

• The time it takes to move between two ﬂoors.

• The initial location of the elevator.

a. Your code should randomly generate a number of requests.

b. Design and implement three diﬀerent algorithms to simulate the elevator movement in order to response to the requests.

c. For each algorithm, you should log the order in which the requests have been served, the time it takes to serve each request, and total time it takes to serve all requests..


Explanation: 

NOTE: If you have an issue with max_element() 
    Include the <algorithm>  headerfile.

Algorithm1:
•	Serves the requests based on the First come first serve.
•	It generates a random number of requests to from and to destinations.
•	Uses those requests to calculate the time.
•	Here is the screenshot of the output
### Preview
![Resume Screenshot](/Alg1.png)

Algorithm2: 

•	In Algorithm 2, the requests are being served based on the more number of requests from particular floor.
•	Therefore, it checks which floor has more requests and stores those destinations in an array and sends them to particular destination.
•	Times are logged into time2 array.
•	Here is the sceenshot.

### Preview
![Resume Screenshot](/alg2.png)

Algorithm 3: 

•	In Algorithm 2, the requests are being served based on the more number of requests from particular floor.
•	Therefore, it checks which floor has more requests and stores those destinations in an array and sends them to particular destination.
•	Times are logged into time2 array.
•	Here is the sceenshot.
### Preview
![Resume Screenshot](/Algo3.png)
