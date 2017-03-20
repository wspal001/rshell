#!/bin/sh
touch testFile.txt
echo inside testFile > testFile.txt
echo appended >> testFile.txt
ls >> testFile.txt
echo '\n' ; $(cat testFile.txt) ; '\n'
echo test over
rm testFile.txt
exit

