// /u/dubei/miaojiang

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
�������嶾�̵�ǰ��������ȫ���置���ķ��ݡ�һ��������������Ѳ��
�ţ���̧����ȥ���������ܵ��ݶ��Ͼ�����඾�ߡ�
LONG
        );

        set("exits", ([
                "south" : __DIR__"wddamen",
                "east" : __DIR__"bingqif",
                "west" : __DIR__"chufang",
                "north" : __DIR__"myt",                
        ]));
      
        set("objects",([
                __DIR__"npc/jiaozhong" : 1,
        ]));

	setup();
}

#include "mjpoison.h"
