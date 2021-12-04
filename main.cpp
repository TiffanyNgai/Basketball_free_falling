//
//  Tiffany Ngai
//  20900617
//  121 assignment2 q2
//
//  I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.
//
//  Project: Basketball free falling
//  Due Date: 9/10/2020


/*
 For the basketball_distance function(step1 of the assignment):
 Checked the output for some values e.g. 0,1,15,27,30 with calculator and the output is correct
 Changed the starting time to a negative integer(e.g. -2) and both distance outputs are 0.000, which is consistent to the reality because time can only be positive
 Changed the starting time to a value with decimal(e.g. 0.2) and the program automatically round down the value and the program continue to run smoothly
 Changed the condition of the loop to a larger number (e.g. time < 41), the program ran smoothly and no incorrect value is found
 
 For the basketball_time function(step2 of the assignment):
 The output of the third step is 55.4 sec
 Used 20000 (a value larger than 15000) and 10000 (a value smaller than 15000) as the original height to test the program and both of them gave a correct answer
 Used a negative number for the original height to check the program, (-1s), the output is a negative number. Thus, I decide to check if the height is valid (greater than or equal to zero) before outputing
 Used a height with decimal to check the program (213123123.12), the output is correct (6592.9 sec)
 The valid range for the original height is all positive values less than or equal to the maximum value of double in C++
 */

#include <iostream>
#include <cmath>
using namespace std;

//function that output the distance the ball has fallen in each 1-second interval for the first 30 seconds along with the total distance travelled at the end of each interval
//output: old_total_distance_travelled = total distance travelled in current time minus one second; total_distance_travelled = total distance travelled; interval_distance = the distance travelled by the ball in each one second interval
void basketball_distance() {
    
    //declare and initialize variables
    int time = 0.2;
    double old_total_distance_travelled = 0;
    double total_distance_travelled = 0;
    double interval_distance = 0;
    const double GRAVITATIONAL_ACCELERATION = 9.80665;
    
    //set precision of three decimal points
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    
    while (time < 31) {
        
        if (time > 0) {
            //calculate the total distance travelled for the last second
            time = time - 1;
            old_total_distance_travelled = GRAVITATIONAL_ACCELERATION * time * time / 2;
            
            //increment the time by one so the time equal to the current time
            time++;
            
            //calculate the total distance travelled for the current second
            total_distance_travelled = GRAVITATIONAL_ACCELERATION * time * time / 2;
            
            //calculate the distance travelled in the corresponding second interval
            interval_distance = total_distance_travelled - old_total_distance_travelled;
            
            //output the interval and total distance
            cout << "Time(in sec): " << time << endl;
            cout << "Distance during interval(in m): " << interval_distance << endl;
            cout << "Total distance(in m): " << total_distance_travelled << endl << endl;
            
            //increase the time by one second to allow the loop continue
            time++;
        }
        else {
            //output the interval and total distance for time equals zero
            cout << "Time(in sec): " << time << endl;
            cout << "Distance during interval(in m): " << interval_distance << endl;
            cout << "Total distance(in m): " << total_distance_travelled << endl << endl;
            
            //increase the time by one second to allow the loop continue
            time++;
            
        }
    }
}


//function that output the time needed for a ball to reach the ground
//output: time = time needed for the ball to reach the ground from a hight of 15000m
void basketball_time() {
    
    //declare and initialize variables
    double original_height = 15000;
    double time = 0;
    double height = original_height;
    double total_distance_travelled = 0;
    const double GRAVITATIONAL_ACCELERATION = 9.80665;
    bool original_height_is_positive = true;

    //check to see if the original height is greater than or equal to zero
    original_height_is_positive = height >= 0;
    
    if (!original_height_is_positive) {
        cout << "Invalid height" << endl;
    }
    
    //calculate the time needed for the ball to reach the ground rounding up to one second
    while (height > 200 && original_height_is_positive) {
        
        //increment the time by one second
        time ++;
        
        //calculate the total distance for the time travelled
        total_distance_travelled = GRAVITATIONAL_ACCELERATION * time * time / 2;
        
        // calculate the height of the ball
        height = original_height - total_distance_travelled;

    }
    
    //minus the time by one second to allow the program carry out comparasion with small time interval
    time = time - 1;
    
    //declare and initialize continue_loop boolean value
    bool continue_loop = true;
    
    //calculate the time needed for the ball to reach the ground when the ball is near to the ground
    while (continue_loop && original_height_is_positive) {
        
               //increment the time by 0.1 second
               time = time + 0.1;
        
               //calculate the total distance for the time travelled
               total_distance_travelled = GRAVITATIONAL_ACCELERATION * time * time / 2;
               
               // calculate the height of the ball
               height = original_height - total_distance_travelled;

               
               //set precision of one decimal points
               cout.setf(ios::fixed);
               cout.setf(ios::showpoint);
               cout.precision(1);
                
     
        if (height <= 0) {
            
            //output the time needed for the ball to reach the ground rounding up to one decimal place
            cout << "The time needed for the ball to reach the ground is " << time
                 << " sec" << endl;
            
            //decide whether the loop should continue
            continue_loop = false;
            
        }
        
    }
    
}


int main() {
    
    basketball_distance();
    basketball_time();
    
    return 0;
}
