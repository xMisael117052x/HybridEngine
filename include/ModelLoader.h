﻿#pragma once
#include "Prerequisites.h"
#include "MeshComponent.h"
#include "fbxsdk.h"

class 
ModelLoader {
public:
    ModelLoader() = default;
    ~ModelLoader() = default;

    /* OBJ MODEL LOADER*/
    MeshComponent
    LoadOBJModel(const std::string & filePath);

    /* FBX MODEL LOADER*/
    bool
    InitializeFBXManager();

    bool 
    LoadFBXModel(const std::string & filePath);

    void 
  ProcessFBXNode(FbxNode* node);

    void 
    ProcessFBXMesh(FbxNode* node);

    void 
    ProcessFBXMaterials(FbxSurfaceMaterial* material);

    std::vector<std::string> 
  GetTextureFileNames() const { return textureFileNames; }

private:
    FbxManager* lSdkManager;
    FbxScene* lScene;
    std::vector<std::string> textureFileNames;
public:
    std::string modelName;
    std::vector<MeshComponent> meshes;
};