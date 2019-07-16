#!/bin/sh
for var in $(ls -l | grep ^- | awk '{print $9}' | awk -F '.' '{print $0}')
do
    num=$(echo $var | awk -F. '{print $1}')
    title=$(echo $var | awk -F. '{print $2}')
    type=$(echo $var | awk -F. '{print $3}')
    if [ -n "$type" ]; then
        path="P${num} ${title}"
        mkdir "${path}"
        mv "$var" "${path}/sl.${type}"
    fi
done
