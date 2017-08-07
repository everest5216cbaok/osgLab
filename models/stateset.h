#ifndef _STATESET_H_
#define _STATESET_H_

#include <osg/CullFace>
#include <gl/GL.h>
#include <osg/BlendFunc>
#include <osg/Material>
#include <osg/LightModel>

#include "typedef.h"

R_Program getProgram(const char * vertexShader, const char * fragmentShader)
{
    osg::ref_ptr<osg::Program> program = new osg::Program;
    osg::ref_ptr<osg::Shader> vs = new osg::Shader(osg::Shader::VERTEX, vertexShader);
    osg::ref_ptr<osg::Shader> fs = new osg::Shader(osg::Shader::FRAGMENT, fragmentShader);
    program->addShader(vs);
    program->addShader(fs);

    return program;
}

void setTransparencyStateSet(P_StateSet pStateSet)
{
    pStateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
}

void setTransparencyStateSet2(P_StateSet pStateSet)
{
    pStateSet->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
    pStateSet->setAttribute(new osg::BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);

    osg::Material* material = new osg::Material;
    material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0.2f, 0.2f, 0.2f, 0.3f));
    material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0.8f, 0.8f, 0.8f, 0.3f));
    pStateSet->setAttribute(material, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);

    osg::LightModel* lm = new osg::LightModel();
    lm->setTwoSided(true);
    pStateSet->setAttribute(lm, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);

}

void setTransparencyStateSet3(P_StateSet pStateSet)
{
    // set the states of the truck so that it actually appears transparently and nicely lit.
    pStateSet->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
    pStateSet->setAttribute(new osg::BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
    osg::Material* material = new osg::Material;
    material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0.2f, 0.2f, 0.2f, 0.3f));
    material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0.8f, 0.8f, 0.8f, 0.3f));
    pStateSet->setAttribute(material, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
    osg::LightModel *lm = new osg::LightModel();
    lm->setTwoSided(true);
    pStateSet->setAttribute(lm, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
}


void setProgramStateSet(P_StateSet pStateSet, R_Program rProgram)
{
    pStateSet->setAttributeAndModes(rProgram);

    //pStateSet->setMode(GL_CULL_FACE, osg::StateAttribute::ON);
    //pStateSet->setAttributeAndModes(new osg::CullFace(osg::CullFace::BACK));
}


#endif //_STATESET_H_