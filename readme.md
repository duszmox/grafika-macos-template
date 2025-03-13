## Számítógépes Grafika Template macOS felhasználók számára
A projekt a CMake build tool segítségével fordítható.  
### Függőségek telepítése
- **Xcode command line tools** (compiler, make, git, stb..)  
  `xcode-select --install`
- **CMake** *(CLion használata esetén nem szükséges)*
  - Homebrew: `brew install cmake`
  - [A CMake weboldalról](https://cmake.org/)
- **GLM**
  - Homebrew: `brew install glm`
- **GLFW**
  - Homebrew: `brew install glfw`
- Az `OpenGL` és `GLAD` könyvtárakat nem kell telepítenünk.  
### Egyéb
#### `OpenGL` deprecation
Mivel ez a könyvtár elalvultként van megjelölve fordításkor rengeteg ezzel kapcsolatos "hibával" találkozhatunk. Az olvashatóbb output érdekében érdemes definiálni a `GL_SILENCE_DEPRECATION` makrót projekt szinten *(cmake segítségével így)*:  
```
target_compile_definitions(${PROJECT_NAME} PRIVATE GL_SILENCE_DEPRECATION)
```
#### Xcode használata 
[CMake segítségével generálható Xcode projekt is.](https://cmake.org/cmake/help/v3.0/manual/cmake-generators.7.html)
```console
cmake -G Xcode <CMakeLists.txt-t tartamazó mappa>
```
#### **Disclaimer: Framework fájlok**
Arra nem tudok garanciát vállalni, hogy a `framework.h` és `framework.cpp` fájlok naprakészek a tárgyoldalon találhatóakhoz képest. A template használata előtt érdemes frissíteni ezeket a fájlokat.
