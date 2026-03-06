CC = clang
CFLAGS = -Wall -Wextra -Iinclude -MMD -MP

SRC = src/main.c \
	src/panel/panel.c \
	src/panel/cosmetic.c \
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
	$(CC) $(OBJ) -o program

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(DOBJ) program

-include $(OBJ:.o=.d)