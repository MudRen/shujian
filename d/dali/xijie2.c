// Room: /dali/xijie2.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�������֣�������հ���������½֣��ֽй����֡��ǰ�������ó
�йŽ֡�ÿ�����£����Ｗ���˽��׵���Ⱥ��������һ����¥��͸�ſ�ȥ����
��һλ�ٸ������ϰ�����˵�Ż���
LONG
	);
	set("outdoors", "����");
	set("exits", ([ 
		"west" : __DIR__"xiulou",
		"south" : __DIR__"xijie3",
		"north" : __DIR__"xijie1",
	]));
	set("incity", 1);
	setup();
}
