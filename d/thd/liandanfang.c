// /u/jpei/thd/liandanfang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����һ�������ҩʦ��������������
LONG
	);
	set("exits", ([
	      "out" : __DIR__"jingshe.c",
	]) );
	set("objects", ([
        MEDICINE_D("jiuhuawan"): 1,
	]));
	set("no_clean_up",0);
	setup();
}

