// Modify By River 98/12
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"�Ƽ���"NOR, ({ "tuijian xin", "xin", "letter" }));
        set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit","��");
		set("long","����һ���������ױ�������Ƽ��ţ�����д���������˻���ʦ�ġ�\n");
                set("no_get", 1);              
                set("material", "paper");
         }
}
