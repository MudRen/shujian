// ��̶ ����ϵͳ 
// longtan.c
// Created by Ciwei@SJ 22/3/2004

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIY"��̶"NOR);
	set("long","������ľ������ǰ��Ȼһ����ɫѣ�ԣ�����ˮ��������ˮӰ��ȴ��ɽ����
һ������׵Ĳ���ɫˮ̶�����˲����������ǣ�̶ˮ��Ȼ��ͨ͸�ĺ�īɫ��
̶�й�ʯ���������ڹ������·���һ���ڽ��ʯ����������ˮ̶�ϣ�����ͷ��
����б����̶ˮ����һ����ʯ������ˮ̶����������֮�ӣ�ֻ�з紵�����֣�
��������ĺ��⡣��ս�һ����̶ˮ��Ȼ��ڣ����Ǻڵ�����һ��īɫ��ˮ����
�·����"HIY"��"NOR"���������ڤ����
"
	); 
		        
        set("exits",([
                "up" : __DIR__"duanhunya",
        ]));
        
	set("outdoors", "��ɽ");
	set("no_fight",1);
	setup();
}

void init()
{
	add_action("do_show",({"show","zhao"}));	
	add_action("do_jijian",({"jijian","����"}));	
	add_action("do_jiaofu",({"jiaofu","����"}) );
	add_action("do_qijian",({"zhi","��","reng" }));
	//drop
}

int do_show(string str)
{
	object me,obj;
	int btime,t;
	string id;
	
	if(!str) return notify_fail("��Ҫ����̶����ʲô������\n");
	me = this_player();
	if(me->is_busy() || me->is_fighting()) return notify_fail("����æ�ţ�\n");
	if(!objectp(obj = present(str, me))) return notify_fail("������û������������\n");
	
	if(me->query_temp("longtanjijian")) return notify_fail("��û�չ�����\n");
	notify_fail("������̶�Ͻ��鿴"+obj->name()+"����ûʲô�ÿ��ġ�\n");
	if (!(int)obj->query("imbued")) return 0;
	if( mapp(obj->query("armor_mp/armor_prop")) && me->query_skill("zhizao",1)<220) return 0;
	if( mapp(obj->query("weapon_mp/weapon_prop")) && me->query_skill("duanzao",1)<220) return 0;
	if(sscanf(obj->query("save_id"), "%s%d%*s",id,btime)!=3) return 0;
	if(id!=getuid(me) && id!="zhujian shi") return 0;
	if(stringp(obj->query("owner")) && obj->query("owner")!="0" && obj->query("owner")!=getuid(me)) return 0;
	t = time();
	//if(t-btime<86400) return 0;//������24Сʱ�������		
	//if(NATURE_D->query_daytime() != "event_noon") return 0;//����
	message_vision(HIY"$N"+HIY"��$n"+HIY"��̶ˮ����ҫ�������"+BLINK HIM"�⻪"NOR NOR+HIY"���ܾ�������ϴ�����˼��׹���\n"NOR,me,obj);
	call_out("do_show2",5+random(5),me,obj);
	me->start_busy(10);
	return 1;
}
void do_show2(object me,object obj)
{
	if(!me || !obj || environment(obj)!=me) return;	
	message_vision(HIM"$N"+HIM"����һ����Ī����Ҫ���Լ������������ܵ�����̶��֮������Ϊ�Լ���$n"+HIM"����������\n"NOR,me,obj);
	tell_object(me,RED"Ѫ���ѵ����Ǽ���(jijian)�����У�\n"NOR);
	me->start_busy(-1);
	me->interrupt_me();
	me->set_temp("longtanjijian",obj);
	return;
}

int valid_leave(object me, string dir)
{
	if(me) me->delete_temp("longtanjijian");
	return ::valid_leave(me,dir);
}

