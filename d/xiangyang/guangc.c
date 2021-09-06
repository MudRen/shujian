// leitai.c 擂台前广场

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","擂台前广场");
	set("long",@long
这里是襄阳擂台前面的一个大型广场，有许多人正在擂台上比武，到处
是人山人海，如果你也想试试身手，那么就请上擂台比试比试吧。
long);
        set("xyjob", 1);
	set("exits",([
                "tiandi" : "/d/wizard/lt",
                "fengyun" : "/d/wizard/lt1",
                "longhu" : "/d/wizard/lt2",
		"north" : __DIR__"bcx2",
	]));
	set("outdoors", "襄阳");
	set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
	object *ob;
  int i, db_time;
  db_time = me->query_condition("db_exp",1);  
  
  if (dir != "north" && me->query_condition("db_exp",1) > 0 ){
                        me->clear_condition("db_exp");
                        me->set("db_time",db_time);
                                                              }
                                                                 
	if (dir != "north" && (!userp(me) || sizeof(me->query_entire_conditions())))
                return notify_fail(HIW"\n你还有要事在身，不得进入擂台重地！\n"NOR);
	if ( dir != "north" && me->query("no_quest"))
	            	return notify_fail("\n");
	ob = deep_inventory(me);
	i = sizeof(ob);
	while (i--)
	if ((ob[i]->is_character() || ob[i]->query("unique")) && dir != "north")
		return notify_fail(HIW"\n你不得带人或带宝物进入擂台重地。\n"NOR);

  if (dir == "north" && me->query("db_time",1) > 0 ){
  	                    me->apply_condition("db_exp",me->query("db_time",1)); //注意这里不能引用db_time,因为db_time是在玩家最后一次抵达这个地点的时候采集的，如果从擂台出来，那么db_time必然是0
                        me->delete("db_time");
                                                              }


	return ::valid_leave(me, dir);
}
