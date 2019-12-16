#define T_DIR  1   // Directory
#define T_FILE 2   // File
#define T_DEV  3   // Device

struct stat {
  short type;  // Type of file
  int dev;     // File system's disk device
  uint ino;    // Inode number
  short nlink; // Number of links to file
  uint size;   // Size of file in bytes
};

struct timeVariable{
    int creationTime;      // Time process has been created
    int terminationTime;   // Time process has been terminated
    int sleepingTime;      // Time duration that process has been sleeping
    int readyTime;         // Time duration that process was in ready in state
    int runningTime;       // Time duration process was running
};
