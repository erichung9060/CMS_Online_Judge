#!/bin/bash
set -e

if [[ ! -d "cmsTestCase" ]]; then
    mkdir "cmsTestCase"
fi

echo -n "Enter the name of the problem to zip testcase, or leave blank to zip all : "
read toDoList

if [[ $toDoList == "" ]];then
    toDoList=$(ls | sed s/pack_to_yaml.sh//g | sed s/Contest//g)
fi

for PROBLEM_NAME in $toDoList; do
    if [[ $PROBLEM_NAME == "pack.sh" || $PROBLEM_NAME == "cmsTestCase" ]];then
        continue
    fi

    all=`ls $PROBLEM_NAME/tests`

    N=1
    for NUM in $all; do
        if [[ $NUM =~ ^[0-9]+$ ]] && [ $NUM -gt $N ]; then
            N=$NUM
        fi
    done

    if ! [ -e "$PROBLEM_NAME/RenamedTestCase" ]; then
        mkdir "$PROBLEM_NAME/RenamedTestCase"
    fi

    ALL=""
    for ((i = 1; i <= $N; i++)); do
        index=$((i-1))
        index=$(printf "%03d" $index)

        if [ $i -lt 10 ]; then
            cp "$PROBLEM_NAME/tests/0$i" "$PROBLEM_NAME/RenamedTestCase/input.$index"
            cp "$PROBLEM_NAME/tests/0$i.a" "$PROBLEM_NAME/RenamedTestCase/output.$index"
        else
            cp "$PROBLEM_NAME/tests/$i" "$PROBLEM_NAME/RenamedTestCase/input.$index"
            cp "$PROBLEM_NAME/tests/$i.a" "$PROBLEM_NAME/RenamedTestCase/output.$index"
        fi

        ALL+="$PROBLEM_NAME/RenamedTestCase/input.$index $PROBLEM_NAME/RenamedTestCase/output.$index "
    done

    if [ -f "cmsTestCase/${PROBLEM_NAME}.zip" ]; then
        rm "cmsTestCase/${PROBLEM_NAME}.zip"
    fi

    zip -j "cmsTestCase/${PROBLEM_NAME}.zip" $ALL

    echo "Problem : $PROBLEM_NAME finished !"

    rm -rf "$PROBLEM_NAME/RenamedTestCase"
done
