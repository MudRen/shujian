// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/wanhonglou.c

inherit ROOM;

void create()
{
        set("short", "���¥");
        set("long", @LONG
���¥�ǳ���������һָ�Ĵ��Ժ�����ﲻ����ͨ�������ĵط��������
û��������ᣬ�������������š�¥�й͵Ĵ��ָ����ߴ����ͣ�ûǮû�Ƶ�
�����ⳡ��������˿�ȥ��
LONG
        );
	set("exits", ([
		"south" : __DIR__"eastjie1",
	]));
	set("objects", ([
                __DIR__"npc/guinu" : 1,
                __DIR__"npc/xuexianer" : 1,
                __DIR__"npc/dashou" : 1,
                __DIR__"npc/piaoke" : 1,
                __DIR__"npc/gongzi" : 1,
        ]));
	set("incity",1);
	setup();
}