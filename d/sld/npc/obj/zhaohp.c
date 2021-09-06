#include <ansi.h>

inherit ITEM;

int do_zh(string arg);
int do_yes(string arg);
int do_no(string arg);

object obj;

void create()
{
	set_name(YEL "�����л���" NOR, ({"zhaohunpai" ,"pai" }));
	set_weight(20);
        
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������̵��л��ƣ���������������(zhaohun)���������˹�˳�ģ�\n");
		set("no_sell",1);
		set("no_get",1);
		set("no_steal",1);
		set("no_give",1);
		set("no_drop",1);
	}
	setup();
}

void init()
{
	add_action("do_zh","zhaohun");
	add_action("do_yes","yes");
	add_action("do_no","no");
	obj=this_player();
}

int do_zh(string arg)
{
	object me=this_player();
	string tid,tname;
	int i,j,k,texp,myexp,adds,kar,times,qnadd,bz,temp,zhcs,qi;
	string * skill=({"poison","shenlong-yaoli","force","dulong-dafa"});

	if((uptime()-query("zhaotime"))<2)
		return notify_fail("���������������Ϣһ�����аɡ�");
	else
		set("zhaotime",uptime());
	if(!arg || arg==" " || arg==" ") return 0;

	if((obj = present(arg, environment(me))) && (obj->is_character())) {
		if(obj->is_corpse())
			return notify_fail("�˶����ˣ��㻹��ʲô�У�! \n");
		tname=obj->name();
		tid=obj->query("id");
		texp=obj->query("combat_exp"); 
		myexp=me->query("combat_exp");
                bz=1;
		if(!living(obj))
		{
			if((texp<=myexp) || random(3)==0)
				return notify_fail("��������ڴ��ڻ����У���������˵�Ļ�! \n");
			bz=random(2)+2;
		}
		if((tname!=me->query("quest_kill/name")) || (tid!=me->query("quest_kill/id")))
			return notify_fail("û��������������˹�˳ѽ! \n");

		message_vision("$N�ó��л��ƶ���"+tname+"һ�Σ�Ȼ��������\n",me);
		
		me->receive_damage("jingli",50);

		if(myexp<=0) myexp=1;
		if(texp<=0) texp=1;

		i = texp;
                zhcs=me->query_temp("zhaohun/times",1);
                qi=obj->query("qi");
                if(qi<=0) qi=1;
		if(myexp<texp)
			bz= bz*(random(1200) + obj->query("max_qi")*200/qi)*myexp;
		else {
			bz= (random(500) + obj->query("max_qi")*100/qi)*myexp;
			temp=myexp;
			myexp=texp;
			texp=temp;
		}
                bz=bz*((zhcs/10)+1);    
		if ( (bz < (i*(random(500)+500))) || random(2)) {
			me->start_busy(random(3)+1);
			if(random(3)==0)  {
				message_vision(tname+"�ݺݵص���$Nһ�ۡ�\n",me);
				
				return 1;
			}
			else  {
				message_vision(tname+"��$Nŭ�ȵ��������ǽ�ѵ��һ�²��ɣ�\n",me);
				
				obj->kill_ob(me);
				me->fight_ob(obj);
                                obj->set_leader(me);
                                tell_object(me, tname+"����������һ���ж���\n");
				zhcs++;
                		me->set_temp("zhaohun/times",zhcs);
                                remove_call_out("nofollow");
                                call_out("nofollow", random(30)+30, obj); 
				return 1;
			}
		}

		me->remove_enemy(obj);
		obj->remove_killer(me);
		if(obj->query_leader())
		{
			remove_call_out("nofollow");
			obj->set_leader(0);
		}
		tell_room(environment(obj),tname+"ͻȻ��ħ�Ƶز���������ȫ��������̱֮���ڵء�\n");
		if(random(10)>7)    {
			tell_object(me, tname+"���㰧���������ǵ�С��˼�����ʹ��˴����Ź��Ұɣ�(yes/no)\n");
			me->set_temp("quest/huilu",1);
			return 1;
		}

		tell_room(environment(obj), tname+"���ڵأ��ߺ������������ͨ���ս�޲�ʤ��\n" );

		me->set("quest_kill/questing",0);

		kar=random(me->query_kar());
		if(kar>30) kar=30;
		times= 4+ random(5);
		
		i = texp*1000/(myexp+1)+(kar*50/times);
		if(i>=2000)
		{
			j=random(sizeof(skill));
			k=0;
			while(1)
			{
				if(j==0)
				{
					if(me->query_skill("poison",1)>=150)
					{
			   			break;
					}
					j++;
				}
				if(j==1)
				{
					if(me->query_skill("shenlong-yaoli",1)>=200)
			   		{
			   			break;
					}
					j++;
				}
				if(j==2)
				{
					if(me->query_skill("force",1)>=200 && 
					   me->query_skill("force",1)<
					   (me->query_skill("shenlong-yaoli",1)+100))
					{
						break;
					}
					j++;
				}
				if(j==3)
				{
					if(me->query_skill("dulong-dafa",1)>=200 && 
					   me->query_skill("dulong-dafa",1)<
					   me->query_skill("force",1))
					{
						break;
					}
					if(k==0)
					{
						j=0;
						k=1;
					}
					else
					{
						j=-1;
						break;
					}
				}
			}
			if(j!=-1)
				me->improve_skill(skill[j],i*2,1);
		}
		if ((i>2500) || (i<0)) i=2500;
		qnadd = 10 + (i/2+random(i/2))/16;
		if (qnadd>me->query("max_pot") ) qnadd = me->query("max_pot");
		adds = qnadd+ random(qnadd*2);
		adds=adds*2;
		qnadd=qnadd*2;

		i =10+i/4*3/16;
		if(wizardp(me)) tell_object(me,"get pot: "+i+"\n" );

         	i = me->query("max_pot")-me->query("potential");
		if ( i< qnadd ) qnadd = i;
                if (adds > 300) adds = 280+random(40);
                if (adds <30) adds = 30;
                
                //me->add("combat_exp",adds);
                adds = me->add_exp_combat(adds,tname,"�����л�");
                
		qnadd = adds/5 + random(adds/10);
		me->add("potential",qnadd);

		if( me->query("potential") > me->query("max_pot"))
			me->set("potential", me->query("max_pot"));

		me->add("shen",-adds*2);

		tell_object(me,"�㱻������"+chinese_number(adds)+"�㾭�飬"
			+chinese_number(qnadd)+"��Ǳ�ܣ�"+chinese_number(adds*2)+"�㸺��\n");

// add �л� Log By River
	        log_file("job/shenlong",sprintf("%8s%-10s�л�����(0)��������%3d��Ǳ��%2d��Ŀǰ���飺%d��\n",
			me->name(1),"("+me->query("id")+")", adds ,qnadd, me->query("combat_exp")));

		if(me->query_temp("quest_kill/failin5",1)!=0)
			me->delete_temp("quest_kill/failin5");

		if(!me->query("quest_kill/quests"))
			me->set("quest_kill/quests",1);
		else
			me->add("quest_kill/quests",1);
		destruct(this_object());
		return 1;
	}
	return 0;    
}

