// Update by lsxk@hsbbs 2008/1/11 
//ͳһ�������㷽ʽ��

#include <ansi.h>
#include <get_place.h>
#include <job_mul.h>
#include <jobround.h>

inherit ITEM;

string do_look();
int check(object ob);

void create()
{
	set_name(RED"�ż�"NOR, ({ "letter","xin","secret letter" }));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���ż����������ױ����ͣ��ŷ�ĺ���ʵ����ڸ��ź���ӡ����\n");
		set("value", 0);
		set("material", "paper");
		set("no_drop",1);
	}
	set("long", (: do_look :));
}

void init()
{
	call_out("dest", random(200)+1200);
	add_action("do_send", "songxin");
}

string do_look()
{
	int now_time, time;
	object me;
	string ret;
	string where;
	
	me = this_player();
	where = me->query_temp("songxin/where");
	if (me->query_temp("songxin/twice") && strlen(where) < 1)
		where = "\n"+CHINESE_D->font(me->query_temp("songxin/where"))+"\n";
	if (where == "����������ַ�����")
		where = me->query_temp("songxin/where");

	now_time = me->query_condition("dali_songxin");
	time = me->query_temp("songxin/time");

	if( me->query_temp("dali_songxin")) {
		ret = "\n����һ���ɴ�����������������ż�������д��\n\n"
		"    ��"HIR + where + " " +me->query_temp("songxin/target_name") + NOR"�� ������\n\n"NOR;
		if (now_time > time*3/4) ret += "�������г����ʱ��ȥ���š�\n";
		else if (now_time > time/2 && now_time <= time*3/4) ret += "�Ѿ���ȥһС��ʱ���ˡ�\n";
		else if (now_time > time/4 && now_time <= time/2) ret += "�㻹��һ���ʱ��ȥ���š�\n";
		else if (now_time > time/8 && now_time <= time/4) ret += "���ʱ���Ѿ������ˡ�\n";
		else if (now_time > 0 && now_time <= time/8) ret += "ʱ�佫�������񼴽�ʧ�ܡ�\n";
	}
	return ret;
}

object other;

