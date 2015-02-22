#!/bin/bash
#
#   Util script which takes care of the starting and stopping of st-util.
#

pid=/tmp/st-util.pid
isp=/dev/stlinkv2_2

case "$1" in
    "start")
        if [ -e ${pid} ]; then
            echo -e "[\033[32m:)\033[m] st-util already running."
            exit 0
        fi
        if [ ! -e ${isp} ]; then
            echo -e "[\033[31mError\033[m] No Stlink v2 connected."
            exit 0    
        fi
        echo -e "[\033[32m:)\033[m] Starting st-util."
        /bin/st-util > /dev/null 2>&1 &
        echo $! > /tmp/st-util.pid
    ;;
    "stop")
        if [ ! -e ${pid} ]; then
            echo -e "[\033[31mError\033[m] st-util not running."
            exit 1
        fi
        echo -e "[\033[31m:(\033[m] Stopping st-util."
        killall st-util
        rm -f /tmp/st-util.pid
    ;;
    "status")
        if [ -e ${pid} ]; then
            echo -e "[Status] \033[32mrunning.\033[m"
            exit 0
        else
            echo -e "[Status] \033[31mstopped.\033[m"
            exit 1
        fi
    ;;
    *)
        echo -e "[\033[31mError\033[m] \033[32mUsage: $0 {start|stop|status}\033[m"
        exit 1
esac
