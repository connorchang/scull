#ifndef _SCULL_H
#define _SCULL_H

#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/export.h>
/* use dynamic assignment */
#define SCULL_MAJOR 0
#define SCULL_QUANTUM 4000
#define SCULL_QSET 1000
#define SCULL_NR_DEVS 1

struct scull_dev {
        struct scull_qset *data; /* pointer to first quantum set */
        int quantum;             /* the current quantum size */
        int qset;                /* the current array size */
        unsigned long size;      /* amount of data stored here */
        unsigned long access_key; /* used by sculluid and scullpriv */
        struct semaphore sem;     /* mutual exclusive semaphore */
        struct cdev cdev;         /* Char device structure */
};

struct scull_qset {
        void **data;
        struct scull_qset *next;
};


static void scull_setup_cdev(struct scull_dev *dev, int index);
int scull_open(struct inode *inode, struct file *filp);
int scull_release(struct inode *inode, struct file *flip);
int scull_trim(struct scull_dev *dev);
ssize_t scull_read(struct file *filp, char __user *buf, size_t count,
                   loff_t *f_pos);


ssize_t scull_write(struct file *filp, char __user *buf, size_t count,
		    loff_t *f_pos);


struct file_operations scull_fops = {
        .owner = THIS_MODULE,
        /* .llseek = scull_llseek, */
        .read = scull_read,
        .write = scull_write,
        /* .ioctl = scull_ioctl, */
        .open  = scull_open,
        .release = scull_release,
};

#endif
