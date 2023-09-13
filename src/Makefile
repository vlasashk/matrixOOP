CXX 		= g++ 
CXXFLAGS 	= -std=c++17 -Wall -Werror -Wextra
TEST_LIBS 	= -lstdc++ -lm -lgtest -fsanitize=address
SOURCES 	= $(wildcard *.cpp)
OBJECTS 	= $(patsubst %.cpp, %.o, $(SOURCES))
EXECUTABLE 	= test
LIB 		= s21_matrix_oop.a
TESTS_DIR 	= Tests

all: test

build: $(LIB)
	$(CXX) $(CXXFLAGS) $(TESTS_DIR)/*.cpp $(LIB) -o $(EXECUTABLE) $(TEST_LIBS)
	
debug_flag:
	$(eval CXXFLAGS += -g)

gcov_flag:
	$(eval CXXFLAGS += --coverage)

gcov_report: clean gcov_flag test
	mkdir -p gcov
	lcov --ignore-errors mismatch -o coverage.info -c --directory . 
	genhtml coverage.info --output-directory gcov
	rm -rf *.gcno *.gcda *.gcov


$(LIB): $(OBJECTS)
	ar -rcs $(LIB) $(OBJECTS)
	ranlib $(LIB)


test: build
	./$(EXECUTABLE)
	rm -f *.o

debug: debug_flag build

valgrind:
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

clean:
	rm -rf *.a *.o $(TESTS_DIR)/*.o $(EXECUTABLE) *.a* *.gcno *.gcda *.gcov *.info gcov