#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "ʮ�����ɢ��ҩ" NOR, ({"shixiang ruanjinsan cure", "cure"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 1);
                set("unit", "С��");
        }
       setup();
}

void init()
{ 
        add_action("do_fu","fu");
}

int do_fu(string arg)
{
        object me, ob;
        me=this_player();

        if( !arg || !objectp(ob = present(arg, environment(me))) 
        || !ob->is_character() || ob == me)
                return notify_fail("��˭�ⶾ�أ�\n");
        
        message_vision(HIG"$N��һС��ʮ�����ɢ�Ľ�ҩ��$n�����ˡ�\n"NOR, me, ob);
        ob->clear_condition("ruanjin_poison");
        destruct(this_object());
        return 1;
}

