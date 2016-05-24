#!/bin/bash
echo "Creating testing set"
echo "bytes = 16"
echo "benign"
rm 16_testing.txt
for file in $(find ~/experiment/testing/original -name "*.*"); do ./min_bit $file -1 16 >> 16_testing.txt; done
echo "random"
for file in $(find ~/experiment/testing/shreded -name "*.*"); do ./min_bit $file 1 16 >> 16_testing.txt; done

echo "bytes = 512"
echo "benign"
rm 512_testing.txt
for file in $(find ~/experiment/testing/original -name "*.*"); do ./min_bit $file -1 512 >> 512_testing.txt; done
echo "random"
for file in $(find ~/experiment/testing/shreded -name "*.*"); do ./min_bit $file 1 512 >> 512_testing.txt; done

echo "bytes = 4096"
echo "benign"
rm 4096_testing.txt
for file in $(find ~/experiment/testing/original -name "*.*"); do ./min_bit $file -1 4096 >> 4096_testing.txt; done
echo "random"
for file in $(find ~/experiment/testing/shreded -name "*.*"); do ./min_bit $file 1 4096 >> 4096_testing.txt; done
