// /u/jpei/guiyun/zoulang2.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����������������������ȡ������������ۣ����������˻�����������һ
��ͷ���
LONG
);
	set("exits",([
		"east" : __DIR__"zoulang1",
		"west" : __DIR__"zoulang3",
		"north" : __DIR__"kefang",
	]) );
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	set("objects",([
        __DIR__"npc/zhuangding" : 1,
	]));  
	setup();
}
