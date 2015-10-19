Arduino UNO Macro Device
===================================================
This project is derived from the Arduino USB HID Keyboard gist and modified to use a series of other uncommonly used keyboard combinations to allow a total of twelve macros to be defined using AutoHotKey.

Resources Used:

* http://mitchtech.net/arduino-usb-hid-keyboard/
* http://www.freebsddiary.org/APC/usb_hid_usages.php

Purpose
---------------------------------------------------
The Arduino Uno does not support emulating a USB keyboard using the Arduino keyboard libraries unlike the newer Leonardo, Micro or Due models. Using the firmware modification as provided in Michael's tutorial, you can use the serial interface to send HID keyboard commands.

I created this project to provide a range of keyboard combinations that are uncommonly used, which can be used to create your own macros using AutoHotkey or your own OS's keyboard preferences.

Configuration
---------------------------------------------------
### Hardware Design
This project is configured for five push buttons using digital reads. It is possible to modify this to use analogue reads, which will allow the buttons to be connected to a single analogue pin, but requires more complex set up of resistors, and proved to be too unreliable for my use.

### Software
The Arduino sends a number of keyboard combinations via the serial port according to the USB HID specification. Each combination is a modifier followed by a Numpad key (assuming NumLock is on), which can be changed according to the current control mode.

Ctrl was used as the keyboard modifier as the Windows/Super/GUI key produced unexpected behaviour on Windows. Only one modifier can be sent.

### Scripting the macros on the PC side
The actual function of each macro needs to be configured on your OS. This could be achieved using your OS's built-in keyboard preference options, or by using another tool.

A sample AutoHotKey configuration has been included in the repo.

Keys
---------------------------------------------------

**Button 0**: Control Mode

- Description: used to switch between a total of three modes, allowing a total of twelve macros.
- Keys: Ctrl + { Numpad0 }

**Button 1**:

- Keys: Ctrl + { Numpad1 || Numpad4 || Numpad7 }

**Button 2**:

- Keys: Ctrl + { Numpad2 || Numpad5 || Numpad8 }

**Button 3**:

- Keys: Ctrl + { Numpad3 || Numpad8 || Numpad9 }

**Button 4**:

- Keys: Ctrl + { Numpad. || Numpad+ || Numpad- }

Sample Auto HotKey configuration
---------------------------------------------------

The control mode button modifies the keys sent by each of the four macro buttons. If you wish to keep track of which mode is selected, you may need to create a script that notifies you when the mode has been changed. The autohotkey script that I am using for this purpose is as follows:

    controlMode = 0

    ^Numpad0::
    controlMode := mod((controlMode + 1), 3)
    TrayTip, MacroDevice, Mode %controlMode%, 3
    return

I also added a Reload macro that allows you to reload the autohotkey scripts in case it gets out of synch with the mode on the Arduino.

    #NumpadDot::
    TrayTip, MacroDevice, Reloading script - Mode 0
    Sleep, 500
    Reload
    return
