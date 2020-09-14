NON_RECURSIVE = 0
TARGET := bubble_sort quick_sort merge_sort heap_sort

all: $(TARGET)

$(TARGET):
ifeq ($(NON_RECURSIVE),1)
	g++ -std=c++11 -DNON_RECURSIVE -o $@ main.cpp $@.cpp
else
	g++ -std=c++11 -o $@ main.cpp $@.cpp
endif

test: $(TARGET)
	@for n in 1 2 3 4 5 6 7 8 9; do \
		echo "========== Unit Test $$n =========="; \
		for prog in $?; do \
			./$$prog --test < ../test/unit$$n.txt; \
		done \
	done

benchmark: $(TARGET)
	@for n in 1 2 3; do \
		echo "========== Benchmark $$n =========="; \
		for prog in $?; do \
			echo "$$prog:"; \
			time -p ./$$prog < ../benchmark/input$$n.txt; \
			echo ""; \
		done \
	done

clean:
	rm -f $(TARGET)
