obj-m += startstop.o
startstop-objs := start.o stop.o

all:
	make -C /lib/modules/4.2.6-parrot-amd64/build M=$(PWD) modules

clean:
	make -C /lib/modules/4.2.6-parrot-amd64/build M=$(PWD) clean
