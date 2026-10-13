#!/bin/bash
g++ -std=c++23 -O2 -o gen gen.cpp
g++ -std=c++23 -O2 -o brute brute.cpp
g++ -std=c++23 -O2 -o sol sol.cpp

for i in $(seq 1 1000); do
    echo "test "$i
    ./gen $i > gen_in.txt
    ./sol < gen_in.txt > out1.txt
    ./brute < gen_in.txt > out2.txt
    if ! diff -q out1.txt out2.txt > /dev/null; then
        echo "❌ Mismatch found on seed $i"
        echo "----- Input -----"
        cat gen_in.txt
        echo "----- Your output -----"
        cat out1.txt
        echo "----- Brute output -----"
        cat out2.txt
        break
    fi
done
echo "✅ Stress test finished"