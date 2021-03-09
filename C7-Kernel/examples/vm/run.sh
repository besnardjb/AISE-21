
qemu-system-x86_64 -drive file=${PWD}/img.qcow2,if=virtio -kernel /home/jbbesnard/repo/linux/./arch/x86/boot/bzImage  -append "console=ttyS0 debug rootfstype=ext4,xfs root=/dev/vda1 ide_core.noprobe=0.1 ide_core.noprobe=1.1 init=/bin/sh"  --enable-kvm -cpu host -nographic

#qemu-system-x86_64 -drive file=${PWD}/img.qcow2,if=virtio -kernel /home/jbbesnard/repo/linux/./arch/x86/boot/bzImage --enable-kvm -cpu host -append "root=/dev/vda1" 

