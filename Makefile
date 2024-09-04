FLAGS = -Wall -Werror -Wextra -std=c11
OS := $(shell uname)
SOURCE = s21_help_func.c support.c s21_convert.c s21_arithmetic.c s21_other_func.c s21_oop.c s21_oop_big.c s21_comparison.c s21_decimal.h

ifeq ($(OS),Linux)
 OPEN_CMD = xdg-open
 ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURSE
endif

ifeq ($(OS),Darwin)
 OPEN_CMD = open
 ADD_LIB = -lcheck 
endif

all: clean s21_decimal.a test gcov_report

test: clean s21_decimal.a
	gcc $(FLAGS) tests/test.c s21_decimal.a -o test $(ADD_LIB)
	./test

s21_decimal.a:
	gcc -c $(FLAGS) $(SOURCE) 
	ar rcs s21_decimal.a *.o 

gcov_report: ${SOURCE}
	gcc --coverage ${SOURCE} ./tests/*.c -o s21_test $(ADD_LIB)
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

clean:
	rm -f test
	rm -f *.gc*
	rm -f s21_test.info
	rm -rf report
	rm -f *.o *.a
	rm -f s21_test

format:
	clang-format -style=Google -n *.c *.h tests/*.c

