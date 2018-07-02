#!/bin/bash

#make clean
echo "first to clean some rubbish file"
make clean
#syn-code with origin master
echo "syn-code with origin master"
echo "the password for(Ubuntu@lab206) is 123456"
git pull origin master
#to make find error
echo "cd .. / to make find error"
cd ..;make
read -p "if make is successed ? please to runtest ?y?n:" flag
if [ $flag == 'y' ];then
	cd test.release;./runtest
	cd ../src
else
	cd ../src
fi
