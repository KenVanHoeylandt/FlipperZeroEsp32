# Usage:
#   ./build.sh /dev/ttyUSB0

idf.py build
idf.py -p $1 flash
idf.py -p $1 monitor
