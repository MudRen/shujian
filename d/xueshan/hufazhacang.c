// Room: hufazhacang.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����������ܾż������ߵ�ǽ��ɫ����г����̬ׯ�أ��������Ҷ�һ����
������д���߿򸡵��������ɽ��߲ʣ���Ϊ�������ڹ������ʮ�Ĵ󻤷���
���ܵ�����бڻ������������ʮ�Ĵ󻤷������ҷ𣬽�����а���¼���
LONG
	);

	set("exits", ([
		"northup" : __DIR__"fanyinge",
		"east" : __DIR__"jingjinzhacang",
		"west" : __DIR__"kuxiuzhacang",
		"south" : __DIR__"rimulundian",
	]));

}
