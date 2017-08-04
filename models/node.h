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



R_Geometry createNode()
{
    osg::ref_ptr<osg::Geode> geode = new osg::Geode();

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8);
    (*vertices)[0].set(-0.5f, -0.5f, 0.5f);
    (*vertices)[1].set(0.5f, -0.5f, -0.5f);
    (*vertices)[2].set(0.5f, -0.5f, 0.5f);
    (*vertices)[3].set(-0.5f, -0.5f, -0.5f);
    (*vertices)[4].set(-0.5f, 0.5f, 0.5f);
    (*vertices)[5].set(0.5f, 0.5f, 0.5f);
    (*vertices)[6].set(-0.5f, 0.5f, -0.5f);
    (*vertices)[7].set(0.5f, 0.5f, -0.5f);

    osg::ref_ptr<osg::DrawElementsUInt> indices =
        new osg::DrawElementsUInt(GL_TRIANGLES, 36);
    (*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2;
    (*indices)[3] = 0; (*indices)[4] = 3; (*indices)[5] = 1;
    (*indices)[6] = 4; (*indices)[7] = 2; (*indices)[8] = 5;
    (*indices)[9] = 4; (*indices)[10] = 0; (*indices)[11] = 2;
    (*indices)[12] = 6; (*indices)[13] = 5; (*indices)[14] = 7;
    (*indices)[15] = 6; (*indices)[16] = 4; (*indices)[17] = 5;

    (*indices)[18] = 3; (*indices)[19] = 7; (*indices)[20] = 1;
    (*indices)[21] = 3; (*indices)[22] = 6; (*indices)[23] = 7;

    (*indices)[24] = 5; (*indices)[25] = 2; (*indices)[26] = 1;
    (*indices)[27] = 5; (*indices)[28] = 1; (*indices)[29] = 7;

    (*indices)[30] = 4; (*indices)[31] = 3; (*indices)[32] = 0;
    (*indices)[33] = 4; (*indices)[34] = 6; (*indices)[35] = 3;




    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
    geom->setVertexArray(vertices.get());
    geom->addPrimitiveSet(indices.get());
    
    return geom;
}

#endif //_NODE_H_