# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 18:07:23 by gboutin           #+#    #+#              #
#    Updated: 2019/03/14 11:44:49 by gboutin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fdf
CFLAGS = -Wall -Wextra -Werror
MLX	= -framework OpenGL -framework AppKit -lmlx -L /usr/local/lib/
LIBFT = @cd ../libft_perso && make
LIBFTFILES = ../libft_perso/libft.a
OBJDIR = ./obj/
SRCDIR = ./src/
HDRDIR = ./include/
RED =		\033[1;31m
CYAN =		\033[1;36m
GREEN =		\033[1;32m
NO_COLOR =	\033[0m
SRCS =	test.c \
		main.c \
		parse.c \
		bresenham.c \
		pensive.c \
		grid.c \
		ft_commands.c

SRCFILES = $(addprefix $(SRCDIR), $(SRCS))
OBJFILES = $(addprefix $(OBJDIR), $(OBJ))
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HDRDIR)$(NAME).h
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(HDRDIR)
	@echo "$(CYAN)Compiling:\t\t$(GREEN)$<$(NO_COLOR)"

$(NAME): $(OBJFILES)
	$(LIBFT)
	@$(CC) -o $@ $(CFLAGS) $^ $(LIBFTFILES) $(MLX)
	@echo "$(CYAN)Executable:\t\t$(GREEN)[Done]$(NO_COLOR)"

clean:
	@/bin/rm $(OBJFILES)
	@cd ../libft_perso && make fclean

fclean: clean
	@/bin/rm $(NAME)
	@echo "$(RED)Deleted:\t\t$(NAME)$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