int do_send(string arg)
{
	int job_time, i, j, time;
	object me, target, ob, *living, obj;
	string t_name, str, m_name,where;

	me = this_player();
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���ء�\n");
	if( !arg ) return notify_fail("��Ҫ�͸�˭��\n");
	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("��Ҫ�͸�˭��\n");

	t_name = target->query("name");
	job_time = me->query_temp("songxin/time");

	if( !living(target) )
		return notify_fail("������㣬���ǻ����𣿣�\n");
	if( userp(target) )
		return notify_fail("�ٺ٣������ף���\n");
	if( me->query_temp("dali_songxin_late"))
		return notify_fail("�������Ѿ�ʧ���ˣ���������һ���ɡ�\n");
	if( !wizardp(me) && !me->query_temp("dali_join") )
		return notify_fail(t_name+"�����㲻�Ǵ��������ӣ���ô�������������͵��Ÿ��ң�\n");
	if( !me->query_temp("dali_songxin"))
		return notify_fail(t_name+"�������Ǵ���������������Խ�����ģ����ǲ��Ǵӱ������������ģ�\n");
	if( me->query_temp("songxin/target_name") != t_name)
		return notify_fail(t_name+"��������Ų��Ǹ��ҵģ����ǲ����ʹ��ˣ�\n");
	if (me->query_temp("songxin/areab") != target->query("startroom"))
		return notify_fail(t_name+"��ֵ����㿴������Ƿ��ʹ����ˣ�����ͬ�����˿ɲ���Ŷ��\n");

	me->add_busy(random(2)); // hehe, ��ֹ����bug������Ч :) snowman@SJ

	m_name = me->query_temp("songxin/twice") ? me->query_temp("songxin/twice"): "����ү";

	message_vision(HIY"$N����һ�Ѷ�ͷ�ĺ����ӻ����ͳ��Ž���$n˵��������"+m_name+"�������͸������ţ������պá�\n"NOR, me, target);
	message_vision(HIY "$N�ӹ��ſ��˿������˵�ͷ˵������λ"+RANK_D->query_respect(me)+"�������ˡ�\n"NOR, target, me);

	if (!me->query_temp("zuji"))
       TASKREWARD_D->get_reward(me,"����",0,0,0,-3,0,0,0,t_name);
   else if (me->query_temp("songxin/twice"))
       TASKREWARD_D->get_reward(me,"����",0,0,0,6+random(2),0,0,0,t_name);
   else
       TASKREWARD_D->get_reward(me,"����",0,0,0,2+random(2),0,0,0,t_name);

	me->clear_condition("job_busy");
	me->clear_condition("dali_songxin");
	me->delete_temp("zuji");
	me->delete_temp("songxin_zuji");
	
	me->set("job_name", "��������");
	
	if (!me->query_temp("songxin/other")) {
		me->delete_temp("dali_songxin");
		me->delete_temp("songxin/time");
		me->delete_temp("songxin/times");
		me->delete_temp("songxin/area");
		me->delete_temp("songxin/target_name");
		me->delete_temp("songxin/where");
		me->delete_temp("letter_steal");
		me->set_temp("songxin_ok",1);		
		if (me->query_temp("songxin/twice")) {
			if(target->query("no_quest")) destruct(target);
			me->delete_temp("songxin/twice");
		}
		destruct(this_object());
	} else {
		living = livings();
		for (i=0;i < sizeof(living);i++){
			j = random(sizeof(living));
			if (j <= 1 || j == sizeof(living) -1) continue;
			if(check(living[j]) ){
				ob = living[j];
				str = environment(ob)->query("short");
				if( str == "��ɮ��"
				 || str == HIR"������"NOR
				 || str =="���º�ȭ��"
				 || str == "��շ�ħȦ" ) continue;
				if( environment(ob) == environment(target)) continue;
				if (get_place(base_name(environment(target))) == get_place(base_name(environment(ob)))) continue;
				if( get_place(base_name(environment(ob)))!="" ) break;
			}
		}

		if( !ob ) {
			if(target->query("no_quest")) destruct(target);
			me->delete_temp("dali_songxin");
			me->delete_temp("songxin/time");
			me->delete_temp("songxin/times");
			me->delete_temp("songxin/area");
			me->delete_temp("songxin/target_name");
			me->delete_temp("songxin/where");
			me->delete_temp("letter_steal");
			me->set_temp("songxin_ok",1);
			me->delete_temp("songxin/other");
			destruct(this_object());
			return 1;
		}

		time = random(10)+ 25;
		me->delete_temp("songxin_ok");
		me->delete_temp("dali_songxin_late");
		me->delete_temp("songxin_zuji");
		me->set_temp("dali_songxin", 1);
		me->set_temp("songxin/time", time);
		me->set_temp("songxin/times", uptime());
		me->apply_condition("dali_songxin", time*9/10+1);
		me->apply_condition("job_busy", time);

		me->delete_temp("zuji");
		me->delete_temp("letter_steal");

		obj = new(__DIR__"sxtarget");
		obj->set("startroom", ob->query("startroom"));
		obj->move(environment(ob));
		other = obj;
		me->set_temp("songxin/target_name", obj->query("name"));
		me->set_temp("songxin/area", load_object(ob->query("startroom"))->query("short"));
		me->set_temp("songxin/areab", ob->query("startroom"));
		me->set_temp("songxin/id", obj->query("id"));
		me->set_temp("songxin/where", get_place(me->query_temp("songxin/areab"))+me->query_temp("songxin/area"));
		me->set_temp("songxin/twice", get_place(base_name(environment(target)))+target->query("name"));
		where = me->query_temp("songxin/where");
		if (strlen(where) < 0)
			where = "\n"+CHINESE_D->font(me->query_temp("songxin/where"))+"\n";
		if (where == "����������ַ�����")
			where = me->query_temp("songxin/where");
		
			
		message_vision(HIY"$N˳�������Ϲ����˼��£�Ȼ������ŷ⣬�ֽ�������$n��\n"NOR, target, me);
		tell_object(me, GRN+target->name()+"����Ķ�������˵������Ͻ������͵���"+HIY+where+GRN"���ġ�"+me->query_temp("songxin/target_name")+GRN"�����ϡ�\n"NOR);
		
		if (me->query("bonus/����") >= SX_JOB_ROUND || !me->query("bonus/����") || me->query("bonus/����")<1 )
		{
			if (me->query("bonus/����") == SX_JOB_ROUND)
				me->set("bonus/����",4);
			else
				me->set("bonus/����",1);
		}
		else
			me->add("bonus/����",1);  
			
		switch ((int)me->query("bonus/����"))
	       	{
	       		case 1:
	       			tell_object(me, GRN+target->name()+"����Ķ�������˵���������и��书�������" + BLU + "΢�����" + GRN + "�ļһ�Ҫ��������ţ���Ӧ�����Ը����¾Ϳ����˰ɡ�\n"NOR);
	       		break;
	       		case 2:
	       			tell_object(me, GRN+target->name()+"����Ķ�������˵���������и��书�������" + HIB + "������" + GRN + "�ļһ�Ҫ��������ţ��㼰ʱ�͵�Ӧ��û����ɡ�\n"NOR);
	       		break;
	       		case 3:
	       			tell_object(me, GRN+target->name()+"����Ķ�������˵���������и��书�������" + CYN + "С������" + GRN + "�ļһ�Ҫ��������ţ���һ·С�ı��ǡ�\n"NOR);
	       		break;
	       		case 4:
	       			tell_object(me, GRN+target->name()+"����Ķ�������˵���������и��书�������" + HIC + "�ڻ��ͨ" + GRN + "�ļһ�Ҫ��������ţ���ɵ�С�ĶԸ�Ŷ��\n"NOR);
	       		break;
	       		case 5..7:
	       			tell_object(me, GRN+target->name()+"����Ķ�������˵���������и��书�������" + HIC + "��Ϊ�˵�" + GRN + "�ļһ�Ҫ��������ţ���ҪС�ĵ�Ŷ��\n"NOR);
	       		break;
	       		
	       		case 8..9:
	       			tell_object(me, GRN+target->name()+"����Ķ�������˵���������и��书�������" + HIW + "��������" + GRN + "�ļһ�Ҫ��������ţ���ɵ�С��Ӧ����\n"NOR);
	       		break;
	       		case 10:
	       			tell_object(me, GRN+target->name()+"����Ķ�������˵���������и��书�������" + HIR + "���뻯��" + GRN + "�ļһ�Ҫ��������ţ��򲻹��ɲ�Ҫ���ܡ�\n"NOR);
	       	}
	       		
		tell_room( environment(me), target->name() + "��" + me->name() + "����С����˵��Щ����\n", ({ target, me }) );
		write("�����ѡ��ͬ����߷�������(no)��\n");
		add_action("do_no", "no");
		if(target->query("no_quest")) destruct(target);
		me->delete_temp("songxin/other");
		remove_call_out("dest");
		call_out("dest", random(200)+1200);
	}
	return 1;
}

