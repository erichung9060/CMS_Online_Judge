#!/bin/bash
set -e

# configuration
Contest_Name="test_contest"
Contest_Description="contest of testing cms judge"
#--------------

if [[ -d "Contest" ]]; then
    rm -r Contest    
fi
mkdir "Contest"

echo -n "Enter Problem Name or blank for all to add to a Contest: "
read toDoList

if [[ $toDoList == "" ]];then
    toDoList=$(ls | sed s/pack_to_yaml.sh//g | sed s/Contest//g)
fi

echo -e "name: \"$Contest_Name\"
description: \"$Contest_Description\"
token_mode: disabled
timezone: \"+8\"
tasks:" > "Contest/contest.yaml"

for PROBLEM_NAME in $toDoList; do
    mkdir "Contest/$PROBLEM_NAME"
    mkdir "Contest/$PROBLEM_NAME/statement"
    mkdir "Contest/$PROBLEM_NAME/gen"
    mkdir "Contest/$PROBLEM_NAME/input"
    mkdir "Contest/$PROBLEM_NAME/output"
    
    N=$(($(ls $PROBLEM_NAME/tests | wc -l)/2))
    PROBLEM_TITTLE=$(cat $PROBLEM_NAME/problem.xml | grep -m 1 'value="[^\"]*"' -o | sed -e s/value=// -e s/\"//g)
    TIME_LIMIT=$(($(cat $PROBLEM_NAME/problem.xml | grep '<time-limit>' | sed -e s/'<time-limit>'// -e s/'<\/time-limit>'//)/1000))
    MEMORY_LIMIT=$(($(cat $PROBLEM_NAME/problem.xml | grep '<memory-limit>' | sed -e s/'<memory-limit>'// -e s/'<\/memory-limit>'//)/1024/1024))

    for ((i = 01; i <= $N; i++)); do
        id=$i
        if [ $i -lt 10 ]; then
            id="0$i"
        fi

        cp "$PROBLEM_NAME/tests/$id" "Contest/$PROBLEM_NAME/input/input$((i-1)).txt"
        cp "$PROBLEM_NAME/tests/$id.a" "Contest/$PROBLEM_NAME/output/output$((i-1)).txt"
    done
    
    echo -e "name: $PROBLEM_NAME\ntitle: $PROBLEM_TITTLE\ntime_limit: $TIME_LIMIT\nmemory_limit: $MEMORY_LIMIT\nn_input: $N\ntoken_mode: disabled\npublic_testcases: all\ninfile: \"\"\noutfile: \"\"" > Contest/$PROBLEM_NAME/task.yaml
    echo -e "# ST: 100\n$(seq 1 $N)" > Contest/$PROBLEM_NAME/gen/GEN
    echo "statement" > Contest/$PROBLEM_NAME/statement/statement.pdf
    echo "  - \"$PROBLEM_NAME\"" >> "Contest/contest.yaml"

    printf "%s  %ds  %dMiB  %s\n" "$PROBLEM_NAME" "$TIME_LIMIT" "$MEMORY_LIMIT" "$PROBLEM_TITTLE" 
done

echo -e "users:\n  - username: \"test\"\n    password: \"test\"\n    first_name: \"test\"" >> "Contest/contest.yaml"
echo "sudo cmsImportUser --all -L italy_yaml . && sudo cmsImportContest -i -L italy_yaml ." >> "Contest/import.sh"
echo "Finished!"
