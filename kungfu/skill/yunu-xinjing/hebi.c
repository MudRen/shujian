// hebi.c �ϱ�
// by Yu Jue 98/7
// Modify by River 98/10
// server ���ŵ���Hebi

#include <ansi.h>
string exert_name(){ return HIW"˫���ϱ�"NOR; }
int exert(object me, object target)
{
        object *enemy;
        int i,j;
        mapping fam,fam1;
        object weapon1,weapon = me->query_temp("weapon");

      if (!target || (target == me && !me->query("double_attack"))) return notify_fail("��Ҫ��˭�ϱڣ�\n");
    
        if (!target || (target == me && me->query("gender")=="����")) return notify_fail("��Ҫ��˭�ϱڣ�\n");
        if( ! present(target,environment(me))) return notify_fail("�������������\n");
        if (me->query_temp("hebi")) return notify_fail("���Ѿ��ںϱ��ˡ�\n");
        if (target->query_temp("hebi")) return notify_fail("���Ѿ��ںϱ��ˡ�\n");
        if (me->query("jingli") < 200) return notify_fail("��ľ��������ˡ�\n");
        if (target->query("jingli") < 200) return notify_fail("�Է��ľ��������ˡ�\n");
        if (!me->is_fighting()) return notify_fail("�ϱ�ֻ����ս����ʹ�á�\n");
        if (me->is_fighting(target)) return notify_fail("�����ںͶԷ���ܣ��ϱڸ�ʲô��\n");
        if ((int)me->query_temp("gumu_suxin")) return notify_fail("����������ʹ�á���Ů���ġ�������\n");
        if((int)target->query_temp("gumu_suxin")) return notify_fail("�Է���������ʹ�á���Ů���ġ�������\n"); 

        fam= me->query("family");
        fam1= target->query("family");
        if (!fam || fam["family_name"] != "��Ĺ��")
                return notify_fail("�㲻�ǹ�Ĺ������ô�ܺϱڣ�\n");
        if (!fam1 || fam1["family_name"] != "��Ĺ��")
                return notify_fail("�Է����ǹ�Ĺ���ӣ����ܺ���ϱڣ�\n");

        if((string)me->query("gender") =="Ů��" 
         && (int)me->query_skill("yunu-jianfa", 1) < 100 )
                return notify_fail("�����Ů����������죬����ʹ�úϱڡ�\n");
        if((string)me->query("gender") =="����" 
         && (int)me->query_skill("quanzhen-jianfa", 1) < 100 )
                return notify_fail("���ȫ�潣��������죬����ʹ�úϱڡ�\n");

        if ((string)me->query("gender")=="Ů��" 
        && (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yunu-jianfa"
        || me->query_skill_mapped("parry") != "yunu-jianfa"))
                return notify_fail("�������޷��ϱڡ�\n");
        if ((string)me->query("gender")=="����" 
        && (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "quanzhen-jianfa"
        || me->query_skill_mapped("parry") != "quanzhen-jianfa"))
                return notify_fail("�������޷��ϱڡ�\n");

        if( me->query("id") != target->query("marry/id") && !me->query("double_attack"))
                return notify_fail("�Է����������ż�����������޷��ﵽ˫���ϱ�����Ҫ���⾳��\n");

        enemy = me->query_enemy();
        i = sizeof(enemy);
        while (i--) if (target->is_fighting(enemy[i])) break;
        if (i<0) return notify_fail(target->name()+"��û�к���Ķ����ڽ�ս��\n");

        if((string)me->query("gender")=="����" 
         && (int)target->query_skill("yunu-jianfa", 1) < 100)
                return notify_fail("�Է�����Ů����������죬����ʹ�úϱڡ�\n");
        if((string)me->query("gender")=="Ů��"
         && (int)target->query_skill("quanzhen-jianfa", 1) < 100)
                return notify_fail("�Է���ȫ�潣��������죬����ʹ�úϱڡ�\n");

        weapon = target->query_temp("weapon");
        if ((string)target->query("gender")=="Ů��"
        && (target->is_busy() || !weapon || weapon->query("skill_type") != "sword"
        || target->query_skill_mapped("sword") != "yunu-jianfa"
        || target->query_skill_mapped("parry") != "yunu-jianfa"))
                return notify_fail("�Է������޷��ϱڡ�\n");
        if ((string)target->query("gender")=="����" 
        && (target->is_busy() || !weapon || weapon->query("skill_type") != "sword"
        || target->query_skill_mapped("sword") != "quanzhen-jianfa"
        || target->query_skill_mapped("parry") != "quanzhen-jianfa"))
                return notify_fail("�Է������޷��ϱڡ�\n");

        if (target == me)
    message_vision(HIY "\n$N�������һ���֮������Ȼ���书������һ��ͬʹ��������֮˫���ϱڣ�������ǿ��\n\n" NOR, me);
        else
        message_vision(HIY "\n$N���������������⣬��������$n�����˽Բ��ض����أ�˫��֮����Ȼ������\n\n" NOR, me, target);
        me->set_temp("hebi", 1);
        target->set_temp("hebi", 1);
        me->receive_damage("jingli", 100);
        target->receive_damage("jingli", 100);
 //       me->start_busy(1);
 //      target->start_busy(1);
        if ((string)me->query("gender")=="Ů��")
        i = me->query_skill("yunu-jianfa", 1) / 3;
        if ((string)me->query("gender") =="����")
        i = me->query_skill("quanzhen-jianfa", 1) / 3;
        if ((string)target->query("gender") =="����")
        j = target->query_skill("quanzhen-jianfa", 1) / 3;
        if ((string)target->query("gender") =="Ů��")
        j = target->query_skill("yunu-jianfa", 1) / 3;

        me->add_temp("apply/parry", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/sword", i);
        me->add_temp("apply/damage", i);
        me->add_temp("apply/dodge", i);

        target->add_temp("apply/parry", j);
        target->add_temp("apply/attack", j); 
        target->add_temp("apply/sword", j);
        target->add_temp("apply/damage", j);
        target->add_temp("apply/dodge", j);

        weapon = me->query_temp("weapon");
        weapon1 = target->query_temp("weapon");
        if( me->query("gender") == "����" 
         && weapon->query("id") == "junzi jian" 
         && target->query("gender") == "Ů��" 
         && weapon1->query("id") =="shunu jian"){
          me->set_temp("double_attack", 1);
          target->set_temp("double_attack", 1);
        }
        if( me->query("gender") == "Ů��" 
         && weapon->query("id") == "shunu jian" 
         && target->query("gender") == "����" 
         && weapon1->query("id") =="junzi jian"){
          me->set_temp("double_attack", 1);
          target->set_temp("double_attack", 1);
        }
        call_out("hebi", 1, me, target, environment(me), i, j, (i+j)/5);
        return 1;
}

void hebi(object me, object target, object env, int i, int j, int count)
{
        object weapon;

        if (!me && !target) return;
        if (!me && target) {
                tell_room(env, HIY "\n�ϱ��Զ��߽⡣\n" NOR);

        target->add_temp("apply/parry",- j);
        target->add_temp("apply/attack", -j); 
        target->add_temp("apply/sword",- j);
        target->add_temp("apply/damage",- j);
        target->add_temp("apply/dodge",- j);


                target->delete_temp("double_attack");
                target->delete_temp("hebi");
                return;
        }
        if (me && !target) {
                tell_room(env, HIY "\n�ϱ��Զ��߽⡣\n" NOR);

        me->add_temp("apply/parry",- i);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/sword",- i);
        me->add_temp("apply/damage",- i);
        me->add_temp("apply/dodge",- i);

                me->delete_temp("double_attack");
                me->delete_temp("hebi");
                return;
        }
        weapon = me->query_temp("weapon");
        if ((string)me->query("gender") =="����" 
        && (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "quanzhen-jianfa"
        || me->query_skill_mapped("parry") != "quanzhen-jianfa")) {
                tell_room(env, HIY "�ϱ��Զ��߽⡣\n" NOR);

        me->add_temp("apply/parry",- i);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/sword",- i);
        me->add_temp("apply/damage",- i);
        me->add_temp("apply/dodge",- i);

                me->delete_temp("hebi");
                me->delete_temp("double_attack");

        target->add_temp("apply/parry",- j);
        target->add_temp("apply/attack", -j); 
        target->add_temp("apply/sword",- j);
        target->add_temp("apply/damage",- j);
        target->add_temp("apply/dodge",- j);

                target->delete_temp("hebi");
                target->delete_temp("double_attack");
                return;
        }
        if ((string)me->query("gender") =="Ů��" 
        && (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yunu-jianfa"
        || me->query_skill_mapped("parry") != "yunu-jianfa")) {
                tell_room(env, HIY "�ϱ��Զ��߽⡣\n" NOR);
  


        me->add_temp("apply/parry",- i);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/sword",- i);
        me->add_temp("apply/damage",- i);
        me->add_temp("apply/dodge",- i);

                me->delete_temp("hebi");
                me->delete_temp("double_attack");

        target->add_temp("apply/parry",- j);
        target->add_temp("apply/attack", -j); 
        target->add_temp("apply/sword",- j);
        target->add_temp("apply/damage",- j);
        target->add_temp("apply/dodge",- j);

                target->delete_temp("hebi");
                target->delete_temp("double_attack");
                return;
        }
        weapon = target->query_temp("weapon");
        if ((string)target->query("gender") =="����"
        && (!weapon || weapon->query("skill_type") != "sword"
        || target->query_skill_mapped("sword") != "quanzhen-jianfa"
        || target->query_skill_mapped("parry") != "quanzhen-jianfa")) {
                tell_room(env, HIY "�ϱ��Զ��߽⡣\n" NOR);

        me->add_temp("apply/parry",- i);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/sword",- i);
        me->add_temp("apply/damage",- i);
        me->add_temp("apply/dodge",- i);


                me->delete_temp("hebi");
                me->delete_temp("double_attack");

                target->delete_temp("double_attack");

        target->add_temp("apply/parry",- j);
        target->add_temp("apply/attack", -j); 
        target->add_temp("apply/sword",- j);
        target->add_temp("apply/damage",- j);
        target->add_temp("apply/dodge",- j);

                target->delete_temp("hebi");
                return;
        }
        if ((string)target->query("gender") =="Ů��" 
        && (!weapon || weapon->query("skill_type") != "sword"
        || target->query_skill_mapped("sword") != "yunu-jianfa"
        || target->query_skill_mapped("parry") != "yunu-jianfa")) {
                tell_room(env, HIY "�ϱ��Զ��߽⡣\n" NOR);
        me->add_temp("apply/parry",- i);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/sword",- i);
        me->add_temp("apply/damage",- i);
        me->add_temp("apply/dodge",- i);
                me->delete_temp("hebi");
                me->delete_temp("double_attack");
                target->delete_temp("double_attack");
        target->add_temp("apply/parry",- j);
        target->add_temp("apply/attack", -j); 
        target->add_temp("apply/sword",- j);
        target->add_temp("apply/damage",- j);
        target->add_temp("apply/dodge",- j);
                target->delete_temp("hebi");
                return;
        }
        if (environment(me) != env || environment(target) != env) {
                tell_room(env, HIY "�ϱ��Զ��߽⡣\n" NOR);
        me->add_temp("apply/parry",- i);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/sword",- i);
        me->add_temp("apply/damage",- i);
        me->add_temp("apply/dodge",- i);
                me->delete_temp("hebi");
                me->delete_temp("double_attack");
                target->delete_temp("double_attack");
        target->add_temp("apply/parry",- j);
        target->add_temp("apply/attack", -j); 
        target->add_temp("apply/sword",- j);
        target->add_temp("apply/damage",- j);
        target->add_temp("apply/dodge",- j);
                target->delete_temp("hebi");
                return;
        }
        if (!me->is_fighting() || !target->is_fighting() || count < 1)
        {
        if (target == me)
                {
                message_vision(HIY "\n$N�ϱ���ϣ��������С�\n" NOR, me);
        me->add_temp("apply/parry",- i);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/sword",- i);
        me->add_temp("apply/damage",- i);
        me->add_temp("apply/dodge",- i);
                  me->delete_temp("hebi");
                  me->delete_temp("double_attack");
                  target->delete_temp("double_attack");
        target->add_temp("apply/parry",- j);
        target->add_temp("apply/attack", -j); 
        target->add_temp("apply/sword",- j);
        target->add_temp("apply/damage",- j);
        target->add_temp("apply/dodge",- j);
                  target->delete_temp("hebi");
                }
                else
                {
                message_vision(HIY "\n$N��$n����һЦ���������С�\n" NOR, me, target);
        me->add_temp("apply/parry",- i);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/sword",- i);
        me->add_temp("apply/damage",- i);
        me->add_temp("apply/dodge",- i);
                  me->delete_temp("hebi");
                  me->delete_temp("double_attack");
                  target->delete_temp("double_attack");
        target->add_temp("apply/parry",- j);
        target->add_temp("apply/attack", -j); 
        target->add_temp("apply/sword",- j);
        target->add_temp("apply/damage",- j);
        target->add_temp("apply/dodge",- j);
                  target->delete_temp("hebi");

                }
                return;
        }
        call_out("hebi", 1, me, target, env, i, j, count - 1);
}
int help(object me)
{
write(HIW"\n��Ů�ľ���˫���ϱڡ���"NOR"\n");
write(@HELP
��ʽҪ����޶���ͬʱʩչ����ʹ�ã���ʹȫ�潣��Ůʹ��Ů���Ľ�����
����ȫ�潣������Ů���Ľ����ศ��ɵ��ɺ�ʩչ������覵����������
��ʤǿ����������ϰ�����һ���֮�������������Ǿ��ˣ�

      Ҫ������ 300 ���ϣ�
            ���� 200 ���ϣ�
            ��Ů���� 100 ���ϣ�
            ȫ�潣�� 100 ���ϣ�

HELP
);
return 1;
}
