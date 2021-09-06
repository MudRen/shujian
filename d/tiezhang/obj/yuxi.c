// zitie.c
// zqb

#include <ansi.h>

inherit ITEM;
void setup()
{}
void create()
{
           set_name( HIY"大燕国世系表"NOR, ({"shixi biao","shixi","biao"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "卷");
		set("long", YEL"\n这是一卷大燕国世系表，但时过境迁物是人非，大燕国复国是空，不复国还是空。\n"NOR);  
		set("value", 10000000);
		set("material", "stone");

set("no_cun",1);
set("no_give",1);
set("no_get",1);
		
	}
}
