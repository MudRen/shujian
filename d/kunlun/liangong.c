// liangongfang.c (kunlun) ������

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż������ţ��������ż����㣬����������
�𡣼�λ�����ɵ�������ϥ�������������
LONG
	);
	set("exits", ([
                "west"  : __DIR__"lang2",
	]));
	set("objects", ([
		BINGQI_D("zhujian") : 2,
	]));

	setup();
}
