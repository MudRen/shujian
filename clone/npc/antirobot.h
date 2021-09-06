// YUJ@SJ ��Ȩ����

object ob;
int timer = 0;

int is_corpse(){ return 1; }
void move_to_court(object ob);
void test_robot(object obj);
void question();

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
			"ask", "beep", "chat", "chat*", "emote", "exercise",
			"irc", "irc*",  "learn", "lingwu", "mm",
			"party", "party*", "post", "practice", "quit",
			"reply", "respirate", "rumor", "rumor*",
			"say", "sj", "study", "sleep",
			"teach", "team", "tell", "to", "whisper",
			})
		);
	}
}

int wait()
{
	write("�Բ������Ȼش����⡣\n");
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
	string room;
	int times, times2;

	ob->delete_temp("robot_check_pass");
	ob->apply_condition("robot", 15);
	message_vision("$N��$n��ȥ�˷�ͥ��\n", this_object(), ob);
	if (!stringp(room = base_name(environment(ob)))	|| environment(ob)->query("no_save")) {
		if (ob->query("enter_wuguan"))
			room = "/d/wuguan/dayuan";
		else    room = "/d/city/chmiao";
	}
	if (ob->query("robot") < 2) {
		ob->set("catch_robot_place", room);
		ob->move("/d/wizard/robot_court");
		tell_object(ob,"���Ѿ��ۼƱ�����ɱ��ץ�ͻ����˷�ͥ"+chinese_number(ob->add("robot",1))+"���ˡ�\n");
	}
	else {
		ob->delete("robot");
		times2 = times = ob->add("rules",1);
		if (times2 > 3 && ob->query("registered") == 3)
			times2 = 3;

		ob->set("relax_timeout_room",room);
		ob->apply_condition("relax", times2*30);

		message("channel", HIW "\n�����ɡ�"+ob->query("name")+"("+capitalize(ob->query("id"))
			+")��Ϊ�������ˡ���Υ���齣��Ϸ���򹲼�" +chinese_number(times)
			+ "�Σ���������ؽ���"+chinese_number(times2*10)+"���ӵĴ�����\n\n" NOR, users());

		tell_object(ob, "����ɱ�ְ���ֱ��ץ�����һ�Դ��\n");
		ob->move("/d/wizard/relax");
		log_file("static/ROBOT",
			sprintf("%s(%s)��Ϊ�����˱��ؽ��գ�����Υ�� %d �Ρ�\n",
				ob->query("name"), ob->query("id"), times
			), ob
		);
	}
}

void test1()
{
	object me = this_object();

	if (ob) {
		timer -= 10;
		if (timer > 0) {
			message("channel", "����ɱ�־����㣺�㻹��" + chinese_number(timer) + "���ӵĿ���ʱ�䡣\n", ob);
			me->move(ob, 1);
			call_out("test1", 10);
		} else {
			if (!interactive(ob) || query_idle(ob) >= 170) {
				"/cmds/usr/quit"->main(ob);
				if (me) destruct(me);
			} else {
				// ��ֹplayer�����ε���bug. snowman@SJ 12/06/2000.
				if (!living(ob)) ob->revive(1);
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

void test_player(string player)
{
	object ob = find_player(player);

	if (ob) test_robot(ob);
}
