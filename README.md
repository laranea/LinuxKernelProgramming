# Linux Kernel Programming


## Basics

    lsmod: Lists all the current modules loaded onto the kernel and gets the information by reading /proc/modules
    
When kernel needs to load a particular module, kmod(kernel daemon) executes a command called modprobe which takes the name of module as parameter. It first looks up the file modules.dep to check for dependencies a particular module might require. Then goes on to call insmod to load the particular file and its dependecies. The difference between insmod and modprobe is that insmod does needs the file path to load the file while modprobe has some default paths in it.
