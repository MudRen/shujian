// /u/jpei/guiyun/kefang.c

inherit ROOM;

void create()
{
	set("short","�ͷ�");
	set("long",@LONG
�����д�����ס�޵ķ��䡣���ڳ��辫�ţ�������ԣ������Žࡣ
LONG
);
	set("exits",([
		"south" : __DIR__"zoulang2",
	]) );
	set("no_clean_up", 0);
        set("no_fight", 1);
	set("sleep_room", 1);
	setup();
}
