cd $(System.DefaultWorkingDirectory)/testes
make all

cd $(System.DefaultWorkingDirectory)/bin
./Test_CThread.exe --pnpcunit-test --junit
result=$?

cd $(System.DefaultWorkingDirectory)/testes
make clean

if [ $result == 0 ]; then exit 0
else exit 1
fi
