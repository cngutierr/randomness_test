#!/bin/bash
echo "Creating training set"
echo "bytes = 16"
echo "benign"
rm 16_training.txt
for file in $(find ~/experiment/random_copy/original -name "*.*"); do ./min_bit $file -1 16 >> 16_training.txt; done
echo "random"
for file in $(find ~/experiment/random_copy/shreded -name "*.*"); do ./min_bit $file 1 16 >> 16_training.txt; done

echo "bytes = 512"
echo "benign"
rm 512_training.txt
for file in $(find ~/experiment/random_copy/original -name "*.*"); do ./min_bit $file -1 512 >> 512_training.txt; done
echo "random"
for file in $(find ~/experiment/random_copy/shreded -name "*.*"); do ./min_bit $file 1 512 >> 512_training.txt; done

echo "bytes = 4096"
echo "benign"
rm 4096_training.txt
for file in $(find ~/experiment/random_copy/original -name "*.*"); do ./min_bit $file -1 4096 >> 4096_training.txt; done
echo "random"
for file in $(find ~/experiment/random_copy/shreded -name "*.*"); do ./min_bit $file 1 4096 >> 4096_training.txt; done
