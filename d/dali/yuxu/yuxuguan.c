// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
���������������ˣ�ӭ���ͤ����Ԫʼ����Ľ����������ֱ߻���һ
����С���̫�����˽������񣬴�������վ��һλ������á�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"guanmen",
		"east" : __DIR__"shuifang",
		"west" : __DIR__"shufang1",
	]));
	set("objects", ([
		__DIR__"npc/yuxu" : 1
	]) );

	setup();
}
