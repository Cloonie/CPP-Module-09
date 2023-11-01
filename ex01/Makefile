COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

NAME		=	RPN
CC			=	g++
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-std=c++98
RM			=	rm -rf

SRCS		=	main.cpp	\
				RPN.cpp

OBJS		=	$(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(COLOUR_GREEN)"
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME): Executable sucessfully compiled.$(COLOUR_END)"

%.o : %.cpp
	@echo "$(COLOUR_BLUE)"
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@echo "$(COLOUR_RED)clean: Removing object files...$(COLOUR_END)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(COLOUR_RED)fclean: Removing program file...$(COLOUR_END)"
	@$(RM) $(NAME)

re:	fclean all