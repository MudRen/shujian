// ũ��
// nongtian13.c
// augx@sj 10/17/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","ũ��");
	set("long",
"����һƬ��û������ׯ�ڵ�ũ��������������ֲ(zhongzhi)�Լ���ֲ
�ũ���Ի���һ��ˮ���ͷ��ϳأ������������ˮ(jiaoshui)��ʩ��(shife
i)��������ֲ��ֲ������˾Ϳ����ո�(shouge)�ˡ�
"); 
        
	set("exits",([
		"out" : __DIR__"nongtian3",
	]));
	
	set("outdoors", "��������");
	set("incity",1);
	set("exam",0);
	setup();
}

#include "nongtian.h"
