// Room: /dali/dongjie6.c
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ��ֵ��ϻ��ݺ���ľ�����дУ��������󣬽����������
��Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ�ӣ�ϰ�׸��죬��
ʳ�����޲�������ԭ�������Ǹ��軨԰��Ʒ�ַ��ࡣ
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"east" : __DIR__"chyuan",
		"south" : __DIR__"dongjie7",
		"north" : __DIR__"dongjie5",
	]));
	setup();
}
