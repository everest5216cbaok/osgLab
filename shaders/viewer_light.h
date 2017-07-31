#ifndef _VIEWER_LILGHT_H_
#define _VIEWER_LILGHT_H_

static const char* vs = {
    "void main(void){\n"
    "    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
    "}\n"
};

static const char* fs = {
    "uniform vec3 modelColor;"
    "void main(void){\n"
    "    gl_FragColor = vec4(modelColor, 0.5);\n"
    "}\n"
};

#endif //_VIEWER_LILGHT_H_