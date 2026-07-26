//#############################################################################################################
//  _______  _        _______    _______  _______  _______           _______     ___  _______  _______ 
// (       )| \    /\(  ____ \  (  ____ \(  ____ \(  ____ )|\     /|(  ___  )   /   )/ ___   )(  ____ \
// | () () ||  \  / /| (    \/  | (    \/| (    \/| (    )|| )   ( || (   ) |  / /) |\/   )  || (    \/
// | || || ||  (_/ / | (_____   | (_____ | (__    | (____)|| |   | || |   | | / (_) (_   /   )| |      
// | |(_)| ||   _ (  (_____  )  (_____  )|  __)   |     __)( (   ) )| |   | |(____   _)_/   / | |      
// | |   | ||  ( \ \       ) |        ) || (      | (\ (    \ \_/ / | |   | |     ) ( /   _/  | |      
// | )   ( ||  /  \ \/\____) |  /\____) || (____/\| ) \ \__  \   /  | (___) |     | |(   (__/\| (____/\
// |/     \||_/    \/\_______)  \_______)(_______/|/   \__/   \_/   (_______)     (_)\_______/(_______/
//                                                                                                    
// Library to control the Makerbase Servo42C driver
//
// The platform.ini file is configured for the
// AZdelivery ESP32 Wroom32 NodeMCU
// For a different board please adjust the platform.ini file as needed
//#############################################################################################################

//#############################################################################################################
// Main includes
//#############################################################################################################
#include <Arduino.h>
#include "main.h"
#include "servo42c.h"

SERVO42C *servo_stepper;
HardwareSerial mks_serial(2);

void setup() {

  // Start Serial for debug messages
  Serial.begin(115200,SERIAL_8N1,RX,TX);
  // Start Serial 2 for coomunication with the MKS 42C
  mks_serial.begin(MKS42C_BAUDRATE,SERIAL_8N1,RX_PIN,TX_PIN);
  delay(2000);

  Serial.println("Configuration begin");
  // create and configure the 42C servo stepper
  servo_stepper = new SERVO42C();
  servo_stepper->init( mks_serial );
  servo_stepper->set_slave_address( MKS42C_ADDRESS_DEFAULT );  // set the drivers slave address (this needs to be the same as set on the stepper driver itself)
  
  Serial.print("Setting max current: ");
  Serial.print( MKS42C_MAXCURRENT_DEFAULT );
  Serial.print( servo_stepper->set_max_current( MKS42C_MAXCURRENT_DEFAULT ) ? " - Success" : " - Failed" );
  Serial.println();

  Serial.print("Setting max torque: ");
  Serial.print( MKS42C_MAXTORQUE_DEFAULT );
  Serial.print( servo_stepper->set_max_torque( MKS42C_MAXTORQUE_DEFAULT ) ? " - Success" : " - Failed" );
  Serial.println();

  Serial.print("Setting enable mode: ");
  Serial.print( MKS42C_ENABLEMODE_DEFAULT );
  Serial.print( servo_stepper->set_enable_mode( MKS42C_ENABLEMODE_DEFAULT ) ? " - Success" : " - Failed" );
  Serial.println();

  Serial.print("Setting microseps: ");
  Serial.print( MKS42C_MICROSTEPS_DEFAULT );
  Serial.print( servo_stepper->set_subdivision( MKS42C_MICROSTEPS_DEFAULT ) ? " - Success" : " - Failed" );
  servo_stepper->set_subdivision_interpolation( MKS42C_ENABLEMICROSTEPS_DEFAULT ); // enable microstepping I guess, no idea..
  Serial.println();


  Serial.print("Setting PID KP: ");
  Serial.print( MKS42C_PID_KP_DEFAULT );
  Serial.print( servo_stepper->set_pid_kp( MKS42C_PID_KP_DEFAULT ) ? " - Success" : " - Failed" ); // Immediate response to current error
  Serial.println();

  Serial.print("Setting PID KI: ");
  Serial.print( MKS42C_PID_KI_DEFAULT );
  Serial.print( servo_stepper->set_pid_ki( MKS42C_PID_KI_DEFAULT ) ? " - Success" : " - Failed" ); // Response to accumulated error	
  Serial.println();

  Serial.print("Setting PID KD: ");
  Serial.print( MKS42C_PID_KD_DEFAULT );
  Serial.print( servo_stepper->set_pid_kd( MKS42C_PID_KD_DEFAULT ) ? " - Success" : " - Failed" ); // Damping / anticipatory response
  Serial.println();

  Serial.print("Setting Accel: ");
  Serial.print( MKS42C_ACC_DEFAULT );
  Serial.print( servo_stepper->set_acc( MKS42C_ACC_DEFAULT ) ? " - Success" : " - Failed" ); // Damping / anticipatory response
  Serial.println();

  vTaskDelay(50);

  servo_stepper->set_zero_position();
  servo_stepper->set_stop_motor(); // enforce motor to stop
  Serial.println("Configuration done");
}

void loop(){ 
  // add stuff here if needed
  vTaskDelay(5000); // runs every 5 seconds
}

