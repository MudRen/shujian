//jingzuo.c
// ����

#include <ansi.h>
#include <skill.h>

void init()
{
	add_action("do_jingzuo", "jingzuo");
}

int jingzuoing(object me);
int halt_jingzuo(object me);


int do_jingzuo(object me, string arg)
{
        int lvl, cycle;
        object where;

        seteuid(getuid());
        where = environment(me);

        if( me->query_temp("pending/jingzuo") )
                return notify_fail("���Ѿ��ھ����ˡ�\n");

        if( me->query_condition("over_zuochan") > 0 )
                return notify_fail("������Ļس�����Ƶ���뾲�س���������ħ����\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

      if( me->query("family/family_name") != "������" )
              return notify_fail("���Ƕ����ɵ���������Ϲ��ʲô�ң�\n");


        lvl = (int)me->query_skill("dacheng-fofa", 1);
        if( lvl < 30 )
                return notify_fail("���˷�δ����򣬲��ܾ���������\n");

        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 50 )
                return notify_fail("�����ھ��������޷�������ħ������\n");

        if( present("muyu chui", me) )
                message_vision("\nֻ���ˣ��ˣ��ˣ�$N��ľ������˼��¡�\n", me);
        write("����ϥ����������Ƭ�̱������һ���������\n");

        tell_room(where,
                me->name() + "��ϥ���£������۾���ʼ������\n", me);

        cycle = 2000 / (30 + lvl);

                cycle *= 2;

        me->set_temp("pending/jingzuo", 1);
        me->set_temp("jingzuo/period", 1);
        me->set_temp("jingzuo/cycle", cycle);

        me->start_busy((: jingzuoing :), (: halt_jingzuo :));
        return 1;
}

