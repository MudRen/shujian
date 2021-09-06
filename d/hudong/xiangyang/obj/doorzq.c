
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(RED "朱雀门城门" NOR, ({ "zhuque chengmen", "chengmen" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "对");
set("long", @LONG
这是一对厚重的城门，紧紧地关闭着，城门楼上是一队队整装的士兵
走来走去。城外由于连年的战争，百姓流离失所，造成了大片的荒
地，人烟稀少。
LONG);
set("value",50000000); 
set("no_get",1);
set("defend",10);
        setup();
}
}
void init()
{
	
   add_action("do_recover", ({"buji", "bu"}));
}

int do_recover(string arg)
{
object me = this_player();
object ob = this_object();
if (!arg)
		return notify_fail("你要给什么补给?\n");
	    
	if (arg!="城门" && arg!="chengmen")
		return notify_fail("你要给什么补给?\n");
if ( !me->query_temp("互动任务/襄阳大战/阵营") || me->query_temp("互动任务/襄阳大战/阵营") != 1)
return notify_fail("你不能给城门补给?\n");
if( me->is_busy() || me->is_fighting())
return notify_fail("你现在忙得很，不能补给城门。\n");
if(ob->query("defend")>=50000 )
return notify_fail(""+ob->query("name")+"现在不需要补给。\n");
message_vision(WHT"$N指挥着一队宋军抱来一大堆木料，死死地顶住了"+ob->query("name")+WHT",暂时确保了安全。\n"NOR, me);
ob->add("defend",random(30));
message_vision(HIG""+ob->query("name")+HIG"的坚固增加到了"+ob->query("defend")+"。\n"NOR, me);
me->start_busy(random(4));
if(random(10)>6)
{
message_vision(RED"突然从城外射进几支冷箭，$N身边的几名宋兵中箭倒下，$N不禁方寸大乱。\n"NOR, me);
me->add_busy(random(6));
}

return 1;
}

