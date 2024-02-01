# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:56:27 by cpeset-c          #+#    #+#              #
#    Updated: 2024/02/01 16:07:47 by cpeset-c         ###   ########.fr        #
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
SRC_DIR	:= srcs/
TUL_DIR	:= tools/
UTL_DIR	:= utils/

MAP_DIR	:= $(TUL_DIR)map_read/
PRS_DIR	:= $(TUL_DIR)map_parser/
HUK_DIR	:= $(TUL_DIR)cub_hooks/
PLY_DIR	:= $(TUL_DIR)player/
RAY_DIR	:= $(TUL_DIR)ray/

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

CUB_SRC	= cub3d.c \
		cub3d_init_vals.c \
		cub3d_init_imgs.c \
		cub3d_init_player.c

CUB_MAP	= cub_map.c \
		cub_map_utils.c

CUB_PRS	= cub_parser.c \
		cub_parser_utils.c  \
		cub_parser_textures.c \
		cub_parser_textures_utils.c \
		cub_parser_colours.c \
		cub_parser_map.c \
		cub_parser_map_expander.c \
		cub_parser_map_validation.c \
		cub_parser_format_map.c

CUB_HUK	= key_hooks.c \
		mouse_hooks.c

CUB_PLY = player_move.c \
		player_rotate.c

CUB_RAY = ray_calc.c \
		ray_dda.c \
		draw.c

CUB_UTL = cub3d_utils.c \
		cub3d_errors.c

SRCS	+= $(addprefix $(SRC_DIR), $(CUB_SRC))
SRCS	+= $(addprefix $(MAP_DIR), $(CUB_MAP))
SRCS	+= $(addprefix $(PRS_DIR), $(CUB_PRS))
SRCS	+= $(addprefix $(HUK_DIR), $(CUB_HUK))
SRCS	+= $(addprefix $(PLY_DIR), $(CUB_PLY))
SRCS	+= $(addprefix $(RAY_DIR), $(CUB_RAY))
SRCS	+= $(addprefix $(UTL_DIR), $(CUB_UTL))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addprefix $(DEP_DIR), $(addsuffix .d, $(basename $(SRCS))))


# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: makelib $(NAME)
	
makelib:
	@$(MAKE) -sC $(MLX_DIR)
	@$(MAKE) -sC $(LIB_DIR)

$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(GFLAGS) $(LIBRARY) -o $(NAME)
	@printf "\n\t$(WHITE)Program \033[1;31mCub3D $(WHITE)has been compiled!$(DEF_COLOR)\n"

$(NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31mCub3D$(DEF_COLOR)\n"

clean:
	@$(MAKE) clean -C $(LIB_DIR)
# @$(MAKE) clean -C $(MLX_DIR)
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR)
	@echo "$(BLUE)	Cub3D object and dependencies files cleaned.$(DEF_COLOR)"

fclean: 
# @$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR) $(BIN_DIR)
	@$(RM) $(NAME)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "$(GREEN)	Cleaned and rebuilt everything for Cub3D project.$(DEF_COLOR)"

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MK) $(dir $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))
	@printf "\r$(GREEN)\tCompiling: $(YELLOW)$< $(DEF_CLR)                   \r"
	@$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))

-include $(DEPS)

.PHONY: all clean fclean re norm
