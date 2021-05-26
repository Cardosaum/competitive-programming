##
# C++ template
#
# @author Matheus Cardoso
# @file
# @version 0.1

SHELL := /bin/bash
TEMPLATE_DIR = .templates
MAIN_CPP = main.cpp

# credit: https://stackoverflow.com/a/14061796
# If the first argument is "input_test"...
ifeq (input_test,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "input_test"
  INPUT_TEST_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(INPUT_TEST_ARGS):;@:)
endif

.PHONY: all test input_test clean

all: main.cpp

main: main.cpp
	@g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -fno-sanitize-recover \
        -fstack-protector -fsanitize=undefined -pedantic -Wformat=2 \
        -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2  \
        -Wduplicated-cond -Wcast-qual -Wcast-align -fsanitize=address \
        -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -D_GLIBCXX_DEBUG \
        -o "main" "main.cpp"

test: main
	@cat "${in}" | ./main

input_test: main
	@cat "${INPUT_TEST_ARGS}" | ./main

clean:
	rm main

# end
