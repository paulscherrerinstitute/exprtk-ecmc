exprtk-ess
==

C++ Mathematical Expression Parsing And Evaluation Library for ESS Customized Version


# Purpose

We are using this repository in order to use it witin ESS EPICS environment and the EPICS community one.

## EPICS Community Version
This repository can be translated into exprtkSupport in the ecmc EPICS module as `git submodule`. Thus, the main `makefile` is the EPICS standard makefile. Please look at the following repository for further detailed information.

* https://github.com/epics-modules/ecmc


## ESS EPICS Environment
This repository can be translated into exprtk in the ESS EPICS mdoule `e3-exprtk` as `git submodule`. The `e3-exprtk` has its own `makefile` to build it within e3. Please look at the following repository for further information:

* https://github.com/icshwi/e3-exprtk
