// lianzi-wan.c

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
        add_action("do_fu", "fu");
}

void create()
{
        set_name(MAG"���������"NOR, ({"tianxiang duanxugao", "duanxugao", "gao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ɵ��鵤��ҩ�������˵�ʱ����Ͽ��Ժܿ츴ԭ����ҩ�����ң����ú����һ��ʱ���ڲ������κ����顣\n");
                set("no_drop", 1);
                set("no_give", 1);
                set("value", 5000);
                set("no_get", "�����������ò��ˡ�\n");
        }
        setup();
}

int do_fu(string arg)
{
//      int nv;
//      nv = ((int)this_player()->query("max_qi") - (int)this_player()->query("eff_qi")) * 8 / 10;
        object me=this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");

        if ( me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");

        if( me->query_condition("bonze_drug"))
                return notify_fail("�㲻�ǸճԹ�ҩ�������������ˣ� ��ҩ����к����ˣ�����ʱ���ٳ԰ɡ�\n");

        if ((int)me->query("eff_qi") == (int)me->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ����������ࡣ\n");

        else {
                me->set("eff_qi", this_player()->query("max_qi"));
                me->set("qi", this_player()->query("max_qi"));
                message_vision("$N���˿ڷ���һ����������࣬��ɫ�������ö��ˡ�\n", this_player());
                me->set("eff_jing", me->query("max_jing") );
                me->set("jing", me->query("eff_jing") );
                me->set("qi", me->query("eff_qi") );
                me->set("jingli", me->query("eff_jingli") );
                me->set("neili", me->query("max_neili")/10);
                me->start_busy(2);
                me->apply_condition("bonze_drug", 30);
                destruct(this_object());
                return 1;
        }
}
