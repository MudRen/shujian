// /clone/armor/yellow-cloth.c
// by dubei

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(YEL "��ɫɮ��" NOR, ({ "seng pao", "cloth" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɫɮ��,�����½�����һ�Ѵ�Ѫ�Ķ̵���\n"
                            "������������Ѫ����,Ҳ�Ǻ������,��̬����,ʮ�ֿɲ�.\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 40);
                set("wear_msg","$N����һչ,��$n�������ϡ�\n");
                set("remove_msg","$N��$n����������������\n");
        }
        setup();
}

