// andao7.c
// Created by Numa 19991021

#include <ansi.h>
inherit ROOM;
#include "andao.h"

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ͨ�������İ���������������ʽ���̾ߣ���΢�������֮�£�
ɢ���ű���ĺ��⣬����Խ��Խ�����з�ë����������֮�����ֲ�״�������
�Ľ��������и��е�һ�󾪲���
LONG
	);
	set("exits", ([ 
	  "southeast" : __DIR__"andao6",
	  "north" : __DIR__"andao8",
]));
	setup();
}
