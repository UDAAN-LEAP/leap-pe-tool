# [Project website](https://udaanproject.org)
## [Read the docs](https://posteditingtool.readthedocs.io/en/latest/)


# Installation

## Windows 
- [Windows Installation Guide](https://docs.google.com/document/d/16P1UZ2t1Dd8qhAsl2UqL5hTkrsOkBJqr/edit)
- [Download Binary](https://www.cse.iitb.ac.in/~ayusham/Udaan-Windows-v4.0.zip)
Minimum requirements:
OS version: Windows 7+

## Linux Distro
- [Linux Installation Guide](https://docs.google.com/document/d/15PbeYfdMl1eMypAMoqibG6Z5dxipfx_aZBSAhifTlec/edit)
- [Download Source](https://www.cse.iitb.ac.in/~ayusham/Udaan-Linux-v4.0.tar.xz)

- Linux (Ubuntu) : Minimum requirements: OS version: Ubuntu 20.04 +

1. Install qt5:
- $ `sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools`

2. Install Dependencies:
- $ `sudo apt install build-essential libgit2-dev libpugixml-dev`
- $ `sudo apt install libqt5networkauth5 libqt5networkauth5-dev`
- $ `sudo apt install qtmultimedia5-dev`
- $ `sudo apt install libqt5svg5 libqt5svg5-dev`


3. Go to folder "FrameWorkCode", compile qpadfinal.pro and make:
- $ cd FrameWorkCode
- $ qmake qpadfinal.pro
- $ make
- Ignore the warnings(if any). Will be removed in the next version.


Execute file qpadfinal in folder "FrameWorkCode"
- $ ./qpadfinal
