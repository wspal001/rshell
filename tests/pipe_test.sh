#!/bin/sh
touch testFile2.txt
ls >> testFile2.txt
echo $(cat testFile2.txt) ; echo '\n'
touch output1.txt
touch output2.txt
cat < testFile2.txt | tr A-Z a-z | tee output1.txt | tr a-z A-Z > output2.txt
rm testFile2.txt
echo $(cat output1.txt) ; echo '\n'
echo $(cat output2.txt) ; echo '\n'
rm output1.txt ; rm output2.txt
exit
