# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:56:27 by cpeset-c          #+#    #+#              #
#    Updated: 2024/02/02 15:59:31 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME    	:= cub3D

MKFL		:= Makefile

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_CLR		:= \033[0;39m
GRAY		:= \033[0;90m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
WHITE		:= \033[0;97m

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

INC_DIR	:= inc/
SRC_DIR	:= src/

PRS_DIR	:= $(SRC_DIR)parser/

OBJ_DIR	:= .objs/
DEP_DIR	:= .deps/

LIBS	= library/
LIB_DIR	= $(LIBS)clift/
LFT_DIR	= $(LIB_DIR)libft/
OUT_DIR	= $(LIB_DIR)liboutput/
MLX_DIR	= minilibx/

# -=-=-=-=-	CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

UNAME	= $(shell uname -s)

CFLAGS		= -Wall -Wextra -Werror -W
# XFLAGS		= -fsanitize=address -g
DFLAGS		= -MT $@ -MMD -MP

ifeq ($(UNAME), Darwin)
	GFLAGS	= -framework OpenGL -framework Appkit -lm
	MLX_DIR	= ./$(LIBS)mlx_Darwin/
	INCLUDE	= -I$(INC_DIR) -I$(MLX_DIR)
	CC		= clang
else ifeq ($(UNAME), Linux)
	GFLAGS	= -L$(MLX_DIR) -lmlx -lX11 -lm -lXext 
	MLX_DIR	= ./$(LIBS)mlx_Linux/
	CC		= gcc
endif

AR		= ar -rcs
RM		= rm -f
MK		= mkdir -p
CP		= cp -f

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBRARY	= $(LIB_DIR)libft.a $(LIB_DIR)liboutput.a $(MLX_DIR)libmlx.a

INCLUDE	= -I$(INC_DIR) -I$(MLX_DIR) \
			-I$(LFT_DIR)$(INC_DIR) -I$(OUT_DIR)$(INC_DIR)

CUB_SRC	= main.c \
		reader.c \
		errors.c

CUB_PRS	= parse.c \
		prs_map.c \
		prs_map_data.c \

SRCS	+= $(addprefix $(SRC_DIR), $(CUB_SRC))
SRCS	+= $(addprefix $(PRS_DIR), $(CUB_PRS))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addprefix $(DEP_DIR), $(addsuffix .d, $(basename $(SRCS))))


# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: makelib $(NAME)
	
makelib:
	@$(MAKE) -sC $(MLX_DIR)
	@$(MAKE) -sC $(LIB_DIR)

$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(GFLAGS) $(LIBRARY) -o $(NAME)
	@printf "\n\t$(WHITE)Program \033[1;31m$(NAME) $(WHITE)has been compiled!$(DEF_COLOR)\n"

$(NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31m$(NAME)$(DEF_COLOR)\n"

clean:
	@$(MAKE) clean -C $(LIB_DIR)
# @$(MAKE) clean -C $(MLX_DIR)
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR)
	@echo "$(BLUE)	$(NAME) object and dependencies files cleaned.$(DEF_COLOR)"

fclean: 
# @$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR)
	@$(RM) $(NAME)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "$(GREEN)	Cleaned and rebuilt everything for $(NAME) project.$(DEF_COLOR)"

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MK) $(dir $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))
	@printf "\r$(GREEN)\tCompiling: $(YELLOW)$< $(DEF_CLR)                   \r"
	@$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))

-include $(DEPS)

.PHONY: all clean fclean re norm
