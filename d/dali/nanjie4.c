// Room:  /dali/nanjie4.c
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
���Ƿ����Ĵ����ϴ�֣�����������������������ߵ�����޲�������
�Ų����Ծ�����Ŀ��������ȥ�����߹�ȥ���Ǵ���ʹ��ˡ�����ס��һ�Ҵ�
�˼ң��ſ�վ�ż������ˣ����߾���̫���Ͻ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"nanjie3",
		"east" : __DIR__"nanjie5",
		"south" : __DIR__"dafujia",
	]));
	set("outdoors", "����");
	setup();
}
