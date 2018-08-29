#!/bin/bash

timeout() {

    time=$1

    command="/bin/sh -c \"$2\""

    echo $command

    expect -c "set echo \"-noecho\"; set timeout $time; spawn -noecho $command; expect timeout { exit 1 } eof { exit 0 }"    

    if [ $? = 1 ] ; then
        echo "Timeout after ${time} seconds"
    fi

}

program="./start";

timeout 1000 $program

exit 0