# Basketball_free_falling
SYDE 121 - A#2 Q2

Assignment instruction: 
A baseball ball is dropped from a drone. The distance that the ball will fall in t seconds is given by the following, where g is the
gravitational constant: Distance = 1⁄2 g t2.
For g, you may use 9.80665 m/s2. Ignore air resistance for this question.

1. Write a program that will output the distance the ball has fallen in each 1-second interval for the first 30 seconds along with the total distance travelled at
   the end of each interval.
   Time (in sec):     Distance during interval (in m):     Total distance (in m):
   0                  0.000                                0.000
   1                  4.903                                4.903
   ...                ...                                  ...
   
   Before writing any code, outline program steps as comments. After that, appropriately declare and initialize a number of variables for this problem, and give
   each identifier a descriptive name. Avoid magic numbers. Introduce functions where appropriate.

2. Let us assume that a specialized drone is flying at 15,000 meters.
   Use the program from part (1) to calculate how long it will take for the ball to reach the ground. As the ball is reaching the ground, increase the resolution to
   0.1 seconds (i.e., decrease time interval length to 0.1 s when close to the ground).

3. Verify that your program is correct by manually computing the result (e.g., on paper, using an online calculator), and then compare that result with the output
   of your program; test a number of different values.
   As a comment at the start of your program (i.e., using /* ... */ notation), explain what values you used to test the program logic, and identify the valid range
   of values for which your program will work correctly.
   Also record the output for step (2) as part of these comments. Do not insert all your code into the main() function.
