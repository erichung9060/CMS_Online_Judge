#!/bin/bash
id=""

while true; do
    if ! curl -s http://localhost:8888 > /dev/null || [[ $id != $(cat /home/contest/contest_id) ]]; then
        id=$(cat /home/contest/contest_id)
        kill $(ps aux | grep cms | awk '{print $2}' | head -n -1)
        cmsResourceService -a <<< $id &
    fi
    sleep 1
done
