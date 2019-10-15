You can run ncs algorithm for a particular problem with fix random seed by using this command in current path:

 python -m algorithm_ncs.ncs_client -d 12 -c algorithm_ncs/parameter.json

The parameters should be written in the corresponding json file.


Also, you can run the algorithm multiple times with different seends, the commands is:

python3 -m algorithm_ncs.ncs_c

In this case, you need to look up ncs_c.py to setup your parameters and the core logic is also in this file.

