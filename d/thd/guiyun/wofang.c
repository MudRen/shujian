// /u/jpei/guiyun/wofang.c

inherit ROOM;

void create()
{
	set("short","�Է�");
	set("long",@LONG
����ׯ�����Է������䲻����ʰ�úܸɾ������е�С�������Ϸ���һ��
�ƺ���һֻ���ѣ��������˳������������ס�
LONG
);
	/*  set("object",([
	__DIR__"obj/luchenfen.c" :     1,
	]));  */
	set("exits",([
		"east" : __DIR__"houting",
	]) );
	set("no_clean_up",0);
	setup();
}
