#!/bin/bash

OBJDUMP="arm-none-eabi-objdump -D -bbinary -marmv4t -Mforce-thumb"
OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
$OBJDUMP $OPTIONS baserom.gba > baserom.dump
$OBJDUMP $OPTIONS advancewars.gba > advancewars.dump
diff -u baserom.dump advancewars.dump
