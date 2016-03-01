#include "keyboard.h"


#define KEYBOARD_BUFFER_SIZE 40


volatile static char keyboard_buffer[KEYBOARD_BUFFER_SIZE];

volatile static char keyboard_buffer_top = NULL;


// HID scancodes

#define KEY_1 0x1E
#define KEY_2 0x1F
#define KEY_3 0x20
#define KEY_4 0x21
#define KEY_5 0x22
#define KEY_6 0x23
#define KEY_7 0x24
#define KEY_8 0x25
#define KEY_9 0x26
#define KEY_0 0x27

#define KEY_PERIOD 0x37
#define KEY_MINUS  0x2D

#define KEY_ENTER 0x28




int keyboard_type_ulong(unsigned long value){
  char * temp = &keyboard_buffer[KEYBOARD_BUFFER_SIZE];
  *--temp = 0;
  *--temp = KEY_ENTER;
  
  do {
    int r = value % 10;
    
    *--temp = 0;
    
    if(r == 0)
      *--temp = KEY_0;
    else
      *--temp = r - KEY_1 + 1;
   
  } while (value > 0);
  
  
  *--temp = 0;
  
  keyboard_buffer_top = temp;
  
  return 1;
}
