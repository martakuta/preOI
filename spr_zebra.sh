g++ -o gen gen_zebra.cpp
g++ -o bru zebra2.cpp
g++ -o tes zebra.cpp

for ((i=1; i<=100; i++)) do
	echo $i
	echo $o | ./gen > test
	./bru < test > brut
	./tes < test > myout
	diff brut myout || break
done
