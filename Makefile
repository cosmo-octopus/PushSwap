NAME			= push_swap
BONUS			= checker
SRC_DIR 		= src
SRCS			= $(wildcard $(SRC_DIR)/*.c)
MAIN_SRCS		= $(filter-out $(SRC_DIR)/checker_bonus.c, $(SRCS))
B_SRCS			= $(filter-out $(SRC_DIR)/push_swap.c, $(SRCS))
HEADERS			= $(wildcard includes/*.h) Makefile
OBJ_DIR			= obj/main
B_OBJ_DIR		= obj/checker
OBJ_ROOT_DIR	= obj
INCS			= -Iincludes
MAIN_OBJS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(MAIN_SRCS))
B_OBJS			= $(patsubst $(SRC_DIR)/%.c, $(B_OBJ_DIR)/%.o, $(B_SRCS)) 
CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MK				= mkdir -p

all:			$(OBJ_DIR) $(NAME)

$(OBJ_DIR): $(SRC_DIR)
	$(MK) $(OBJ_DIR)

$(B_OBJ_DIR): $(SRC_DIR)
	$(MK) $(B_OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(B_OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(MAIN_OBJS)
				$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(MAIN_OBJS)

bonus: $(B_OBJ_DIR) $(OBJ_DIR) 	$(BONUS)

$(BONUS):	$(B_OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(BONUS) $(B_OBJS)

clean:			
				$(RM) $(OBJ_ROOT_DIR)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(BONUS)

re:				fclean all bonus

.PHONY:			all clean fclean re bonus

