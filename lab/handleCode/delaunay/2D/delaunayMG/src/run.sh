##########################################################################
# File Name: run.sh
# Author: Charliegean
# mail:wht905@gmail.com
# Created Time: Tue Mar  9 09:27:25 2021
#########################################################################
#!/bin/bash

cd ../libwht
./compile.sh 
cd ../lib
./compile.sh 
cd ../src
cppName=$1
outName=${cppName%.*}
g++ $cppName -o $outName -I ../lib/  ../lib/treeHandleWht.o ../lib/readWriteWht.o ../lib/dataStructureWht.o ../libwht/printFunct.o ../libwht/readWrite.o ../libwht/tempNumberFunct.o ../libwht/tempStringFunct.o ../libwht/tempVectorFunct.o 
./$outName $2
rm $outName
cd ../libwht
./deleteWht.sh
cd ../lib
./deleteWht.sh
cd ../src

