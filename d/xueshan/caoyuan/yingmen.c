// Room: yingmen.c

inherit ROOM;

void create()
{
	set("short", "Ӫ��");
	set("long", @LONG
��ǰ��ԭ�ϳ���һƬ�ɹ�����������¹��Ѿ�Χ����Ӫկ�����ߴ�������
�ĺŽ�������Զ���и�Ӫ�ţ�һ�Ӷӵ��ɹ������������������Ӫ�������Ѿ�ע
�⵽���ˣ�����û��ǸϿ��뿪Ϊ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"jifeng",
		"south" : __DIR__"caohai1",
	]));
	set("outdoor","���ԭ");
        
	set("objects", ([
		__DIR__"../npc/jqbing" : 2,
	]));

	setup();
}
