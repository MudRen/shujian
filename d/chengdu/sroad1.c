// Room: sroad1.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ������ʯ�̳ɵĴ�������߾����������񶼳ɶ��Ĵ������ˡ�����
������·��ֱͨ����ɽ����
LONG);
	set("outdoors", "�ɶ�");

	set("exits", ([
		"north" : __DIR__"dananmen",
		"southwest" : __DIR__"tulu3",
	]));
	setup();
}
