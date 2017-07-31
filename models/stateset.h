#ifndef _STATESET_H_
#define _STATESET_H_

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

void setTransparencyStateSet(P_StateSet p_stateSet)
{
    p_stateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
}

void setProgramStateSet(P_StateSet p_stateSet, R_Program rProgram)
{
    p_stateSet->setAttributeAndModes(rProgram);
}

#endif //_STATESET_H_