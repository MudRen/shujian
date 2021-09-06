/*
�°�web��runner
Linux
*/

inherit NPC;

#include <ansi.h>
#include <mudlib.h>
#include <database.h>

#define URLMSG(x) HIY"�����"+HIW+U+BBS_ADDR+"/runner.php?id="+x+NOR+HIY+"�ѿ��������ֺ���ĸ�������answer�ش�\n"NOR

object ob;
int timer = 0;

int is_corpse(){ return 1; }
void move_to_court(object ob);
void test_robot(object obj,int reward);
void question();
string makepasswd();

void create()
{
	set_name("����ɱ��", ({ "blade runner", "runner" }));

	set("gender", "����");
	set("age", 20);
	set("no_quest", 1);
	set("no_drop", 1);
	set("no_get", 1);
	set_temp("apply/long",
		({ "����һ��ר��׷�������˵Ļ���̽Ա��\n"
		"������û����Զ��ش����⣬��������������ɾ����\n"})
	);
	set_skill("dodge", 1000);
	set("max_qi", 10000);
	set("qi", 10000);
	set("max_jing", 10000);
	set("jing", 10000);

	set("combat_exp", 5000000);

	set("inquiry", ([
		"name": "�㻹�����й��򰡣�ר�Ļش�����ɣ�",
		"rumors": "��˵�л����˻��뱾MUD���ٺ٣��ҿ��ǻ��۽�ѽ��",
	]) );
	set("attitude", "friendly");
	set("env/invisibility", 1);

	setup();
	set_weight(0);
}

void init()
{
	if (environment() == ob) {
		question();
		add_action("do_answer", ({ "answer" }));

		add_action("wait",
			({
			"beep", "chat", "chat*",
			"irc", "irc*","mm",
			"party", "party*", "quit",
			"reply", "rumor", "rumor*",
			"group","group*",
			"sr","sr*",
			"say", "sj",  "tell", "to", "whisper",
			})
		);
	}
}

int wait()
{
	//return 0;
	write("�Բ���������ɱ���ж��ڼ�,�㲻�����������,���Ȼش����⡣\n");
	return 1;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��ɥ�ط�������ɱ�ָ����������ս����\n", ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say("����ɱ����Ц��˵�������޵в����棡\n");
	command("hehe");
}

void die()
{
	unconcious();
}

void give_reward(object ob)
{
	mapping skills, skls = ([]), skls2 = ([]);
	int sn,sn2, lvl = 0;
	string skill;
	string* quest_skill = ({ "jiuyin-zhengong","hamagong", "kuihua-xinfa" });
	
	if (ob->query("registered") < 3) return;
	switch (ob->add_temp("robot_check_pass", 1)) {
		case 1:
			skills = ob->query_skills();
			if (!(sn = sizeof(skills))) break;
			sn2 = sn;
			foreach (skill, int val in skills) {
				if ( SKILL_D(skill)->type() == "martial"
				|| (sn2>5 && SKILL_D(skill)->type2()=="worker") ) {
					skls2 += ([ skill : val ]);
					lvl += val;
				} else sn--;
			}
			if (!sn) break;
			lvl /= sn;
			foreach (skill, int val in skls2) {
				if (val >= 0) {
					skls += ([ skill : val ]);
				}
			}
			
			sn = random(sizeof(skls));
			skill = keys(skls)[sn];			
			
			while( member_array(skill,quest_skill)!= -1 || SKILL_D(skill)->type2() == "worker" )
			{
				sn = random(sizeof(skls));
				skill = keys(skls)[sn];
			}
						
			lvl = values(skls)[sn];
			lvl *= lvl/2;
			lvl = lvl/2 + random(lvl/2);
			
			if( SKILL_D(skill)->type2() == "worker" ) {
				if( values(skls)[sn] > 300 )
					lvl = lvl / 3;
				else if( values(skls)[sn] > 200 )
					lvl = lvl / 2;
			}
			
			write("������"+chinese_number(lvl)+"�㡸"+to_chinese(skill)+"���Ľ�����\n");
			ob->improve_skill(skill, lvl, 1);
			log_file("static/ROBOT",
				sprintf("%s(%s)ͨ����飬���� %s %d��\n",
					ob->query("name"), ob->query("id"), skill, lvl
				), ob
			);
			break;
		case 2:
			lvl = 500 + random(500);
			write("������"+chinese_number(lvl)+"�㾭��Ľ�����\n");
			ob->add("combat_exp", lvl);
			log_file("static/ROBOT",
				sprintf("%s(%s)ͨ����飬���� exp %d��\n",
					ob->query("name"), ob->query("id"), lvl
				), ob
			);
		default:
			ob->delete_temp("robot_check_pass");
	}
}

void move_to_court(object ob)
{
	object me=this_object();
	ob->delete_temp("robot_check_pass");
	ob->apply_condition("robot", 15);
	
	ob->delete_temp("robot_test");	
	ob->set("iamrobot",1);
	ob->add("iamrobottime",1);
	if (ob->is_vip())
	if (me->query("reward")) ob->set_temp("robot_prize",1);
	message_vision("ϵͳ�ж�$nΪ�����ˣ�����ʱ������"HIY"robot"NOR"���������ٻ�����ɱ�ְ��Լ���robot״̬ȡ������\n", this_object(), ob);	
}

