//ROOM: /d/dzd/shulin2.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","����");
	set("long",@LONG
��ľϡ��س��ţ������������Ƭ���֡������ǰ�����ɳ�ĵ��棬������Ϫ���԰���
�ݵ����Ǻ��߶��ˡ�һЩɽʯ�Ӵ��������У������ƺ������һЩ��������ֵ��Ǿ�Ȼ��
����һ˿������
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"east" : __DIR__"shulin3",
		"west" : __DIR__"shulin1",
		"south" : __DIR__"haitan3",
		"northeast" : __DIR__"senlin2",
		"northwest" : __DIR__"senlin1",
	]));
	setup();
}