void init()
{
        object me = this_player();
	int i,j;
        i=random(5)+2;
	j=random(4)+3;

	if ( me->query("quest/tonglao/quest") >= 3 && me->query("registered") < 3)
		return;
        if  (me->query("combat_exp") >= 1500000 
	 &&  me->query("shen") >= 10000
	 &&  me->query("max_neili") >= 5000  //���Ǻ�����ڱ����󲼴����ܵķɿ죬�������е�Ҫ��
	 &&  random(me->query("kar")) >= 20
	 &&  me->query("quest/tonglao/quest") <= me->query("combat_exp") / 1000000
	 &&  (time() - me->query("quest/tonglao/time")) > 86400
	 &&  !(me->query_temp("tonglao/pass1"))
	 &&  !(me->query("quest/tonglao/pass"))	//�Ѿ��⿪��quest
	 &&  random(200) > 100 ) {
		tell_object(me, YEL"������·�����ţ���������ɽ����¶��һ��"HIY"�ƻ�"YEL"����\n\n"+
				"�㲻�ɵ�ͣ�½Ų����߹�ȥ����������\n"NOR);
	        me->add_busy(4 + random(4));
		me->move(__DIR__"shandao1",1);
		me->set_temp("tonglao/pass1",1);
		me->set_temp("tonglao/steps",j);
		me->set_temp("tonglao/step",-i);
		me->add("quest/tonglao/quest",1);
		me->set("quest/tonglao/time", time());
		log_file("quest/tonglao",sprintf("%8s%-10sͨ��ͯ�ѽ��Ե�һ�������飺%d������%d��������%d��\n",
			me->name(),"("+me->query("id")+")", me->query("combat_exp"), 
			me->query("kar"), me->query("quest/tonglao/quest")), me);
		tell_room(environment(me), me->name()+"��ɽ�����˹�����\n",  ({ me }));
		return;
        }
}