int do_jijian(string str)
{
	object me,obj;	
	
	object zhong;
	int needdest = 0;
			
	me= this_player();
		
	if(!objectp(obj=me->query_temp("longtanjijian"))) return 0;
	
	zhong = find_object(NPC_D("zhong-shentong"));
	if(!zhong)
	{
		zhong = load_object(NPC_D("zhong-shentong"));
		needdest = 1;
	}
	if( zhong->query("winner") == me->query("id") )
	{
		if(needdest) destruct(zhong);
		return notify_fail("����æ�ţ�\n");
	}
	
	if(needdest) destruct(zhong);
			
	if(me->is_busy() || me->is_fighting()) return notify_fail("����æ�ţ�\n");
	if(environment(obj)!=me) return notify_fail(obj->name()+"����������ô��\n");
	
	//if( mapp(obj->query("armor_mp/armor_prop")) && me->query_skill("zhizao",1)<350) return notify_fail("����Ҫ�������,ȴ�����Ѿ��������ġ�\n");
	//if( mapp(obj->query("weapon_mp/weapon_prop")) && me->query_skill("duanzao",1)<350) return notify_fail("����Ҫ�������,ȴ�����Ѿ��������ġ�\n");
	if(me->query("neili") < me->query("max_neili"))
	return notify_fail("����Ҫ�������,ȴ�����Ѿ��������ġ�\n");
	
	if(query("longtanjijian")) return notify_fail("̶�е�ˮ���Ѿ�Խ��Խ��,�㻹�ǵȻ��ټ����ɡ�\n");	
	
	me->delete_temp("longtanjijian");
	message_vision(HIY"$Nһҧ���������������ھ������Լ��Ļ��ڡ� ������Ѫ���죬˳��$n"HIY"����ֱ����̶ˮ��\n"NOR,me,obj);
	
	set("longtanjijian",obj);
	set("owner",getuid(me));
	
	remove_call_out("delete_jj");
	call_out("delete_jj",120+random(10));
		
	me->start_busy(6);
	call_out("jijian1",4+random(2),me,obj);
	/*
	message_vision(HIY"����̶�еĺڳ�������ɫ���𽥷���������Ĺ⻪��$N��Ѫ��Խ��Խ�࣬Խ��Խ�Ǿ���������֧��\n"NOR,me,obj);
	message_vision(HIY"����̶�е�ˮ��ȴ��Խ��Խ����$n"HIY"Ҳ�������˵Ĺ�������̶�о�ʯ��Ӧ��$N����������ת���Ѿ���Ҫ���ԡ�\n����$n"HIY"ȴһϴ��������ͬ�������µ�������\n"NOR,me,obj);
	tell_object(me,NOR"�㾿��Ҫ��������(jiaofu)����ʹ���أ� \n",);
		
	me->set_temp("last_damage_from", "��Ѫ����������̶��");
	me->add("qi",-me->query("max_qi")*4/5);
	me->add("eff_qi",-me->query("max_qi")*4/5);	
	set("longtanjijian",obj);
	set("owner",getuid(me));
	me->start_busy(random(3));
	remove_call_out("delete_jj");
	call_out("delete_jj",60+random(10));
	*/
	return 1;
}

void jijian1(object me,object obj)
{
	remove_call_out("jijian1");
	if(!me || !obj || environment(me)!=this_object()) return;
	message_vision(HIR"��ѪԽ��Խ�࡭��\n"NOR,me);
	me->start_busy(6);
	call_out("jijian2",4+random(2),me,obj);	
}

void jijian2(object me,object obj)
{
	remove_call_out("jijian2");
	if(!me || !obj || environment(me)!=this_object()) return;
	message_vision(HIY"����̶�еĺڳ�������ɫ���𽥷���������Ĺ⻪��$N��Ѫ��Խ��Խ�࣬Խ��Խ�Ǿ���������֧��\n"NOR,me,obj);
	me->start_busy(6);
	call_out("jijian3",4+random(2),me,obj);
}

void jijian3(object me,object obj)
{
	remove_call_out("jijian3");
	if(!me || !obj || environment(me)!=this_object()) return;
	message_vision(HIY"����̶�е�ˮ��ȴ��Խ��Խ����$n"HIY"Ҳ�������˵Ĺ�������̶�о�ʯ��Ӧ��$N����������ת���Ѿ���Ҫ���ԡ�\n����$n"HIY"ȴһϴ��������ͬ�������µ�������\n"NOR,me,obj);
	tell_object(me,NOR"�㾿��Ҫ��������(jiaofu)����ʹ���أ� \n",);
	me->start_busy(random(3));	
}
void reset()
{
	if(query("longtanjijian")) return;
	::reset();
}
void delete_jj()
{
	delete("longtanjijian");
	delete("owner");
	tell_room(this_object(),HIC"̶��ˮ���ָֻ��糣��\n"NOR);
}

