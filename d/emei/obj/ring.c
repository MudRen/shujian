// zhihuan.c
// ָ��
#include <ansi.h>
#include <armor.h>
inherit FINGER;
inherit F_UNIQUE;
void create()
{
       set_name(HIW"��ָ��"NOR, ({ "zhi huan" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "֧");
               set("long", "����һ֧��ָ�����Ƕ��������ŵ����\n");
               set("value", 100000);
               set("unique", 1);
               set("material", "steel");
               set("armor_prop/armor", 5);
               set("armor_prop/parry", 5);
}
       setup();
}

void init()
{
        add_action("do_stop", "stop");
}

int do_stop(string arg)
{
        object me = this_player();
        object ob;
        if (!arg) return notify_fail("��ҪȰ��˭��\n");
        ob = present(arg, environment(me));
        if (!ob) return notify_fail("��ҪȰ��˭��\n");
        if(ob==me) return notify_fail("������ֱ���� halt ָ��ͺ��ˣ�\n");
        if(!userp(ob) || !ob->is_fighting(me)) return notify_fail("��ͱ��������ˡ�\n");
        if (!ob) return notify_fail("�Ҳ�������ˡ�\n");
message_vision(HIY"$N��������������ָ������$n���������������飬�ѵ��㲻֪���᣿��\n",me,ob);
        message_vision(HIW"$N˵��������˿�������$n����Ǳߡ�\n"NOR,me,ob);
        me->remove_all_enemy();
        ob->remove_all_enemy();
        return 1;
}
