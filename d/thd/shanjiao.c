// Room: /u/numa/thd/shanjiao.c
// Modified by Numa 19980903

inherit ROOM;

void create()
{
        set("short", "�Խ���ɽ��");
        set("long",@LONG
�������Խ����ɽ���£�ֻ��ɽ��������ƣ���ɽ������������
���ƣ�Ҫ������ȥʵ��Ҫ��һ������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "up" : __DIR__"shanlu1",  
                "westdown" : __DIR__"caodi",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","�һ���");

        setup();
}

