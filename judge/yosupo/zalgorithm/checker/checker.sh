for i in $(seq 1 99); do
    S=$(python3 random_testcase.py)
    out=$(go run ../zalgorithm.go <<< $S)
    correct=$(go run correct.go <<< $S)
    echo $out
    echo $correct
    if [[ $out != $correct ]]; then
        echo "You do something wrong"
        exit
    fi
done

echo "Passed. Good job!"