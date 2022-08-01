#! /bin/bash

if [ $# != 1 ]
    then 
        echo "Wrong number of parameters!"
        exit 1
fi

root=$(cd $(dirname "$0") && pwd)
path=$1

if [ ! -f $root/../$path ]
    then
        echo "File not exist!"
        exit 2
fi

entries=$(wc -l $root/../$path | awk '{print $1}' | xargs)
uniqFiles=$(awk '{print $1}' $root/../$path | sort -u | wc -l | xargs)
test=$(awk '{print $8}' $root/../$path | uniq | wc -l | xargs)

echo "$entries $uniqFiles $test"