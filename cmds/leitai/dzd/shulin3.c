//ROOM: /d/dzd/shulin3.c

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
		"west" : __DIR__"shulin2",
		"northeast" : __DIR__"senlin3",
		"northwest" : __DIR__"senlin2",
		"southwest" : __DIR__"haitan3",
	]));
	setup();
}