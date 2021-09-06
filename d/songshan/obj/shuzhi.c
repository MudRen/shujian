// shuzhi.c
// Created by Numa 1990805

#include <ansi.h>
#include <weapon.h>
inherit F_SWORD;
inherit F_EQUIP;
inherit COMBINED_ITEM;

void set_amount(int count)
{
    unequip();
        set("weapon_prop/damage", 10*count);
        set("long", "����"+CHINESE_D->chinese_number(count)+"֦��֦��\n");
       :: set_amount(count);
}

void create()
{
        set_name( MAG"��֦"NOR, ({ "shu zhi", "zhi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
               set("base_unit", "��");
               set("base_value", 0);
               set("base_weight", 100);
                set("long", "����һ֦��֦��\n");
                set("value", 0);
                set("material", "wood");
                set("wield_msg", "$N�ó�$n���������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        set_amount(1);
        setup();
}

void init()
{
        object me = this_player();
        if (present("shu zhi",me))
                add_action("do_cuo","cuo");
}

int do_cuo(string arg)
{
        object me = this_player();
        if (!arg)
                return notify_fail("ʲô��\n");
        if (arg == "songzhi" || arg == "shuzhi" || arg == "shu zhi" || arg == "zhi")
        {
                if (this_object()->query_amount() <2)
                        return notify_fail("�������֦����ĳ�������ĩ��\n");
                new(__DIR__"sheng")->move(me);
                message_vision("$N�������������¾ͽ����е���֦�����һ��������\n",me);
                call_out("destroy",1,this_object());
               return 1;
        }
        else
                return notify_fail("��Ҫ��ʲô��\n");
}

void destroy(object ob)
{
        destruct(ob);
}
