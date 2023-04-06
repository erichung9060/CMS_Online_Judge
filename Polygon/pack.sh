#!/bin/bash
set -e

if [[ ! -d "cmsTestCase" ]]; then
    mkdir "cmsTestCase"
fi

if [[ $# == 0 ]];then
    toDoList=$(ls | sed s/pack.sh//g | sed s/cmsTestCase//g)
else
    toDoList=$@
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
        zero="000"
        zero=${zero:0:$((3-${#i}))}

        if [ $i -lt 10 ]; then
            cp "$PROBLEM_NAME/tests/0$i" "$PROBLEM_NAME/RenamedTestCase/input.$zero$i"
            cp "$PROBLEM_NAME/tests/0$i.a" "$PROBLEM_NAME/RenamedTestCase/output.$zero$i"
        else
            cp "$PROBLEM_NAME/tests/$i" "$PROBLEM_NAME/RenamedTestCase/input.$zero$i"
            cp "$PROBLEM_NAME/tests/$i.a" "$PROBLEM_NAME/RenamedTestCase/output.$zero$i"
        fi

        ALL+="$PROBLEM_NAME/RenamedTestCase/input.$zero$i $PROBLEM_NAME/RenamedTestCase/output.$zero$i "
    done

    if [ -f "cmsTestCase/${PROBLEM_NAME}.zip" ]; then
        rm "cmsTestCase/${PROBLEM_NAME}.zip"
    fi

    zip -j "cmsTestCase/${PROBLEM_NAME}.zip" $ALL

    echo "Problem : $PROBLEM_NAME finished !"

    rm -rf "$PROBLEM_NAME/RenamedTestCase"
done