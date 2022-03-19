# qsort
This repo is intended to measure an imbecile implementation of qsort (no clever selection of pivot, no insert sort, etc) to compare a browsers js interpreter vs native code.

On my machine (A macbook pro) the times are:
* 910 ms for 10 000 000 numbers with g++ -Os
* 970 ms for 10 000 000 numbers with g++ -O3
* 1220 ms for 10 000 000 numbers on chrome
* 1780 ms for 10 000 000 numbers with g++ -O0

Update 2022-03-19
On my current machine (A System76 Gen10 laptop)
* 730 ms with g++ -Os
* 770 ms with g++ -O17 (720 ms with clang)
* 1210 ms on chrome
* 1550 ms with g++ -Og
