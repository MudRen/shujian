//jiaowei qin ��β��

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(MAG"��β��"NOR,({"jiaowei qin","qin", "jiaowei"}));
	set_weight(10000);
	if(clonep())
		set_default_object(__FILE__);
	else{
		set("unit","��");
		set("value",3000);
		set("material","steel");
		set("unique", 1);
		set("rigidity", 5);
		set("treasure",1);
		set("long","�ഫ����ǵ�����ļ��ӻ������ȳ��Ľ�ľ���ɵ����٣��ٵ�β���Կɼ�����ɫ��\n");
		set("wield_msg",HIY"$N��������һ�ӣ�һ��$n"HIY"���ѳ�����$N���С�\n"NOR);
		set("unwield_msg",HIY"$Nʮָһ��������ҷȻ��ֹ��$N����$n"HIY"���Ž����ŵİ����\n"NOR);
	}
	init_sword(60);
	setup();
}

void init()
{
	if (environment() == this_player())
		add_action("do_ba", "ba");
}

int flag = 0;

int do_ba(string arg)
{
	object me = this_player();
	object ob;

	if (arg != "sword" && arg != "jian")
		return 0;
	if (query("equipped"))
		return notify_fail("������Ȱ��ٷ�������\n");
	if (flag || !(ob  = unew(BINGQI_D("sword/qz-jian")))) {
		flag = 1;
		return notify_fail("�����ѿ���һ�\n");
	}
	ob->move(me);
	message_vision("$N���±��ϵ�"+name()+"�����ٵ׳��һ�ѱ�������������������������ˡ�\n",me);
	destruct(this_object());
	return 1;
}
