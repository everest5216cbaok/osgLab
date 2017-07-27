This project is mainly used for shader test.
######################################################################
# platform
######################################################################
just test in window7

######################################################################
# build
######################################################################
before building this project(Target project), you should 
    1.set cmake CMAKE_INSTALL_PREFIX
    2.set environment variable OSG_ROOT( the same as CMAKE_INSTALL_PREFIX).
    3.construct openscenegraph solution
    4.run INSTALL project(There are two folders in the directory bin, include, lib)
    5.construct Target project by cmake
    6.build and run project