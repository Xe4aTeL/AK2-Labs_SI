## AK lab3
AK2 Laboratory work 5 (1st task)

Skorobagatko Ivan IO-13

# Setup

```
export PATH=/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin:$PATH
```
```
export CROSS_COMPILE="ccache arm-linux-gnueabihf-"
```
```
export ARCH=arm
```
```
export KDIR=$HOME/repos/linux-stable
```
# Compile

```
make clean
```
```
make
```
```
cp hello.ko $HOME/repos/busybox/_install/
```
# Rebuild

Commands for rebuild archive:
```
cd ~/repos/busybox/_install
```
```
find . | cpio -o -H newc | gzip > ../rootfs.cpio.gz
```
```
cd ..
```
# Start QEMU

```
qemu-system-arm -kernel _install/boot/zImage -initrd rootfs.cpio.gz -machine virt -nographic -m 512 --append "root=/dev/ram0 rw console=ttyAMA0,115200 mem=512M"
```
# Kernel commands

```
insmod hello.ko
```
```
modinfo hello.ko
```
```
rmmod hello
```

# DEBUG
```
${CROSS_COMPILE}objdump -dS hello.ko.unstripped | less
```
```
${CROSS_COMPILE}gdb -q hello.o
disas hello_init+0x88,hello_init+0x98+4
```