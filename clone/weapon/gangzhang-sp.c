// gangzhang.c by caiji@SJ 8/24/2000
//
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("����", ({ "gangzhang","gang zhang","zhang" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ȡ�\n");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 7);
                set("sharpness", 6);
                set("material", "steel");
                set("weapon_prop/parry", 2);
                set("weapon_prop/dodge", 2);
                set("treasure",1);  
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������\n");
        }
        init_staff(70);
        setup();
}
void init()
{
    add_action("do_sub",({"ba", "��"}));
}

int do_sub(string arg)
{
     object me, obj;
     me = this_player();
     obj = this_object();
     if(arg!="jian" && arg!="��")
           return 0;
     if((int)me->query("neili") < 150)
                return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������β�����ڤ����\n");
     message_vision(HIY"\nֻ�����һ����$N�Ӹ����аγ�һ����ɫ������ԭ�����ڰ���������\n"NOR, me);
     me->add("neili", -100);
     new(BINGQI_D("sword/qm-jian"))->move(me, 1);
     new(BINGQI_D("sword/qm-qiao"))->move(me, 1);  
     destruct(obj);
     return 1;
}
