/* �����ʣ��޷�ͨ��˯���ָ�������*/
// sleep.c
// yuj
// last updated 6/29/96
// Modified by snowman@SJ 28/02/2001
// added sleep string check.
// Modify by LinuX@SJ

mapping party=([
        "emei":       	"������",
        "gaibang":    	"ؤ��",
        "gumu":       	"��Ĺ��",
        "huashan":    	"��ɽ��",
        "kunlun":   	"������",
        "mingjiao":   	"����",
        "murong":     	"����Ľ��",
        "quanzhen":   	"ȫ���",
        "shaolin":    	"������",
        "shenlong":   	"������",
        "songshan":   	"��ɽ��",
        "taohua":     	"�һ���",
        "tianlong":   	"������",
        "tiezhang":   	"���ư�",
        "wudang":     	"�䵱��",
        "xingxiu":    	"������",
        "xueshan":    	"������",
]);

int main(object me, string arg)
{
	mapping fam;
	mixed sleep;
 	object where = environment(me);

	seteuid(getuid());
	
	if (me->is_busy())
		return notify_fail("����æ���أ�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в���˯����\n");
		
	if ( (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("���ﲻ������˯�ĵط���\n");
        
	if (where->query("hotel") && !(me->query_temp("rent_paid"))){
		message_vision("��С���������$N���: �����ﵱ��������! �ȵ�һ¥��Ǯ������˯!\n",me);
		return 1;
	}
	sleep = where->query("sleep_room");
	if (intp(sleep) && sleep) {
		write("��������һ�ɣ���ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$Nһ�������ڴ��ϣ���һ�����������硣\n",me);
	}
	else if( stringp(sleep) ){
		if (sleep == "Ů��" && me->query("gender") != sleep)
				return notify_fail("������Ů��˯����\n");
		if (sleep == "����" && me->query("gender") != sleep)
				return notify_fail("����������˯����\n");
		if (member_array(sleep, keys(party)) != -1) {
			if (me->query("family/family_name") != party[sleep])
				return notify_fail("������"+ party[sleep] + "��˯������������ʲô��\n");
			write("��������һ�ɣ���ʼ˯����\n");
			write("��һ�������ͽ��������硣\n");
			me->set_temp("block_msg/all",1);
			message_vision("$Nһ�������ڴ��ϣ���һ�����������硣\n",me);
		} else {
			write("��������һ�ɣ���ʼ˯����\n");
			write("��һ�������ͽ��������硣\n");
			me->set_temp("block_msg/all",1);
			message_vision(sleep,me);
		}
	} else { 
		write("�������½���һ�ɣ���ʼ˯����\n");
		write("��һ�������ͽ��������硣\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N�����½�������һ�ɣ���һ�������������\n",me);
	}


	if (where->query("hotel")) 
		me->delete_temp("rent_paid");

	me->disable_player(" <˯����>");

	call_out("wakeup",10 + random(30 - me->query("con")), me, environment(me));
        
	return 1;
}

void wakeup(object me, object env)
{
	int cost;
	object where;

	if (!me || living(me) || !(where = environment(me)) ) return;
	cost = me->query_condition("sleep");
	if (!cost)
		me->apply_condition("sleep", 9);
	
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
	if (environment(me)->query("hotel")) cost /= 2;
	cost++;
	/* �����ʣ��޷�ͨ��˯���ָ�������*/
	if((me->query("food") && me->query("water")) || !userp(me))
	{	
		me->add("qi",    (me->query("eff_qi") - me->query("qi"))/cost);
		me->add("jing",  (me->query("eff_jing") - me->query("jing"))/cost);
		me->add("neili", (me->query("max_neili") - me->query("neili"))/2/cost);
		me->add("jingli", (me->query("eff_jingli") - me->query("jingli"))/2/cost);
	}
	me->enable_player();	
	

			
	if(!me->query("food"))
	{
		me->delete_temp("block_msg/all");
		tell_object(me,"����Ӷ���ߴ�������ҽУ�û�취ֻ������������\n");
		tell_room(where,me->name()+"�������۾�����������\n",({me}));
		return;
	}
	
	if(!me->query("water"))
	{
		me->delete_temp("block_msg/all");
		tell_object(me,"��ʵĿڸ����û�취ֻ������������\n");
		tell_room(where,me->name()+"�������۾�����������\n",({me}));
		return;
	}
	
	if (cost > 2)
		message_vision("$Nһ��������������ػ��һ�½�ǡ�\n",me);
	else
		message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
	
	me->delete_temp("block_msg/all");
	
	if (cost > 2)
		write("��һ������������˯��̫Ƶ���������Ǻܺá�\n");
	else
		write("��һ�����������þ������棬�ûһ���ˡ�\n");
		
	if (env != environment(me)) me->move(environment(me), 1);
}
