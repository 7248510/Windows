# Windows-CPP/C

This is a repository for windows programs.
## Using MSVC without the C/C++ extension
* Disabling the IntelliSense engine takes away a lot of features/functionality but the syntax highlighting works :)
* You cannot debug in VSC if you use this trick
* The terminal tab displays powershell, after you type a character the tab reverts to cmd
* If you want debugging functinality follow the offical guide
* If you'd like normal debugging/source code level? Use Visual Studio community's debugger or fix the extension
* Alternative windows debuggers(these will show assembly) include Windbg, Ollydbg, Cutter, x64 debugger, Immunity Debugger
In the event Microsoft's C/C++ extension doesn't add cl/MSVC or you'd like to use MSVC without the extension here's a guide.
Using the windows search bar look up "Developer Command Prompt for VS 2019", right click the shortcut and view the target.
The target field should match below, unless you changed the install directory, the same steps apply.
%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\Tools\VsDevCmd.bat" = This is the target value
Create a bat file where ever you'd like, I created the bat file in my Visual Studio directory*/Tools
You can name the bat file anything.
Paste the following into the bat file

@echo off
%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"

The comspec value should match the target field of the short cut.
Now that you have your new bat file. Edit VSC'S main settings
GUI = ctrl+,     The JSON is much easier to work with, I couldn't file terminal.integrated.shell.windows, I found "terminalintegrated.automationShell.windows" which doesn't work
JSON = ctrl + shift(left/right) + p, Preferences: Open Settings (JSON)
The second line of the json should display "terminal.integrated.shell.windows": "copy the location of your newly created bat"
Below is my example/what I'm using
"terminal.integrated.shell.windows": "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\Common7\\Tools\\vs.bat",
Restart VSC
ctrl + `(launch the terminal)
You should see the developer terminal!

There are other bat files in Microsoft's directory, when testing the other bats.
VsDevCmd.bat launches and closes
LaunchDevCmd.bat launches and goes to Visual Studio's editor directory. Example "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community"
The shortcut target's arguments worked perfectly in the sense that it displays the correct working directory and successfully links the Winapi

If you try to add cl to Window's path/edit systems varibles and add cl.exe to your path the files you'll run into linking issues