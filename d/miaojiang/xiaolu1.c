// /u/dubei/miaojiang
 

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
����һ���ྻ��С·����ʱ��һЩ���˼絣����·����·�Ա���һ���峺
���׵ĺ����������ɽ��ˮ�㳣ʹ������ԭ�Ŀ�������������
LONG
        );

        set("exits", ([
                "north" : __DIR__"myp",
                "east" : __DIR__"xiaolu2",
                "northwest" : __DIR__"shanlu1",
        ]));
        set("objects",([
//                __DIR__"npc/miaobing" : 1,

        ]));

        set("no_clean_up", 0);
        set("outdoors", "miaojiang");

        setup();

}
