// Room: /city/zuixianlou2.c
// YZC 1995/12/04 
inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
	����������������ѧʿ������������ʫ��������������Ҳ������߳Ժȱ�
�����ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ�����Ŀ�������
������һ�غ�ˮ���̲������������ǳ�ɽ���룬��������Կ�������ȫ���İ�¹��
Ժ�ĺ�ͥ��ǽ�Ϲ��ż۸�����(paizi)��
LONG
	);
	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));
	set("exits", ([
		"down" : __DIR__"zuixianlou",
		"east" : __DIR__"zxlpath",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }