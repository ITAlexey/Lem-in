#!/bin/bash

echo -e "\n====One ant to one path====\n"
./generate_map --flow-one > map
echo -e "Time:"
time ./lem-in < map > result
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log
echo -e ""
grep -n "#Here" map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < result)"

echo -e "\n====Ten ants to one path====\n"
./generate_map --flow-ten > map
echo -e "Time:"
time ./lem-in < map > result
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log
echo -e ""
grep -n "#Here" map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < result)"

echo -e "\n====Thousand ants to one path====\n"
./generate_map --flow-thousand > map
echo -e "Time:"
time ./lem-in < map > result
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log
echo -e ""
grep -n "#Here" map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < result)"

echo -e "\n=======Big (~4K rooms)===========\n"
./generate_map --big > map
echo -e "Time:"
time ./lem-in < map > result
echo -e ""
grep -n "#Here" map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < result)"

echo -e "\n=======Complex big map===========\n"
./generate_map --big-superposition > map
echo -e "Time:"
time ./lem-in < map > result
echo -e ""
grep -n "#Here" map | head -1 | awk -F"of " '{print $2}'
echo -e "lines recieved: $(wc -l < result)"
