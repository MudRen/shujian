// OBJ : /d/wudang/obj/cloth.c �಼��ȹ
// By lius 99/8
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�಼��ȹ", ({"cloth", "huaqun"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
		set("long", "һ����ͨ���಼������ȹ��\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
