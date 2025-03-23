# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 11:15:07 by ayasar            #+#    #+#              #
#    Updated: 2025/03/13 11:21:26 by ayasar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

PRINTF_DIR	= ./ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

GNL_DIR		= ./get_next_line
GNL			= $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

MLX_DIR		= ./minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

SRC			= check_map_helper_functions.c\
			  check_map.c\
			  find_comp_loc.c\
			  free.c\
			  game_starter.c\
			  main.c\
			  map_path_check.c\
			  map_utils.c\
			  mlx_cleanup.c\
			  mlx_operations.c\
			  $(GNL)

OBJS		= $(SRC:.c=.o)

INCLUDE		= -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GNL_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX_LIB)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME) compiled successfully."

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@echo "Compiling ft_printf..."
	@make -C $(PRINTF_DIR)

$(MLX_LIB):
	@echo "Compiling minilibx..."
	@make -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "Object files cleaned."

fclean: clean
	@echo "Cleaning executable..."
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@echo "Executable cleaned."

re: fclean all

.PHONY: all clean fclean re
