// Room: /d/shaolin/houshan.c

inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
��վ�����м������ǰ�������ƺ����ñ��ص�ɽ���������ģ���ʵ������
ˮ���ݶ���é���̵ģ�����¶���������紵�����ƶ�����ߵ����Ӻ����Ǽ���
�ᣬ�ұߵ������ű߹��ż���ɹ�ɵ����������м����ݵ����ǿ��ŵġ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaojing2",
		"north" : __DIR__"xiaowu",
		"northwest" : __DIR__"zhushe",
	]));

	set("outdoors", "����");
	setup();
}
