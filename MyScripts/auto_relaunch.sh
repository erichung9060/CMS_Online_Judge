#!/bin/bash
id="1"

if ! curl -s http://localhost:8888 > /dev/null; then
    kill $(ps aux | grep cms | awk '{print $2}' | head -n -1)
    /usr/local/bin/cmsResourceService -a <<< $id &
fi
