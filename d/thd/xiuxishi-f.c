// /u/jpei/jpei/xiuxishi-f.c

inherit ROOM;

void create()
{
	set("short","Ů��Ϣ��");
	set("long",@LONG
�����һ�����Ů�����ǵ���Ϣ�ң������м��Ŵ󴲣���Ů��������ʱ��Ϣ
�á�
LONG
);
	set("exits",([
		"north" : __DIR__"lianwuchang",
	]) );
	set("no_clean_up",0);
	set("no_fight", 1);
	set("sleep_room", 1);
	setup();
}
