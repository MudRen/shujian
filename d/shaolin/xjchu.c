
#include <job_mul.h>
#include <ansi.h>
inherit ROOM;

int do_pi(string arg);

void create()
{
	set("short", "����");
	set("long", @LONG
һ�䲻���С�ݣ����а���һ�ڴ���������ð�����ڵ�������һ��������
�������ڡ�����������æ�żӲ�ɿ��ȫ�µ���������ζ�Ҫ���ࡣһλ
����ɮ�����ų��صĴ����ף����ڳ����Ľ�����������
LONG
       );
	set("no_fight",1);
	set("exits", ([
		"south"  : __DIR__"zhaitang",
	]));
	set("objects", ([
        	"d/shaolin/npc/szseng" : 1,
      	]));
	setup();
}

void init()
{
        add_action("do_ao", "ao");
        add_action("do_ao", "��");
}

int do_ao(string arg)
{
        object me;
        int costj, costq,times;
        int exp,pot;
        me = this_player();

        if(me->query_temp("job_name")!="����") 
          	return notify_fail("�����ɲ���������ĵط����㻹���߿���! \n");

        if (me->is_busy())
         	return notify_fail("��������æ����!\n");

        if (me->is_fighting())
         	return notify_fail("������ս����,�޷�ר�ĸɻ�!\n");

        if ( !arg || arg != "��" )
        	return notify_fail("��Ҫ��ʲô��\n");

        costj = (int)me->query("con")/2;
        costq = (int)me->query("str")/2;

        times = 15+random(6);

        if ((int)me->query("jingli") < costj
         || (int)me->query("qi") < costq){
        	message_vision("$N��һ�ɣ���������\n",me);
        	me->unconcious();
        	return 1;
        }
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       
        if ((int)me->query_temp("mark/��")>times 
         &&(present("shizhou seng", environment(me)))){
         	
         	me->add("job_time/����",1);
         	
         	exp = (int)(me->query_skill("buddhism",1)/5)+60;
         	
         	exp = me->add_exp_combat(exp,"�̷�ɮ","���ְ���");
         	//me->add("job_time/���ְ���",1);
         	//GIFT_D->check_count(me,"�̷�ɮ","���ְ���");
         	//me->add("combat_exp",exp);
         	         	         	
         	pot = 20+random(5);
		me->add("potential",pot);
                if(me->query("potential") > me->query("max_pot"))
                	me->set("potential", me->query("max_pot"));
             	
             	me->delete_temp("job_name");
             	me->delete_temp("mark");
            	return notify_fail(CYN"�̷�ɮ˵������л�������ҵ�æ�����ǿ��ȥ��!!!\n"NOR);
        }
        message_vision("$N����һ����˫�Ź�ס�����������ڿ��У��ӹ������������������\n", me);
        me->add_temp("mark/��",1);
        me->add_busy(1);
        
	if ((int)me->query_skill("hand", 1) < 20
         && random(10) > 6 ){
        	write(HIM"���ڻ��������У������Ϲ�����Щ����!\n"NOR);
                me->improve_skill("hand", (int)(me->query_skill("buddhism",1) / 5));
                me->improve_skill("finger", (int)(me->query_skill("buddhism",1) / 5));
	}
      	return 1;
}
