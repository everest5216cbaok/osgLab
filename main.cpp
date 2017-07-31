#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

#include <osg/Geode>
#include <osg/Group>
#include <osg/ShapeDrawable>

#include "models/node.h"
#include "models/stateset.h"
#include "shaders/viewer_light.h"

void modelConfig()
{
    
}

int main(int argc, char** argv)
{
    osgViewer::Viewer viewer;

    //gen box
    R_Geode rBox = getBox_Geode_R();
    //set StateSet
    P_StateSet pStateSet = rBox->getOrCreateStateSet();
    
    setTransparencyStateSet(pStateSet);
    R_Program rProgram = getProgram(vs, fs);
    setProgramStateSet(pStateSet, rProgram);

    R_Uniform modelColor = new osg::Uniform("modelColor", osg::Vec3(1.0f, 0.0f, 0.0f));
    pStateSet->addUniform(modelColor);

    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild(rBox);

    viewer.setSceneData(root);
    return viewer.run();
}
