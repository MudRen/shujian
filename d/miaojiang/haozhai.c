// /u/dubei/miaojiang
// by dubei

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������һ�����������լԺ�����ڰ���ȴ����ԭ���ǽ�Ϲ��ż����Ż���
���µ������Ϸ����ķ��ı���
LONG
        );

        set("exits", ([
                 "north" : __DIR__"jiedao3",
        ]));
        set("objects",([
                __DIR__"npc/chen" : 1,

        ]));

         setup();

}
