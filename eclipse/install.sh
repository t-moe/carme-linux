#!/bin/bash
echo "installing cdt, make support,  gdb hardware debugging and memoryview enhancements"

eclipse -nosplash -application org.eclipse.equinox.p2.director -repository http://download.eclipse.org/tools/cdt/releases/8.4 -installIU org.eclipse.cdt.feature.group,org.eclipse.cdt.gnu.build.feature.group,org.eclipse.cdt.debug.gdbjtag.feature.group,org.eclipse.cdt.debug.ui.memory.feature.group


echo "installing ebmsysregview (sfr register view)"
eclipse -nosplash -application org.eclipse.equinox.p2.director -repository http://embsysregview.sourceforge.net/update -installIU org.eclipse.cdt.embsysregview_feature.feature.group
