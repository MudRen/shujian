// Room: /d/wizard/zoulang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Զ����ݻ��Զ��Ѹ�λ��ʦ�͵��Լ��Ĺ����䡣
LONG	);
	set("exits", ([
		"down" : __DIR__"wizard_room"
]));

	set("coor/x",0);
  set("coor/y",0);
   set("coor/z",10000);
   setup();
}

void run(object ob)
{
	if (environment(ob) == this_object() )
        ob->move("/d/wizard/wizard_room");
}

void init()
{
	object ob = this_player();
	if(wiz_level(ob))
    		call_out("run", 5, ob);
}
