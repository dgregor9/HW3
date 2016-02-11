 /* Dynamixel ID Change Example
 -- SET POSITION --
 Controls 2 dynamixel motors

 /* Serial device defines for DXL1 bus */ 
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
/* Dynamixel ID defines */
#define MOTOR1_ID 1
#define MOTOR2_ID 2
#define deg_45 155
#define deg_90 310
#define deg_0 0
#define deg_180 620 
#define SPEED_1 136 //68 //used to move motor 45* @ 2Hz
#define SPEED_2 500 //to move motor 180* @ 1Hz
#define PRESENT_POS 54 //Present Position Register Address?

Dynamixel DXL(DXL_BUS_SERIAL1); //Instantiate DXL serial bus
 
void setup() {
  // Initialize the dynamixel bus:
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps  
  DXL.begin(3); //set Baudrate -> 1Mbps 
  DXL.jointMode(MOTOR1_ID); //jointMode() is to use position mode
  DXL.jointMode(MOTOR2_ID); 
  DXL.goalSpeed(MOTOR1_ID, SPEED_1);  //Set motor speed
  DXL.goalSpeed(MOTOR2_ID, SPEED_2);  //Set motor speed
}

void loop() {
  
    /*Control two motors*/    
    DXL.goalPosition(MOTOR1_ID, deg_45);
    DXL.goalPosition(MOTOR2_ID, deg_0);  
    delay(500);
    DXL.goalPosition(MOTOR2_ID, deg_180);
    delay(500);  
    DXL.goalPosition(MOTOR1_ID, deg_90);
    DXL.goalPosition(MOTOR2_ID, deg_0);
    delay(500);
    DXL.goalPosition(MOTOR2_ID, deg_180);
    delay(500);
 
}// end loop()
