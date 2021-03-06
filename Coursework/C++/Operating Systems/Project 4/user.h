struct stat;
struct rtcdate;
struct uproc;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int halt(void);
//Defined date function that allows user to call through shell
int date(struct rtcdate*);

// Project 3
int getuid(void);   // UID of the current process
int getgid (void);  // GID of the current process
int getppid(void);  // process ID of the parent process 

int setuid(unsigned int); // set UID to unsigned int 
int setgid(unsigned int); // set GID to unsigned int 
int getprocs(int, struct uproc*);
 
// Project 4
int setPriority(unsigned int, unsigned int); 

// ulib.c
int stat(char*, struct stat*);
char* strcpy(char*, char*);
void *memmove(void*, void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, char*, ...);
char* gets(char*, int max);
uint strlen(char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
