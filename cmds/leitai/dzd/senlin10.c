//ROOM: /d/dzd/senlin10.c

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
		"west" : __DIR__"senlin9",
		"south" : __DIR__"senlin7",
		"southeast" : __DIR__"senlin8",
		"southwest" : __DIR__"senlin6",
	]));
	set("objects",([
		__DIR__"npc/tiger" : 1,
	]));
	setup();
}