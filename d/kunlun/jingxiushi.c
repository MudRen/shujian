inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ����ң�����˳��ط��ż������ţ��������ż����㣬����������
�𡣼�λ�����ɵ�������ϥ��������������ޡ�
LONG
	);
	set("exits", ([
		"south" : __DIR__"shiqiao",
		"east"  : __DIR__"shilu1",
	]));

        set("objects", ([
		BINGQI_D("zhujian") : 2,
	]));

	setup();
}
