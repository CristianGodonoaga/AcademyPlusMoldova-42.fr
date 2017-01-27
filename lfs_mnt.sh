#!/ib/bo

SETCOLOR_SUCCESS="echo -en \\033[1;32m"
SETCOLOR_FAILURE="echo -en \\033[1;31m"
SETCOLOR_NORMAL="echo -en \\033[0;39m"

function status_success () 
{
	$SETCOLOR_SUCCESS
	echo -n "$(tput hpa $(tput cols))$(tput cub 6)[OK]"
	$SETCOLOR_NORMAL
	echo
}
function status_fail ()
{
	$SETCOLOR_FAILURE
	echo -n "$(tput hpa $(tput cols))$(tput cub 6)[fail]"
	$SETCOLOR_NORMAL
	echo
}
function check_operation()
{
if [ $? -eq 0 ]; then
    $SETCOLOR_SUCCESS
    echo -n "$(tput hpa $(tput cols))$(tput cub 6)[OK]"
    $SETCOLOR_NORMAL
    echo
else
    $SETCOLOR_FAILURE
    echo -n "$(tput hpa $(tput cols))$(tput cub 6)[fail]"
    $SETCOLOR_NORMAL
    echo
	exit
fi
}


#Check $LFS variable
if [[ $LFS ]]; then
	echo -n "\$LFS is set"
	status_success
else
	echo -n "\$LFS are not set!!!"
	status_fail
	exit
fi

echo -n "Mount LFS Partition?(y/n) "
read state
if [[ $state == "y" ]]; then
mount -v -t ext4 /dev/sdb3 $LFS/
check_operation
mount -v -t ext4 /dev/sdb4 $LFS/home/
check_operation
mount -v -t ext2 /dev/sdb1 $LFS/boot/
check_operation
fi

echo -n "Mount and populating \"/dev\"?(y/n) "
read state
if [[ $state == "y" ]]; then
mount -v --bind /dev $LFS/dev
check_operation
fi

echo -n "Mount Virtual Kernel File System?(y/n) "
read state
if [[ $state == "y" ]]; then
mount -vt devpts devpts $LFS/dev/pts -o gid=5,mode=620
check_operation
mount -vt proc proc $LFS/proc
check_operation
mount -vt sysfs sysfs $LFS/sys
check_operation
mount -vt tmpfs tmpfs $LFS/run
check_operation
fi
