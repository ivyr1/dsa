CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wshadow -Wconversion -g -fsanitize=address,undefined

# Trích xuất tên file truyền vào sau tên lệnh (run, new, aced)
COMMANDS := run new aced
FIRST_WORD := $(firstword $(MAKECMDGOALS))

ifneq ($(filter $(FIRST_WORD),$(COMMANDS)),)
  FILE_ARG := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # Tạo dummy target để make không báo lỗi khi nhận tên file
  $(eval $(FILE_ARG):;@:)
endif

.PHONY: run new aced FORCE

# 1. Build & Run
run:
	@if [ -z "$(FILE_ARG)" ]; then echo "Error: Missing filename. Usage: make run <file.cpp>"; exit 1; fi
	$(CXX) $(CXXFLAGS) $(FILE_ARG) -o ./leetcode
	./leetcode

# 2. Tạo file mới từ sample.cpp
new:
	@if [ -z "$(FILE_ARG)" ]; then echo "Error: Missing filename. Usage: make new <file.cpp>"; exit 1; fi
	cp sample.cpp $(FILE_ARG)
	@echo "=> Copied sample.cpp to $(FILE_ARG)"

# 3. Ghi nhận AC vào aced.txt
aced:
	@if [ -z "$(FILE_ARG)" ]; then echo "Error: Missing filename. Usage: make aced <file.cpp>"; exit 1; fi
	@echo "$$(date '+%Y-%m-%d %H:%M:%S') - $(FILE_ARG)" >> aced.txt
	@echo "=> Logged $(FILE_ARG) to aced.txt"

FORCE:
