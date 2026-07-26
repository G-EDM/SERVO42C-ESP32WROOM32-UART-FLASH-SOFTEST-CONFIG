#pragma once

#ifndef WIRE_CONTROLLER_CONFIG
#define WIRE_CONTROLLER_CONFIG

//###############################################################
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
//###############################################################

//##################################################################################
// Pinout
//##################################################################################
#define RX_PIN 16
#define TX_PIN 0



// max current and max torque are the values that will require changes to fit the requirenments
// this demo produces the softest motion I was able to get out of the 42C and may be too weak
// for some motors. Increase both in steps of 10 or 20 and reflash to see the impact

//##################################################################################
// The max current that the driver will provide to the motor is very critical and
// has the most impact on how much torque the motor produces
//##################################################################################
#define MKS42C_MAXCURRENT_DEFAULT 320 // mA
//##################################################################################
// Same as above. Big impact. This Demo value will make the motor struggle to move 
// back to the zero position even without load. Just enough to get the shaft rotated
// A tiny load and it will stop
//##################################################################################
#define MKS42C_MAXTORQUE_DEFAULT 320 // no idea about the unit. Max is 1200; 

//##################################################################################
// The default PID parameters are very aggressive. Fast and strong reaction
// This values are the softest I could get without making the shaft osciallate while 
// settling back at zero. It may not be enough for other motors.
// Try increasing MKS42C_PID_KP_DEFAULT in steps of 1 to 10 to see the difference if 
// the motor does not smoothly return to 0
//##################################################################################
#define MKS42C_PID_KP_DEFAULT 1400 //250  // Immediate response to current error. Lower means less aggressive reaction
#define MKS42C_PID_KI_DEFAULT 0    // Response to accumulated error. Not wanted. Constant torque without increase is wanted.	
#define MKS42C_PID_KD_DEFAULT 1500 // Damping / anticipatory response

// this also has an impact but not sure why and how
#define MKS42C_ACC_DEFAULT 1042 // Accel I guess

//##################################################################################
// Baudrate:
// This is only for programming and the baud is very high. The code will try 
// multiple times to write the settings. if it fails try a lower baudrate.
// The baudrate needs to be set on the MKS driver to the same as the one used 
// here. If communication fails I recommend doing it with 9600
//##################################################################################
#define MKS42C_BAUDRATE 115200 // if the MKS driver does not react maybe the baud is too high. The firmware will try multiple times. If 
//#define MKS42C_BAUDRATE 9600 

//##################################################################################
// Other stuff
//##################################################################################
#define MKS42C_MICROSTEPS_DEFAULT       128
#define MKS42C_ENABLEMICROSTEPS_DEFAULT 1
#define MKS42C_ADDRESS_DEFAULT          0   // default device slave address (0-9)
#define MKS42C_ENABLEMODE_DEFAULT       0   // active low enable pin

#endif