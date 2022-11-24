regexp_integer='^[0-9]+$'

if [ $# -eq 0 ]; then  #full auto
    ./gen.py 1000 | ./qsort -s 1000
elif [ $# -eq 1 ]; then # auto thread count
    if ! [[ $1 =~ $regexp_integer ]] ; then
        echo "Error: [N] must be an non-negative integer" >&2; exit 1
    else
        ./gen.py $1 | ./qsort -s $1
    fi
elif [ $# -eq 2 ]; then # thread count comes last
    if ! [[ $1 =~ $regexp_integer ]] ; then
        echo "Error: [N] must be an non-negative integer" >&2; exit 1
    elif ! [[ $2 =~ $regexp_integer ]]; then
        echo "Error: [thread count] must be an non-negative integer" >&2; exit 1
    elif [ $2 -eq 0 ]; then
        echo "Error: thread count cannot be zero" >&2; exit 1
    else
        ./gen.py $1 | OMP_NUM_THREADS=$2 ./qsort -s $1
    fi
else
    echo "Usage: cl.sh N [thread_count]"
fi
