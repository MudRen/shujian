// sjsz_time.c  �Խ�ɽׯѰ����Чʱ���ʱ
// Create By lsxk@hsbbs 2008/6/20

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
       int i;

       if (duration < 1){
           tell_object(me,BLINK + HIC"ͻȻ�ӱ��ϴܳ��������δ󺺣�һ�ѿ����㣬�����˳��������ʱ�����˰��졣\n"NOR);
           me->move("/d/city/chmiao");
           return 0;
       }
       me->apply_condition("sjsz_time", duration - 1);
       //�������������by lsxk@hsbbs
     if ( strsrch(file_name(environment(me)), "/cmds/leitai/bwdh") >= 0){
       switch(random(5)){
       case 0:
           me->add("combat_exp",(i=71+random(80)));
           tell_object(me,HIM"�������Խ�ɽׯ��̽�գ���������"+HIW+chinese_number(i)+HIM+"�㾭��ֵ����!\n"NOR);
           break;
       case 1:
           me->add("max_neili",(i=1+random(3)));
           tell_object(me,HIG"�������Խ�ɽׯ��̽�գ���������"+HIW+chinese_number(i)+HIG+"�������������!\n"NOR);
           break;
       default:
           me->add("potential",(i=21+random(30)));
           tell_object(me,HIC"�������Խ�ɽׯ��̽�գ���������"+HIW+chinese_number(i)+HIC+"��Ǳ�ܽ���!\n"NOR);
           break;
       }
     }

	return 1;
}

string query_type(object me)
{
       return "quest";
}
