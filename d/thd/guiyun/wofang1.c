// /u/jpei/guiyun/wofang.c

inherit ROOM;

void create()
{
	set("short","�Է�");
	set("long",@LONG
������ׯ�����Է�����������Ž�����һλŮ���ߴ������ڴ��ߡ�
LONG
);
	/*  set("object",([
	__DIR__"obj/luchenfen.c" :     1,
	]));  */
	set("exits",([
        "south" : __DIR__"zoulang3",
	]) );
    set("objects",([
          __DIR__"npc/cheng" : 1,
      ]));
	set("no_clean_up",0);
	setup();
}
