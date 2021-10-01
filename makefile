.PHONY: clean build test coverage

MAKE_FLAGS=-j $$(nproc)

# ============================================================================ #
#  BUILD
# ============================================================================ #
build:
	@mkdir -p build/ && cd build/ && cmake -D CMAKE_BUILD_TYPE=Release ..

# ============================================================================ #
#  clean
# ============================================================================ #
clean:
	@rm -r -f build/

# ============================================================================ #
#  TEST
# ============================================================================ #
TEST_C_FLAGS = "-g -O2"

test:
	@mkdir -p build/
	@cd build/ && cmake -D CMAKE_BUILD_TYPE=Debug -D CMAKE_C_FLAGS=$(TEST_C_FLAGS) -D CMAKE_CXX_FLAGS=$(TEST_C_FLAGS) ..
	@cd build/ && make $(MAKE_FLAGS) test_unit
	@./build/test/test_unit --reporter=info --colorizer=light

# ============================================================================ #
#  MAIN for console debugging
# ============================================================================ #
main:
	@mkdir -p build/
	@cd build/ && cmake -D CMAKE_BUILD_TYPE=Debug ..
	@cd build/ && make $(MAKE_FLAGS) qs_main
	@echo "" && echo ""
	@./build/src/qs_main
