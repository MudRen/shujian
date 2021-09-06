// qingming-jian.c by caiji@SJ 8/24/2000
//
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(CYN"��ڤ��"NOR, ({"qingming jian", "sword", "jian","qingming"}));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�˽�ǣ������������Թ�����İ��������������ʮ�־�����\n"+
"�����߾ţ���һ��һ������һ�磬������������ߴ磬������һ���塣\n"+
"�������أ��������ǣ��ӽ������ƿ������������������������������ʧ���ˡ�\n");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 4);
                set("sharpness", 4);
                set("material", "steel");
                set("weapon_prop/parry", 2);
                set("weapon_prop/dodge", 2);
                set("treasure",1);       
                set("wield_neili", 500);
                set("wield_maxneili", 700);
                set("wield_str", 20);
                set("wield_msg",HIC"\nֻ����ৡ���һ����$N�������һ���������ı������������˵�������\n"NOR);
                set("unwield_msg",HIC"$N�����е���ڤ������������\n"+
                "�˽�������á��ƺ����л��������һЩ���˵ĵ���\n"NOR);
        }
        init_sword(45);
        setup();
}
void init()
{
    add_action("do_add", "��");
    add_action("do_add", "cha");
}

int do_add(string arg)
{
     object me,ob, obj, zhang;
     me = this_player();
     ob = this_object();
     obj = present("jian qiao", me);
     if(arg!="jian" && arg!="��")
           return notify_fail("�����ʲô��������\n");
     if(!objectp(obj))
           return notify_fail("��û�н��ʣ���ѽ��嵽����ȥ����\n");
     if((int)me->query("neili") < 150)
                return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������޷��������뽣�ʣ�\n");
     me->add("neili", -100);
     message_vision(HIY"\nֻ�����һ����$N����ڤ�����뽣���У���Ϊһ���ֵܴĸ��ȡ�\n"NOR, me);
     destruct(obj);   
     zhang = new(BINGQI_D("staff/gangzhang-sp"))->move(me, 1);     
     destruct(ob);
     return 1;
}
     