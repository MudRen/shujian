// created by Keepon
// modified by Darken
// �ĳɷǳ�����Ҳ�ܾ�������������ʱ����࣬������١�
// ����������ߵ� 3000000����������Խ�ߣ��õ���Ǳ��Խ�١�
// Modify By River@SJ 2000/3/14 
// Exp ���� 1M ,pot�õ� �Ե���
#include <ansi.h>

int exercising(object me);
int halt_exercise(object me);

int main(object me)
{
        object where;
        seteuid(getuid());
        where = environment(me);
        if(!where->query("jingzuo"))
              return notify_fail("���ﲻ�Ǿ����ĵط���\n");

        if(me->query("family/family_name") != "������")
              return notify_fail("���Ƕ����ɵ���������Ϲ��ʲô�ң�\n");

        if(me->query("class")!="bonze" && me->query_skill("dacheng-fofa",1) < 200)
              return notify_fail("����Ϊ�׼ҵ��ӣ���˷���Ҫ���ߵ���Ϊ���ܾ�����\n");

        if((int)me->query_skill("dacheng-fofa", 1) < 30 )
              return notify_fail("���˷�δ����򣬲��ܾ���������\n");

        if(me->is_busy() || me->is_fighting())
              return notify_fail("����æ���ģ�\n");

        if( me->query("combat_exp") > 1000000 )
              return notify_fail("�������ڵ���Ϊ���Ѿ�����ͨ�����������ˡ�\n");
        
        if(me->query_temp("pending/jingzuo"))
              return notify_fail("�����ھ����С�\n");

        if ((int)me->query("jingli", 1) < 30 )
              return notify_fail("��̫���ˣ����Ǻú���Ϣ�ɡ�\n");

        message_vision(HIW"$N�ֳ�������������飬�Ȳ�ͷ����һ�ᣬȻ���ڵ��������������������ȡ�\n"NOR, me);
        me->set_temp("pending/jingzuo", 1);
        me->set_temp("exercise_cost", 50+random(60));
// ���ǳ����ˣ�ʱ��ϳ�
        if (me->query("class")!="bonze")
          me->set_temp("exercise_cost", 100+random(50));
        me->start_busy((: exercising :), (:halt_exercise:));
        return 1;
}

int exercising(object me)
{
        object where;
        int gps;
        int exercise = (int)me->query_temp("exercise_cost");
        where = environment(me);
        me->set_temp("exercise_cost", exercise -= 1);
        if( where && me->query_temp("pending/jingzuo")){
          if (exercise == 80)
          write(GRN"
����ã������Ȼ��Ȼ�������ۣ���������˯�ţ�����˼·ʮ�������
��ֻ�������������Źֵ�����������Щ�Źֵ�������ȫ���������Լ�
����֮�ڵģ����������������������������Ĺ������������ڣ���ѪҺ
��������������Ҳ���Ըо��ó���������˵�������Լ�����ѪҺ����
����������Ϊ��ʵ�ڲ����ܣ�����ȴ��ʵʵ���ڣ���Ѫ�����������ĸ�
�� �� \n"NOR);          

          if (exercise == 60)
          write(CYN"
�������Լ�������֮�ڣ�������ô�����������ͬʱ�������أ�������
һ��ʮ������ĸо������ָо���������ǰ��δ���ģ�����Ҳʮ������
���ݡ����������������Ƿ��������������������ǲ�֪��ʲô�������
������Ѫ����������������һ����Ϫ�����岻Զ����������������������
����СϪ��ʯ�ϣ�������Ⱥ�����С�����
\n"NOR);

          if (exercise == 40)
          write(BLU"
����һ�ᣬ������ת����һ�£���֪��������ʲôԭ�����Ȼ�뵽��
��ɽ��ѩ���ڻ������ǣ�һ���ӣ������������������������뵽�ķ羰
������ˣ����˵�ѩ�������һ�ɹɵ�ˮ�������ʣ���ʱ�������ң���
�������������δ���������������ɣ�������Ҳ����СϪ�ߵ���磬��
���ӹ�ɽ�ҵľ��硣 
\n"NOR);

          if (exercise == 20)
          write(RED"
�������������ڵ���������Ϊ����Ȼ����������һ�����������������ˣ�
��������Щ��������Χ��������������Щ�������γɵĻ���֮�С����ң�
��������ǣ�����������ȫȻ�����Լ���������ı䣬һ��������Ϫ֮
�ԣ�һ�����ڸ�ɽ֮�ۣ�һ�������ڴ�֮������ֱ��ǧ���򻯣�����
���������ڵ���������ĸо����������Ѿ��뿪���Լ������壬������
�����Ȼ���޵ر�󣬶��˵�˼�룬���ڱ���˵�����֮�ڻһ���� 
\n"NOR);

          if (exercise == 1)
          write(HIW"
��֪���˶�ã������ڸо����������ȫ���עȥ������ָо�����
��Ȼ��ȴ��ʱ�䡣����
��Ȼһ���𶯣���������һ�������˻����������뿪��������㣬
�ֻص�������֮��һ��������������ʱ�����������������Լ�������
Բ����ʯ���ڣ�Ҳ��ά�������ȶ��������ơ�  
\n"NOR);

        }
        if (exercise <= 1) {
           message_vision(HIY"$N�Ѿ��ʹ���Ȼ��Ϊһ�壬����Ƭ�̣������ӵ�վ��������\n"NOR, this_player());
           me->delete_temp("pending/jingzuo");
           me->delete_temp("exercise_cost");
//����Խ�ߣ��õ���Ǳ��Խ��
           gps=(((int)me->query_skill("dacheng-fofa", 1))/8+random(20));
           gps-=((int)me->query("combat_exp",1))/200000;
           if ( gps < 1 ) gps = 1;
           if( ((int)me->query("potential", 1) + gps) > (int)me->query("max_pot", 1) ) {
              me->set("potential", (int)me->query("max_pot", 1));
              return 0;
           }
me->add("potential",gps);
           return 0;
        }
        return 1;
}

int halt_exercise(object me)
{
        if(environment(me) && me->query_temp("pending/jingzuo")) { 
          message_vision(HIY"$N�Ѿ�����ƣ�룬���������ϵĻҳ���վ��������\n"NOR, me);
          me->receive_damage("jingli", 20);
          me->delete_temp("pending/jingzuo");               
          me->delete_temp("exercise_cost");
          return 1;
        }
        else return 0;
}
