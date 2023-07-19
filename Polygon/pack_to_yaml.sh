#!/bin/bash
set -e

if [[ ! -d "cmsPackage" ]]; then
    mkdir "cmsPackage"
fi

echo -n "please enter problem name or all : "
read reply

if [[ $reply == "all" ]];then
    toDoList=$(ls | sed s/pack.sh//g | sed s/cmsPackage//g)
else
    toDoList=$reply
fi

for PROBLEM_NAME in $toDoList; do
    if [[ -d "cmsPackage/$PROBLEM_NAME" ]]; then
        rm -rf cmsPackage/$PROBLEM_NAME
    fi

    mkdir "cmsPackage/$PROBLEM_NAME"
    mkdir "cmsPackage/$PROBLEM_NAME/statement"
    mkdir "cmsPackage/$PROBLEM_NAME/gen"
    mkdir "cmsPackage/$PROBLEM_NAME/input"
    mkdir "cmsPackage/$PROBLEM_NAME/output"
    
    N=$(ls $PROBLEM_NAME/tests | wc -l)
    N=$((N/2))

    for ((i = 1; i <= $N; i++)); do
        id=$i

        if [ $i -lt 10 ]; then
            id="0$i"
        fi
            
        cp "$PROBLEM_NAME/tests/$id" "cmsPackage/$PROBLEM_NAME/input/input$((i-1)).txt"
        cp "$PROBLEM_NAME/tests/$id.a" "cmsPackage/$PROBLEM_NAME/output/output$((i-1)).txt"
    done
    public_tc=$(seq -s, 0 $((N-1)) )
    public_tc=${public_tc%,}

    echo -e "name: $PROBLEM_NAME
title: $PROBLEM_NAME
time_limit: 1
memory_limit: 256
n_input: $N
token_mode: disabled
public_testcases: $public_tc
infile: ""
outfile: ""
    " > cmsPackage/$PROBLEM_NAME/task.yaml

    echo -e "# ST: 100
$(seq 1 $N)
    " > cmsPackage/$PROBLEM_NAME/gen/GEN
done
