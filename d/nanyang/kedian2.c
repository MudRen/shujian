// Room: d/nanyang/kedian2.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ�������ٿ���
�����¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���������ŵ���
�˹�ȥ��
LONG
	);

	set("sleep_room",1);
	set("no_fight", 1);
	set("hotel", 1);

	set("exits", ([
		"down" : __DIR__"kedian1",
	]));
	setup();
}
