#!/bin/bash
echo "creating testing set..."
echo "benign..."
for file in $(find ~/experiment/testing/original -name "*.*"); do ./min_bit $file -1 16 >> 16_testing.txt; done
echo "random..."
for file in $(find ~/experiment/testing/shreded -name "*.*"); do ./min_bit $file 1 16 >> 16_testing.txt; done
