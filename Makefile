##
## EPITECH PROJECT, 2022
## zoijr
## File description:
## ouais
##

SRC		=	my_radar.c 					\
			setup.c 					\
			set_array.c 				\
			check_assets.c 				\
			set_sprite.c 				\
			update_plane_position.c 	\
			display_elements.c 			\
			collision.c 				\
			clean_my_radar.c 			\
			check_script.c 				\
			display_usage.c 			\
			display_error.c 			\
			display_board_instructions.c\
			collision_formula.c

OBJ		=	$(SRC:.c=.o)

NAME 	= 	my_radar

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
			-lm -L./lib/ -lmy

CFLAGS=	-I./include -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
