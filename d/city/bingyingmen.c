// Room: /city/bingyingmen.c

inherit ROOM;

void create()
{
	set("short", "��Ӫ����");
	set("long", @LONG
����վ�ڱ�Ӫ���ſڣ������һ�ż�ª��Ӫ�������Կ��������Ʒ��Ĺٱ�
���ڲ�������ʱ�ش����ź������ϰ����ǲ������ڴ˹ۿ��ģ�����û��ǸϿ�
�߿�Ϊ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"bingying",
		"east" : __DIR__"guangchangxi",
	]));
	set("objects", ([
		NPC_D("guanfu/bing") : 4,
	]));
	set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) &&
		dir == "south")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}
