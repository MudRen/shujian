inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ���ֵ����죬������
���ݳ���һ�����ֺŵĵ��̣�������һ��С��ͬ�����������ǲ���ͤ�����Ϸ�
���Ǳ����š�
LONG
	);
        set("outdoors", "����");
        set("objects",([
		NPC_D("youke") : 2,
        ]));
	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"southwest" : __DIR__"baodaiqiao",
		"northwest" : __DIR__"canglangting",
		"north" : __DIR__"hutong",
		"south" : __DIR__"baoheji",
	]));
	set("incity",1);
	setup();
}

