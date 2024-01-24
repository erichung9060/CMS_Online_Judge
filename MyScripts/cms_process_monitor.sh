#!/bin/bash

while true; do
    if ! curl -s http://localhost:8888 > /dev/null; then
    	sudo cmsResourceService -a <<< 1
    fi
    sleep 60
done
