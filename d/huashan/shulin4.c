// Room: /d/huashan/shulin4.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ǰ��Ȼһ�ڣ������У�ֻ������ǰ�󣬵�����������ǵص������֡�
��ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ���������
��˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ�Ų���ȥ������β����������ƺ���
ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG);

	set("exits", ([
		"east" : __DIR__"shiwu",
        "south" : __DIR__"path1",
		"west" : __FILE__,
		"north" : __DIR__"kongdi",
	]));

	set("outdoors", "��ɽ");
	setup();
}



