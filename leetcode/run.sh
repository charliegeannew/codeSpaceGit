##########################################################################
# File Name: run.sh
# Author: Charliegean
# mail:wht905@gmail.com
# Created Time: Tue Mar  9 09:27:25 2021
#########################################################################
#!/bin/bash

cppName=$1
outName=${cppName%.*}
g++ $cppName -o $outName
./$outName $2
rm $outName