int jingzuoing(object me)
{
        //object where = environment(me);
        int period = (int)me->query_temp("jingzuo/period");
        int cycle = (int)me->query_temp("jingzuo/cycle");
        int bonus = 0;

        if( (int)me->query_skill("dacheng-fofa", 1) > 99 && present("muyu chui", me) ) {
                bonus = 2;
                cycle = cycle * 4 / 5;
        }

        if( me->query("food") + me->query("water") < 20 )
                cycle *= 2;
  
    
        if( present("muyu chui", me) && period % 4 == 1 )
                message_vision("\nֻ���ˣ��ˣ��ˣ�$N��ľ������˼��¡�\n", me);

        if( period == 1 )
        if( random(10) > (1 + bonus) ) {
                write("�������Χ̫�����ӣ������뾲��\n");
                period = 0;
        }

        if( period % 4 == 2 )
        switch(random(4)) {
        case 0:
               write(HIW"
��ʱ����������˵�Ǿ��������Ȥ�����ᱯ�������׷��ԣ���ϣ�У���
�𣡷�˵��������䣬�Ҵ��������û��ۣ�δ����������֮��������
�������˵����Ǿ��������徻������ʵ�࣬��֪���ˣ��ɾ͵�һϣ�й�
�¡�������ʵ���ߣ����Ƿ��࣬�ǹ�����˵��ʵ�ࡣ�����ҽ����
���Ǿ��䣬�Ž��ֲܳ���Ϊ�ѣ�����������������꣬��������������
�Ǿ����Ž��֣ܳ�������Ϊ��һϣ�С����Թʣ����������ࡢ���ࡢ��
���ࡢ�����ࡣ�����ߺΣ����༴�Ƿ��࣬���ࡢ�����ࡢ������
���Ƿ��ࡣ���Թʣ���һ�����࣬������𡣡�           
 \n"NOR);
               break;
        case 1:
               write(GRN"
�������ᣡ���������ǡ��������ԣ����ҵ����������������������
�������Թʣ������ᣡ���з���Ϊ�������ǹʷ�˵��һ�з����ҡ����ˡ�
�������������ߡ������ᣡ�����������ԣ����ҵ�ׯ�Ϸ��������ǲ���
���������Թʣ�����˵��ׯ�Ϸ����ߣ�����ׯ�ϣ�����ׯ�ϡ������ᣡ
������ͨ�����ҷ��ߣ�����˵������������
\n"NOR);
               break;
        case 2:
               write(CYN"
�ƺ������������ӣ�һ����������ʼ�������ֵߵ����������ˣ��ķ���
���������Ĵ�Ϊ�����࣬����Ե��Ϊ�����ࡣƩ�˲�Ŀ�����л����ڶ�
�������ӣ���ʵ�޻���������ִ������ִ�ʣ���Ψ���������ԣ��ิ
�Ա�ʵ���������ɴ�������ת�����������������������ߣ�����ʵ�塣
�������ˣ���ʱ���ޣ�������ѣ��������á����ڿջ������գ�����
��˵�ж��𴦡����Թʣ��������ʣ�һ������������У�����������
��˵����ת������
\n"NOR);
               break;
        case 3:
               write(HIY"
�����ᣡ�����ȥ����������������ˣ��ڶ������������ࡢ�����ࡢ
�������ࡢ�������ࡣ�ǹ������ᣡ����Ӧ��һ���࣬�������������
�������ģ���Ӧסɫ���ģ���Ӧס����ζ�������ģ�Ӧ������ס�ġ���
����ס����Ϊ��ס���ǹʷ�˵�������Ĳ�Ӧסɫ��ʩ�������ᣡ����Ϊ
����һ��������Ӧ���ǲ�ʩ������˵��һ�����࣬���Ƿ��ࡣ��˵��һ
����������������������ᣡ�����������ߡ�ʵ���ߡ������ߡ���ڿ��
�ߡ��������ߡ������ᣡ�������÷����˷���ʵ���顣�����ᣡ������
��ס�ڷ����в�ʩ�������밵�������������������Ĳ�ס�ڷ����в�ʩ��
������Ŀ���չ����գ�������ɫ�������ᣡ����֮�������������ӡ���
Ů�ˣ����ڴ˾��ֶܳ��У���Ϊ�����Է��ǻۣ�Ϥ֪���ˣ�Ϥ�����ˣ�
�Եóɾ������ޱ߹��¡�
\n"NOR);
                break;
        }

        if (random(12) == 5) {
                me->update_condition();
                if ( (int)me->query("water") > 0 ) me->add("water", -1);
                if ( (int)me->query("food") > 0 ) me->add("food", -1);
        }

        me->improve_skill("dacheng-fofa", 1 + random(3));

        if( period >= cycle ) {
                period = 0;
                write(HIW"
��֪���˶�ã������ڷ𷨵��������ȫ���עȥ������ָо�����
��Ȼ��ȴ��ʱ�䡣��������һ�ᣬ����Ƿ�������������غ���һ��    
��������ʱ��һ�ַ��ޱߵĸо���
\n"NOR);

                me->receive_curing("jing", me->query_con());
                me->receive_heal("jing", me->query_con());
                me->improve_skill("dacheng-fofa", me->query("int") + random(3 * me->query("int")));
                  me->add("potential", (int)me->query_skill("dacheng-fofa", 1) / 10 + random(25));
// (jingzuoֻ�õ�pot������exp,����˵һ��) me->add("combat_exp", (int)me->query_skill("dacheng-fofa", 1) / 15);

                if( me->query_temp("apply/jingzuo") < me->query("int") * me->query("int") / 6 ) { 
                        me->add_temp("apply/jingzuo", 1);
                }

                
        }
                       
        period++;
        me->set_temp("jingzuo/period", period);
        return 1;
}

int halt_jingzuo(object me)
{
        me->delete_temp("pending/jingzuo");
        me->start_busy(1 + random(3));
          me->apply_condition("over_jingzuo", 3 + random(3));
        
        return 1;
}

int update_condition(object me, int duration)
{
        if (duration < 1) {
                return 0;
        }
        me->apply_condition("over_jingzuo", duration - 1);
        return 1;
}
