// Room: wroad2.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ�������߼��ﴦ�����������񶼳ɶ��ˡ�
LONG);
	set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"wroad1",
                "west" : "/d/xueshan/tulu1",
	]));

	setup(); 
}
