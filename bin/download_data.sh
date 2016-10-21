#!/bin/bash
echo "download binary data to ../data/binary/training"
mkdir -p ../data/binary/
wget http://digitalcorpora.org/corp/files/filetypes1/EXE.zip
mv EXE.zip ../data/binary/
echo "Extracting zip..."
mkdir -p ../data/binary/training/benign
unzip ../data/binary/EXE.zip -d ../data/binary/training/benign/
mv ../data/binary/training/benign/EXE/* ../data/binary/training/benign
rm -d ../data/binary/training/benign/EXE
chmod +w ../data/binary/training/benign/*
find ../data/binary/training/benign -name "* *" -type f | rename 's/ /_/g'
echo "Split extracted files into training and testing"
mkdir -p ../data/binary/testing/benign/
ls -a ../data/binary/training/benign/ | sort -n | head -45 | xargs -i mv ../data/binary/training/benign/"{}" ../data/binary/testing/benign/ 

echo "Creating random sets"
mkdir -p ../data/binary/training/random/
cp ../data/binary/training/benign/* ../data/binary/training/random/
chmod +w ../data/binary/training/random/*
shred -n 1 ../data/binary/training/random/*

mkdir -p ../data/binary/testing/random/
cp ../data/binary/testing/benign/* ../data/binary/testing/random/
chmod +w ../data/binary/testing/random/*
shred -n 1 ../data/binary/testing/random/*

echo "downloading zip and bz"
mkdir -p ../data/compressed/training/benign/
wget http://digitalcorpora.org/corp/files/filetypes1/BZ2.zip
wget http://digitalcorpora.org/corp/files/filetypes1/ZIP.zip
wget http://digitalcorpora.org/corp/files/filetypes1/JAR.zip

mv BZ2.zip ../data/compressed/
mv ZIP.zip ../data/compressed/
mv JAR.zip ../data/compressed/
unzip ../data/compressed/BZ2.zip -d ../data/compressed/training/benign/
mv ../data/compressed/training/benign/BZ2/* ../data/compressed/training/benign/
rm -d ../data/compressed/training/benign/BZ2/
chmod +w ../data/compressed/training/benign/*
find ../data/compressed/training/benign -name "* *" -type f | rename 's/ /_/g'
echo "split files into training and testing sets"
mkdir -p ../data/compressed/testing/benign/
ls -a ../data/compressed/training/benign/ | sort -n | head -14 | xargs -i mv ../data/compressed/training/benign/"{}" ../data/compressed/testing/benign/ 

unzip ../data/compressed/ZIP.zip -d ../data/compressed/training/benign/
find ../data/compressed/training/benign/ZIP -name "* *" -type f | rename 's/ /_/g'
chmod +w ../data/compressed/training/benign/ZIP/*
echo "split files into training and testing sets"
ls -a ../data/compressed/training/benign/ZIP | sort -n | head -7 | xargs -i mv ../data/compressed/training/benign/ZIP/"{}" ../data/compressed/testing/benign/ 
mv ../data/compressed/training/benign/ZIP/* ../data/compressed/training/benign
rm -d ../data/compressed/training/benign/ZIP

unzip ../data/compressed/JAR.zip -d ../data/compressed/training/benign/
find ../data/compressed/training/benign -name "* *" -type f | rename 's/ /_/g'
chmod +w ../data/compressed/training/benign/JAR/*
echo "split files into training and testing sets"
mkdir -p ../data/compressed/testing/benign/
ls -a ../data/compressed/training/benign/JAR | sort -n | head -52 | xargs -i mv ../data/compressed/training/benign/JAR/"{}" ../data/compressed/testing/benign/ 
mv ../data/compressed/training/benign/JAR/* ../data/compressed/training/benign
rm -d ../data/compressed/training/benign/JAR/

echo "Creating random sets"
mkdir -p ../data/compressed/training/random/
cp ../data/compressed/training/benign/* ../data/compressed/training/random/
chmod +w ../data/compressed/training/random/*
shred -n 1 ../data/compressed/training/random/*

mkdir -p ../data/compressed/testing/random/
cp ../data/compressed/testing/benign/* ../data/compressed/testing/random/
chmod +w ../data/compressed/testing/random/*
shred -n 1 ../data/compressed/testing/random/*
echo "Done!!"
