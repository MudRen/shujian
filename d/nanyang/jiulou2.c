// Room: d/nanyang/jiulou2.c
// Lklv Modify 2001.10.10

inherit ROOM;
inherit F_DEALER;

void create()
{
	set("short", "ӭ��¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳Ժȱ�
�����ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ�����Ŀ���
����������һ�غ�ˮ���̲������������ǳ�ɽ���롣ǽ�Ϲ��ſ�����(paizi)��
LONG
	);

	set("item_desc", ([
		"paizi" : "����ר���ϵ����롣\n",
	]));

	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	setup();
}
