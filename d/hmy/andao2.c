// andao2.c
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
	  "south" : __DIR__"andao1",
	  "east" : __DIR__"andao3",
]));
	setup();
}
