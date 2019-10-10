/******************************************************************************
              Author: Alex Martinez Veloz.
              Date: 10/03/2019.
              Description: This lab simulates the backend of an app like
                           google maps, in this case is called Poogle maps.
*******************************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//side notes: fix the time and also the exit value you are getting in calcTrafficIncrese fucntion
//

const int END = 0;
const int INVALID_DATA = -1;
const int VALID_DATA = 1;
const double NO_TRAFFIC = 1.0;
const double SMALL_TRAFFIC = 1.25;
const double MEDIUM_TRAFFIC = 1.5;
const double LARGE_TRAFFIC = 2.0;

//Prototypes
int getUserData(double& miles, double& avgSpeed, int& hours);
double calcTrafficIncrese(int hour);
void printOutput(double miles, double minutes, double trafficIncrease);

int getUserData(double& miles, double& avgSpeed, int& hours){
  int exit;
    std::cout << "Please enter zero (0) if you want to exit this program" << '\n';
    std::cout << "If you want to keep this program press one (1)" << '\n';
    std::cin >> exit;

      if (exit != END){
      //  bool flag = false;
        //do {
          std::cout << "Enter miles on your route (0 to end): " << '\n';
          std::cin >> miles;
          std::cout << "Enter your average speed in miles per hour: " << '\n';
          std::cin >> avgSpeed;
          std::cout << "Enter the time of the day (24- hour clock): " << '\n';
          std::cin >> hours;

            if ((miles <= 0) || (avgSpeed <= 0) || (hours <= 0)){
              std::cout << "You entered an invalid value" << '\n';
              std::cout << "Please make sure you are entering positive numeric values..." << '\n';
              return INVALID_DATA;
            }
            else
              return VALID_DATA;
        //}while (flag);
      }else
        return exit;
}

double calcTrafficIncrese(int hour){
  int random_chance;
     random_chance = rand() % 50 + 1; //random number between 1 and 100;
    // std::cout << random_chance << '\n'; flag
    // system("PAUSE"); flag
        if ((hour == 7) || (hour == 8) || (hour == 17) || (hour == 18)){
          if (random_chance <= 5) return 1.0;
          else if ((random_chance > 5) && (random_chance <= 10)) return 1.25;
          else if ((random_chance > 10) && (random_chance <= 35)) return 1.5;
          else return 2.0;
        }
        else{
          if (random_chance <= 5) return 2.0;
          else if (random_chance <= 15) return 1.5;
          else if (random_chance <= 30) return 1.25;
          else return 1.0;
        }
}

void printOutput(double miles, double minutes, double trafficIncrease){
    if (trafficIncrease == NO_TRAFFIC)
      std::cout << "There is no traffic at this time. You are in the fastest route"<< '\n';
    else if (trafficIncrease == SMALL_TRAFFIC)
      std::cout << "The traffic is light. You are in the fastest route " << '\n';
    else if (trafficIncrease == MEDIUM_TRAFFIC)
      std::cout << "The traffic is normal. Faster routes might be available" << '\n';
    else
      std::cout << "There is a lot of traffic. You are not in the fastest route" << '\n';

    std::cout << "Miles: " << miles << '\t';
    std::cout << "Minutes: " << minutes << '\n';
}

int main(){
  double miles, avgSpeed;              //average speed per hour
  double timeToSchool;                //in minutes.
  double trafficIncrease;            // increase in time due to traffic.
  //*********************************************************
  int rv;                          // return value of getUserData.
  int hour;                       // starting hour in 24-hour clock.

  srand( time( 0 ) );

  std::cout.precision(0);
  std::cout.setf( std::ios::fixed );

    std::cout << "Welcome to Poogle maps \n";
    rv = getUserData(miles, avgSpeed , hour);

        while (rv != END){
          if (rv != INVALID_DATA){
            trafficIncrease = calcTrafficIncrese(hour);
            //std::cout << trafficIncrease << '\n'; flag
            timeToSchool = miles/ avgSpeed * 60 * trafficIncrease;
            //std::cout << timeToSchool << '\n'; flag
            printOutput(miles, timeToSchool, trafficIncrease);
          }// end if valid data.
          rv = getUserData(miles, avgSpeed, hour);
        }

      std::cout << "Exiting Poogle maps!" << '\n';

  return 0;
}
