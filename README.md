[Ethereal Engine](https://github.com/volcoma/EtherealEngine) - Cross-platform C++ Game Engine
============================================================================

[![Join the chat at https://gitter.im/EtherealEngine/Lobby](https://badges.gitter.im/EtherealEngine/Lobby.svg)](https://gitter.im/EtherealEngine/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![Build Status](https://travis-ci.org/volcoma/EtherealEngine.svg?branch=master)](https://travis-ci.org/volcoma/EtherealEngine)
[![Build status](https://ci.appveyor.com/api/projects/status/18pxyag4wok2fscl?svg=true)](https://ci.appveyor.com/project/volcoma/etherealengine)
[![license](https://img.shields.io/github/license/volcoma/EtherealEngine.svg)](LICENSE.txt)
![language](https://img.shields.io/badge/language-c++-blue.svg) ![c++](https://img.shields.io/badge/std-c++14-blue.svg)
![msvc2017+](https://img.shields.io/badge/MSVC-2017+-ff69b4.svg) ![mingw-5.3+](https://img.shields.io/badge/MINGW-5.3+-ff69b4.svg) 
![gcc-5.0+](https://img.shields.io/badge/GCC-5.0+-ff69b4.svg) ![clang-3.8+](https://img.shields.io/badge/CLANG-3.8+-ff69b4.svg)
[![](https://codescene.io/projects/1800/status.svg) Get more details at **codescene.io**.](https://codescene.io/projects/1800/jobs/latest-successful/results)

## INFO
This is mostro verson of Ethereal.  
I added the bullet physics engine.  
I've made some useful updates to the interface, camera, and game & editor separation.

My goal of this work is **WYSIWYG** and **highly scalable**. 

## STATUS
I am continuing to develop, 

## Building
**Don't forget to update submodules**
```bash
git clone https://github.com/volcoma/EtherealEngine.git
cd EtherealEngine
git submodule init
git submodule update

mkdir build
cd build
cmake ..

```

## PLATFORMS
It is written in a cross-platform manner using ![c++](https://img.shields.io/badge/std-c++14-blue.svg).

![msvc2017+](https://img.shields.io/badge/compilers--ff69b4.svg)      | ![windows](https://img.shields.io/badge/platform-windows-blue.svg) | ![linux](https://img.shields.io/badge/platform-linux-blue.svg)
---------------| --------|--------
![msvc2017+](https://img.shields.io/badge/MSVC-2017+-ff69b4.svg)   | ![yes](https://img.shields.io/badge/status-yes-green.svg)     |
![mingw-5.3+](https://img.shields.io/badge/MINGW-5.3+-ff69b4.svg)    | ![yes](https://img.shields.io/badge/status-yes-green.svg)     |
![gcc-5.0+](https://img.shields.io/badge/GCC-5.0+-ff69b4.svg)    |         | ![yes](https://img.shields.io/badge/status-yes-green.svg)
![clang-3.8+](https://img.shields.io/badge/CLANG-3.8+-ff69b4.svg)   |         | ![yes](https://img.shields.io/badge/status-yes-green.svg)

## ASSETS
Some high quality assets: https://github.com/volcoma/Library

Supported texture formats: png, tga, dds, ktx, pvr

Supported mesh formats: obj, fbx, dae, 3ds

Supported audio formats: ogg, wav

## SUGGESTIONS AND ISSUES
Any suggestions and help will be appreciated.

## BUILD
The engine uses the CMake build system.

## CODEBASE
![c++](https://img.shields.io/badge/std-c++14-blue.svg) Using the latest and greatest features of the language.

## CODE STYLE
```c++
#include "some_header.h"
#include "some_other_header_impl.hpp"

namespace nsp {
  class some_class {
  public:
    /**
     * @brief This is a method comment description.
     *
     */
    void some_method();
  
    /**
     * @brief 
     * 
     * @tparam T 
     */
    template<typename T> void some_templated_method();
  public:
    // this is a member comment
    int some_public_member = 0;
    
  private:
    // this is a member comment
    int some_private_member_ = 0;
}

template<typename T>
inline void some_class::some_templated_method() {
// If the class is fully templated it is acceptable to put this inside the class
}
```
## PREVIEW
![screenshot1](https://user-images.githubusercontent.com/1499411/29488399-e4c76a18-8512-11e7-8090-7453fea8d33f.png)

![screenshot2](https://user-images.githubusercontent.com/1499411/29488400-f43a5960-8512-11e7-923e-86a0c204da31.png)

![screenshot3](https://user-images.githubusercontent.com/1499411/29488403-ff3c3df6-8512-11e7-869f-32a783530cc3.png)

## REQUIRED FEATURES
### PRIMARY FEATURE
* Implement all methods of Rigidbody Component
* Implement all Collider Component and its method
* Fix camera sight distance bugs
* Script Component, which support programing language such as C++, C#, Python(Yes, I've seriously thought about it)
* game & editor separation
* Game play & close button switch
* Scene(Project) save
* Use system default file explorer
* Double click game object to focus
* Unit test of Transform Component



## LIBRARIES
bgfx - https://github.com/bkaradzic/bgfx

cereal - https://github.com/USCiLab/cereal

rttr - https://github.com/rttrorg/rttr

spdlog - https://github.com/gabime/spdlog

imgui - https://github.com/ocornut/imgui

assimp - https://github.com/assimp/assimp

glm - https://github.com/g-truc/glm

openal-soft = https://github.com/kcat/openal-soft
