// /d/dzd/obj/bishou.c

#include <ansi.h>
#include <weapon.h>

inherit DAGGER;
//inherit F_UNIQUE;

void create()
{
	set_name("ذ��",({"bishou","dagger"}));
	set_weight(20000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("material","steel");
		set("value",100000);
		//set("unique",1);
		//set("treasure",1);
		set("long","ذ����������һ�߶��磬��������Ƥ������֮�У���������Ѱ���ĳ����������졣\n");
		set("wield_msg",BLU"$N������ס���������˳�����ֻ��һ�ɺ����������,������ī��ȴ������Ҳû�С�\n"NOR);
		set("unwield_msg",BLU"$N��ذ�ײ�ؽ��ʣ�ϵ���´�֮�ϡ�\n"NOR);
             set("dzd",1);

	}
	init_dagger(180);
	setup();
}