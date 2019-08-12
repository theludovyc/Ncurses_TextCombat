OK_COLOR = \033[0;32m

OBJ = entity.o entity_player.o

BUILD0 = @g++ -o $@ -c $< -w
BUILD1 = @printf "%s compiled\n" $@

a.out: $(OBJ)
	@g++ -o $@ main.cc $(OBJ) -lncurses -w
	@printf "%b" "$(OK_COLOR)compil success\n"

force: clean a.out

%.o : %.cc
	$(BUILD0)
	$(BUILD1)

clean:
	@rm -rf a.out
	@rm -f *.o
	@printf "clean success\n"