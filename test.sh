#!/usr/bin/bash

for i in $(ls $2 | grep input)
do

    diff <($1 < $(echo "$2/$i"))  $(echo "$2/$i" | sed 's/input/output/')
done