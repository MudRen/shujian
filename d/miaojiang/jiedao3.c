// /u/dubei/miaojiang
 

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
��������������ˣ��Ա���һ��������լԺ����������ȺҲ�Ƚ�ӵ������ʱ
��Ҳ�ܿ���һЩ�������˹����Ҵҡ�
LONG
        );

        set("exits", ([
                 "north" : __DIR__"jiedao2",
                 "south" : __DIR__"haozhai",
                 "west" : __DIR__"jiedao4",
                 "east" : __DIR__"jiedao5", 
        ]));
        set("objects",([
//                __DIR__"npc/miaobing" : 1,

        ]));

        set("no_clean_up", 0);
        set("outdoors", "miaojiang");

         setup();

}
