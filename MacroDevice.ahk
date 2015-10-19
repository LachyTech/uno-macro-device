#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

controlMode = 0

#NumpadDot::
TrayTip, MacroDevice, Reloading script - Mode 0
Sleep, 500
Reload
return

^Numpad0::
controlMode := mod((controlMode + 1), 3)
TrayTip, MacroDevice, Mode %controlMode%, 3
return

^Numpad1::
TrayTip, MacroDevice, Mode0: Macro1, 3
return

^Numpad2::
TrayTip, MacroDevice, Mode0: Macro2, 3
return

^Numpad3::
TrayTip, MacroDevice, Mode0: Macro3, 3
return

^NumpadDot::
TrayTip, MacroDevice, Mode0: Macro4, 3
return

^Numpad4::
TrayTip, MacroDevice, Mode1: Macro1, 3
return

^Numpad5::
TrayTip, MacroDevice, Mode1: Macro2, 3
return

^Numpad6::
TrayTip, MacroDevice, Mode1: Macro3, 3
return

^NumpadAdd::
TrayTip, MacroDevice, Mode1: Macro4, 3
return

^Numpad7::
TrayTip, MacroDevice, Mode3: Macro1, 3
return

^Numpad8::
TrayTip, MacroDevice, Mode3: Macro2, 3
return

^Numpad9::
TrayTip, MacroDevice, Mode3: Macro3, 3
return

^NumpadSub::
TrayTip, MacroDevice, Mode3: Macro4, 3
return