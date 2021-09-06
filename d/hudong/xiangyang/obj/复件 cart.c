#include <ansi.h>
#include <room.h>
inherit ITEM;

void create()
{
	set_name(HIR"冲车"NOR, ({ "chong che", "che", "cart"}) );
	set_weight(300000);
	set("no_get", 1);
	set("no_get_from", 1);
	set_max_encumbrance(80000);
	set("unit", "辆");
	set("long", "一辆黑漆漆的厚重冲车，专门冲击城门而用。\n");
	set("closed", 1);
	set("value", 2000);
	set("location",1);
}

void init()
{
       add_action("do_driver", ({"driver", "tui"}));
add_action("do_chong", ({"chong", "zhuang"}));

	
}
int do_driver(string arg)
{
object me = this_player();
object cart = this_object();
object room,newroom;
string dirname;
string dir, roomfile, newroomfile;

if( me->is_busy() || me->is_fighting())
return notify_fail("你现在忙得很，不能指挥冲车前进。\n");
if (query_temp("busy/"+me->query("id")))
		return notify_fail("冲车行进速度很慢，等等吧。\n");
if(query("make") != me->query("id"))
return notify_fail("这两冲车不是由你操纵的。\n");

room = environment(cart);

	roomfile = file_name(room);

switch(arg) {
		case "e":	dir="east";		dirname="东面";		break;
		case "w":	dir="west";		dirname="西面";		break;
		case "n":	dir="north";		dirname="北面";		break;
		case "s":	dir="south";		dirname="南面";		break;
		case "ne":	dir="northeast";	dirname="东北";		break;
		case "nw":	dir="northwest";	dirname="西北";		break;
		case "se":	dir="southeast";	dirname="东南";		break;
		case "sw":	dir="southwest";	dirname="西南";		break;
		case "u":	dir="up";		dirname="上面";		break;
		case "up":	dir="up";		dirname="上面";		break;
		case "d":	dir="down";		dirname="下面";		break;
		case "down":	dir="down";		dirname="下面";		break;
		case "nu":	dir="northup";		dirname="北边";		break;
		case "eu":	dir="eastup";		dirname="东边";		break;
		case "su":	dir="southup";		dirname="南边";		break;
		case "wu":	dir="westup";		dirname="西边";		break;
		case "nd":	dir="northdown";	dirname="北边";		break;
		case "ed":	dir="eastdown";		dirname="东边";		break;
		case "sd":	dir="southdown";	dirname="南边";		break;
		case "wd":	dir="westdown";		dirname="西边";		break;
		case "enter":	dir="enter";		dirname="里面";		break;
		case "out":	dir="out";		dirname="外面";		break;
		default:	dir=arg;		dirname="一边";		break;
	}
	if(!room || !room->query("exits/"+dir))
		return notify_fail("你要往哪里去？\n");

newroomfile=room->query("exits/"+dir);

if(!objectp(newroom=find_object(newroomfile))) newroom=load_object(newroomfile);

	message_vision(HIW"冲车在$N的驱使下缓缓地往"+dirname+"的"+newroom->query("short")+HIW"离去了。\n"NOR, me);

	move(newroom);
me->start_busy(random(3));

return 1;
}
int do_chong(string arg)
{
object me = this_player();
object cart = this_object();
object obj;
if(!arg || !objectp(obj = present(arg, environment(me))))
		
return notify_fail("你要让冲车去冲撞什么？\n");
if(!obj->query("defend"))
return notify_fail("这东西用得着冲车么？\n");

if( me->is_busy() || me->is_fighting())
return notify_fail("你现在忙得很，不能指挥冲车冲撞。\n");
if(query("make") != me->query("id"))
return notify_fail("这两冲车不是由你操纵的。\n");
message_vision(YEL"$N指挥着冲车猛烈地往"+obj->query("name")+YEL"撞去，发出轰轰的巨响，一时间尘土飞扬。\n"NOR, me);

obj->add("defend",-random(10));
message_vision(YEL""+obj->query("name")+YEL"的坚固还有"+obj->query("defend")+"。\n"NOR, me);
me->start_busy(random(3));

if(obj->query("defend") <= 0 )
{
if(obj->query("id") == "baihu chengmen")
{
obj->delete("defend");
message_vision(YEL""+obj->query("name")+YEL"再也禁受不住冲车的撞击，哗啦一声塌了。\n"NOR, me);
destruct(obj);
"adm/daemons/xyjobd"->xy_attackbh();

}
else if(obj->query("id") == "qinglong chengmen")
{
obj->delete("defend");
message_vision(YEL""+obj->query("name")+YEL"再也禁受不住冲车的撞击，哗啦一声塌了。\n"NOR, me);
destruct(obj);
"adm/daemons/xyjobd"->xy_attackql();

}
else if(obj->query("id") == "zhuque chengmen")
{
obj->delete("defend");
message_vision(YEL""+obj->query("name")+YEL"再也禁受不住冲车的撞击，哗啦一声塌了。\n"NOR, me);
destruct(obj);
"adm/daemons/xyjobd"->xy_attackzq();

}
else if(obj->query("id") == "xuanwu chengmen")
{
obj->delete("defend");
message_vision(YEL""+obj->query("name")+YEL"再也禁受不住冲车的撞击，哗啦一声塌了。\n"NOR, me);
destruct(obj);
"adm/daemons/xyjobd"->xy_attackxw();

}
}
return 1;
}
