NAME = fdf

SRC = \
./draw.c \
./file_read.c \
./keys.c \
./errors.c \
./main_fdf.c \

OUT = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L minilibx/ -lmlx -I /usr/local/X11/include -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

LIBFLGS =  -L./minilibx -lmlx -framework OpenGL -framework AppKit

LIBDIR = libft

LIB = libft/libft.a

HDR = libft/

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBDIR)
	gcc -c $(SRC)
	gcc $(FLAGS) $(LIB) $(OUT) $(LIBFLAGS) -I $(HDR) -o $(NAME)

school:
	$(MAKE) -C $(LIBDIR)
	gcc -c $(SRC)
	gcc $(FLAGS) $(LIB) $(OUT) $(LIBFLGS) -I $(HDR) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBDIR)
	/bin/rm -rf $(OUT)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
