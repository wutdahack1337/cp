for i in {1..1000}; do
    testcase=$(python3 rand.py)
    output=$(python3 1733.py <<< $testcase)
    correct=$(python3 correct.py <<< $testcase)
    echo $testcase
    echo $output
    echo $correct

    if [[ $output != $correct ]]; then
        echo "You do something wrong"
        exit
    fi
done

echo "Good job"