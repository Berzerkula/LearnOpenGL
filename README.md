# Learning OpenGL with GLFW framework #

Install [GLFW framework](https://www.glfw.org/)

Install GLAD ```headers``` to ```/usr/include``` or put them elsewhere and adjust the ```Makefile``` for GCC to find them.

Run ```make``` to build the source.

Run ```./main``` and should see a GL window (provided all the deps are installed)

## For a new project ##
Put GLAD ```glad.c``` into your project's main directory with the Makefile.
