# fract-ol

```
open -a XQuartz
export DISPLAY=:0
xhost + localhost
```

```
valgrind --leak-check=full ./fractol Julia -0.4 0.6
```