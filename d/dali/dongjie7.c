// Room: /dali/dongjie7.c
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ��ֵ��ϻ��ݺ���ľ�����дУ��������󣬽����������
��Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ�ӣ�ϰ�׸��죬��
ʳ�����޲�������ԭ�������Ǹ����꣬�����軨�����Ͼ����ϴ���ˡ�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"north" : __DIR__"dongjie6",
		"east" : __DIR__"huadian",
		"south" : __DIR__"nanjie5",
	]));
	setup();
}
