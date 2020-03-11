#!/bin/bash

g++ -o gen -Wall -O2 -std=c++11 gen_minibatony.cpp
g++ -o bru -Wall -O2 -std=c++11 brut_minibatony.cpp
g++ -o tes -Wall -O2 -std=c++11 minibatony.cpp

for ((i=1; i<10000; i++))
do
	echo $i
	echo $i | ./gen > test
	./bru < test > brut
	./tes < test > myout
	diff brut myout || break
	
done
