for i in {1..1000}; do
    python3 rand.py
    out=$(python3 1753.py < input.txt)
    correct=$(python3 correct.py < input.txt)
    cat input.txt
    echo $out
    echo $correct

    if [[ $out != $correct ]]; then
        echo "You do something wrong"
        exit
    fi
done

echo "Good job"