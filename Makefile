NAME = fdf

SRC = \
./draw.c \
./file_read.c \
./keys.c \
./main_fdf.c \

OUT = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBFLAGS = -lmlx -L./Users/zraunio/Desktop/HIVE/FDF/minilibx /Users/zraunio/Desktop/HIVE/FDF/minilibx/libmlx.a  -framework OpenGl -framework AppKit

LIBFLGS =  -L./minilibx -lmlx -framework OpenGL -framework AppKit

LIBDIR = libft

LIB = libft/libft.a

HDR = libft/

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBDIR)
	gcc -c $(SRC)
	gcc $(FLAGS) $(LIB) $(OUT) $(LIBFLGS) -I $(HDR) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBDIR)
	/bin/rm -f $(OUT)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
