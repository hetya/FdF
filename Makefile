# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hetya                                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 12:05:44 by hetya             #+#    #+#              #
#    Updated: 2022/02/12 18:25:51 by hetya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --> OS -------------------------------------------------------------------------
ifneq ($(OS), Windows_NT)
	OS_NAME = $(shell uname -s)
else
	OS_NAME = OS
endif

# --> PROGRAM --------------------------------------------------------------------

# ~~~~~~~~~~~~~~~~ SOURCES ~~~~~~~~~~~~~~~~

NAME = fdf
SRCS        	=	main.c \
					verif.c \
					create_window.c \
					utils.c \
					create_segment.c \
					parsing.c \
					utils_parsing.c \
					draw_map.c \
					key.c \
					pixel_put.c \
					rotation.c \
					color.c \
					ft_atoi_base.c

# SRC_PATH = src/
SRCS_PATH    	=    src

# ~~~~~~~~~~~~~~~~ OBJECTS ~~~~~~~~~~~~~~~~

#OBJ_PATH = obj/
OBJS_PATH    	=    objs
				

OBJS        	=    $(addprefix $(OBJS_PATH)/, $(SRCS:.c=.o))
# ~~~~~~~~~~~~~~~~ INCLUDES ~~~~~~~~~~~~~~~~

INCLUDES= fdf.h
INCLUDES_PATH = includes

# --> COMPILER AND FLAGS ---------------------------------------------------------

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -I./$(INCLUDES_PATH)
# FLAGS			+=	-Ofast -Wno-unused-result
# FLAGS			+=	-fsanitize=address -g


# --> LIBFT ----------------------------------------------------------------------

LIBFT			= libft
LIBRARY			= -L $(LIBFT) -lft
LIBFT_LIBRARY	= libft/libft.a

# --> MINILIBX -------------------------------------------------------------------

MLX_FOLDER		= ""
ifeq ($(OS_NAME), Linux)
	MLX_FOLDER	= minilibx_linux
else
	MLX_FOLDER	= minilibx_macos
endif

# --> TEST MODULE ----------------------------------------------------------------


# --> RULES ----------------------------------------------------------------------

all:    header lib $(NAME)

# ~~~~~~~~~~~~ COMPILING IN .o ~~~~~~~~~~~~

objs/%.o:	$(SRCS_PATH)/%.c $(INCLUDES_PATH)/$(INCLUDES) $(LIBFT_LIBRARY) Makefile
	mkdir -p $(dir $@);
	printf "%-62b%b" "$(CYAN)$(BOLD)compiling $(END)$<"
	$(CC) $(FLAGS) -c $< -o $@
	printf "$(GREEN)[✓]$(END)\n"

# ~~~~~~~ COMPILING THE EXECUTABLE ~~~~~~~~

$(NAME):	$(OBJS)
	printf "%-63b%b" "\n$(BOLD)$(GREEN)creating$(END) $@"
ifeq ($(OS_NAME), Linux)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L$(MLX_FOLDER) -lmlx -lm  $(LIBRARY) -lbsd -lX11 -lXext
else
	$(CC) $(FLAGS) -Iincludes -I$(MLX_FOLDER) -L$(MLX_FOLDER) -lmlx -framework OpenGL -framework AppKit $(OBJS) $(LIBRARY) -o $(NAME)
endif
	printf "$(GREEN)[✓]$(END)\n\n\n"

# ~~~~~~~~~~ COMPILING THE LIBFT ~~~~~~~~~~

lib:
	printf "%-62b%b" "$(BOLD)$(PURPLE)compiling$(END) the $(LIBFT)"
	@$(MAKE) --no-print-directory -C $(LIBFT)
	printf "$(GREEN)[✓]$(END) \n\n\n"


# ~~~~~~~~~~~~ CLEANNING RULES ~~~~~~~~~~~~

clean:
	rm -rf $(OBJS_PATH)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

# ~~~~~~~~~~~~~~ REMAKE RULE ~~~~~~~~~~~~~~
re: fclean all

# --> HEADER ---------------------------------------------------------------------

header :
	@printf "      ___        _____          ___    \n"
	@printf "     /  /\      /  /::\        /  /\   \n"
	@printf "    /  /:/_    /  /:/\:\      /  /:/_  \n"
	@printf "   /  /:/ /\  /  /:/  \:\    /  /:/ /\ \n"
	@printf "  /  /:/ /:/ /__/:/ \__\:|  /  /:/ /:/ \n"
	@printf " /__/:/ /:/  \  \:\ /  /:/ /__/:/ /:/  \n"
	@printf " \  \:\/:/    \  \:\  /:/  \  \:\/:/   \n"
	@printf "  \  \::/      \  \:\/:/    \  \::/    \n"
	@printf "   \  \:\       \  \::/      \  \:\    \n"
	@printf "    \  \:\       \__\/        \  \:\   \n"
	@printf "     \__\/                     \__\/   \n"
	@printf "\n\n"


# --> COLOR --------------------------------------------------------------------

BLACK		:= ""
RED			:= ""
GREEN		:= ""
YELLOW		:= ""
BLUE		:= ""
PURPLE		:= ""
CYAN		:= ""
WHITE		:= ""
END			:= ""
UNDER		:= ""
BOLD		:= ""
rev			:= ""
END			:= ""

ifneq (,$(findstring 256color, ${TERM}))
	BLACK		:= $(shell tput -Txterm setaf 0)
	RED			:= $(shell tput -Txterm setaf 1)
	GREEN		:= $(shell tput -Txterm setaf 2)
	YELLOW		:= $(shell tput -Txterm setaf 3)
	BLUE		:= $(shell tput -Txterm setaf 4)
	PURPLE		:= $(shell tput -Txterm setaf 5)
	CYAN		:= $(shell tput -Txterm setaf 6)
	WHITE		:= $(shell tput -Txterm setaf 7)
	END			:= $(shell tput -Txterm sgr0)
	UNDER		:= $(shell tput -Txterm smul)
 	BOLD		:= $(shell tput -Txterm bold)
	rev			:= $(shell tput -Txterm rev)
endif

.PHONY: all clean fclean re
.SILENT:
