// /u/dubei/miaojiang
inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
������һ��������置С�򣬵����������Ա뺷�ö�������ò�Ҫ������
�������ǡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaolu2",
                 "south" : __DIR__"jiedao2",
                 "east" : __DIR__"zhd",
        ]));
        set("objects",([
                __DIR__"npc/miaobing" : 1,

        ]));

        
        set("outdoors", "miaojiang");

        setup();

}
