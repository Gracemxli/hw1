grade:
	g++ ulliststr.cpp grade_ulliststr.cpp -o grade_ulliststr `pkg-config --cflags --libs gtest` -std=c++14 -g
rungrade:
	./grade_ulliststr
all0:
	g++ ulliststr.cpp test_ulliststr.cpp -o test_ulliststr -g
run0:
	./test_ulliststr
gradesplit:
	g++ split.cpp grade_split.cpp -o grade_split `pkg-config --cflags --libs gtest` -std=c++14 -g
rungradesplit:
	./grade_split