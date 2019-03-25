#!/usr/bin/env bash

includes="functions.cpp pascal_string.cpp"

for f in $(ls -1 | grep -E ^a[0-9]+.cpp); do
  clang++ $f $includes -o $(echo $f | cut -d. -f1 ).out
done

