// jianxia.c 游龙剑匣
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("剑匣",({ "jian xia", "jianxia", "xia", "box" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("no_sell", 1);
                set("value", 100000);
                set("material", "wood");
                set("long", "这是一个沉甸甸的剑匣，弥漫着一股凛冽刺骨的寒意。\n");
                 }
        setup();
}
void init()
{
       add_action("do_break", "break");
       add_action("do_break", "zhen");
       add_action("do_break", "sui");
       add_action("do_break", "posui");
}

int do_break(string arg)
{
        object me,ob;
        me = this_player();
               
       if (!(arg=="xia" || arg == "jian xia" || arg == "jianxia" || arg == "box"))
       return 0;

if( (int)me->query("max_neili") < 3000)
		        {
                       write("你内力太低,根本无法驱动匣内宝剑。\n");
			return 1;
				}
       
        if( (int)me->query_skill("sword", 1) < 180)
		        {
              write("你剑法造诣太低，神剑自有灵性，无法驱动。\n");
                 return 1;
				}
      
message_vision(HIY   "$N微一用劲，剑匣应劲破开！只听得「嗡」的一声，一道寒光冲天而起，在空中飞舞盘旋，刺击往来，宛若游龙。\n" NOR, me);
            ob=new("/clone/weapon/youlong-jian");
            ob->move(me);
            ob->wield();
            destruct(this_object());
            return 1;
}
