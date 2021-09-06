#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("��¨", ({ "yu lou","yulou", "lou" }));
	set_weight(1000);
	set_max_encumbrance(8000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�����ϵ����ӱ��Ƶ���¨����������͸��һ�ɺ�����\n"+
			"�������¨��װ(zhuang)���㶼������ʡ�\n");
		set("value", 1);
	}
	setup();
}

void init()
{
	add_action("do_zhuang","zhuang");
	add_action("do_noput","put");
}

int do_zhuang(string arg)
{
	object ob,obj;
	ob=present("yu lou",this_player());
	obj=present("yu",this_player());

	if(!present("yu lou",this_player())) return notify_fail("������û����¨��\n"); 
	if(!objectp(obj=present("yu",this_player()))) return notify_fail("������û���㡣\n");
	if(!arg || arg !="yu" ) return notify_fail("������¨��ֻ��װ�㣬����װʲô��ȥ��\n");
	if (obj->move(ob)){
		message_vision("$N��һ��"+(string)obj->query("name")+"װ��$n��\n",this_player(),ob);
		return 1;
	}
	return notify_fail(obj->name()+"����¨��˵̫���ˡ�\n");
}

int do_noput(string arg) 
{
	string item, target; 
	if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");
	if(sscanf(arg,"%s in %s",item,target)==2 && target == "lou"||target =="yu lou" ||target =="yulou" ) {
		write("��ֻ���԰���װ(zhuang)����¨�\n");
		return 1; 
	}
}