int do_no()
{
	object me = this_player();

	message_vision("$N���˿��ţ��������ǲ�ȥ�ˡ�\n", me);
	me->clear_condition("job_busy");
	me->clear_condition("dali_songxin");
	me->delete_temp("zuji");
	me->delete_temp("songxin_zuji");

	me->delete_temp("dali_songxin");
	me->delete_temp("songxin/time");
	me->delete_temp("songxin/times");
	me->delete_temp("songxin/area");
	me->delete_temp("songxin/target_name");
	me->delete_temp("songxin/where");
	me->delete_temp("letter_steal");
	me->set_temp("songxin_ok",1);
	me->set("job_name", "��������");
	me->delete_temp("songxin/twice");
	
	me->add("bonus/����",-3);
	
	if (other) {
		destruct(other);
	}
	destruct(this_object());
	return 1;
}

void dest()
{
	message_vision("$N��Ȼ������·�ϲ����ˡ�\n", this_object());
	destruct(this_object());
}

string *no_kill_list = ({
	"mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

int check(object ob)
{
	object room;
	string room_name, start_room;

	if (!objectp(ob)
	|| userp(ob)
	|| ob->query("env/invisibility")
	|| ob->query("no_quest")
	|| member_array(ob->query("id"), no_kill_list) != -1
	|| ob->query("attitude")=="aggressive"
	|| ob->query("have_master")
	|| !(start_room = ob->query("startroom"))	// add by Yuj@SJ to void job NPC
	|| !objectp(room=environment(ob))
	|| room->query("no_fight")
	|| room->query("quest")
	|| room->query("outdoors") == "���ش��"
	|| strsrch(room_name = base_name(room), "/d/") != 0
	|| ob->query("lastroom") == room_name && start_room != room_name
	|| start_room[0..5] != room_name[0..5]
	|| strsrch(room_name, "/d/wizard/") == 0
	|| strsrch(room_name, "/d/wuguan/") == 0
	|| strsrch(room_name, "/d/death/") == 0
	|| strsrch(room_name, "/d/mingjiao/bhd/") == 0
	|| strsrch(room_name, "/d/mingjiao/lsd/") == 0
	|| strsrch(room_name, "/d/group/") == 0
	|| strsrch(room_name, "/d/shaolin/fumoquan") == 0
	|| strsrch(room_name, "/d/baituo/") == 0 )
		return 0;
	return 1;
}

int move(mixed dest, int silently)
{
	int i;
		
	i = ::move(dest, silently);
	if(i && stringp(this_object()->query("ever_owner"))){
		this_object()->set("owner",this_object()->query("ever_owner"));
		remove_call_out("delete_owner");
		call_out("delete_owner",90+random(30));
	}
	return i;
}
                                                                                                                                     