void nofollow(object ob)
{
	if(objectp(ob)) {
		if(living(ob) && ob->query_leader())
			ob->set_leader(0);
		else if(!living(ob) && !ob->is_corpse())
			call_out("nofollow",5,ob);
	} 
}

int do_yes(string arg)
{
	object me=this_player();
	string tid,tname;
	int golds,adds,times,kar,myexp,texp,temp;
	object gold;

	if(me->query_temp("quest/huilu",1)==0)
		return 0;
	if(!objectp(obj))
	{
		destruct(this_object());
		return 1;
	}
	tname=obj->name();
	tid=obj->query("id");
	texp=obj->query("combat_exp");
	myexp=me->query("combat_exp");
	kar=me->query_kar();

	if((tname!=me->query("quest_kill/name")) || (tid!=me->query("quest_kill/id")))  return 0;

	tell_object(me,"���"+tname+"�ٺ�һЦ������Ҳ�գ���ξͷ���һ��Ǯ�أ�\n");
	tell_object(me,tname+"��æ�ӻ����ͳ��������ӣ����ĵ������㡣\n");

	golds=random(texp/1000)*kar/20;
	if(golds<10) golds=10;
		else if(golds>200) golds=200;

	gold=new("/clone/money/silver");
	gold->set_amount(golds);
	if(!(gold->move(me)))
		gold->move(environment(me));
	
	times=15+random(16);
	if(myexp<=0)  myexp=1;
	if(texp<=0)   texp=1;
	if(myexp>texp)   {
		temp=myexp;
		myexp=texp;
		texp=temp;
	}

	adds=100+random(120*texp*kar/(times*myexp));
	me->add("shen",-adds);
	tell_object(me,"�㱻������"+chinese_number(adds)+"�㸺��\n");
	me->delete_temp("quest/huilu");
	destruct(this_object());

	return 1;
}

