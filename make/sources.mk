SRCS += ./src/expand/expand.c
SRCS += ./src/expand/expand_utils.c
SRCS += ./src/exec/exec_path.c
SRCS += ./src/exec/exec_bltin.c
SRCS += ./src/exec/exec_check_redir.c
SRCS += ./src/exec/exec.c
SRCS += ./src/exec/exec_fork.c
SRCS += ./src/builtins/exit.c
SRCS += ./src/builtins/pwd.c
SRCS += ./src/builtins/env.c
SRCS += ./src/builtins/utils.c
SRCS += ./src/builtins/echo.c
SRCS += ./src/builtins/export.c
SRCS += ./src/builtins/unset.c
SRCS += ./src/builtins/cd.c
SRCS += ./src/heredoc/heredoc.c
SRCS += ./src/env/env_init.c
SRCS += ./src/env/env_modifs.c
SRCS += ./src/env/utils.c
SRCS += ./src/env/env_errors.c
SRCS += ./src/errors/errors.c
SRCS += ./src/parsing/mini_loop.c
SRCS += ./src/parsing/parser/redir_in_tree.c
SRCS += ./src/parsing/parser/_creating_nodes_utils.c
SRCS += ./src/parsing/parser/____parser.c
SRCS += ./src/parsing/parser/___node_functions.c
SRCS += ./src/parsing/parser/_creating_tree.c
SRCS += ./src/parsing/parser/link_functions_utils.c
SRCS += ./src/parsing/parser/complex_commands.c
SRCS += ./src/parsing/parser/link_functions.c
SRCS += ./src/parsing/parser/__creating_nodes.c
SRCS += ./src/parsing/parser/_single_command.c
SRCS += ./src/parsing/lexer/_token_functions.c
SRCS += ./src/parsing/lexer/creating_tokens_utils.c
SRCS += ./src/parsing/lexer/__lexer.c
SRCS += ./src/parsing/lexer/creating_tokens.c
SRCS += ./src/parsing/lexer/token_redir.c
SRCS += ./src/main/main.c
SRCS += ./src/main/clean_exit.c
