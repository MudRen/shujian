#include <ansi.h>

int main(object me)
{
// �����ʧ
        int cost = 5;

        if (functionp(me->is_busy()) 
         || (me->is_busy() < 5 && me->is_perform() < 3 && me->is_exert() < 3) 
         || me->query_temp("chongxue"))
                return notify_fail("�����ã�С���߻���ħ��\n");
        if (me->query_skill("force") < 400)
                return notify_fail("����ڹ��ȼ�������\n");
        if (me->query("family/family_name") == "�һ���" && me->query_skill("tanzhi-shentong", 1) < 300)
                return notify_fail("��ĵ�ָ��ͨ���������졣\n");
        if (me->query("max_neili", 1) < 5000 || me->query("neili", 1) < 3000)
                return notify_fail("�������������\n");
 
        if (me->is_busy())   
                cost += me->is_busy();
        if (me->is_perform()) 
                cost += me->is_perform();
        else
                cost += 2;
        if (me->is_exert()) 
                cost += me->is_exert();
        else
                cost += 2;
        me->set_temp("last_damage_from","�߻���ħ");
        if (me->query("family/family_name") == "�һ���") 
        {
                message_vision(HBMAG HIC"\n$N�õ�ָ��ͨ�������������账һ������ǿ�⿪���Լ�������������\n"NOR, me);
                me->receive_wound("jing", cost * 30 + random(cost * 30));
                me->add("neili", - cost * 50 - random(cost * 50));
                if (!random(3)) me->start_perform(0);
        }
        else
        {
                message_vision(HBMAG HIG"\n$Nǿ���������������ߣ����ڳ����������Ѩ���Լ�����������\n"NOR, me);
                me->receive_wound("jing", cost * 60);
                me->add("neili", - cost * 100);
        } 
        message_vision(HIR"$N�³�һ����Ѫ��\n"NOR, me);
        if (random(2)) me->set("neili", 0);
        me->add("max_neili", - cost * 2);
        me->set_temp("chongxue",1);
        me->interrupt_me();
        me->start_busy(1, 2);
        me->interrupt_me();
        me->start_exert(0);
        log_file("skills/chongxue",sprintf("[%s] %s(%s)ǿ�г�Ѩ����� %d ���������ˡ�\n",
                ctime(time())[4..19], me->name(), getuid(me), cost * 2 ));
        call_out("finish", 300, me);
        return 1;
} 
 
void finish(object me)
{
        if (!me || !me->query_temp("chongxue"))
                return;
        write(HIY"$N���������˿�������Ϣ�������������ˡ�\n");
        me->delete_temp("chongxue");
}

