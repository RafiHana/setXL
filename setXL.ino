/* Dynamixel ID Change Example

Dynamixel ID Change and  Turns left the dynamixel , then turn right 
for one second, repeatedly.

              Compatibility
CM900                  O
OpenCM9.04             O

               Dynamixel Compatibility
              AX    MX      RX    XL-320    Pro
CM900          O      O      O        O      X
OpenCM9.04     O      O      O        O      X
**** OpenCM 485 EXP board is needed to use 4 pin Dynamixel and Pro Series ****  

created 16 Nov 2012
by ROBOTIS CO,.LTD.
*/
/* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

/* Dynamixel ID defines */
#define NEW_ID 25//New ID to be changed.

/* Control table defines */
Dynamixel Dxl(DXL_BUS_SERIAL1);

void setup() {
 // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
 Dxl.begin(3);
 
/*************** CAUTION ***********************
* All dynamixels in bus will be changed to ID 2 by using broadcast ID(0xFE)
* Please check if there is only one dynamixel that you want to change ID
************************************************/
 Dxl.setID(BROADCAST_ID, NEW_ID);    //Change current id to new id
 Dxl.jointMode(NEW_ID); //jointMode() to use position mode
}

void loop() {
 /*Turn dynamixel to position 0 by new id*/
 Dxl.goalPosition(NEW_ID, 0); 
 // Wait for 1 second (1000 milliseconds)
 delay(1000);              
 /*Turn dynamixel to position 300 by new id*/
 Dxl.goalPosition(NEW_ID, 512);
//  Dxl.goalPosition(NEW_ID, 212);
 delay(1000);
 // Wait for 1 second (1000 milliseconds)
//  while(1);              
}
