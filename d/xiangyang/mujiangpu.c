// Room: /d/xiangyang/mujiangpu.c

inherit ROOM;

void create()
{
	set("short", "ľ����");
	set("long", @LONG
����һ�Ҽ�ª��ľ���̣�һ������ľ�������ڵ��϶�������
LONG
	);
        set("xyjob", 1);
	set("exits", ([
		"west" : __DIR__"ncx4",
	]));

	set("objects", ([
                __DIR__"npc/mujiang" : 1,
	]));
	set("no_clean_up", 0);

	set("incity",1);
	setup();
}
