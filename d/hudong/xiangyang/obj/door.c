
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL "城门" NOR, ({ "cheng men", "men" ,"door"}) );         
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
        setup();
}
}
