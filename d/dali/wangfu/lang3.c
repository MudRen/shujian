// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�������������ڵ�һ�����ȣ�����һֱͨ�������ڣ��ȱߵ����˻��ߣ�͸
���ƿյĻ��ƣ���ɿ����������ľ���ݡ���������������������ů��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"lang1",
		"south" : __DIR__"lang5",
		"west" : __DIR__"yizheng",
		"east" : __DIR__"nuange",
	]));
	 
	setup();
}
