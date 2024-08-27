# C/C++ library with example to control syringe pump PSD4
 Inculding library and a simple application allow ESP32 Devkit1c to control syringe pump PSD4

 ![alt text](2024-08-27-07-29-20-476-1.jpg)

 Including functions:
 
    // Function to initialize the PSD4 Pump
    PSD4_PUMP(byte Pump_Addr, byte COM_Port, int COM_Speed, byte RX_Pin, byte TX_Pin); 

    // Function to initiallize the Pump 1st time after it is power on / reset
    void PSD4_PUMP::Init_Pump(byte operation_mode); 

    // Function to set Port number (1 to 8) of Valve to 
    void PSD4_PUMP::Set_Port_Direction(byte Port_No, byte Port_Dir); 

    // Function to move syringe up/down X step from current position
    void PSD4_PUMP::Syringe_Move(byte Syringe_Dir, int No_of_Step);

    // Function to move syringe to absolute position
    void PSD4_PUMP::Syringe_Move_To_Position(int Absolute_position);

    // Function to set parameters of motor
    void PSD4_PUMP::Set_Motor_Parameters(byte steps_sec_sec, int start_velo, int max_velo, byte speed_code, int stop_velo); 

    // Function to query current status of PSD4 pump
    void PSD4_PUMP::Get_Pump_Status();

    // Function to read the return data from the pump
    void PSD4_PUMP::Read_from_pump();

Notes:
   - Long delay() has been used here to make sure pump finish each command before sending the new ones.
   - In a real application, function Get_Pump_Status() should be use to check if pump is ready for the new command.
   - Even this example is for ESP32 in particular, the library can be use with any other MCU that support C/C++.