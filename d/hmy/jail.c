// /d/hmy/jail.c
// Created by Numa 19991019

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIB"����"NOR);
	set("long", @LONG
������������̵ĵ��¼��������涼��ʯ�ڣ�ֻ��һ�����ţ�ֻ�������
�˴����Ų��ܳ�ȥ����Ҫ�����ӳ�ȥ�ǲ����ܵġ�����ʮ�ֳ�ʪ����������
ʱ��һ�ñص��ز���
LONG
	);
          set("objects",([
                FOOD_D("zongzi") : 2,
                FOOD_D("zhuhu") : 1,
        ])); 
	setup();
}
