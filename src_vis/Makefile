NAME := vkozhemi.visual

LIB_DIR := ../libftprintf/
SRC_DIR := 
OBJ_DIR := ./objects/
INC_DIR := ../includes/

SRCS := main2.c save_map.c
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC := gcc
FLAGS := -g -lmlx -framework OpenGL -framework AppKit 

LIBFT = $(LIB_DIR)libftprintf.a
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)includes

HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ $(CC) $(OBJ) $(FLAGS) $(HDR_FLAGS) -o $(NAME) $(LIBFT) -fsanitize=address

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

$(LIBFT):
	@ make -C $(LIB_DIR)

clean:
	@ make clean -C $(LIB_DIR)
	@ rm -f $(OBJ)
	

fclean:
	@ make fclean -C $(LIB_DIR)
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_DIR)

re: fclean all

test:
		./filler_vm -f maps/map01 -p2 players/abanlin.filler -p1 players/carli.filler

test00:
		./filler_vm -f maps/map00 -p2 players/abanlin.filler -p1 ./vkozhemi.filler

test10:
		./filler_vm -f maps/map01 -p2 players/abanlin.filler -p1 ./vkozhemi.filler

test20:
		./filler_vm -f maps/map02 -p2 players/abanlin.filler -p1 ./vkozhemi.filler

test01:
		./filler_vm -f maps/map00 -p2 players/carli.filler -p1 ./vkozhemi.filler

test11:
		./filler_vm -f maps/map01 -p2 players/carli.filler -p1 ./vkozhemi.filler

test21:
		./filler_vm -f maps/map02 -p2 players/carli.filler -p1 ./vkozhemi.filler

test02:
		./filler_vm -f maps/map00 -p2 players/champely.filler -p1 ./vkozhemi.filler

test12:
		./filler_vm -f maps/map01 -p2 players/champely.filler -p1 ./vkozhemi.filler

test22:
		./filler_vm -f maps/map02 -p2 players/champely.filler -p1 ./vkozhemi.filler

test03:
		./filler_vm -f maps/map00 -p2 players/grati.filler -p1 ./vkozhemi.filler

test13:
		./filler_vm -f maps/map01 -p2 players/grati.filler -p1 ./vkozhemi.filler

test23:
		./filler_vm -f maps/map02 -p2 players/grati.filler -p1 ./vkozhemi.filler

test04:
		./filler_vm -f maps/map00 -p2 players/hcao.filler -p1 ./vkozhemi.filler

test14:
		./filler_vm -f maps/map01 -p2 players/hcao.filler -p1 ./vkozhemi.filler

test24:
		./filler_vm -f maps/map02 -p2 players/hcao.filler -p1 ./vkozhemi.filler

test05:
		./filler_vm -f maps/map00 -p2 players/superjeannot.filler -p1 ./vkozhemi.filler

test15:
		./filler_vm -f maps/map01 -p2 players/superjeannot.filler -p1 ./vkozhemi.filler

test25:
		./filler_vm -f maps/map02 -p2 players/superjeannot.filler -p1 ./vkozhemi.filler




test002:
		./filler_vm -f maps/map00 -p1 players/abanlin.filler -p2 ./vkozhemi.filler

test102:
		./filler_vm -f maps/map01 -p1 players/abanlin.filler -p2 ./vkozhemi.filler

test202:
		./filler_vm -f maps/map02 -p1 players/abanlin.filler -p2 ./vkozhemi.filler

test012:
		./filler_vm -f maps/map00 -p1 players/carli.filler -p2 ./vkozhemi.filler

test112:
		./filler_vm -f maps/map01 -p1 players/carli.filler -p2 ./vkozhemi.filler

test212:
		./filler_vm -f maps/map02 -p1 players/carli.filler -p2 ./vkozhemi.filler

test022:
		./filler_vm -f maps/map00 -p1 players/champely.filler -p2 ./vkozhemi.filler

test122:
		./filler_vm -f maps/map01 -p1 players/champely.filler -p2 ./vkozhemi.filler

test222:
		./filler_vm -f maps/map02 -p1 players/champely.filler -p2 ./vkozhemi.filler

test032:
		./filler_vm -f maps/map00 -p1 players/grati.filler -p2 ./vkozhemi.filler

test132:
		./filler_vm -f maps/map01 -p1 players/grati.filler -p2 ./vkozhemi.filler

test232:
		./filler_vm -f maps/map02 -p1 players/grati.filler -p2 ./vkozhemi.filler

test042:
		./filler_vm -f maps/map00 -p1 players/hcao.filler -p2 ./vkozhemi.filler

test142:
		./filler_vm -f maps/map01 -p1 players/hcao.filler -p2 ./vkozhemi.filler

test242:
		./filler_vm -f maps/map02 -p1 players/hcao.filler -p2 ./vkozhemi.filler

test052:
		./filler_vm -f maps/map00 -p1 players/superjeannot.filler -p2 ./vkozhemi.filler

test152:
		./filler_vm -f maps/map01 -p1 players/superjeannot.filler -p2 ./vkozhemi.filler

test252:
		./filler_vm -f maps/map02 -p1 players/superjeannot.filler -p2 ./vkozhemi.filler