#!/bin/bash

#Write a shell script that takes 3 parameters, (ext1,  ext2, word) and will 
#rename all the files with the extension  ext1 to ext2 from it and its 
#subfolders and will count how many times word appears in each file.



if [ $# -lt 3 ]
then
        echo "Invalid number of parameters"
        exit
fi

for file in `find -name "*$1"`
do
        echo "$3 appers in $file `grep -o "\<$3\>" $file | wc -l` times."
        mv $file `echo $file | sed "s/$1/$2/"` #`perl -e 'print substr($ARGV[0], 0, length($ARGV[0])-length($ARGV[1])).$ARGV[2];' $file $1 $2`
done
