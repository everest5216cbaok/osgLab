#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osg/Program>

typedef osg::ref_ptr<osg::Geode> R_Geode;
typedef osg::ref_ptr<osg::ShapeDrawable> R_ShapeDrawable;
typedef osg::ref_ptr<osg::Group> R_Group;
typedef osg::ref_ptr<osg::Program> R_Program;
typedef osg::ref_ptr<osg::Uniform> R_Uniform;

typedef osg::StateSet* P_StateSet;


#endif //_TYPEDEF_H_