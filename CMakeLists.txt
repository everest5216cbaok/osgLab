cmake_minimum_required( VERSION 2.6 )

set(MyPROJECT OsgLab)

project( OsgLab )
find_package( OpenThreads )
find_package( osg )
find_package( osgDB )
find_package( osgUtil )
find_package( osgViewer )
macro( config_project PROJNAME LIBNAME )
include_directories( ${${LIBNAME}_INCLUDE_DIR} )
target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY_DEBUG} 
								   #optimized ${${LIBNAME}_LIBRARY}
								)
endmacro()
add_executable( OsgLab main.cpp )
config_project( OsgLab OPENTHREADS )
config_project( OsgLab OSG )
config_project( OsgLab OSGDB )
config_project( OsgLab OSGUTIL )
config_project( OsgLab OSGVIEWER )
config_project( OsgLab OSGTEXT )
config_project( OsgLab OSGGA )

target_link_libraries( OsgLab
    opengl32
)