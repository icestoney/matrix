.PHONY: all clean test s21_matrix.a gcov_report

CC := gcc
CC_FLAGS := -Wall -Werror -Wextra -pedantic -std=c11
GCOVR := gcovr
GCOVR_FLAGS := --html --html-details --html-medium-threshold 79.9 --html-high-threshold 80.0
COV_FLAGS = -fprofile-arcs -ftest-coverage -fPIC --coverage

CF := clang-format
STYLE_BASE := --style=Google

CPPFLAGS = --enable=all --suppress=missingIncludeSystem --std=c11 --check-config

VG := valgrind
VG_FLAGS := --tool=memcheck --leak-check=full --show-leak-kinds=all --log-file="valgrind.log"

SRC := $(wildcard ./s21_*.c)
HEADER := $(wildcard ./s21_matrix.h)
OBJ := $(patsubst %.c, %.o, $(SRC))
TEST_DIR := unit_tests
TEST_SRC := $(wildcard $(TEST_DIR)/s21_*.c)
TEST_HEADER := $(wildcard $(TEST_DIR)/s21_*.h)
TEST_TARGET := s21_matrix_tests

RM := rm -rf
KERNEL := $(shell uname -s)

ifeq ($(KERNEL), Linux)
	LIBS := -lcheck -lsubunit -lm
endif

ifeq ($(KERNEL), Darwin)
	LIBS := -lcheck
endif

all: clean s21_matrix.a

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(LIBS)

s21_matrix.a: $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

test: $(SRC) $(TEST_SRC) s21_matrix.a
	$(CC) $(CC_FLAGS) -g $^ -o $(TEST_DIR)/$(TEST_TARGET) $(LIBS)
	$(RM) *.o
	./$(TEST_DIR)/$(TEST_TARGET)

test_gcov: $(SRC) $(TEST_SRC) s21_matrix.a
	$(CC) $(CC_FLAGS) -g $(COV_FLAGS) $^ -o $(TEST_DIR)/$(TEST_TARGET) $(LIBS)
	./$(TEST_DIR)/$(TEST_TARGET)
	$(RM) *.o $(TEST_DIR)/$(TEST_TARGET)-s21_test*.gcno $(TEST_DIR)/$(TEST_TARGET)-s21_test*.gcda

gcov_report: clean test_gcov
	mkdir $@
	$(GCOVR) -d $(TEST_DIR) $(GCOVR_FLAGS) -o $@/report.html
	$(RM) $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno

clean:
	$(RM) $(OBJ) $(TEST_DIR)/*.o \
	$(TEST_DIR)/$(TEST_TARGET) \
	*.gcno $(TEST_DIR)/*.gcno *.gcda $(TEST_DIR)/*.gcda \
	gcov_report \
	*.a \
	valgrind.log

check_clang:
	clang-format $(STYLE_BASE) -n *.c *.h $(TEST_DIR)/*.c $(TEST_DIR)/*.h

fix_clang:
	clang-format $(STYLE_BASE) -i *.c *.h $(TEST_DIR)/*.c $(TEST_DIR)/*.h

cppcheck:
	cppcheck ${CPPFLAGS} .

valgrind: test
	valgrind $(VG_FLAGS) $(TEST_DIR)/$(TEST_TARGET)