// /u/dubei/miaojiang


inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����쵽�������ˣ�·����һ��С��̯��һ��������Ů����������һЩ�置
���е�ˮ����С�ԡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"jiedao1",
                 "south" : __DIR__"jiedao3",
                 "southeast" : __DIR__"ywj",
                 "east" : __DIR__"xiaotan", 
        ]));
        set("objects",([
                __DIR__"npc/miaobing" : 1,

        ]));

        set("outdoors", "�置");

        setup();
}
