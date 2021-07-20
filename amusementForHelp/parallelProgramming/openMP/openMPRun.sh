##########################################################################
# File Name: run.sh
# Author: Charliegean
# mail:wht905@gmail.com
# Created Time: Tue Mar  9 09:27:25 2021
#########################################################################
#!/bin/bash

counter=1
if [ $# -ne 1 ];then
    counter=$2
fi
cppName=$1
outName=${cppName%.*}
g++ -fopenmp $cppName -o  $outName
for((i=1;i<=$counter;i++))
do
    echo "this is the $i th run!"
    ./$outName 
done
rm $outName 
