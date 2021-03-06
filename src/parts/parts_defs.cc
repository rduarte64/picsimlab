/* ########################################################################

   PICsimLab - PIC laboratory simulator

   ########################################################################

   Copyright (c) : 2010-2017  Luis Claudio Gambôa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */


#include"parts_defs.h" 

//includes of parts
#include"part_servo.h" 
#include"part_step.h" 
#include"part_d_transfer_function.h"
#include"part_push_buttons.h"
#include"part_switchs.h"
#include"part_LEDs.h"
#include"part_pot.h"
#include"part_RGB_LED.h"
#include"part_LCD_hd44780.h"

#include"part_LCD_pcf8833.h"
#include"part_LCD_pcd8544.h"
#include"part_gamepad.h"
/*
#include"part_MI2C_24CXXX.h"
#include"part_RTC_ds1307.h"
#include"part_RTC_pfc8563.h"
#include"part_Signal_Generator.h"
#include"part_VCD_Dump.h" or csv dump
*/

#ifdef _EXPERIMENTAL_
const char parts_list[NUM_PARTS][30]={"D. Transfer function","Gamepad", "LCD hd44780", "LCD pcf8833", "LCD pcd8544", "LEDs", "MEM 24CXXX", "Potentiometers", "Push buttons", "RGB LED", "RTC ds1307", "RTC pfc8563", "Servo motor", "Signal Generator", "Step motor","Switchs",};
#else
const char parts_list[NUM_PARTS][30]={"LCD hd44780",  "LCD pcf8833", "LCD pcd8544", "LEDs", "Potentiometers", "Push buttons", "RGB LED", "Servo motor", "Step motor","Switchs",};
#endif

//boards object creation
part * create_part(String name, unsigned int x, unsigned int y)
{
   part * part_=NULL; 
 
   if(name.compare(lxT("Servo motor")) == 0 )part_= new cpart_servo(x,y);

   if(name.compare(lxT("Step motor")) == 0 )part_= new cpart_step(x,y);
#ifdef _EXPERIMENTAL_   
   if(name.compare(lxT("D. Transfer function")) == 0 )part_= new cpart_dtfunc(x,y);
#endif
   if(name.compare(lxT("Push buttons")) == 0 )part_= new cpart_pbuttons(x,y);
   
   if(name.compare(lxT("Switchs")) == 0 )part_= new cpart_switchs(x,y);
   
   if(name.compare(lxT("LEDs")) == 0 )part_= new cpart_leds(x,y);
   
   if(name.compare(lxT("Potentiometers")) == 0 )part_= new cpart_pot(x,y);
   
   if(name.compare(lxT("RGB LED")) == 0 )part_= new cpart_rgb_led(x,y);
   
   if(name.compare(lxT("LCD hd44780")) == 0 )part_= new cpart_LCD_hd44780(x,y);
   
   if(name.compare(lxT("LCD pcf8833")) == 0 )part_= new cpart_LCD_pcf8833(x,y);
  
   if(name.compare(lxT("LCD pcd8544")) == 0 )part_= new cpart_LCD_pcd8544(x,y);
 
   if(name.compare(lxT("Gamepad")) == 0 )part_= new cpart_gamepad(x,y);
 
   return part_; 
}
