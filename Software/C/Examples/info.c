/*
 *  https://www.dexterindustries.com/BrickPi/
 *  https://github.com/DexterInd/BrickPi3
 *
 *  Copyright (c) 2017 Dexter Industries
 *  Released under the MIT license (http://choosealicense.com/licenses/mit/).
 *  For more information, see https://github.com/DexterInd/BrickPi3/blob/master/LICENSE.md
 *
 *  This code is an example for reading BrickPi3 information
 *
 *  Results: Print information about the attached BrickPi3.
 *
 *  Example compile command:
 *    g++ -o program "info.c"
 *  Example run command:
 *    sudo ./program
 *
 */

#include "BrickPi3.cpp" // for BrickPi3
#include <stdio.h>      // for printf

BrickPi3 BP; // Create a BrickPi3 instance with the default address of 1
//BrickPi3 BP_7(7); // Create a BrickPi3 instance with address 7

int main(){
  //BrickPi3_set_address(1, ""); // set BrickPi3 with any id to the default address of 1
  //BrickPi3_set_address(7, "192A0F96514D4D5438202020FF080C23"); // set BrickPi3 with id 192A0F96514D4D5438202020FF080C23 to address 7
  
  BP.detect(); // Make sure that the BrickPi3 is communicating and that the firmware is compatible with the drivers.
  
  char string[32];
  
  BP.get_manufacturer(string);
  printf("Manufacturer    : %s\n", string);
  
  BP.get_board(string);
  printf("Board           : %s\n", string);
  
  BP.get_id(string);
  printf("Serial Number   : %s\n", string);
  
  BP.get_version_hardware(string);
  printf("Hardware version: %s\n", string);
  
  BP.get_version_firmware(string);
  printf("Firmware version: %s\n", string);
  
  printf("Battery voltage : %.3f\n", BP.get_voltage_battery());
  printf("9v voltage      : %.3f\n", BP.get_voltage_9v());
  printf("5v voltage      : %.3f\n", BP.get_voltage_5v());
  printf("3.3v voltage    : %.3f\n", BP.get_voltage_3v3());
}
