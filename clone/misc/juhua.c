// juhua.c �ջ�
// creat by Lklv@SJ for ��λ��Ů @@

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
	set_name(HIY"�ջ�"NOR, ({"ju hua", "juhua", "hua"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
        else {
        	set("unit","��");
		set("value",150);
		set("female_only", 1);
        	set("armor_prop/armor", 1);
		set("long", "����һ�������ľջ����󴿽����Ů��\n");
		set("wear_msg", "$N����һ��$n���ڷ��ߡ�\n");
		set("remove_msg", "$Nժ�·��ߵ�$n��С������İ����պá�\n"NOR);
	}
        setup();
}
