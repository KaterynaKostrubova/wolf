NAME = wolf3d

SRC_PATH = srcs
SRC_NAME = main.c\
			valid.c\
			help.c\
		# algoritm.c\
		# mouse.c\
		# action.c\
		# calc_texture.c\
		# help.c\
		# hook.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc -g
FLAGS = -Wall -Werror -Wextra

# LIBS = -F./frameworks \
# 		-rpath ./frameworks \
# 		-framework SDL2 -framework SDL2_ttf -framework SDL2_image \

# INCL = -I./frameworks/SDL2.framework/Versions/A/Headers \
# 		-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
# 		-I./frameworks/SDL2_image.framework/Versions/A/Headers \

INCL = -I include -I /usr/locale/include

LIBS =  -L libft -lmlx -framework OpenGL -framework AppKit

LIBFT =	libft/libft.a

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all:  $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LIBS) $(LIBFT)  $^ -o $@
	@afplay sound/enclume.mp3 &
	@echo "\033[1;33mCompilation of Wolf3d:\033[m	\033[1;32mOK\033[m"
	
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $< $(INCL) -o $@

$(LIBFT):
		@make -C libft

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make clean -C  libft
	@afplay sound/del.mp3 &
	@echo "\033[1;35mWolf3d:	Removing Obj\033[m    \033[1;31mOK\033[m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "\033[1;35mWolf3d:	Removing Wolf3d\033[m \033[1;31mOK\033[m"

re: fclean all

.PHONY: all clean fclean re libft