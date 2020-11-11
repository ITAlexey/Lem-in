#!/bin/bash

echo -e "\n====One ant to one path====\n"
./resources/generator --flow-one > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < resources/map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < resources/result)"

echo -e "\n====Ten ants to one path====\n"
./resources/generator --flow-ten > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < resources/map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < resources/result)"

echo -e "\n====Thousand ants to one path====\n"
./resources/generator --flow-thousand > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < resources/map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < resources/result)"

echo -e "\n=======Big (~4K rooms)===========\n"
./resources/generator --big > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < resources/result)"

echo -e "\n=======Complex big resources/map===========\n"
./resources/generator --big-superposition > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < resources/result)"
