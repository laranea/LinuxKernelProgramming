# Linux Kernel Programming


## Compilation

    lsmod: Lists all the current modules loaded onto the kernel and gets the information by reading /proc/modules
    
    sudo insmod <filepath>
    
    sudo modprobe <filename>

After compiling the module has an extension .ko

To get information about the kernel module:

        sudo modinfo <module.ko>


## Loading and Unloading Module

Once the compilation is completed, load the module:

        insmod ./<module.ko>
        
        lsmod   #to check if module was loaded
        
        rmmod <modulename>
        
        cat /var/log/messages  (Might have to use grep)
