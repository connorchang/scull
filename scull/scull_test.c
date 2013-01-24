#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
        int fd, result, len;
        char buf[10];
        const char *str;
        if ((fd = open("/dev/scull0", O_WRONLY)) == -1) {
                perror("open failed");
                return -1;
        }

        str = "abcde"; len = strlen(str);
        if ((result = write(fd, str, len)) != len) {
                perror("read failed");
                return -1;
        }
        buf[result] = '\0';
        if (strncmp(buf, str, len)) 
                fprintf(stdout, "failed: read back \"%s\"\n", buf);
        else 
                fprintf(stdout, "passed\n");

        close(fd);

        return 0;
}
