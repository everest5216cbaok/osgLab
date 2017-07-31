#ifndef _NODE_H_
#define _NODE_H_

#include "typedef.h"

R_Geode getBox_Geode_R()
{
    R_Geode boxGeode = new osg::Geode;
    R_ShapeDrawable boxShape = new osg::ShapeDrawable;
    boxShape->setShape(new osg::Box(osg::Vec3(0.0f, 0.0f, 0.0f), 1.0f, 1.0f, 1.0f));
    boxGeode->addDrawable(boxShape);

    return boxGeode;
}



#endif //_NODE_H_