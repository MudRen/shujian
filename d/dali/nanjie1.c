// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�����ڴ����ϴ���ϣ����ﰲ�����ˣ���������ߵ�����޲������˽�
�����Ծ�����Ŀ���򶫿�ȥ�����߹�ȥ���Ǵ���ʹ��ˡ������Ƕ��������ش�
��һ�������������ԭ���Ǹ������̣������и���ģ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"nanjie2",
		"west" : __DIR__"datiepu",
		"south" : __DIR__"shudian",
		"north" : __DIR__"xijie7",
	]));
	set("incity", 1);
	set("outdoors", "����");
	setup();
}
