// usage 1: 直接用open打开目录，用返回值作为openat的第一个参数的值
#include "apue.h"
#include <fcntl.h>

int main() {
char *dir_path = "../test_lhl";
char *relative_path = "log.txt";    // dir_fd: 3, AT_FDCWD: -100


int dir_fd;
 int fd;
 int flags;
 mode_t mode;
 
 dir_fd = open(dir_path, O_RDONLY);
 if (dir_fd < 0) {
  perror("open");
  exit(EXIT_FAILURE);
 }
 
 // lhl
 #define MAX_SIZE 255
char path[MAX_SIZE];
getcwd(path,sizeof(path));
 printf("dir_fd: %d, AT_FDCWD: %d, pwd: %s \n", dir_fd, AT_FDCWD, path);    //dir_fd: 3, AT_FDCWD: -100, pwd: /work/share/apue.3e/fileio


 flags = O_CREAT | O_TRUNC | O_RDWR;
 mode = 0640;
//  fd = openat(dir_fd, relative_path, flags, mode);
 fd = openat(AT_FDCWD, relative_path, flags, mode);     // lhl *****

 if (fd < 0) {
  perror("openat");
  exit(EXIT_FAILURE);
 }
 
 write(fd, "adida", 5);
 
 close(fd);
 close(dir_fd);
 return 0;
}


// // usage 2: 借用dirfd，将DIR*转成int文件描述符
// #include <sys/types.h>
// #include <dirent.h>

// int main() {
//  DIR *dir;
//  int dirfd2;
//  int fd;
//  int n;
 
//  dir = opendir("../test_lhl");
//  if(NULL == dir) {
//   perror("open dir error");
//   return -1;
//  }
//  dirfd2 = dirfd(dir);
//  if(-1 == dirfd2) {
//   perror("dirfd error");
//   return -1;
//  }
 
//  fd = openat(dirfd2,"log.txt", O_CREAT|O_RDWR|O_TRUNC);
//  if(-1 == fd) {
//   perror("opeat error");
//   return -1;
//  }
//  n = write(fd,"Hello world!\n", 15);    // 多写的字节，可能会有乱码
 
//  close(fd);
//  closedir(dir);
 
//  return 0;
// }
