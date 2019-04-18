# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 13:39:03 by gboutin           #+#    #+#              #
#    Updated: 2019/04/17 13:13:10 by gboutin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
CC = gcc
NAME = fdf
CFLAGS = -Wall -Wextra -Werror
MLX	= -framework OpenGL -framework AppKit -lmlx -L /usr/local/lib/
LIBFT = cd libft && make
LIBFTFILES = libft/libft.a
OBJDIR = ./obj/
SRCDIR = ./srcs/
HDRDIR = ./include/
RED =		\033[1;31m
CYAN =		\033[1;36m
GREEN =		\033[1;32m
NO_COLOR =	\033[0m
SRCS =	main.c \
		init.c \
		ft_function_move.c \
		ft_function_zoom.c \
		ft_change_view.c \
		ft_put_pixel.c \
		ft_change_z.c \
		bresenham.c \
		ft_commands.c \
		ft_store_prev_pos.c \
		parsing.c \
		parsing_2.c \

SRCFILES = $(addprefix $(SRCDIR), $(SRCS))
OBJFILES = $(addprefix $(OBJDIR), $(OBJ))
OBJ = $(SRCS:.c=.o)

all: $(NAME)
	make -C libft all

$(OBJDIR)%.o: $(SRCDIR)%.c $(HDRDIR)$(NAME).h
	mkdir -p obj/
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HDRDIR)
	echo "$(CYAN)Compiling:\t\t$(GREEN)$<$(NO_COLOR)"

$(NAME): $(OBJFILES)
	$(LIBFT)
	$(CC) -o $@ $(CFLAGS) $(MLX) $^ $(LIBFTFILES)
	echo "$(CYAN)Executable:\t\t$(GREEN)[Done]$(NO_COLOR)"

clean:
	$(RM) $(OBJFILES)
	cd libft && make fclean

fclean: clean
	$(RM) $(NAME)
	echo "$(RED)Deleted:\t\t$(NAME)$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
