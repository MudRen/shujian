// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
·����ƽ̹����������Ũ��������һƬ�ž���Զ��ż������һ����������
�Ե��쳣��ࡣ
LONG
        );

        set("exits", ([
		"southeast" : __DIR__"slu7",
		"east" : __DIR__"slu9",
	]));
     
        set("objects",([
                __DIR__"npc/jiaozhong" : 2,

        ]));
 
        set("outdoors", "�置");

        setup();
}

#include "mjpoison.h"
