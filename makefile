OK_COLOR = \033[0;32m

SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

BUILD0 = @g++ -o $@ -c $? -w
BUILD1 = @printf "%s compiled\n" $@

a.out: $(OBJ)
	@g++ -o $@ $^ -lncurses -w
	@printf "%b" "$(OK_COLOR)compil success\n"

%.o : %.cc
	$(BUILD0)
	$(BUILD1)

clean:
	@rm -rf a.out
	@rm -f *.o
	@printf "clean success\n"