void test1()
{
	object me = this_object();

	if (ob) {
		timer -= 10;
		if (timer > 0) {
			message("channel", "����ɱ��˵�����㻹��" + chinese_number(timer) + "���ӵĿ���ʱ�䡣\n", ob);
			me->move(ob, 1);
			call_out("test1", 10);
		} else {
			if (!interactive(ob) || query_idle(ob) >= 170) {

				//"/cmds/usr/quit"->main(ob);
				move_to_court(ob);
				if (me) destruct(me);
			} else {
				// ��ֹplayer�����ε���bug. snowman@SJ 12/06/2000.
				//if (!living(ob)) ob->revive(1);
				message_vision(
					query("name")+"̾�˿�������$Nһ�㷴Ӧ��û�У�����һ���������ӷ���\n", ob
				);
				move_to_court(ob);
				destruct(me);
			}
		}
	}
	else destruct(me);
}

/*
void test_player(string player)
{
	object ob = find_player(player);

	if (ob) test_robot(ob);
}
*/
int aflag;
int num = 2;
string ans="";
string ans1;

string query_id()
{
	string id;
	
	if(!ob) return 0;
	
	id = ob->query("id");
	if(strsrch(id,"@")==-1) id += "@"+lower_case(INTERMUD_MUD_NAME);
	
	return id;
}

void question()
{
	message("channel", URLMSG(query_id())+"\n", ob);
	aflag = 1;
}

int do_answer(string arg)
{
	object me = this_object();
	int len = strlen(ans);

	if (arg) {
		int i = strlen(arg);

		while (i--)
			if (arg[i] == ' ')
				arg = arg[0..i-1] + arg[i+1..<1];
	} else
		arg = "";
	if (strlen(arg) != len)
		return notify_fail("�𰸵ĳ��Ȳ��ԣ�����ϸ������\n");
	if (aflag) {
		aflag = 0;
		if (ans1 == arg) {
			command("wiz "+ob->query("id")+" ������ʹ�����Զ�Ӧ������ˣ����飡");
			return notify_fail("�𰸲��ԣ�����ϸ������\n");
		}
		ans1 = arg;
	}
	if (arg==ans) {
		message_vision("$N���˵�ͷ��˵����OK��$n����æ�ɡ�\n", me, ob);
		ob->delete("iamrobot");
		if(ob->query_temp("robot_try"))
		ob->delete_temp("robot_try");
		//ɾ��robot test���
		ob->delete_temp("robot_test");
		if (me->query("reward")) give_reward(ob);
		message_vision("$NͻȻ��ʧ�����ˡ�\n", me);
	} else {
		if(query("failed") > 10)
		{
			message_vision("$N̾�˿�����������10�ζ��ش������϶��ǻ����ˣ�\n", me);
			move_to_court(ob);
			destruct(this_object());
			return 1;			
		}
		if (num--){
			add("failed",1);
			return notify_fail("�𰸲��ԣ�����ϸ������\n");
		}
		
		message_vision("$N̾�˿�������"+arg+"��"+ans+"�Ŷԣ���ô�򵥶��𲻳����϶��ǻ����ˣ�\n", me);
		move_to_court(ob);
	}
	destruct(this_object());
	return 1;
}

void test_robot(object obj,int reward)
{	
	object me = this_object();
	string prize;
	//int temp;

	ob = obj;
	
	if (reward) 
		prize="�н���.";
	else
		prize="�޽���.";
	if (environment(ob) && !ob->is_fighting() && interactive(ob) ) {
		//len = 4 + random(2);
		//Ŀǰ�ݶ�4λ��֤��
		ans = makepasswd();
		
		/*temp = random(1) + 4;
		while (temp--) {
			ans += "0";
			ans[<1] += random(10);
		}*/
		// reward 1 �Ļ�����ʾ��runner�������
		if (reward)
		{
			me->set("reward",1);
		}
		message("wizard:linux",sprintf(HIY"%-8s �Ļ����˼����� %s, %s\n"NOR,ob->query("id"),ans,prize),users());
		timer = 180;		
		if(!BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,"UPDATE members SET runner_code = '"+ans+"',mud_ip='"+query_ip_number(ob)+"' WHERE username = '"+query_id()+"' limit 1",this_object(),"bbs_ok",1))
			CHANNEL_D->do_channel( me, "sys", ob->name(1)+"("+capitalize(getuid(ob))+")������𰸱���̳�ܾ����ܡ�");
	} else destruct(me);
}

void bbs_ok(mixed ret)
{
	if(!clonep()) return;
	
	if(!ob)
	{
		destruct(this_object());
		return;
	}
	message("channel", HIM"����ɱ���Դ�Ǹ���˵���������˻��飬���й��£���ش�һ��С���⡣��\n", ob);
	message("channel", "��������ڻ������������������ȫ����ᣬ�������Ϸû���κ�Ӱ�졣\n", ob);
	message("channel", "������������ڵ���ǰ���밴������ɱ������ʾ�Ľ��в������������õĽ�������ȽϷ��\n", ob);
	this_object()->set("target",ob->query("id"));
	//��ǰ�жϱ�ǣ���ʾ�������ڲ���
	ob->set_temp("robot_test",1);
	call_out("test1", 10);
	move(ob, 1);
}

string seed = "123456789";

string makepasswd()
{
	int i = 4, j;
	string id = "";

	while (i--) {
		j = random(strlen(seed));
		id += seed[j..j];
	}
	return id;
}

public string query_version(object ob)
{
	if(ob==find_object(BBS_D)) return "1.0";
}