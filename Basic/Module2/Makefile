obj-m += module2.o

all:
	make -C /lib/modules/4.2.6-parrot-amd64/build M=$(PWD) modules

clean:
	make -C /lib/modules/4.2.6-parrot-amd64/build M=$(PWD) clean
