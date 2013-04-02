#ifndef __IOCTL_H
#define __IOCTL_H

/* Return values */
#define NOT_OK -1
#define OK 0


/* IOCTL defines */
#define MY_MAGIC_NO   'P'
#define IOCTL_WRITE_REG   _IOW(MAJOR_NUM, 1, int *)
#define IOCTL_WRITE_REG   _IOR(MAJOR_NUM, 1, int *)


#endif //__IOCTL_H
