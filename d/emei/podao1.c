// Room: /d/emei/podao1.c ������ �µ�1

inherit ROOM;

void create()
{
	set("short", "�µ�");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG
	);

	set("exits", ([
		"east" : __DIR__"lianhuashi",
		"westup" : __DIR__"podao2",
	]));

	set("outdoors", "shaolin");
	setup();
}



