#include <linux/module.h>

static struct file_operations fops = {
//  .open = DEFAULT_OPEN,
//  .release = DEFAULT_RELEASE,
    .unlocked_ioctl = device_ioctl
};

long device_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{

    int len = ANY_VALUE; //Just for return value. No impact on this program !!

    printk (KERN_INFO "In Device_ioctl !!\n");
    switch(cmd)
    {
    case IOCTL_WRITE_REG:
        write_ioctl((unsigned long *)arg);
        break;

    default:
        printk (KERN_INFO "default\n");
        return -ENOTTY;
    }
    printk (KERN_INFO "device_ioctl out\n");
    return len;
}
