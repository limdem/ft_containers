#!/bin/bash

CC="c++"
FLAGS="-Wall -Werror -Wextra -std=c++98"

FILES="main_launcher.cpp"
STL_EXEC="stl_exec"
FT_EXEC="ft_exec"
COMPILATION_ERROR_FILE="compilation_errors"
STL_OUTPUT="stl_output"
FT_OUTPUT="ft_output"
DIFF_OUTPUT="diff_output"
STL_PERF_OUTPUT="stl_perf.txt"
FT_PERF_OUTPUT="ft_perf.txt"
SUCCESS=0
RESULT=0
STL_PERF_VAR=0
FT_PERF_VAR=0

clean()
{
    rm -f $COMPILATION_ERROR_FILE $FT_PERF_OUTPUT $STL_PERF_OUTPUT $DIFF_OUTPUT $FT_OUTPUT $STL_OUTPUT
}

select_container_files()
{
    echo "Select $type tests..."
        
    for filename in $1/*; do
        FILES="$FILES $filename"    
    done

}

compile_source_files()
{
    echo "Compile ft executable"
    $CC $FLAGS -DSELECT_NAMESPACE=1 $FILES -o $FT_EXEC 2>> $COMPILATION_ERROR_FILE
    if [[ $? -eq $SUCCESS ]];
    then 
        echo "OK"
    else
        echo "KO"
        RESULT=1

    fi
    echo "Compile stl executable"
    $CC $FLAGS -DSELECT_NAMESPACE=2 $FILES -o $STL_EXEC 2>> $COMPILATION_ERROR_FILE
    if [[ $? -eq $SUCCESS ]];
    then 
        echo "OK"
    else
        echo "KO"
        RESULT=1
    fi
    if [[ $RESULT -eq $SUCCESS ]];
    then
        echo "Compilation succeeded"
    else
        exit 1
    fi

    ./$STL_EXEC >> $STL_OUTPUT
    ./$FT_EXEC >> $FT_OUTPUT
}

compare_exec_output()
{
    echo "Output Comparison"
    diff $STL_OUTPUT $FT_OUTPUT > $DIFF_OUTPUT
    RESULT=$?
    if [[ $RESULT -eq $SUCCESS ]]
    then
        echo "OK"
    else
        echo "KO"
    fi
}

compare_perf()
{
    echo "Performance Comparison"
    LINE_NUMBER=0
    for line1 in $(<$FT_PERF_OUTPUT); do
        LINE_NUMBER=$((LINE_NUMBER + 1))
        FT_LINE=$(sed -n "${LINE_NUMBER}p" $FT_PERF_OUTPUT)
        STL_LINE=$(sed -n "${LINE_NUMBER}p" $STL_PERF_OUTPUT)
        if [[ STL_LINE -eq 0 ]]
        then
            let STL_LINE="$STL_LINE+1"
        fi
        let STL_LINE="$STL_LINE*20"

        if [[ FT_LINE -gt STL_LINE ]]
        then
            echo "KO"
            exit 1;
        fi
    done
    echo "OK"
}

main()
{
    clean
    containers=("vector" "map" "stack" "set")
    for type in ${containers[@]}; do
        select_container_files $type
    done
    compile_source_files
    compare_exec_output
    compare_perf
}

main

