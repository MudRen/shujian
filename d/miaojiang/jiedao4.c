// /u/dubei/miaojiang
 

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
������С������棬������һ����ɽ���������嶾�̵Ľ��أ�û���嶾��
����ɣ����ص���û�˸�ȥ����˵��������඾�棬������Ǿ͸�����Խ�׳�
�벽��
LONG
        );

        set("exits", ([
                 "north" : __DIR__"mzhai",
                 "west" : __DIR__"slu1",
                 "east" : __DIR__"jiedao3", 
        ]));
        set("objects",([
//                __DIR__"npc/miaobing" : 1,

        ]));

        set("no_clean_up", 0);
        set("outdoors", "miaojiang");

        setup();

}
