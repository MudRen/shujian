// /u/dubei/miaojiang

 
inherit ROOM;

void create()
{
        set("short", "�߷�");
        set("long", @LONG
�������嶾��������ѵ�����ߵĵط������������˸��ֶ��ߡ�
LONG
        );

        set("exits", ([
             "south" : __DIR__"woshi",
             "southeast" : __DIR__"myt",
        ]));
      
        set("objects",([
                __DIR__"npc/dushe1" : 3,

        ]));

       setup();

}
