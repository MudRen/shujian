// /d/dzd/obj/pimao.c

#include <armor.h>
inherit HEAD;

void create()
{
	set_name("Ƥñ",({"pi mao","mao"}));
	set_weight(50);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ������ʷ�����ֵ�ѱ��ʱ���µ�Ƥñ����˵��������ô���\n");
		set("value",10000);
             set("dzd",1);

		set("unit","��");
              	set("armor_prop/armor", 60);
              	set("no_animal",1);
              	set("material", "cloth");
		set("wear_msg","$N����һ��Ƥñ��������ͷ�ϡ�\n");
	}
	setup();
}
