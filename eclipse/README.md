Eclipse Support
============================

## Overview

Eclipse CDT integrates seamlessly with makefile projects. Furthermore you can flash your target and debug it using eclipse (via gdb).

## Eclipse Installation

- Install eclipse (normal package)
- Run the script install.sh. It will install CDT and the required plugins to get you started.

## How to use
- Copy the example project to your desired location and import it into eclipse as "existing project".
- You can compile the code normally by pressing the "build" button. Our makefile is used in the background.
- To download the code you have to press the "debug" button. Make sure the st-util deamon is running beforehand. (Start it with "make start")
- To debug the SFR's you can use the embsysregview plugin. [Tutorial](http://embsysregview.sourceforge.net/content/install3.html) 


## Known Issues / Remarks

- If you rename the project in either the makefile and/or eclipse you need to ajust the pathes of the debug configuration.
- Eclipse shows an error when you try to debug and st-util is not started or has crashed. Use "make start/stop" to reconnect.
- The code analyzer in eclipse is not completely identical to the compiler. You may see lines marked with an error although they would compile just fine.
- Stepping **over** a for loop will cause the debugger to hang. This is a bug in st_link.
