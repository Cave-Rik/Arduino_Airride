# Arduino_Airride
Quick and dirty Arduino sketch for turning an analog airride set to digital.
Specially written for M. Hettema and his Passat 35i.

Be sure to import the OneButton library into your Arduino app before compiling. It can be found here : https://github.com/mathertel/OneButton.git
This airride setup can be expanded to a system with digital pressure sensors for more accurate inflation of the airride forks, as well as a screen to display the 
current inflation of the forks.

Used equipment:<br>
<br>
Arduino Uno (but sketch also works with Arduino Nano)<br>
Arduino relay board (in this case the 4 relay board from <b> Robotdyn)<br></b>
Mini switch DIP P4 5mm (4x) (for mounting inside the VW OEM control button)<br>
VW OEM Window control button<br>
UTP wiring CAT6 (5M front to airride control box)<br>
<br>
All the other equipment (fusebox, compressors etc) was already present.
