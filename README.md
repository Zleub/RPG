norminette:

```
#!/bin/zsh
FILES=$(ls -1 **/*.[ch] | grep -v "minilibx");
norminette $FILES
```
