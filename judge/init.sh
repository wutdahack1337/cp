judge=$1
problemName=$2

echo "init $judge/$problemName/main.cpp"

mkdir -p $judge       && cd $judge
mkdir -p $problemName && cd $problemName

code main.cpp
echo "g++ main.cpp -o main.o && ./main.o" > run.sh
chmod 744 run.sh