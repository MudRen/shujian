// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/zahuopu.c

inherit MISC_ROOM;

void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
һ�����ֺŵ��ӻ��̡�����������Ӫ�������ڳ����Ǳ�һ���Ѿ�����һЩ
С�������������������ν��ף����Ǵ��װ��棬�ϰ����ճ�������Ҫ�Ķ���һ
�������١��ټ�����������ƹ����������ӻ��̵����⿴��һ���һ��á�
    ��ǰ���˸�����(sign)��
LONG
        );

        set("exits", ([
                "north" : __DIR__"neijie4",
        ]));
        
        set("objects", ([
                __DIR__"npc/zhplaoban" : 1,
        ]));
        
        set("incity",1);
	setup();
}