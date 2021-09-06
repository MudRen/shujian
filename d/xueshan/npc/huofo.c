
inherit NPC;
#include "ansi.h"

string ask_job();
void create()
{
	set_name("�ܲ���͵�",({"huo fo","foye"}));
	set("title", RED"����"NOR);
	set("gender", "����" );
	set("class","huznxi");
	set("age", 80);
	set("long", "�ܲ���͵������һλ�����Ĳ��ܾ�ʷ��ң���ʶ���ֲ��ܷ��䡣\n");
	
	set("attitude", "peaceful");
	set("combat_exp", 50000);
	set("inquiry", ([
                "����" : "�����Ƿ���������ص�����������\n",
                "name" : "��ɮ���ܲ���͵���\n",
                "�޳�"  : (: ask_job :),
	]));
	setup();
}

void init()
{
	add_action("do_xiuchi","xiuchi");
}

int do_xiuchi()
{
	object me;	
	int i,j;
	me = this_player();
	i = random(10)+20;
	j = random((100-(int)me->query("int"))/2);

	if ( file_name(environment(this_object())) != this_object()->query("startroom")) 
		return notify_fail("���ǻص�ѩɽ�޳ְɡ�\n");

	if (!(me->query_temp("job_name")) || me->query_temp("job_name")!="�޳�")
		return notify_fail("��Ҫ��ʲô��\n");

	if( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ((int)me->query("jing") < (j+10) ){
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing",j);

	if ((int)me->query_temp("xiuchi",1) > i) {
		me->add("potential",30+random(10));
		if(me->query("potential") > me->query("max_pot"))
			me->set("potential", me->query("max_pot"));
    		me->add("combat_exp",(int)(me->query_skill("huanxi-chan",1)/3) + 80); 
    		me->delete_temp("job_name");
    		me->delete_temp("xiuchi");
    		tell_object(me,"���������ͷ��һ�ģ�����Ȼһ������������\n");
    		return 1;
   	}
	switch (random(5)){
      		case 0:
		      message_vision(HIW"\n$N�����̵���" +"
			���������ʥ������
      			�ӽ�ֱ����������� 
      			��������ʩ�������� 
      			Ϊ�������Ը�����\n\n"NOR,me);   	
		break;
      		case 1:
		      message_vision(HIY"\n$N���������" +" 
      			�˰������ִ�����������ǹ��Ǻ��ޡ�\n\n"NOR,me);
		break;
      		case 2:
      			message_vision(RED"\n$N���������" +" 
      			��������������ߴ����������ຼ��\n\n"NOR,me); 
		break;
      		case 3:
     			message_vision(CYN"\n$N���������" +" 
     			�������ղ� �������������� 
      			�������������� �Ź�����ʮ��ɲ \n\n"NOR,me);
		break;
      		case 4:
      			message_vision(GRN"\n$N���������" +" 
      			�������۽��� ����˫��讽��� 
      			����������ׯ�� ���˫צץ���� \n\n"NOR,me);
    	}
     	me->add_temp("xiuchi",1);
     	me->start_busy(1);    
	return 1;
}

string ask_job()
{
	object me;
        int exp;
        me = this_player();
        exp = (int)me->query("combat_exp",1);
        
        if (!me->query("family/family_name")
         && me->query("family/family_name") != "������") 
        	return ("�㲻�������ڴ��ˡ�\n");
	
	if (exp < 3000)
        	return ("�����Ϊ��̫����������ɡ�\n");
        
        if ((int)me->query_skill("huanxi-chan",1) < 30)
          	return ("������ڵ�������̫����ǻ�ȥ��������ɡ�\n");   

        if (exp >= 30000)
          	return ("��ķ���Ϊ�Ѿ����˻���������Ҫ��ɮ��ָ���ˡ�\n");

        if (me->query_temp("job_name"))
         	return ("���Ѿ����˹����ˣ���ȥ���ɡ�\n");  
      	me->set_temp("job_name","�޳�");
      	me->set_temp("xiuchi",1);
      	return ("�ã���͸�����ɮһ���޳�(xiuchi)��ճ˲��ܷ𷨰ɡ�\n");               
}
