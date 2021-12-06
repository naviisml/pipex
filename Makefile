NAME = pipex

AR = @ar
AR_FLAGS = -rcs

COMPILER = @gcc
COMPILER_FLAGS = -Wall -Werror -Wextra

# Configuration...
TEST_COMMAND 	= 	./$(NAME) resources/input cmd1 cmd2 cmd3 cmd4 cmd5 cmd6 resources/output

# Library...
LIBRARY			=	libft.a
LIBRARY_FOLDER	=	./libft

# Source Files...
SOURCE_FOLDER	=	./srcs
SOURCE_FILES	=	utils/debug.c \
					utils/utils.c \
					utils/file.c \
					pipex.c

# Header Files...

# Object Files...
EXTRA_FOLDERS	=	$(SOURCE_FOLDER)
OBJECT_FOLDER	=	../objects
OBJECT_FILES	=	$(addprefix $(OBJECT_FOLDER)/, $(addprefix $(SOURCE_FOLDER)/, $(SOURCE_FILES:.c=.o)))

.PHONY =  $(NAME) $(LIBRARY) all clean fclean re dev

# Compile the .c files to .o files...
$(OBJECT_FOLDER)/%.o: %.c
	@mkdir -p $(OBJECT_FOLDER) $(addprefix $(OBJECT_FOLDER)/, $(dir $<))
	@echo "Compiling \t$(notdir $<) (100%)"
	@$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

# Compile the program...
$(NAME): $(LIBRARY) $(OBJECT_FILES)
	@echo "Building \t$(NAME)... (100%)"
	$(COMPILER) $(COMPILER_FLAGS) $(OBJECT_FILES) $(LIBRARY) -o $(NAME)

# Compile a library...
$(LIBRARY):
	@echo "Compiling \t$(LIBRARY)..."
	@$(MAKE) bonus -C $(LIBRARY_FOLDER)
	@mv $(addprefix $(LIBRARY_FOLDER)/, $(LIBRARY)) $(LIBRARY)

# Compile the entire project
all: $(NAME)

# Remove the `object` folder and files...
clean:
	@$(MAKE) clean -C $(LIBRARY_FOLDER)
	@rm -rf $(OBJECT_FILES) $(OBJECT_FOLDER)

# Remove the `object` and `build` folder and files...
fclean: clean
	@$(MAKE) fclean -C $(LIBRARY_FOLDER)
	@rm -rf $(NAME) $(LIBRARY)

# Clean the program up and re-compile it...
re: fclean all

# Run a test
test: all
	@echo "Running \t[$(TEST_COMMAND)]..."
	@$(TEST_COMMAND)