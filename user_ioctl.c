#include <stdio.h>
#include <errno.h>
#include "ioctl.h"


retType read_from_register(int read_fd)
{
    int retval;
    unsigned int read;

    retval = NOT_OK;
    retval = ioctl(read_fd, IOCTL_READ_REG, &read);
    if(retval < 0)
    {
        printf("fd: %d, read error: %d\n", read_fd, errno);
        exit(-1);
    }
    return retval;
}

retType write_to_device(int write_fd)
{
    int retval;
    unsigned int to_write;
    
    retval = NOT_OK;
    to_write = 1;

    retval = ioctl(write_fd, IOCTL_WRITE_REG, &to_write);
    if(retval < 0)
    {
        printf("fd: %d, write error: %d\n", write_fd, errno);
        exit(-1);
    }
    return retval;
}

main()
{
    int fd, ret;
    
    ret = NOT_OK;
    fd=open(ARM_NODE, 0776);
    if(fd < 0)
    {
      perror("open");
    }
    while(1)
    {
        PRINT("Enter 1: To read from the register\nEnter 2: To write to the register\nEnter 3: Exit from menu\n");
        PRINT("Provide choice: ");
        SCAN("%d", data);
    
        switch(data)
        {
            case 1:
                  if(!(ret = read_from_register(fd))
                  {
                      perror("read_from_register\n");
                      break;
                  }
                  break;

            case 2:
                  if(!(ret = write_to_register(fd))
                  {
                      perror("write_to_register\n");
                      break;
                  }
                  break;

            case 3:
                  exit(0);

            default:
                  PRINT("Provide proper input\n");
        }
    }
}
