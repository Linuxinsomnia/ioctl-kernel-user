#ifndef __IOCTL_H
#define __IOCTL_H

/* Return values */
#define NOT_OK -1
#define OK 0


/* IOCTL defines */
#define MY_MAGIC_NO   'P'
#define IOCTL_WRITE_REG   _IOW(MY_MAGIC_NO, 1, int *)
#define IOCTL_WRITE_REG   _IOR(MY_MAGIC_NO, 1, int *)


#endif //__IOCTL_H
