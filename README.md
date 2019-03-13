# qsort
This repo is intended to measure an imbecile implementation of qsort (no clever selection of pivot, no insert sort, etc) to compare a browsers js interpreter vs native code.

On my machine the times are:
* 910 ms for 10 000 000 numbers with g++ -Os
* 970 ms for 10 000 000 numbers with g++ -O3
* 1220 ms for 10 000 000 numbers on chrome
* 1780 ms for 10 000 000 numbers with g++ -O0

