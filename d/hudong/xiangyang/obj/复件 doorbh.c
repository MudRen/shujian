
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(WHT "白虎门城门" NOR, ({ "baihu chengmen", "chengmen"}) );         
        set_weight(30000000);
        
        set("unit", "对");
set("long", @LONG
这是一对厚重的城门，紧紧地关闭着，城门楼上是一队队整装的士兵
走来走去。城外由于连年的战争，百姓流离失所，造成了大片的荒
地，人烟稀少。
LONG);
set("value",50000000); 
set("no_get",1);
set("defend",15); // 坚固
        setup();
}

void init()
{
	
object me = this_player();
	
	
	if (this_object()->query("defend") <= 0)
 {
message_vision(RED""+this_object()->query("name")+RED"再也禁受不住冲击，哗啦一声塌了。\n"NOR, me);
	}
}
