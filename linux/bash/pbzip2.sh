#!/bin/bash

directory="/home/trajep/pando/experiment/dbpedia/en/downloads"

for file in `ls $directory`; do
    if [ -d $directory/$file ]; then
        continue
    else
        filename=$directory/$file
        echo $filename
        if [ ${filename##*.} = bz2 ]; then
            pbzip2 -dkfc -p5 $filename > /home/trajep/pando/dataset/dbpedia/$file
        fi
    fi
done
