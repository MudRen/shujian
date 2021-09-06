inherit ITEM;
#include <ansi.h>
void create()
{
set_name( HIY"人肉炸弹"NOR, ({ "zhadan"}) );
set("long", "这是一颗烈性十足的炸弹，专门用于炸(zha)隐身中的巫师现形。\n");
set_weight(1000);
if( clonep() )
                   set_default_object(__FILE__);
else {
                     set("unit", "颗");
                     set("value", 0);
                     }
                     setup();
}

void init()
{
 add_action("do_zha","zha");
}

int do_zha(string arg)
{
 object ob,me=this_player();
 if(!arg) return notify_fail("你想炸谁。\n");
 if(!ob=find_player(arg)) return notify_fail("你想炸谁。\n");
 if( !wizardp(ob) ) return notify_fail("你只能炸巫师哦！\n");
 if( !ob->query("env/invisibility") ) return notify_fail("难道你看不到那个巫师吗？\n");
 if( me->query_temp("zhadan") ) return 1;
message_vision("$N取出一颗人肉炸弹，往空中一抛，人肉炸弹象长了眼睛似的，往远处飞去...\n不一会儿，远处传来一声闷响。\n",  me );
message("vision", HIR"忽然一颗人肉炸弹呼啸地往"+ob->name()+"这个方向飞来,轰的一声响，"+ob->name()+"被炸出了原形。\n"NOR,  environment(ob), ({ ob }) );

tell_object(ob,"忽然一个人肉炸弹撞在你身上，爆炸了，逼得你现出了原形。\n原来是"+me->name()+"向你丢人肉炸弹:->。\n");
message("channel:wiz", HIR"【谣言】："+ob->query("name")+"被炸出了原形。\n"NOR, users());
message("channel:chat", HIR"【谣言】："+ob->query("name")+"双手抱头，痛哭流涕，仰天狂喊：“我装逼，我被雷劈！”\n"NOR, users());
 me->set_temp("zhadan",1);
 ob->set("env/invisibility",0);
 destruct(this_object());
 return 1;
}

