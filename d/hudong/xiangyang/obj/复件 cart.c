#include <ansi.h>
#include <room.h>
inherit ITEM;

void create()
{
	set_name(HIR"�峵"NOR, ({ "chong che", "che", "cart"}) );
	set_weight(300000);
	set("no_get", 1);
	set("no_get_from", 1);
	set_max_encumbrance(80000);
	set("unit", "��");
	set("long", "һ��������ĺ��س峵��ר�ų�����Ŷ��á�\n");
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
return notify_fail("������æ�úܣ�����ָ�ӳ峵ǰ����\n");
if (query_temp("busy/"+me->query("id")))
		return notify_fail("�峵�н��ٶȺ������ȵȰɡ�\n");
if(query("make") != me->query("id"))
return notify_fail("�����峵����������ݵġ�\n");

room = environment(cart);

	roomfile = file_name(room);

switch(arg) {
		case "e":	dir="east";		dirname="����";		break;
		case "w":	dir="west";		dirname="����";		break;
		case "n":	dir="north";		dirname="����";		break;
		case "s":	dir="south";		dirname="����";		break;
		case "ne":	dir="northeast";	dirname="����";		break;
		case "nw":	dir="northwest";	dirname="����";		break;
		case "se":	dir="southeast";	dirname="����";		break;
		case "sw":	dir="southwest";	dirname="����";		break;
		case "u":	dir="up";		dirname="����";		break;
		case "up":	dir="up";		dirname="����";		break;
		case "d":	dir="down";		dirname="����";		break;
		case "down":	dir="down";		dirname="����";		break;
		case "nu":	dir="northup";		dirname="����";		break;
		case "eu":	dir="eastup";		dirname="����";		break;
		case "su":	dir="southup";		dirname="�ϱ�";		break;
		case "wu":	dir="westup";		dirname="����";		break;
		case "nd":	dir="northdown";	dirname="����";		break;
		case "ed":	dir="eastdown";		dirname="����";		break;
		case "sd":	dir="southdown";	dirname="�ϱ�";		break;
		case "wd":	dir="westdown";		dirname="����";		break;
		case "enter":	dir="enter";		dirname="����";		break;
		case "out":	dir="out";		dirname="����";		break;
		default:	dir=arg;		dirname="һ��";		break;
	}
	if(!room || !room->query("exits/"+dir))
		return notify_fail("��Ҫ������ȥ��\n");

newroomfile=room->query("exits/"+dir);

if(!objectp(newroom=find_object(newroomfile))) newroom=load_object(newroomfile);

	message_vision(HIW"�峵��$N����ʹ�»�������"+dirname+"��"+newroom->query("short")+HIW"��ȥ�ˡ�\n"NOR, me);

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
		
return notify_fail("��Ҫ�ó峵ȥ��ײʲô��\n");
if(!obj->query("defend"))
return notify_fail("�ⶫ���õ��ų峵ô��\n");

if( me->is_busy() || me->is_fighting())
return notify_fail("������æ�úܣ�����ָ�ӳ峵��ײ��\n");
if(query("make") != me->query("id"))
return notify_fail("�����峵����������ݵġ�\n");
message_vision(YEL"$Nָ���ų峵���ҵ���"+obj->query("name")+YEL"ײȥ���������ľ��죬һʱ�䳾�����\n"NOR, me);

obj->add("defend",-random(10));
message_vision(YEL""+obj->query("name")+YEL"�ļ�̻���"+obj->query("defend")+"��\n"NOR, me);
me->start_busy(random(3));

if(obj->query("defend") <= 0 )
{
if(obj->query("id") == "baihu chengmen")
{
obj->delete("defend");
message_vision(YEL""+obj->query("name")+YEL"��Ҳ���ܲ�ס�峵��ײ��������һ�����ˡ�\n"NOR, me);
destruct(obj);
"adm/daemons/xyjobd"->xy_attackbh();

}
else if(obj->query("id") == "qinglong chengmen")
{
obj->delete("defend");
message_vision(YEL""+obj->query("name")+YEL"��Ҳ���ܲ�ס�峵��ײ��������һ�����ˡ�\n"NOR, me);
destruct(obj);
"adm/daemons/xyjobd"->xy_attackql();

}
else if(obj->query("id") == "zhuque chengmen")
{
obj->delete("defend");
message_vision(YEL""+obj->query("name")+YEL"��Ҳ���ܲ�ס�峵��ײ��������һ�����ˡ�\n"NOR, me);
destruct(obj);
"adm/daemons/xyjobd"->xy_attackzq();

}
else if(obj->query("id") == "xuanwu chengmen")
{
obj->delete("defend");
message_vision(YEL""+obj->query("name")+YEL"��Ҳ���ܲ�ס�峵��ײ��������һ�����ˡ�\n"NOR, me);
destruct(obj);
"adm/daemons/xyjobd"->xy_attackxw();

}
}
return 1;
}
