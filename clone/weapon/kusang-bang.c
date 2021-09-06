// kusang_stick.c ��ɥ��
// by hunthu 99/7

#include <ansi.h>
#include <weapon.h>
inherit STICK;
inherit F_UNIQUE;
void create()
{
        set_name("��ɥ��", ({"kusang bang", "bang", "stick"}));
        set("weight",12000);
        if (clonep())
               set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "һ���ںڵ��������������ƺ���ʲô�Ź֡�\n");
               set("value", 1000);
               set("unique", 1);
               set("material", "blacksteel");
               set("rigidity", 3);
               set("wield_neili", 500);
               set("wield_maxneili", 900);
               set("wield_str", 22);
               set("weapon_prop/parry", 2);
               set("treasure",1);
               set("wield_msg", "$N����һЦ�ӱ�����һ���ڰ��ӡ�\n");
               set("unwield_msg", "$N�����еĿ�ɥ�����ر���\n");
               set("chanchu_poison",3);
        }
        init_stick(55);
        setup();
}
 
void init()
{
       add_action("do_throw", "she");
}

int do_throw(string arg)
{
       object me, ob;
       int i, damage;
       string msg;

       me = this_player();
       if (!arg || arg == "")   return 0;
       ob = present(arg, environment(me));
       if (!ob) return 0;
       if(! me->is_fighting(ob)) return notify_fail("�������ս���в���ʹ��.\n");
       i = ob->query_skill("dodge", 1) + ob->query_skill("parry", 1);
       i = random(i/2) - 10;
       damage = me->query_skill("poison", 1)+me->query_str()*2;
       if (!arg) return notify_fail("��Ҫ��˭���֣�\n");       
       if (!ob) return notify_fail("�Ҳ���������\n");
       if( environment(me)->query("no_fight") )
                return notify_fail("�㲻�������ﶯ�֡�\n");
       if(me->is_busy())
                return notify_fail("����æ���ء�\n");
       if(me->query("neili") < 500)
             return notify_fail("������������������֡�\n");
       if(this_object()->query("chanchu_poison")<1)
            return notify_fail("��ɥ���������ܶ����Ѿ��þ��ˣ��޷������������ˡ�\n");
       msg = HIW"\n$Nһ����Ц���������׻��飬һ�ɱ��̵���ܶ�����$n�����ȥ��\n"NOR;       
       me->start_busy(2);
       me->add("neili", -100);
       me->add("jingli", -20);
       if(me->query_skill("bangjue", 1) > i
        && random(ob->query("kar")) < 10
        &&random(me->query("combat_exp")) > (int)ob->query("combat_exp")/2 ) {
          msg += HIR"$n����֮�У�ֻ��$n��æ��Ծ���ܣ�������Ȼ���벻�ٶ���ҡҡ��׹��\n"NOR;
          ob->apply_condition("chanchu_poison", 70);
          ob->receive_wound("jing", damage/2);
          ob->set_temp("last_damage_from", "��"+me->name()+"ɱ");
       }
       else {
          msg +=HIY"����������죬$n������Ծ֮��ȴ�Ǹ��죬ֻ������һ��,�����ѱ�$n����������������ʧ�޼���\n"NOR;
          ob->add("jingli", -10);
       }              
       message_vision(msg, me, ob);
       if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
       this_object()->add("chanchu_poison",-1); 
       return 1;
}
