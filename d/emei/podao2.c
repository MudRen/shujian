// Room: /d/emei/podao2.c ������ �µ�2

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
		"eastdown" : __DIR__"podao1",
		"westup" : __DIR__"xixiangchi",
	]));

	set("outdoors", "shaolin");
	setup();
}



