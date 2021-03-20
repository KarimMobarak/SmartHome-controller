# SmartHome-controller
Smart home controller system based on two atmega32 microcontrollers.

## Description
The system is interrupt based, it enables the user to control home appliances over bluetooth from smartphone.

## System Design
The system consists of 2 microcontrollers. The master that handles the user interface such as LCD, recieve commands and send it to the slave to control the appliances.

## Operation
 when the system is powered on it initialize the necessary peripherals as well as their interrupts.
 Then it shows the valid commands through the bluetooth so the user uses them. For instance, to turn on the kitchen light 
 the master must recieve a capital 'K', and in order to turn it off. it must recieve small 'k'.
 
When the user sends data over bleutooth , the interrupt is triggred. The data sent is verified and sent to slave through the SPI. The SPI interrupt is triggered in the slave, and the controller takes the corresponding action.

