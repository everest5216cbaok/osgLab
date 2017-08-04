#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

#include <osg/Geode>
#include <osg/Group>
#include <osg/ShapeDrawable>

#include <iostream>

#include "models/node.h"
#include "models/stateset.h"
#include "shaders/viewer_light.h"
#include "callbacks/CameraGluLookAt.h"

int main(int argc, char** argv)
{
    osgViewer::Viewer viewer;

    //gen box
    R_Geometry rGeom = createNode();
    R_Geode rBox = new osg::Geode;
    rBox->addChild(rGeom);

    //R_Geode rBox = getBox_Geode_R();

    //set StateSet
    P_StateSet pStateSet = rBox->getOrCreateStateSet();
    
    setTransparencyStateSet(pStateSet);
    R_Program rProgram = getProgram(vs, fs);
    setProgramStateSet(pStateSet, rProgram);

    R_Uniform modelColor = new osg::Uniform("modelColor", osg::Vec3(1.0f, 0.0f, 0.0f));
    pStateSet->addUniform(modelColor);

    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild(rBox);

    osg::Camera* pCamera = viewer.getCamera();
    osg::Vec3 eye, center, up;

    pCamera->setUpdateCallback(new CameraCallback(viewer.getCamera()));

    //osg::ref_ptr<osg::Node> dt = osgDB::readRefNodeFile("dumptruck.osg");
    R_Geode dt = getBox_Geode_R();
    P_StateSet pStateSet2 = dt->getOrCreateStateSet();

    setTransparencyStateSet2(pStateSet2);


    viewer.setSceneData(dt);
    return viewer.run();
}
