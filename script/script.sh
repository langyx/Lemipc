#!/bin/bash

for ((i = 0; i < 100; i += 1))
do
    ./lemipc `pwd` 3 &
done

for ((i = 0; i < 100; i += 1))
do
    ./lemipc `pwd` 2 &
done

for ((i = 0; i < 100; i += 1))
do
    ./lemipc `pwd` 1 &
done
for ((i = 0; i < 100; i += 1))
do
    ./lemipc `pwd` 7 &
done