int do_no(string arg)
{
	object me=this_player();
	string tid,tname;
	int i,j,k,adds,times,kar,qnadd,myexp,texp;
   	string * skill=({"poison","shenlong-yaoli","force","dulong-dafa"});

	if(me->query_temp("quest/huilu",1)==0)
		return 0;
	if(!objectp(obj))
	{
		destruct(this_object());
		return 1;
	}
	tname=obj->name();
	tid=obj->query("id");
	texp=obj->query("combat_exp");
	myexp=me->query("combat_exp");
	kar=me->query_kar();

	if((tname!=me->query("quest_kill/name")) || (tid!=me->query("quest_kill/id")))    return 0;

	tell_object(me,"���"+tname+"��Цһ������������ô��Ǯ���򷢽л��Ӱ������漴����"+tname+"�������\n");
	tell_room(environment(obj), tname+"���ڵأ��ߺ������������ͨ���ս�޲�ʤ��\n" );

	me->set("quest_kill/questing",0);

	kar=random(me->query_kar());
	if(kar>30) kar=30;
	times= 4+ random(5);
		
	i = texp*1000/(myexp+1)+(kar*50/times);
	if(i>=2000)
	{
		j=random(sizeof(skill));
		k=0;
		while(1)
		{
			if(j==0)
			{
				if(me->query_skill("poison",1)>=150)
				{
		   			break;
				}
				j++;
			}
			if(j==1)
			{
				if(me->query_skill("shenlong-yaoli",1)>=200)
		   		{
		   			break;
				}
				j++;
			}
			if(j==2)
			{
				if(me->query_skill("force",1)>=200 && 
				   me->query_skill("force",1)<
				   (me->query_skill("shenlong-yaoli",1)+100))
				{
					break;
				}
				j++;
			}
			if(j==3)
			{
				if(me->query_skill("dulong-dafa",1)>=200 && 
				   me->query_skill("dulong-dafa",1)<
				   me->query_skill("force",1))
				{
					break;
				}
				if(k==0)
				{
					j=0;
					k=1;
				}
				else
				{
					j=-1;
					break;
				}
			}
		}
		if(j!=-1)
			me->improve_skill(skill[j],i*2,1);
	}
	if ((i>2500) || (i<0)) i=2500;
	qnadd = 10 + (i/2+random(i/2))/16;
	if (qnadd>me->query("max_pot") ) qnadd = me->query("max_pot");
	adds = qnadd+ random(qnadd*2);
	adds=adds*2;
	qnadd=qnadd*2;

	i =10+i/4*3/16;
	if(wizardp(me)) tell_object(me,"get pot: "+i+"\n" );

      	i = me->query("max_pot") - me->query("potential");
	if ( i< qnadd ) qnadd = i;
	if (adds <30) adds = 30;
        if (adds >300) adds = 280+random(40);
        
        adds = me->add_exp_combat(adds,tname,"�����л�");
        //me->add("combat_exp",adds);
        //me->add("job_time/�����л�",1);
	qnadd = adds/5 + random(adds/10);
	
	me->add("potential",qnadd);
	if( me->query("potential") > me->query("max_pot"))
		me->set("potential", me->query("max_pot"));
	me->add("shen",-adds*2);
	tell_object(me,"�㱻������"+chinese_number(adds)+"�㾭�飬"
			+chinese_number(qnadd)+"��Ǳ�ܣ�"+chinese_number(adds*2)+"�㸺��\n");	

        log_file("job/shenlong",sprintf("%8s%-10s�л�����(1)��������%3d��Ǳ��%2d��Ŀǰ���飺%d��\n",
		me->name(1),"("+me->query("id")+")", adds ,qnadd, me->query("combat_exp")));

	if(me->query_temp("quest_kill/failin5",1)!=0)
		me->delete_temp("quest_kill/failin5");

	if(!me->query("quest_kill/quests"))
		me->set("quest_kill/quests",1);
	else
		me->add("quest_kill/quests",1);
	me->delete_temp("quest/huilu");
	destruct(this_object());
	return 1;
}
   
