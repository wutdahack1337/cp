gcc main.c -o main -lm
gcc correct.c -o correct -lm

for i in {1..333}; do
    testcase=$(python3 rand.py > input.txt)
    output=$(./main < input.txt)
    ans=$(./correct < input.txt)
    cat input.txt
    echo $output
    echo $ans

    if [[ $output != $ans ]]; then
        echo "Something goes wrong"
        exit 1
    fi
done

echo "Good job!"