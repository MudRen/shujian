// Room: /u/numa/thd/shanlu1.c
// Modified by Numa 19980903

inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long",@LONG
���ϰ�ɽ������ֻ���������ˣ�����Ҳ��һ�������ơ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "eastup" : __DIR__"shanya",
                "westdown" : __DIR__"shanlu2",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","�һ���");

        setup();
}

