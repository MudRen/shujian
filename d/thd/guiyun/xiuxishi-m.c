// /d/thd/guiyun/xiuxishi-m.c

inherit ROOM;

void create()
{
	set("short","����Ϣ��");
	set("long",@LONG
���ǹ���ׯ���е����ǵ���Ϣ�ң������м��Ŵ󴲣����е�������ʱ��Ϣ
�á�
LONG
);
	set("exits",([
		"east" : __DIR__"lianwuchang",
	]) );
	set("no_clean_up",0);
	set("no_fight", 1);
	set("sleep_room", 1);
	setup();
}
