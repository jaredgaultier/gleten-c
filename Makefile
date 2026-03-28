CC = clang
CFLAGS = -Wall -Wextra -Iinclude -MMD -MP

NCURSES = -lncurses

STACK_TESTING_SRC = test/test-stack.c \
	src/gletenlibs/stack_panel.c

SRC = src/main.c \
	src/panel/panel.c \
	src/panel/cosmetic.c \
	src/panel/export-data.c \
	src/panel/input/input.c \
	src/panel/input/verify-input/in-command-list.c \
	src/panel/input/verify-input/verify.c \
	src/panel/input/verify-input/parameter-control.c \
	src/gletenlibs/stack_panel.c \
	src/gletenlibs/gleten-string/_gotoxy.c \
	src/gletenlibs/gleten-string/clear.c \
	src/gletenlibs/gleten-string/likeness.c \
	src/gletenlibs/gleten-string/remove-newline.c \
	src/gletenlibs/gleten-string/likeness-find.c

OBJ = $(SRC:.c=.o)
DOBJ = $(OBJ:.o=.d)

RM = rm -f

.PHONY: clean

program: $(OBJ)
	$(CC) $(NCURSES) $(OBJ) -o program


test_stack: $(STACK_TESTING_SRC)
	$(CC) $(STACK_TESTING_SRC) -o test_stack

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(DOBJ) program

-include $(OBJ:.o=.d)
