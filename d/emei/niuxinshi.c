// niuxinshi.c
// ţ��ʯ

#include <ansi.h>
inherit ROOM;
int dazuo(object me);
int halt_dazuo(object me);
void create()
{
        set("short", HIY "ţ��ʯ" NOR);
        set("long",@long
����Ŵ����ǿ�ں�ɫ�ľ�ʯ���������������ڴ˺�����ˮ��ţ�ģ�
�˻��ɽ�������ɽ�ȡ������ڴˣ���������֮ˮ�ӽ��±��ڶ�����������
��ɵ������ȷ��������Գ֡�
long);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
        add_action("do_dazuo", "lianneili");
}

int do_jump(string arg)
{
        object me = this_player();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

        if(!arg || arg == "" || arg != "back")
        return notify_fail("��Ҫ��ʲô��\n");
        
        if( arg == "back") {
              me->move(__DIR__"qingyinge");
              me->receive_damage("jingli", 200);
              message_vision("$N��ţ��ʯ���˹�����\n", me); 
              me->start_busy(2);
              return 1; 
        }
}


int do_dazuo(string arg)
{     
        int qzdazuo_cost,neili_limit;
// mapping fam;
        object me;
        me = this_player();   

        neili_limit = me->query_skill("force")* 8 + me->query("combat_exp", 1) /1000;

        if( me->query("family/family_name") != "������" )
        return notify_fail("�㿴����ǰ�˻��ɽ�������ɽ�ȣ����ɵ���һ˿���⡣\n");
   
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( !stringp(me->query_skill_mapped("force")) )
        return notify_fail("��������� enable ѡ����Ҫ�õ������ڹ���\n");

        if( !arg || !sscanf(arg, "%d", qzdazuo_cost))
                return notify_fail("��Ҫ��������������\n");

        if (qzdazuo_cost < 10)
        return notify_fail("���޷�������Ϣ���е���˾�ϸ�ĳ̶ȣ�\n");

        if (me->query("max_qi") > 1000 && qzdazuo_cost < me->query("max_qi")/5)
                return notify_fail("��������Ҫ"+chinese_number(me->query("max_qi")/5)+"�������������\n");

        if( (int)me->query("qi") < qzdazuo_cost )
                return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
                return notify_fail("�����ھ��������޷�������Ϣ��������\n");

        if ((int)me->query("max_neili") >= neili_limit)
                return notify_fail("�ڴ˵������Ѿ�����ûʲô�������ˣ�\n"); 
                
        write(HIW"�㰵���ټ�ʮ��ׯ�����۵��һ����������֫������������\n"NOR);

        me->set_temp("pending/exercise", 1);
        me->set_temp("pending/qzdazuo", 1);
        me->set_temp("qzdazuo_cost", qzdazuo_cost);
        message_vision(HIW"$N��ϥ�����������죬��ʼ�˹�������\n"NOR,me); 
        me->start_busy((: dazuo :), (: halt_dazuo:));
        return 1;
}

int dazuo(object me)
{
        int qzdazuo_cost = (int)me->query_temp("qzdazuo_cost");
        int neili_gain = 1 + (int)me->query_skill("force") / 10
                * (1 + (int)me->query_skill("force") / 100);    

        if (neili_gain > qzdazuo_cost) neili_gain = qzdazuo_cost;
        me->add("neili", neili_gain *3/2);
        me->set_temp("qzdazuo_cost", qzdazuo_cost -= neili_gain);
        me->receive_damage("qi", neili_gain);

        if (qzdazuo_cost > 0) return 1;

        me->delete_temp("pending/exercise");
        me->delete_temp("pending/qzdazuo");
        message_vision(HIY"����Ƭ�̣�$N���������Ȼ�ں���һ�𣬾����ӵ�վ��������\n"NOR, me);  

        if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
                return 0;

        if ((int)me->query("max_neili") >= (me->query_skill("force")* 8 
          + me->query("combat_exp", 1) /1000)){
                write("���������Ϊ�Ѿ��ﵽ�˴˵����ܰ�����ļ��ޡ�\n"); 
                me->set("neili", (int)me->query("max_neili"));
                return 0;
        }
        me->add("max_neili", 1);
        me->set("neili", (int)me->query("max_neili"));
        write("���������Ϊ�����ˣ���\n");   
        return 0;
}

int halt_dazuo(object me)
{
    if ((int)me->query("neili") > (int)((int)me->query("max_neili") * 2))  
        me->set("neili", (int)((int)me->query("max_neili") * 2));     
        message_vision(HIW"$N����һ����������Ϣ�������˻�ȥ��վ��������\n"NOR, me);
        me->delete_temp("pending/qzdazuo");
        me->delete_temp("pending/exercise");
        return 1;
}

void reset()
{
        object *ob;
        int i;
        
        ob = all_inventory(this_object());
        
        for(i=0; i<sizeof(ob); i++) {
                if( userp(ob[i]) ) continue;
                ob[i]->reincarnate();
                if( !ob[i]->return_home() ) destruct(ob[i]);
        }       
        
}
