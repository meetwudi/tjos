
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            global.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define GLOBAL_VARIABLES_HERE

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"
#include "keyboard.h"

PUBLIC	PROCESS			proc_table[MAX_TASKS_PROCS];
PUBLIC	TASK	task_whole_list[] =	{//函数入口，进程名，是否任务，首tty，优先级
					{task_tty,	"IO-Main", TRUE,  0, 15},//优先级最高		
					{ProMain,	"ProMain", TRUE,  0, 10},
					{TestA,"TestA",FALSE,0,0},		
					{TestB,"TestB",FALSE,0,0},
					{TestC,"TestC",FALSE,0,0},				
		};

PUBLIC	int		task_proc_table[NR_TASKS_PROCS]	=	{1, 2};//专指IO，ProMain

PUBLIC	char			task_stack[STACK_SIZE_TOTAL];

PUBLIC	t_pf_irq_handler	irq_table[NR_IRQ];
PUBLIC	TTY			tty_table[NR_CONSOLES];
PUBLIC	CONSOLE			console_table[NR_CONSOLES];

PUBLIC	t_sys_call		sys_call_table[NR_SYS_CALL] = {//系统调用函数表
														sys_get_ticks, 
														sys_write, 
														sys_getchar, 
														sys_clear, 
														sys_shutdown, 
														sys_echoon, 
														sys_echooff, 
														sys_accepton, 
														sys_acceptoff, 
														sys_flush
										   };

