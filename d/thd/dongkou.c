// Room: /u/jpei/thd/dongkou.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���һ������Ȼ��������ôһ���Ҷ����ɼ���������֮�ɡ��Ҷ���Χȫ��
�һ��������￴���ں�����ʲôҲ��������
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"taohua1",
		"west" : __DIR__"taohua1",
		"south" : __DIR__"taohua1",
		"north" : __DIR__"taohua1",
		"enter" : __DIR__"cave",
	]) );
	set("no_clean_up", 0);
	set("outdoors","�һ���");

	setup();
}
