#include <Arduino.h>
#include "Syringe_Pump_PSD4.h"

// Serial 2 to control Syringe Pump
#define PSD4_Addr 0x31            // Address of the PSD4 Pump
#define PSD4_UART 2               // UART port of ESP32 use to communicate with PSD4 Pump, either 0, 1, 2
#define PSD4_UART_Speed 9600      // UART port speed
#define PSD4_RXD 1                // ESP32 Pin number assign for RXD of PSD4_UART Port 
#define PSD4_TXD 2                // ESP32 Pin number assign for TXD of PSD4_UART Port

PSD4_PUMP Main_Pump(PSD4_Addr, PSD4_UART, PSD4_UART_Speed, PSD4_RXD, PSD4_TXD); //Main pump with Addrr = 0x31 and using UART2 RX pin 1 TX pin 2

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);

  //Init pump in high resolution mode
  Main_Pump.Init_Pump(1); //Init pump in high resolution mode
  delay(5000);
  Main_Pump.Read_from_pump();
  delay(1000);

  // Set motor parameter
  Main_Pump.Set_Motor_Parameters(2, 50, 1000, 11, 500);
  delay(5000);
  Main_Pump.Read_from_pump();
  delay(1000);

  // Move syringe to Absolute position of 100 
  Serial.println("Syringe move to absolute position 100");
  Main_Pump.Syringe_Move_To_Position(100);
  delay(10000);
  Main_Pump.Read_from_pump();
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Move syringe to Absolute position of 22000 
  Serial.println("Syringe move to absolute position 22000");
  Main_Pump.Syringe_Move_To_Position(20000);
  delay(10000);
  Main_Pump.Read_from_pump();
  delay(1000);

  // Move syringe to Absolute position of 1000 
  Serial.println("Syringe move to absolute position 1000");
  Main_Pump.Syringe_Move_To_Position(1000);
  delay(10000);
  Main_Pump.Read_from_pump();
  delay(1000);
  
  // Move syringe down 15000 steps
  Serial.println("Syringe move down 15000");
  Main_Pump.Syringe_Move(0, 15000);
  delay(10000);
  Main_Pump.Read_from_pump();
  delay(1000);

  // Set Port 1 to OUTPUT
  Main_Pump.Set_Port_Direction(1, 1); 
  delay(5000);
  Main_Pump.Read_from_pump();
  delay(1000);

  // Set Port 3 to INPUT
  Main_Pump.Set_Port_Direction(3, 0);  
  delay(5000);
  Main_Pump.Read_from_pump();
  delay(1000);

  // Move syringe up 15000 steps
  Serial.println("Syringe move up 15000");
  Main_Pump.Syringe_Move(1, 15000);
  delay(10000);
  Main_Pump.Read_from_pump();
  delay(1000);

}
