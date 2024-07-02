## How to run it
    1: The first step after opening shell is to type **make clean** (in case there are files already created).
        You may use **mspdebug rf2500 "erase"** to clear a program from the MSP430.
    2: Use **make** in this directory to build the toy program. 
    3: Once the program is built, you can load the program onto the MSP430 by using **make load**. (be sure to be in the directory of the toy program files)
    4: At this point the program should be running already on the device.

When the program is running, the red LED should be on by deafult

## Toy's Button Descriptions
    S1: While it is being pressed, the light will dim.
    S2: While it is being pressed, the green LED will turn on, and the red LED will turn off.
    S3: When pressed, the green LED will turn on, and a melody will play.
    S4: When pressed, a siren will play.
