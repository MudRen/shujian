// Room: /d/nanyang/yidao4.c

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����������һ��յأ��������͸���������ܻ谵����ʱ�����޵Ľ�
����������·�ϣ�������Щ���š�
LONG
	);
	set("outdoors", "�ƺ�");
	set("exits", ([
		"west" : __DIR__"yidao3",
		"northeast" : "/d/huanghe/weifen",
		"south": __DIR__"duanya",
	]));
	setup();
}
