NAME = grav_sim
SRC =   cans_main.c\
		key_hooks.c\
        mouse_hooks.c\
        object_operations.c\
        ft_hash.c\
        ft_rand.c\
		ft_randint.c
OFILES = $(SRC:.c=.o)

LIBFT = libs/libft/
MLX = libs/minilibx/
LIBG = libs/libg/

LIBS = -L $(LIBFT) -lft
LIBS += -L $(MLX) -lmlx -framework OpenGL -framework AppKit
LIBS += -L $(LIBG) -lgraphics

LIBI = -I $(LIBFT)
LIBI += -I $(MLX)
LIBI += -I $(LIBG)
LIBI += -I includes/

all: $(NAME)

$(NAME): dependencies
	gcc -Wall -Wextra -Werror -c $(SRC) $(LIBI)
	gcc -o $(NAME) $(OFILES) $(LIBS)

clean:
	rm -rf $(OFILES)
	make -C $(MLX) clean
	make -C $(LIBG) clean
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBG) fclean
	make -C $(LIBFT) fclean

re: fclean all

dependencies:
	make -C $(MLX)
	make -C $(LIBFT)
	make -C $(LIBG)
