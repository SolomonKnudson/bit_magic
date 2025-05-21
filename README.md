# *bit_magic*

## *Synopsis*

* This repository is a simple library for visualizing binary operations. 

## *Downloading*

#### *Requirements::*

* must have ***git installed locally*** if you're going to use `git clone`
  
#### *Cloning from GitHub::*

* `cd` <*full-path/where git should clone the repo*>

* From command line: `git clone` <https://github.com/SolomonKnudson/bit_magic.git>

#### *Using Zip provided by github::*

* Click on green code button

  ![ALT text][code_button]

* Click *download zip*

  ![ALT text][code_drop_down]

* Un-zip directory, you just downloaded, where you want the project located on your machine  

## *Building*

### *Supported Platforms:*

* Windows

* Linux

### *Requirements::*

1. Must have ***cmake installed*** if you plan on following my ***cmake build instructions*** or using the ***CMakeLists.txt*** provided by the repository

1. Must be able to run c++ files on your machine

### *Generating build files::*

##### *From command line::*

* `cd` <*full-path/repo name*>

* `mkdir` <*build directory name*>

* `cd` <*build directory*>

* ***FROM COMMAND LINE: INSIDE BUILD DIRECTORY::*** `cmake -S .. -B .`

* ***FROM COMMAND LINE: INSIDE REPO ROOT DIRECTORY::*** `cmake` -S . -B <*build directory*>

* ***FROM COMMAND LINE: ANY DIRECTORY::*** `cmake` -S <*full-path/bit_magic/*> -B <*full-path/bit_magic/<*build directory*>*>

### *Building source::*

* *Note:* Previous examples will work here as well; replace cmake -S <*path*> -B <*path*> with cmake --build <*path*>

* ***FROM COMMAND LINE: INSIDE BUILD DIRECTORY::*** `cmake --build .`

## *Running Code*

* Build executable

* Run executable

[code_button]: https://github.com/SolomonKnudson/bit_magic/blob/main/img/installing/code_button.png 
[code_drop_down]: https://github.com/SolomonKnudson/bit_magic/blob/main/img/installing/code_drop_down.png 
