// Room: ������� /dali/dongjie1
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�����֣��ֵ��ϻ��ݺ���ľ�����дУ������������治ʱ����
�������˵���ζ��ԭ������������ѩ¥�������Ǹ����̣��ܶ�����˼�Ϊ����
�Ʋ��ò��Ѽ���ֵǮ�Ķ����䵱��Ǯ�������߾��Ǵ���ı�����ˡ�
LONG
	);
	set("outdoors", "����");
	set("exits", ([ 
		"east" : __DIR__"dangpu",
		"west" : __DIR__"jiulou",
		"north" : __DIR__"beijie5",
		"south" : __DIR__"dongjie2",
	]));
	set("incity", 1);

	setup();
}
