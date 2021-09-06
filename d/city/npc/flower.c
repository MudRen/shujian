#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create()
{       
	switch (random(9)){
		case 0: set_name(HIC "Ұ�ջ�" NOR, ({ "ye juhua", "flower"})); set("unique", 1);break; 
		case 1: set_name(HIY "�ƺ���" NOR, ({ "huang heling", "flower"})); break; 
		case 2: set_name(HIW "�׾ջ�" NOR, ({ "bai juhua", "flower"})); break; 
		case 3: set_name(HIR "���˺�" NOR, ({ "meiren hong", "flower"})); break;
		case 4: set_name(HIC "Ұ�ջ�" NOR, ({ "ye juhua", "flower"})); set("unique", 1);break; 
		case 5: set_name(YEL "���ȸ" NOR, ({ "jin kongque", "flower"})); break; 
		case 6: set_name(HIY "ݺ���" NOR, ({ "yin yuhuang", "flower"})); break; 
		case 7: set_name(WHT "��¥��" NOR, ({ "yu louchun", "flower"})); break; 
		case 8: set_name(HIC "Ұ�ջ�" NOR, ({ "ye juhua", "flower"})); set("unique", 1);break; 
		case 9: set_name(HIM "�һ���" NOR, ({ "tao hongju", "flower"})); break; 
	}
	set_weight(100);
	set("long","һ�����µ�����С"+query("name")+"��ɢ����һ˿˿���㡣\n");
	set("material", "flower");
	set("unit", "��");
	set("armor_prop/armor", 1);
	set("armor_prop/personality", 1);
	setup();
}

int init ()
{
	add_action ("do_wear", "wear");
	add_action ("do_wear", "dai");
	add_action ("do_remove", "remove");
	add_action ("do_smell", "smell");
	add_action ("do_smell", "wen");
	call_out("need_water", 10+random(10), environment(this_object()));
	return 1;
}

int do_wear (string arg)
{
	object flower = this_object();
	string name = flower->query("name");
	string msg;

	if (arg != "flower" && arg != "ju hua")
		return 0;
	msg = "$N����һ��"+name+"��С������ʱ�ǵ�ͨ�졣\n"; 
	flower->set("wear_msg",msg);
	return 0;
}

int do_remove (string arg)
{
	object flower = this_object();
	string name = flower->query("name");
	string msg;

	if (arg != "flower" && arg != "ju hua")
		return 0;

	msg = "$N��"+name+"�����ժ��������\n"; 
	flower->set("unequip_msg",msg);
	return 0;
}

int do_smell (string arg)
{
	object me = this_player();
	object flower = this_object();
	string name = flower->query("name");
	string msg;

	if (arg != "flower" &&  arg != "ju hua")
		return 0;

	msg = "$N��"+name+"���������ţ��ֵ��������Ĺ��ˡ�\n"; 
	message_vision (msg,me);
	return 1;
}
