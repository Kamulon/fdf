# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 16:07:36 by cperegri          #+#    #+#              #
#    Updated: 2022/03/10 20:54:17 by cperegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fdf

CC					=	gcc
FLAGS				=	-Wall -Werror -Wextra -O3
LIBRARIES 			=	-lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES			=	-I$(HDRS_DIR) -I$(LIBFT_HDRS) -I$(MINILIBX_HDRS)

LIBFT				=	$(LIBFT_DIR)libft.a
LIBFT_DIR			=	./sources/libft/
LIBFT_HDRS			=	$(LIBFT_DIR)includes/

MINILIBX			=	$(MINILIBX_DIR)libmlx.a
MINILIBX_DIR		=	./minilibx_macos/
MINILIBX_HDRS		=	$(MINILIBX_DIR)

HDRS				=	fdf.h\

HDRS_DIR			=	./includes/
HEADERS				=	$(addprefix $(HDRS_DIR), $(HDRS))

SRCS_DIR			=	./sources/
SRCS				=	main.c				\
						list_grid_system.c	\
						simple_maths.c		\
						data_and_read.c		\
						draw_system_0.c		\
						draw_system_1.c		\
						control_system_0.c	\
						control_system_1.c	\
						control_system_2.c	\
						
SOURCES 			=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS_DIR 			= 	objects/
OBJS 				= 	$(patsubst %.c, %.o, $(SRCS))
OBJECTS				= 	$(addprefix $(OBJS_DIR), $(OBJS))

.PHONY: all clean fclean re

all					:	$(NAME)

$(NAME)				:	$(LIBFT) $(MINILIBX) $(OBJS_DIR) $(OBJECTS)
						$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJS_DIR):
						mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o 		:	$(SRCS_DIR)%.c $(HEADERS)
						$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
						

$(LIBFT)			:
						$(MAKE) -sC $(LIBFT_DIR)

$(MINILIBX)			:
						$(MAKE) -sC $(MINILIBX_DIR)

clean				:
						$(MAKE) -sC $(LIBFT_DIR) clean
						$(MAKE) -sC $(MINILIBX_DIR) clean
						rm -rf $(OBJS_DIR)

fclean				:	clean
						rm -f $(MINILIBX)
						rm -f $(LIBFT)
						rm -f $(NAME)

re					:
						$(MAKE) fclean
						$(MAKE) all