// Room: beidimiao.c
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "������");
	set("long",@LONG
����������Ժյı��������������ϡ�Ժ����һ����ˮ��������ʯ
��ʯ�ߣ���Ȼ�̾ᡣ�������ʯ����Ѫ����Ȼ�������������ڴ�����С�
LONG
	);

	set("exits", ([
            "south" : __DIR__"xijie2",
]));

        set("objects", ([
            __DIR__"npc/feng-yiming" : 1,
]));
	set("no_clean_up", 0);
	set("coor/x",-20);
  set("coor/y",-520);
   set("coor/z",0);
   setup();
}
