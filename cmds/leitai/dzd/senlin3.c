//ROOM: /d/dzd/senlin3.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","��ɭ��");
	set("long",@LONG
����һƬһ���޼ʡ���������ԭʼɭ�֣����˺ϱ��Ĵ������滨��ݾ�Ŀ���ǡ�
��ľ���Ӵ���һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ���һ
�߽�������������ɭ�ֵģ��ƺ�˭���۾���ע�����㣬��ĸо������㣬�øϿ��뿪��
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"west" : __DIR__"senlin2",
		"northeast" : __DIR__"senlin5",
		"northwest" : __DIR__"mudi",
		"southwest" : __DIR__"shulin3",		
	]));
	setup();
}