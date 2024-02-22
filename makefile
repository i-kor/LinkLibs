main.exe: main.o
	g++ -o main.exe main.o -lglog -L"C:\\libs\\glog\\lib" -lgtest -L"C:\\libs\\gtest\\lib"
main.o: main.cpp main.h
# have to define GLOG_USE_GLOG_EXPORT to correctly use static library
	g++ -c main.cpp -I"C:\\libs\\glog\\include" -I"C:\\libs\\gtest\\include" -DGLOG_USE_GLOG_EXPORT