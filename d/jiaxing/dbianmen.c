// Room: /d/jiaxing/dbianmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǽ��˳ǵĶ����ţ��ֵ������˲��Ǻܶ࣬·���ϵ���ʯ�����ϵ�ϸ��
ϴˢ�øɸɾ���������������������ο͵���Ӱ��������ֱ���Ƕ����Ƿ羰��
���ļ����Ϻ��������ǳ����ġ�
LONG
	);

	set("exits", ([
                "east" : __DIR__"nanhu",
		"west" : __DIR__"jiaxing",
		"south" : __DIR__"tieqiang",
	]));

        set("outdoors", "����");
	setup();
}
