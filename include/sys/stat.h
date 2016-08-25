/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef __STAT_H
#define __STAT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __TYPES_H
#include <sys/types.h>
#endif

/*
 * stat structure, used by stat(2) and fstat(2)
 */
struct	stat {
	dev_t	st_dev;
	ino_t	st_ino;
	mode_t 	st_mode;
	nlink_t	st_nlink;
	uid_t 	st_uid;
	gid_t 	st_gid;
	off_t	st_size;
	time_t	st_atime;
	time_t	st_mtime;
	time_t	st_ctime;
};

#define	S__MASK		     0170000
#ifdef _RESEARCH_SOURCE
#define S_ISLNK(m)	(((m)&S__MASK) == 0120000)
#endif
#define S_ISREG(m)	(((m)&S__MASK) == 0100000)
#define S_ISDIR(m)	(((m)&S__MASK) == 0040000)
#define S_ISCHR(m)	(((m)&S__MASK) == 0020000)
#define S_ISBLK(m)	(((m)&S__MASK) == 0060000)
#define S_ISFIFO(m)	(((m)&S__MASK) == 0010000)

#define	S_ISUID	04000		/* set user id on execution */
#define	S_ISGID	02000		/* set group id on execution */
#define	S_IRWXU	00700		/* read, write, execute: owner */
#define	S_IRUSR	00400		/* read permission: owner */
#define	S_IWUSR	00200		/* write permission: owner */
#define	S_IXUSR	00100		/* execute permission: owner */
#define	S_IRWXG	00070		/* read, write, execute: group */
#define	S_IRGRP	00040		/* read permission: group */
#define	S_IWGRP	00020		/* write permission: group */
#define	S_IXGRP	00010		/* execute permission: group */
#define	S_IRWXO	00007		/* read, write, execute: other */
#define	S_IROTH	00004		/* read permission: other */
#define	S_IWOTH	00002		/* write permission: other */
#define	S_IXOTH	00001		/* execute permission: other */

#ifdef _BSD_EXTENSION
#define S_IFMT S__MASK
#define S_IFDIR 0040000
#define S_IFCHR 0020000
#define S_IFBLK 0060000
#define S_IFREG 0100000
#define S_IFIFO 0010000
#define S_IFLNK 0120000
#define S_IFSOCK S_IFIFO
#endif

extern mode_t umask(mode_t);
extern int mkdir(const char *, mode_t);
extern int mkfifo(const char *, mode_t);
extern	int	__stat(char *, struct stat *);
extern int __stat_ap(const char *, struct stat *);
extern int __fstat(int, struct stat *);
#define stat(c, s) __stat_ap(c, s)
#define fstat(i, s) __fstat(i, s)

extern int chmod(const char *, mode_t);

#ifdef _BSD_EXTENSION
extern int	lstat(const char *, struct stat *);
extern int	symlink(const char *, const char *);
extern int	readlink(const char *, char*, int);
#endif

#ifdef __cplusplus
}
#endif

#endif
