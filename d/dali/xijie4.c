// Room: /dali/xijie2.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "̫������");
	set("long", @LONG
��������ڱ��ߵ�����ó�нֺͶ����ߵĳ����ģ��Եð����˺öࡣ����
���Ǵ������ţ�ͨ�������¹�ɲ�ʹ����ų�ȥ������Ϳ����Ʋ���ˡ�����
������������ս�£�һƬ̫ƽʢ����ģ����
LONG
	);
	set("outdoors", "����");
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xijie5",
		"north" : __DIR__"xijie3",
		"west" : __DIR__"ximen",
	]));
	set("objects", ([
		"/d/zhiye/npc/shangfan": 1,
	]) );
	set("incity", 1);
	setup();
}
