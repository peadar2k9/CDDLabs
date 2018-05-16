# Lab 4 - Producer/Consumer Implementation

## Description
Demonstration of a program with a producer & consumer. The producer generates random characters from ‘a’ to ‘z’ at random intervals (between 0 and 1 second in length). It adds these to a thread safe buffer that has a finite holding capacity of N characters. It generates a preset number of characters (determined at runtime) and when it has finished it add an ‘X’ character to the buffer and exits.

## Author
Peter Cronin

## License
GNU General Public License v3.0

## How to run
Clone the repository using ```git clone https://github.com/peadarcronin/CDDLabs.git```. Navigate to the CDDLabs folder and then into Lab4. To compile the program use ```make``` and then to run it, use ```./prodCom```. To compile and generate documentation, use ```make doc```.