int do_jiaofu(string str)
{
	object me,obj,target;
	mapping worker;
	string* ber;
	string var,type,c_type;
	int i,j;
	string skill;
	mapping skills,learned;
	
	me=this_player();
	if(!objectp(obj=query("longtanjijian"))) return 0;
	if(query("owner")!=getuid(me)) return 0;
	if(me->is_busy() || me->is_fighting()) return notify_fail("����æ�ţ�\n");
	if(environment(obj)!=me) return notify_fail(obj->name()+"����������ô��\n");
	if(!str) return notify_fail("�㾿��Ҫ��������(jiaofu)����ʹ���أ� \n");	
	if(!objectp(target = present(str,this_object()))) return notify_fail("�����û������ˡ�\n");
	if(!userp(target)) return notify_fail("��ֻ�ܽ�����"+obj->name()+"����ҡ�\n");
	if(target==me) return notify_fail("�������Լ�����Թ��緹��ô��\n");
	if(target->is_busy() || target->is_fighting()) return notify_fail(target->name()+"��æ�ţ�\n");
	
	if(mapp(obj->query("weapon_mp")))
	{
		c_type ="skill";
		skill="duanzao";
	}
	else if(mapp(obj->query("armor_mp")))
	{
		c_type ="armor";
		skill="zhizao";
	}
	else notify_fail("������󣡣���֪ͨ��ʦ��\n");	
	if(mapp(worker = target->query("worker")))
	{
		ber = keys(worker);
		for(i=0;i<sizeof(ber);i++)
		{
			if(!mapp(worker[ber[i]])) continue;
			var = worker[ber[i]]["var"];
			if(var[strsrch(var,",",-1)+1..<1]!=getuid(target)) continue;
			sscanf(var,"%s,%*s",type);
			if(type==obj->query(c_type+"_type")) return notify_fail(target->name()+"�Ѿ�ӵ�д�����Ʒ�㲻�ð׷Ѿ��ˡ�\n");
		}
	}
	if(c_type=="skill") c_type = "weapon";
	if(!mapp(worker = obj->query(c_type+"_mp"))) return notify_fail("������󣡣���֪ͨ��ʦ��\n");
	
	message_vision("$N��̾һ����ʥ�����ף��������ݣ�������Ѫ��"HIY"������̶"NOR"����$n������"+target->query("name")+"("+capitalize(getuid(target))+")�ɡ�\n",me,obj);
	message_vision("$N��$n����̶�У�̶��ӿ����Ѫ��ˮ��ȴ����ƽϢ��\n",me,obj);
	me->set_temp("last_damage_from", "��Ѫ����������̶��");
	
	//me->skill_death_penalty();
	
	skills = me->query_skills();
	learned = me->query_learned();
	
	if(skills && learned && skill)
	{
		j = skills[skill] + 1;
		learned[skill] -= (j*j+1) / 2;
		if (learned[skill] < 0) {
			learned[skill] += (j*j+1) / 2;
			j = skills[skill]--;
			learned[skill] += (j*j+1) / 2;
		}
	}
	me->add("max_neili",-30-random(50));
	if(me->query("max_neili")<0)  me->set("max_neili",0);
	me->unconcious();
	worker["owner"] = getuid(target);
	worker["max_dur"] = worker["max_dur"]*(110+random(20))/100;
	//max_dur
	obj->set(c_type+"_mp",worker);
	obj->set("owner",getuid(target));
	obj->set("max_dur",worker["max_dur"] );
	obj->move(load_object(__DIR__"tannei"));
	remove_call_out("delete_jj");
	call_out("delete_jj",7+random(5));
	//me->start_busy(15);
	call_out("give_reward",2+random(5),target,obj);
	tell_object(target,"�㱻��ǰ�澰�������ˣ���Ȼ�������ơ�\n");
	target->start_busy(7);
	return 1;
}

void give_reward(object target,object obj)
{
	if(!target || !obj) return;
	target->start_busy(-1);
	target->interrupt_me();	
	message_vision("̶��ˮ���ٴμ����������죬$N��̶�з���Ծ��$n���С�\n",obj,target);
	obj->move(target);
}

int do_qijian(string str)
{
	object obj,me;
	
	if(!str) return notify_fail("��Ҫ�ڰ�ʲô����������̶�У�\n");
	me = this_player();
	if(me->is_busy() || me->is_fighting()) return notify_fail("����æ�ţ�\n");
	if(!objectp(obj = present(str, me))) return notify_fail("������û������������\n");	
	if (!(int)obj->query("imbued")) return notify_fail("������̶���Ҷ�������\n");
	if(obj->query("owner") != getuid(me)) return notify_fail("�������ô�������ӡ�\n");
	if(me->query_skill("dodge") < 130) return notify_fail("�����ӵ����úܸ߲�������̶�ģ�����Ṧ��Ϊ��������\n");
		
	obj->delete("owner");
	obj->delete("armor_mp/owner");
	obj->delete("weapon_mp/owner");
	obj->move(load_object(__DIR__"tannei"));
	message_vision("$N�߸�Ծ�𣬡�������һ����$n������̶�ڣ���һ�������һ�����졣\n",me,obj);
	destruct(obj);
	return 1;
}