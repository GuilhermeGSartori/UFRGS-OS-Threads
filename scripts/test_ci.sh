cd ../testes
make all

cd ../bin
./Test_CThread.exe --pnpcunit-test --junit
result=$?

cd ../testes
make clean

if [ $result == 0 ]; then exit 0
else exit 1
fi
