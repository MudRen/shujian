// Room: ��� 3
// bbb 1997/06/11
// Modify By River 98/12 
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
һ����ֱ��ʯ����ͨ��ǰ����·�ϲ�ʱ�������������ĳ�����������
�����㷢�ִ�������ε���Խ��Խ���ˣ����������������֮һΪ�������壬
���͡��ס����ᡢ���ȶ�ʮ������壬·�ԵĲ軨Ц��ӭ�ˡ�
LONG
	);
        set("outdoors", "����");
	set("exits", ([ /* sizeof() == 1 */
		"northeast" : __DIR__"htq",
		"north" : "/d/group/entry/dlndao2",
		"south" : __DIR__"dadao4",
        ]));
	set("no_clean_up", 0);

	setup();
}
