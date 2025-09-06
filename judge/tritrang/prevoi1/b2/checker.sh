gcc main.c -o main
gcc correct.c -o correct

for i in {1..1000}; do
    testcase=$(python3 rand.py > input.txt)
    output=$(./main < input.txt)
    correct=$(./correct < input.txt)
    cat input.txt
    echo $output
    echo $correct

    if [[ $output != $correct ]]; then
        echo "You do something wrong"
        exit
    fi
done

echo "Good job"