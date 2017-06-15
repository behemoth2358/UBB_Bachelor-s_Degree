#!/bin/bash


#Write a shell script that takes groups  of 3 parameters  (a name of a file a 
#word and a number k).For each groups, print all the lines from the file that 
#contain the word exactly k times.



while [ $# -ge 3 ]
do
        file=$1
        word=$2
        count=$3
        shift 3 # for every 3 parameters

        echo "$file:"

        if [ ! -f $file ]
        then
                echo "$file not a directory!"
                exit
        fi

        cat $file | while read line #for every line
        do
                if [ `echo $line | grep -o "$word" | wc -l` -eq $count ] #if word appears exactly count time on the line
                then
                        echo $line
                fi
        done
done
