g++ main.cpp -o main.o
g++ correct.cpp -o correct.o

for i in {1..1000}; do
    testcase=$(python3 rand.py)
    output=$(./main.o <<< $testcase)
    correct=$(./correct.o <<< $testcase)
    echo $testcase
    echo $output
    echo $correct

    if [[ $output != $correct ]]; then
        echo "You do something wrong"
        exit
    fi
done

echo "Good job"