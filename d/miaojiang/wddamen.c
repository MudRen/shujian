// /u/dubei/miaojiang

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ����ɫ�Ĵ���,�������һ�����(bian)���嶾����Ȼλ�����置��
����������������ԭ����̸��ɫ�䡣�ſڵ���ʯ̨�����м����嶾���ڰ��ء�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"slu4",
                "east" : __DIR__"shanya2",
                "north" : __DIR__"qiant",
                
        ]));
        set("item_desc", ([
                 "bian" : HIY "�嶾��\n"NOR,
                 ]));
        set("objects",([
                __DIR__"npc/jiaozhong" : 2,

        ]));

       
        set("outdoors", "miaojiang");

        setup();
}
