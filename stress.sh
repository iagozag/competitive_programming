for ((i = 1; ; ++i)); do
    echo $i
    ./gen $i > inp
    # diff -w <(./A < inp) <(./B < inp) || break
done
