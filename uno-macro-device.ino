/*
 * Arduino UNO Macro Device
 * Extended for use when creating macros with autohotkey
 * Source: http://mitchtech.net/arduino-usb-hid-keyboard/
 * Source: http://www.freebsddiary.org/APC/usb_hid_usages.php
 */

#define KEY_LEFT_CTRL   0x01
#define KEY_LEFT_SHIFT  0x02
#define KEY_RIGHT_CTRL  0x10
#define KEY_RIGHT_SHIFT 0x20
#define KEY_LEFT_GUI    0x83
#define KEY_RIGHT_GUI   0x87
#define KEY_NUMPAD_DEL  0x63
#define KEY_NUMPAD_PLU  0x57
#define KEY_NUMPAD_MIN  0x56
#define KEY_NUMPAD_0    0x62
#define KEY_NUMPAD_1    0x59
#define KEY_NUMPAD_2    0x5A
#define KEY_NUMPAD_3    0x5B
#define KEY_NUMPAD_4    0x5C
#define KEY_NUMPAD_5    0x5D
#define KEY_NUMPAD_6    0x5E
#define KEY_NUMPAD_7    0x5F
#define KEY_NUMPAD_8    0x60
#define KEY_NUMPAD_9    0x61

uint8_t buf[8] = { 
  0 };  /* Keyboard report buffer */

#define PIN_CONTROL 6
#define PIN_M1 5
#define PIN_M2 4
#define PIN_M3 3
#define PIN_M4 2

int state = 1;
int controlMode = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_CONTROL, INPUT_PULLUP);
  pinMode(PIN_M1, INPUT_PULLUP);
  pinMode(PIN_M2, INPUT_PULLUP);
  pinMode(PIN_M3, INPUT_PULLUP);
  pinMode(PIN_M4, INPUT_PULLUP);
  delay(200);
}

void loop() 
{
  state = digitalRead(PIN_CONTROL);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL;   // Ctrl
    buf[2] = KEY_NUMPAD_0;    // Letter X
    // buf[2] = 123;    // Cut key: Less portable
    Serial.write(buf, 8); // Ssend keypress
    releaseKey();
    controlMode = (controlMode + 1) % 3;
  } 

  state = digitalRead(PIN_M1);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL;   // Ctrl
    switch (controlMode) {
      case 0:
        buf[2] = KEY_NUMPAD_1;
        break;
      case 1:
        buf[2] = KEY_NUMPAD_4;
        break;
      case 2:
        buf[2] = KEY_NUMPAD_7;
        break;
      default:
        buf[2] = KEY_NUMPAD_1;
    }
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_M2);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL;   // Ctrl
    switch (controlMode) {
      case 0:
        buf[2] = KEY_NUMPAD_2;
        break;
      case 1:
        buf[2] = KEY_NUMPAD_5;
        break;
      case 2:
        buf[2] = KEY_NUMPAD_8;
        break;
      default:
        buf[2] = KEY_NUMPAD_2;
    }
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  }
  
    state = digitalRead(PIN_M3);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL;   // Ctrl
    switch (controlMode) {
      case 0:
        buf[2] = KEY_NUMPAD_3;
        break;
      case 1:
        buf[2] = KEY_NUMPAD_6;
        break;
      case 2:
        buf[2] = KEY_NUMPAD_9;
        break;
      default:
        buf[2] = KEY_NUMPAD_3;
    }
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 
  
    state = digitalRead(PIN_M4);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL;   // Ctrl
    switch (controlMode) {
      case 0:
        buf[2] = KEY_NUMPAD_DEL;
        break;
      case 1:
        buf[2] = KEY_NUMPAD_PLU;
        break;
      case 2:
        buf[2] = KEY_NUMPAD_MIN;
        break;
      default:
        buf[2] = KEY_NUMPAD_DEL;
    }
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  }
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
  delay(500);
}
