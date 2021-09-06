// Room /d/xiangyang/bingqipu.c
inherit ROOM;

void create()
{
        set("short", "兵器铺");
	set("long", @LONG
这是一家新开张的兵器铺，一个中年大汉正蹲在地上磨刀霍霍。身后的兵器架上
是一排排闪闪发光的崭新武器。不过真正的好武器，据说都藏在后面的仓库里。
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
