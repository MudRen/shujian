// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/xiyuan.c

inherit ROOM;

void create()
{
        set("short", "ϷԺ");
        set("long", @LONG
���������İ����������˴���һ�����ɵ����е���ɫ��Ϸ̨��Ϸ̨���߹�
����յ�����ĵ�����̨�º������˵İ��˺ܶ೤�ʡ�������ǰ������Щ���ʣ�
������һЩ���Ͳ����Ϳ������Ρ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"neijie2",
        ]));

        set("objects", ([
                 __DIR__"npc/xizi" : 1,
                 ]));
 
        set("incity",1);
	setup();
}