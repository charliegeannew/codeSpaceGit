##########################################################################
# File Name: runCpp.sh
# Creat Time: 2021年07月12日 星期一 10时49分08秒
# Author :Charliegean
# Mail :wht905@gmail.com
##########################################################################
#!/bin/bash
echo "this is c++OrC complie and run file "
echo "the type is 0-c,1-c++,2-python,3-java,4-openmp-c,5-openmp-c++,6-mpi-c,7-mpi-c++"
echo "the parameter is : runCode.sh 1-inputFile 2-type"
if [ $# -le 0 ];then
    echo "please input your inputFile"
    exit 1
fi
cppName=$1
outName=${cppName%.*}
echo "3-repeatTimes 4-cppPara/mpiTime"
counter=1
if [ $# == 1 ];then
    echo "you should input your type,the default type is c++"
    type=1
elif [ $# == 2 ];then
    type=$2
elif [ $# -gt 2 ];then
    type=$2
    counter=$3
fi

if [ $type == 0 ];then
    gcc $cppName -o $outName
elif [ $type == 1 ];then
    g++ $cppName -o $outName
elif [ $type == 2 ];then
    for((i=1;i<=$counter;i++))
    do
        python3 $cppName 
    done
    exit 2 
elif [ $type == 3 ];then
    javac $cppName
    for((i=1;i<=$counter;i++))
    do
        java $outName 
    done
    exit 3 
elif [ $type == 4 ];then
    gcc $cppName -fopenmp -o $outName
elif [ $type == 5 ];then
    g++ $cppName -fopenmp -o $outName
elif [ $type == 6 ];then
    mpicc -g -Wall $cppName -o $outName
    for((i=1;i<=$counter;i++))
    do
        mpirun -n $4 $outName 
    done
    exit 6 
elif [ $type == 7 ];then
    mpicxx -g -Wall $cppName -o $outName
    for((i=1;i<=$counter;i++))
    do
        mpirun -n $4 $outName 
    done
    exit 7
fi

for((i=1;i<=$counter;i++))
do
    ./$outName $4 
done
rm $outName
