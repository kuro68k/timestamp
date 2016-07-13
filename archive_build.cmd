; archive firmware with build number in file name
echo off
set /p build=<buildnum.txt
copy %1\%3.elf %2\%3.%build%.elf
copy %1\%3.hex %2\%3.%build%.hex
copy %1\%3.map %2\%3.%build%.map
