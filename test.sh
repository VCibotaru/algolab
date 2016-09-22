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
#   $2 - real output
#   $3 - expected output

function EchoTestFailed {
    EchoRed "[  FAILED  ] "
    printf "Test name: $1\nExpected:\n$3\nGot:\n$2\n"
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
    real_output=`./a.out < ./tests/$test`
    if [ $? != 0 ]; then
        EchoCrash $test
        continue
    fi
    expected_output=`cat ./tests/${test%.*}.out`
    if [ $real_output == $expected_output ]; then
        EchoTestPassed $test
    else
        EchoTestFailed $test $real_output $expected_output
    fi
done

