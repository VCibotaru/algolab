#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
NC='\033[0m' # No Color`

# prints $1 with red color
function EchoRed {
printf "$RED$1$NC"
}

# prints $1 with green color
function EchoGreen {
printf "$GREEN$1$NC"
}

# prints $1 with orange color
function EchoOrange {
printf "$ORANGE$1$NC"
}

# args:
#   $1 - test file name
#   $2 - real output file
#   $3 - expected output file

function EchoTestFailed {
  EchoRed "[  FAILED  ] "
  printf "Test name: $1\n"
  printf "Expected:\n"
  cat $3
  printf "Got:\n"
  cat $2
}

# args:
#   $1 - test file name
function EchoTestPassed {
  EchoGreen "[  PASSED  ] "
  printf "Test name: $1\n"
}

# args:
#   $1 - test file name
function EchoCrash {
  EchoOrange "[ CRASHED  ] "
  printf "Test name: $1\n"
}

# get only the filenames, not full paths
tests=`find ./tests/*.in -exec basename {} \;`

for test in $tests
do
  in_file=./tests/$test
  real_out_file=./tests/tmp.out
  rm $real_out_file
  expected_out_file=./tests/${test%.*}.out
  ./a.out < $in_file > $real_out_file
  if [ $? != 0 ]; then
    EchoCrash $test
    continue
  fi
  diff $real_out_file $expected_out_file > /dev/null
  if [ $? == 0 ]; then
    EchoTestPassed $test
  else
    EchoTestFailed $test $real_out_file $expected_out_file
  fi
done

