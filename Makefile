PROGRAM_STD		= 	std
PROGRAM_FT		= 	ft

SRCS			= 	main.cpp
OBJS			=	$(SOURCE:.cpp=.o)
OUTPUT_FILES    =   ft_output.txt std_output.txt diff.txt output.txt

COMPILE			= 	g++

FLAGS_STD		= 	-Wall -Wextra -Werror -std=c++98 -D STD_OPTION=1
FLAGS_FT		= 	-Wall -Wextra -Werror -std=c++98 -D STD_OPTION=0

all: $(PROGRAM_STD) $(PROGRAM_FT)

$(PROGRAM_STD): $(OBJS)
	@$(COMPILE) $(FLAGS_STD) $(SRCS) -o $(PROGRAM_STD)

$(PROGRAM_FT): $(OBJS)
	@$(COMPILE) $(FLAGS_FT) $(SRCS) -o $(PROGRAM_FT)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(PROGRAM_STD) $(PROGRAM_FT) $(OUTPUT_FILES)

re: fclean all

.PHONY: all clean fclean re