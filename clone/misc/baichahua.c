// baichahua.c �ײ軨
// creat by Lklv@SJ for ��λ��Ů @@

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
	set_name(HIW"�ײ軨"NOR, ({"bai chahua", "chahua", "hua"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
        else {
        	set("unit","��");
		set("value",150);
		set("female_only", 1);
        	set("armor_prop/armor", 1);
		set("long", "����һ���ײ軨����ɫ��ף��󴿽����Ů��\n");
		set("wear_msg", "$N����һ��"HIW"�ײ軨"NOR"���ڷ��ߡ�\n");
		set("remove_msg", "$Nժ�·��ߵ�"HIW"�ײ軨"NOR"��С������İ����պá�\n"NOR);
	}
        setup();
}
