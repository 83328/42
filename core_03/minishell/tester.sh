#!/bin/bash

SHELL_PROGRAM="./minishell"

# Run a test and check the result
run_test()
{
    test_name=$1
    expected_output=$2
    command_to_run=$3

    echo -n "Testing $test_name "

    actual_output=$($SHELL_PROGRAM | $command_to_run)

    if [ "$actual_output" = "$expected_output" ]; then
        echo "$(tput setaf 2)OK$(tput sgr0)"  # Green color for OK
    else
        echo "$(tput setaf 1)FAILED$(tput sgr0)"  # Red color for FAILED
        echo "  Input   : $command_to_run"
        echo "  Expected: $expected_output"
        echo "  Actual  : $actual_output"
    fi
}

# Tests
echo "*****************************************************"
echo "***************** MiniShell Tester ******************"
echo "*****************************************************"
echo ""

#run_test "Compilation flags" "OK" "-Wall -Wextra -Werror"
echo "----------------- Simple Commands ------------------"
run_test "Spaces...." ""   "    "
run_test "Tabs......" ""   $'\t\t\t'
run_test "Empty....." ""   ""
#echo "-------------------- Arguments ---------------------"
echo "---------------------- echo -------------------------"
run_test "echo 2...." "hello" "echo hello"
run_test "echo -n..." "hello" "echo -n hello"
run_test "echo 3...." "hello" "echo \"hello\""
run_test "echo 4...." "$(env | grep '^HOME=' | cut -d '=' -f 2)" "echo ~"
echo "------------------ Double Quotes --------------------"
run_test "echo 5...." "12\"" "echo \"12\\\"\""
run_test "echo 6...." "\"hello\"" "echo \"\"hello\"\""
echo "----------------- Single Quotes --------------------"
run_test "Space....." "" "\' \'"
run_test "\'pwd\'...." "" "\'pwd\'"
#echo "---------------------- env -------------------------"
#echo "-------------------- export ------------------------"
#echo "--------------------- unset ------------------------"
echo "----------------------- cd --------------------------"
run_test "cd 1......" "" "cd ../../../../../.."
run_test "cd 2......" "" "cd"
run_test "cd 3......" "" "cd"
echo "----------------------- pwd -------------------------"
run_test "pwd 1....." "$(env | grep '^PWD=' | cut -d '=' -f 2)" "pwd"
run_test "pwd 2....." "$(env | grep '^PWD=' | cut -d '=' -f 2)" "pwd ~"
echo "------------------ Relative Path --------------------"
run_test "cd/pwd...." "/" "cd ../../../../../..; pwd"

#run_test "ls 1......" "$(mkdir temp; touch temp/file1 temp/file2 temp/file3; ls temp; rm -r temp)" "mkdir temp; touch temp/file1 temp/file2 temp/file3; ls temp; rm -r temp"
#run_test "env 1....." "not empty" 'env | [ "$(wc -l)" -gt 0 ] && echo "not empty"'

echo ""
echo "*****************************************************"
echo "****************** Testing Complete *****************"
echo "*****************************************************"
