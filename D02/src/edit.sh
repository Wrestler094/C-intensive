#! /bin/bash

if [ $# != 3 ]
    then 
        echo "Wrong number of parameters!"
        exit 1
fi
 
root=$(cd $(dirname "$0") && pwd)
path=$1
oldString=$2
newString=$3

if [ ! -f $root/../$path ]
    then
        echo "File not exist!"
        exit 2
fi

if [ oldString == "" ]
    then
        echo "String to replace can not be empty"
fi

weight="$(ls -la $root/../$path | awk '{print $5}')"
date=$(date -r $root/../$path +'%F %H:%M')
shasum=$(shasum $root/../$path | awk '{print $1}')

sed -i '' "s/$oldString/$newString/g" $root/../$path

echo "$path - $weight - $date - $shasum - sha256" >> $root/files.log