#!/bin/bash
set -e

if [[ -d "Contest" ]]; then
    rm -r Contest    
fi
mkdir "Contest"

echo -n "Enter file name or blank for all : "
read toDoList

if [[ $toDoList == "" ]];then
    toDoList=$(ls | sed s/pack_to_yaml.sh//g | sed s/Contest//g)
fi

echo -e "name: \"HSPC-Final\"
description: \"國立成功大學暑期高中生程式設計邀請賽決賽\"
token_mode: disabled
timezone: \"+8\"
tasks:" > "Contest/contest.yaml"

for PROBLEM_NAME in $toDoList; do
    if [[ -d "Contest/$PROBLEM_NAME" ]]; then
        rm -rf Contest/$PROBLEM_NAME
    fi

    mkdir "Contest/$PROBLEM_NAME"
    mkdir "Contest/$PROBLEM_NAME/statement"
    mkdir "Contest/$PROBLEM_NAME/gen"
    mkdir "Contest/$PROBLEM_NAME/input"
    mkdir "Contest/$PROBLEM_NAME/output"
    
    N=$(ls $PROBLEM_NAME/tests | wc -l)
    N=$((N/2))

    for ((i = 1; i <= $N; i++)); do
        id=$i

        if [ $i -lt 10 ]; then
            id="0$i"
        fi
            
        cp "$PROBLEM_NAME/tests/$id" "Contest/$PROBLEM_NAME/input/input$((i-1)).txt"
        cp "$PROBLEM_NAME/tests/$id.a" "Contest/$PROBLEM_NAME/output/output$((i-1)).txt"
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
infile: \"\"
outfile: \"\"
    " > Contest/$PROBLEM_NAME/task.yaml

    echo -e "# ST: 100
$(seq 1 $N)
    " > Contest/$PROBLEM_NAME/gen/GEN

    echo "statement" > Contest/$PROBLEM_NAME/statement/statement.pdf

    echo "  - \"$PROBLEM_NAME\"" >> "Contest/contest.yaml"

done
echo "users:
  - username: \"test\"
    password: \"test\"
    first_name: \"test\"" >> "Contest/contest.yaml"
