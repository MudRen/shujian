//ROOM: /d/dzd/senlin9.c

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
		"east" : __DIR__"senlin10",
		"south" : __DIR__"senlin6",
	]));
	setup();
}