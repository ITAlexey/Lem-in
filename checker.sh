#!/bin/bash

green='\033[32;01m'
reset='\033[0m'
red='\033[1;31m'

echo -e "\n$green====One ant to one path====$reset\n"
./resources/generator --flow-one > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "${red}lines recieved: $(wc -l < resources/result)$reset"
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < resources/map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log

echo -e "\n$green====Ten ants to one path====$reset\n"
./resources/generator --flow-ten > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "${red}lines recieved: $(wc -l < resources/result)$reset"
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < resources/map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log

echo -e "\n$green====Thousand ants to one path====$reset\n"
./resources/generator --flow-thousand > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "${red}lines recieved: $(wc -l < resources/result)$reset"
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < resources/map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log

echo -e "\n$green=======Big (~4K rooms)===========$reset\n"
./resources/generator --big > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "${red}lines recieved: $(wc -l < resources/result)$reset"
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < resources/map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log

echo -e "\n$green=======Complex big map===========\n$reset"
./resources/generator --big-superposition > resources/map
echo -e "Time:"
time ./lem-in < resources/map > resources/result
echo -e ""
grep -n "#Here" resources/map | head -1 | awk -F"of " '{print $2}'
echo -e "${red}lines recieved: $(wc -l < resources/result)$reset"
echo -e "\nLeaks:\n"
valgrind --log-file=logs/leaks.log --leak-check=full --track-origins=yes ./lem-in < resources/map > /dev/null
awk -F"== " '/ERROR SUMMARY/ {print $2}' logs/leaks.log
