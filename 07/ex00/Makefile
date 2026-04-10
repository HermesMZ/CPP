NAME = whatever
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD -MP

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SRCS = \
	main.cpp \

SRC_ALL = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SRC_ALL))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -I $(INCLUDE_DIR) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re