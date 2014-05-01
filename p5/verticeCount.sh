#! /bin/bash
# Author: Sean Davis

pattern="+"
count=0


for file in $@ ; do
 (( count = count + `sed  s/"$pattern"/"$pattern\n"/g $file  | grep "$pattern"  | wc -l` ))
done

echo $count
