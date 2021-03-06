# Learning OpenGL with GLFW framework #

## [LearnOpenGL](https://learnopengl.com/) ##

Install [GLFW framework](https://www.glfw.org/)

Install GLAD `headers` to `/usr/include` or put them elsewhere and adjust the `Makefile` for GCC to find them.

The following link was used to generate the GLAD headers. [GLAD Permalink](https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3D1.0&api=gles2%3D3.2&api=glsc2%3Dnone&profile=core&loader=on)

Install [GLM](https://github.com/g-truc/glm)

## Client API ##
- Edit `init.cpp` with appropriate <b>GLFW_CONTEXT_VERSION_MAJOR</b> and <b>GLFW_CONTEXT_VERSION_MINOR</b> values.<p>
- Edit vertexShaderSource and fragmentShaderSource `#version xxx core`

## Build ##
Run `make clean` to clean the build.

Run `make` to build the source.

Run `./main` and should see a GL window (provided all the deps are installed)

Run `make run` to clean, build and run.

## For a new project ##
Put GLAD ```glad.c``` into your project's main directory with the Makefile.
