//ROOM: /d/dzd/shulin1.c

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
		"east" : __DIR__"shulin2",
		"west" : __DIR__"xiliu1",
		"north" : __DIR__"senlin1",
		"south" : __DIR__"haitan2",
	]));
	setup();
}