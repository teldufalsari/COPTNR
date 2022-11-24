regexp_integer='^[0-9]+$'

if [ $# -eq 1 ]; then # auto thread count
    ./qsort -f $1
elif [ $# -eq 2 ]; then # thread count comes last
    if ! [[ $2 =~ $regexp_integer ]]; then
        echo "Error: [thread count] must be an non-negative integer" >&2; exit 1
    elif [ $2 -eq 0 ]; then
        echo "Error: thread count cannot be zero" >&2; exit 1
    else
        OMP_NUM_THREADS=$2 ./qsort -f $1
    fi
else
    echo "Usage: file.sh file [thread_count]"
fi