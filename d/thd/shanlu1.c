// Room: /u/numa/thd/shanlu1.c
// Modified by Numa 19980903

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long",@LONG
������ͺͺ��ɽ·��ʲôҲû�У�ֱͨ���Խ���İ�ɽ����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "northup" : __DIR__"shanlu2",
                "down" : __DIR__"shanjiao",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","�һ���");

        setup();
}

