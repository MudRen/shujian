// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�����·������խ�����ԵĲ���Ĵ���������ǰ����һ�������С��
LONG
        );

        set("exits", ([
                "west" : __DIR__"xiaolu1",
                 "south" : __DIR__"jiedao1",
        ]));
        set("objects",([
//                __DIR__"npc/miaobing" : 1,

        ]));

        set("no_clean_up", 0);
        set("outdoors", "miaojiang");

        setup();

}
