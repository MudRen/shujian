// Room: /d/shaolin/woshi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�Է���ֻ��һ�����Ƶİ����������˰����õ���ϯ��ϯ���ϵ�һ��������
���ϡ�ϯ�ȱ���һ�Ѷ��˵ĵ��������ϰ߰ߵ���ƺ��Ǻö���ǰ���µ�Ѫ����
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaowu",
	]));

	setup();
}
