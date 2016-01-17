/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

typedef struct Tos Tos;
typedef struct Plink Plink;

struct Tos {
	struct			/* Per process profiling */
	{
		Plink	*pp;	/* known to be 0(ptr) */
		Plink	*next;	/* known to be 4(ptr) */
		Plink	*last;
		Plink	*first;
		ulong	pid;
		ulong	what;
	} prof;
	unsigned long long	cyclefreq;	/* cycle clock frequency if there is one, 0 otherwise */
	long long	kcycles;	/* cycles spent in kernel */
	long long	pcycles;	/* cycles spent in process (kernel + user) */
	unsigned long	pid;		/* might as well put the pid here */
	unsigned long	clock;
	/* scratch space for kernel use (e.g., mips fp delay-slot execution) */
	unsigned long	kscr[4];

	/*
	 * Fields below are not available on Plan 9 kernels.
	 */
	int	nixtype;	/* role of the core we are running at */
	int	core;		/* core we are running at */
	/* top of stack is here */
};

extern Tos *_tos;
