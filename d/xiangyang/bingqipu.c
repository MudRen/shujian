// Room /d/xiangyang/bingqipu.c
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����һ���¿��ŵı����̣�һ������������ڵ���ĥ�����������ı�������
��һ�������������ո�����������������ĺ���������˵�����ں���Ĳֿ��
LONG
	);
         set("xyjob", 1);
	set("exits", ([
                "north" : __DIR__"ncx4",
	]));

	set("objects", ([
                 __DIR__"npc/bq-boss" : 1,
	]));
         set("no_clean_up", 0);

        set("incity",1);
	setup();
}
