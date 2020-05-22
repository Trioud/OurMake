#!/usr/bin/env bash
make -s -C src/
sudo cp src/program /usr/bin/ourmake
if [ $? != 0 ]; then
    exit
fi
cat resources/ascii.txt