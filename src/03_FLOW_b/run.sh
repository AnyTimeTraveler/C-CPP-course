#!/bin/bash
./controlFlowIntr &
echo $!
sleep 1
kill -SIGUSR1 $!
sleep 1
kill -SIGUSR1 $!
kill -SIGUSR1 $!

