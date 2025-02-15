# 555-soil-moisture-snsr-cal
GUI calibration program for those cheap 555 timer based capacitive soil
moisture sensors.
Intended to be ran on Raspberry Pi with a BC Robotics 16-channel analog
multiplexer HAT.

01-19-2025 Very much under construction. Just reading values from a couple text
files, until I can get ahold of some actual hardware to do this with.

01-22-2025
Binary is now compiled on the intended target architecture ARM64. Directory
has been restructured.

01-24-2025
Fixed stupid error in Makefile causing whichever first src file is listed to
not compile.. slow down and smell the flowers.
Config ini file code now works.
Calibration and PV calc code works.
Bin prints test of everything to console.
Next.. figure out just how in the world target user wants to use this code..
I mean, it's nice to have cal slopes and offsets for a bunch of sensors..
but how is he going to actually USE those values? How is he going to USE
the PV calculation? khall-repo nCURSES at the sky..
- Start the program.
- Have options of either sensor cal or sensor read loop.
- Sensor cal goes first, it stores its output data to text file.
- After cal, re-run program but pick sensor read loop.
- Sesnor read loop does what it says on the tin, calculates PV for all sensors
using the calibration data and prints them to screen. Maybe plays a jingle when
an alarm point is hit.
- Phase 2: ??
- Phase 3: Profit
Couple of things I need to determine.. may need end user to do a couple
experiments with sensors and report back. What will max offset be? What are the
slope limits going to be, or do we even care? Can we detect a fault condition?
Haven't received the analog HAT in the mail yet, so there's still that to do..

02-09-2025
Working now:
 - ADC data capture
 - ADC data averaging
 - ADC data to millivolts
 - EWMA filtering for millivolts
 - Millivolts to PV
 - Zero and span calibration
 - Calibration save and load, to and from config.ini
 Changed timebase from 1 second to 0.1 second.

Still plenty of work to do.. like supporting the remaining 8 available ADC
channels and alarms.

02-10-2025
We have tabs now in the main-window.
Worked on cleaning up imain-window and adding ability to change foreground
and background color of text. But changing foreground color resets the
background color, and changing background color resets foreground color...

02-15-2025
The color stuff now sorted out, can change text color, text highlight color, and
background colors of data display label boxes.
Font attributes of the data display labels can now be changed/updated, such as
the font family, size, and weight. Font family and weight can be changed in the
config.ini file.
Now working on "arraying" all of the window elements which have mulitiple
similar elements, which took awhile to figure out because it wasn't so straight-
forward. I got the sensor raw data display labels and all font attributes now
"arrayed" in both the main-window and imain-window code. So much more work to
go in this particular task..

## Fresh Pi
# Libraries needed to run ./bin/main are WiringPi and GTK4.

1. Get and install WiringPi
https://github.com/WiringPi/WiringPi
WiringPi can either be built from source or installed from binary.
Instructions for both methods are listed on the WiringPi Github page.

2. Install the GTK4 libary
$ sudo apt install libgtk-4-1

# Additional libraries needed to build this project:
In addition to 1 and 2 above, you need to..

1. Install the GTK4 Dev library
$ sudo apt install libgtk-4-dev

## Building the project:
$ make



## Disclaimer 1 of 2
This software is provided "as is", without warranty of any kind, express or
implied, including but not limited to the warranties of merchantability,
fitness for a particular purpose, and noninfringement. In no event shall the
authors or copyright holders be liable for any claim, damages, or other
liability, whether in an action of contract, tort, or otherwise, arising from,
out of, or in connection with the software or the use or other dealings in the
software.
## Use at your own risk.

## Disclaimer 2 of 2
This software is not intended for public use, but feel free to clone this
project and use it as you please. Do not expect any support from the author,
please do not ask. I am writing this for a personal friend to use, and once
it works well enough for him to use, that is where my effort will end with
this project.

## WiringPi License
This project uses the WiringPi library under the GNU LESSER GENERAL PUBLIC
LICENSE.
License document and listing of authors are located in \wiringPi-license

(C)2025 Keith Hall
All rights reserved
