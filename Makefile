# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:56:27 by cpeset-c          #+#    #+#              #
#    Updated: 2024/02/19 00:43:57 by cpeset-c         ###   ########.fr        #
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
UTL_DIR	:= $(SRC_DIR)basic_utils/
HKS_DIR	:= $(SRC_DIR)hooks/
RDR_DIR	:= $(SRC_DIR)render/
PLY_DIR	:= $(SRC_DIR)player/
TEX_DIR	:= $(SRC_DIR)textures/

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
XFLAGS		= -g3# -fsanitize=address
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
		graphics_init.c \
		errors.c

CUB_PRS	= parse.c \
		prs_file_data.c \
		prs_file_header.c \
		prs_file_body.c \
		prs_map.c \
		prs_map_data.c \
		prs_map_expander.c \
		prs_map_sanitizer.c \
		prs_map_validator.c \
		prs_clr.c \
		prs_txt.c

CUB_HKS = hooks.c \
		hooks_keys_press.c \
		hooks_keys_release.c \
		hooks_mouse_press.c \
		hooks_mouse_release.c \
		hooks_utils.c

CUB_RDR = render.c \
		ray_calc.c \
		ray_dda.c \
		ray_pixel_calc.c

CUB_PLY = player_init.c \
		player_move.c \
		player_rotate.c

CUB_TEX = texture_init.c \
		texture.c
		
CUB_UTL = inclusive_split.c \
		ft_strncpy.c \
		ft_strnchr.c \
		is_spc.c \
		ft_put_pixel.c

SRCS	+= $(addprefix $(SRC_DIR), $(CUB_SRC))
SRCS	+= $(addprefix $(PRS_DIR), $(CUB_PRS))
SRCS	+= $(addprefix $(UTL_DIR), $(CUB_UTL))
SRCS	+= $(addprefix $(HKS_DIR), $(CUB_HKS))
SRCS	+= $(addprefix $(RDR_DIR), $(CUB_RDR))
SRCS	+= $(addprefix $(PLY_DIR), $(CUB_PLY))
SRCS	+= $(addprefix $(TEX_DIR), $(CUB_TEX))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addprefix $(DEP_DIR), $(addsuffix .d, $(basename $(SRCS))))


# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: makelib $(NAME)
	
makelib:
	@$(MAKE) -sC $(MLX_DIR)
	@$(MAKE) -sC $(LIB_DIR)

$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) $(GFLAGS) $(LIBRARY) -o $(NAME)
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
	@$(CC) $(CFLAGS) $(XFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))

-include $(DEPS)

.PHONY: all clean fclean re norm
