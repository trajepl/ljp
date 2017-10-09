#!/bin/bash/

for file in `ls ./`; do
    newname=${file%.*}
    mv $file $newname
done

