#ifndef ASGN1_IOCTL_H
#define ASGN1_IOCTL_H

#include <linux/ioctl.h>

struct asgn1_stats {
    int open_count;
    int write_count;
    int read_count;
    int buffer_len;
    int last_write_size;
};

#define ASGN1_MAGIC 'A'

// Lệnh 1: RESET_BUFFER (Không truyền dữ liệu, dùng _IO)
#define ASGN1_RESET_BUFFER  _IO(ASGN1_MAGIC, 1)

// Lệnh 2: GET_STATS (Đọc dữ liệu struct từ driver ra, dùng _IOR)
#define ASGN1_GET_STATS     _IOR(ASGN1_MAGIC, 2, struct asgn1_stats)

// Lệnh 3: SET_MODE (Gửi 1 số int từ user xuống driver, dùng _IOW)
#define ASGN1_SET_MODE      _IOW(ASGN1_MAGIC, 3, int)

// Lệnh 4: GET_VERSION (Đọc chuỗi version 64 byte từ driver ra, dùng _IOR)
#define ASGN1_GET_VERSION   _IOR(ASGN1_MAGIC, 4, char[64])

#endif