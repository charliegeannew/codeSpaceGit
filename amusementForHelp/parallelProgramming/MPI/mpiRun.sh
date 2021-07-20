##########################################################################
# File Name: run.sh
# Author: Charliegean
# mail:wht905@gmail.com
# Created Time: Tue Mar  9 09:27:25 2021
#########################################################################
#!/bin/bash

counter=1
if [ $# -gt 2 ];then
    counter=$3
fi
cppName=$1
outName=${cppName%.*}
mpicxx -g -Wall $cppName -o $outName
for((i=1;i<=$counter;i++))
do
    echo "this is the $i th run!"
    mpirun -n $2 ./$outName 
done
rm $outName 
