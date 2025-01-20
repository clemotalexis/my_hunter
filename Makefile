##
## EPITECH PROJECT, 2024
## my_hunter
## File description:
## Makefile
##

CC = gcc

SRC	=	main.c										\
		src/events/event_game.c						\
		src/events/event_menu.c						\
		src/events/event_options.c					\
		src/events/update_view.c					\
		src/events/get_corrected_mouse_position.c	\
		src/display/display_game.c					\
		src/display/display_menu.c					\
		src/display/display_options.c				\
		src/clock/clock.c							\
		src/set_all/set_all.c						\
		src/set_all/set_window.c					\
		src/set_all/set_mob.c						\
		src/set_all/set_cursor.c					\
		src/set_all/set_music.c						\
		src/set_all/set_back_menu.c					\
		src/set_all/set_back_game.c					\
		src/set_all/set_buttons.c					\
		src/set_all/set_view.c						\
		src/set_all/set_text.c						\
		src/end_game/destroy_end_game.c				\
		src/lib/int_to_char.c						\
		src/lib/my_strcmp.c							\

OBJ = $(SRC:.c=.o)

NAME	=	my_hunter

CSFMLFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

CFLAGS = -I./include

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CSFMLFLAGS)

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)
	rm -rf $(OBJ)

re:	fclean all
