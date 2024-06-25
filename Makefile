#	colors	#

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
END= 	$(shell tput -Txterm sgr0)

#			#

NAME = so_long

CC = cc

MAKEFILE = ./Makefile

FLAGS = -Wall -Wextra -Werror -g3 -O3

MlX_FLAGS = -Lmlx -Imlx -lmlx -framework OpenGL -framework AppKit

GENERATOR_PATH = ./so_long_map_generator

GENERATOR_FILE = $(addprefix $(GENERATOR_PATH)/srcs/, main.c create_map.c place_sprite.c check_if_playable.c place_wall.c)

GENERATOR = $(GENERATOR_PATH)/so_long_generator

SRC_PATH = ./srcs

LIBFTPATH = libft

FILES = $(foreach dir, $(SRC_PATH), $(wildcard $(dir)/*c))

INCLUDE_PATH = ./includes

INCLUDES = -I/usr/include -lmlx -lft -I$(INCLUDE_PATH)

OBJ = $(FILES:.c=.o)

LIBFT = $(LIBFTPATH)/libft.a

LIBFT_FILES = 	$(wildcard $(LIBFTPATH)/*.c)	\

LIBMLX = libmx_linux.a

all : $(NAME)

$(NAME) :   $(LIBMLX) $(INCLUDE_PATH) $(LIBFT) $(OBJ)
			@$(CC) $(FLAGS) $(OBJ) $(INCLUDES) -L $(LIBFTPATH) -lft -L ./minilibx-linux -lmlx -lXext -lX11 -o $(NAME)
			@echo "$(GREEN)$(NAME) done ! ✅$(END)"

$(LIBMLX) :
			@make -C ./minilibx-linux


$(LIBFT) : $(LIBFT_FILES)
			@make -C $(LIBFTPATH)

%.o: %.c
		@$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
		@echo "$(BLUE)Compiling: $^$(END)"

clean :
			@make clean -C $(LIBFTPATH)
			@make clean -C ./minilibx-linux
			@make clean -C $(GENERATOR_PATH)
			@rm $(foreach dir, $(SRC_PATH), $(dir)/*.o)
			@echo "$(RED)remove objects 🚮$(END)"

fclean : clean
			@make fclean -C $(LIBFTPATH)
			@make fclean -C $(GENERATOR_PATH)
			@rm $(NAME)
			@echo "$(RED)remove $(NAME) 🚮$(END)"

re : fclean all

random : $(GENERATOR) $(NAME)
			@./so_long_map_generator/so_long_generator 40x21 15 random
			@./so_long random.ber

$(GENERATOR) :
			@make -C $(GENERATOR_PATH)