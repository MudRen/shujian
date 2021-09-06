#include <ansi.h>
#include <job_mul.h>

int level = 10;
int my_learned = 0;

string *my_skills = ({
	"jimie-zhua", "mohe-zhi",
	"longzhua-gong", "yizhi-chan",
	"fengyun-shou", "shaolin-tantui",
	"banruo-zhang", "jingang-quan",
	"sanhua-zhang", "nianhua-zhi",
	"qianye-shou", "ruying-suixingtui"
});

mapping mpto =
([
	"jimie-zhua":"claw",
	"mohe-zhi":"finger",
	"yizhi-chan":"finger",
	"longzhua-gong":"claw",	
	"fengyun-shou":"hand",
	"shaolin-tantui":"leg",
	"banruo-zhang":"strike",
	"jingang-quan":"cuff",
	"sanhua-zhang":"strike",
	"nianhua-zhi":"finger",
	"qianye-shou":"hand",
	"ruying-suixingtui":"leg",
]);

string *names1 = ({
"/d/shaolin/fatang",  "/d/shaolin/sblu-3", "/d/shaolin/jietan2",
"/d/shaolin/xiaolu5", "/d/shaolin/fzjs2",  "/d/shaolin/xiaolu2",
"/d/shaolin/bydian",  "/d/shaolin/dzdian", "/d/shaolin/putiyuan",
"/d/shaolin/fota3",   "/d/shaolin/zhlou7", "/d/shaolin/gulou7",
"/d/shaolin/qyping",  "/d/shaolin/celang1", "/d/shaolin/celang2",
"/d/shaolin/gchange", "/d/shaolin/gchangw", "/d/shaolin/shifang",
"/d/shaolin/fxjing",  "/d/shaolin/damodong","/d/shaolin/lhtang",
"/d/shaolin/brtang",  "/d/shaolin/smdian", "/d/shaolin/zhlou7",
"/d/shaolin/gulou7",  "/d/shaolin/houdian", "/d/shaolin/zdyuan",
"/d/shaolin/pingtai", "/d/shaolin/putiyuan", "/d/shaolin/yaowang",
"/d/shaolin/xumidian","/d/shaolin/liuzu",   "/d/shaolin/jnlwang",
"/d/shaolin/lxting",  "/d/shaolin/qfdian",  "/d/shaolin/czan",
"/d/shaolin/bydian",  "/d/shaolin/dzdian",  "/d/shaolin/xcping",
"/d/shaolin/cjlou"
});

void init()
{
	object ob;
	this_object()->set("no_get",1);

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_teach", "teach");
}

mixed ask_me()
{
	object fighter;
	string skill_name, skill_id;
	int i;

	fighter = this_player();

	if (!fighter->query_condition("lh_job")) return "����ɲ�����˵��";
	if (query("teacher") && query("teacher") != fighter) {
		if (fighter->query_temp("ask_monk") == 1) {
			fighter->set_temp("ask_monk", 2);
			command("mimi "+query("id"));
			return 1;
		}
		if (fighter->query_temp("ask_monk") == 2) {
			fighter->set_temp("ask_monk", 3);
			command("mimi2 "+fighter->query("id"));
			return 1;
		}
		command("mimi "+fighter->query("id"));
		fighter->set_temp("ask_monk", 1);
		return 1;
	}
	if (!query("learn")) {
		i=random(sizeof(my_skills));
		skill_id=my_skills[i];
		skill_name=to_chinese(skill_id);
		set("learn",skill_name);
		set("nickname",skill_name);
		set("skill",skill_id);
		set_skill(skill_id, 1);
	}
	if (!query("teacher")) level = 10;
	return "Сɮ��ѧ"+query("learn")+"���Ѿ�����" + chinese_number(level) + "��������ָ��(teach monk)��";
}

void relay_emote(object me, string arg)
{
	if (arg != "admit") return;
	if (me->query_temp("ask_monk") > 2 && query("teacher") && query("teacher") != me) {
		me->delete_temp("ask_monk");
		command("callname "+query("id"));
		command("say Сɮ��ѧ"+query("learn")+"���Ѿ�����" + chinese_number(level) + "����");
		return;
	}
	command("wuwu "+me->query("id"));
}

int do_teach(string arg)
{
	object me = this_object(), teacher, ob;
	string my_skill, where, na;
	int gin_cost, exp,pot;

	teacher=this_player();
	if (arg != "monk") return notify_fail("��Ҫ��ʲô?\n");
	if (!query("skill")) return notify_fail("��������ѧʲô����?\n");
	if (query("teacher") && query("teacher") != teacher) {
		command("say ������"+ query("teacher")->name(1) + "("
			+ capitalize(query("teacher")->query("id")) + ")�����أ�");
		return 1;
	}
	if (!teacher->query_condition("lh_job")) return notify_fail("�㻹����ȥ�����Ѵ�ʦ�����к��ɡ�\n");
	if (!query("teacher")) {
		level = 10;
		my_learned = 0;
	}
	my_skill = query("skill");
	if (level > teacher->query_skill(my_skill,1)) return notify_fail("�����Ϊ���������أ�������ң���\n");
	if (teacher->is_busy()) return notify_fail("����æ���ء�\n");
	if (is_busy()) return notify_fail(name()+"��æ���ء�\n");
	foreach(object item in all_inventory(environment())) {
		if (item != teacher && userp(item) && !wizardp(item) && !random(3)) {
			tell_room(environment(), teacher->name()+"һ���������͡��˼��˰������ӡ�\n", teacher);
			return notify_fail(item->name()+"�����Աߣ����޷�ר��ָ�㡣\n");
		}
	}
	if (!query("teacher")) set("teacher", teacher);
	gin_cost = 300 / query("int");
	if (!living(this_object()) || query("jing") < gin_cost*3) {
		write(name()+"̫���ˣ�����û�а취ѧ��\n");
		return 1;
	}
	if (!random(5)) tell_room(environment(), teacher->name() + "������" + name() + "ָ���书��\n", teacher);
	write("�㾡�Ľ�������" + name() + "ָ��" + query("learn") + "�ĵ���\n");
	if (teacher->query("jing") < gin_cost*2) {
		message_vision("$N���۹��ȣ�������Щ��㱡�\n", teacher);
		teacher->unconcious();
		return 1;
	}
	receive_damage("jing", gin_cost*3);
	teacher->receive_damage("jing", gin_cost*2);
	me->add_skill(my_skill, me->query_int() / 4 + random(teacher->query_int() * 5 / 3) + random(level * 2 / 3 ));
	if (random(10) < 6) {
		tell_object(teacher,"�ڽ�" + me->name() + "�Ĺ����У���Ҳ������һЩ" + me->query("learn") + "�����\n");
		teacher->improve_skill(my_skill, teacher->query_int() / 5 + random(teacher->query_int() * 5 / 6));
	}
	exp = level / 10 + 1;
	if (exp < 5) teacher->add("potential",random(2));
	if(exp >= 10) exp = 6+random(5);
	exp += random(exp/2);
	pot = exp / 6 + random(exp / 10);
	exp = random(exp);
		
	exp = teacher->add_exp_combat(exp,this_object(),"���ֽ̺���",1);
	//teacher->add("combat_exp",exp );
	teacher->add("potential",pot );
			
	if (teacher->query("potential") > teacher->query("max_pot"))
		teacher->set("potential", teacher->query("max_pot"));
	if ( random(level) > 20	 && !teacher->query_temp("meetmotou")){
		where = names1[random(sizeof(names1))];
		tell_room(environment(), HIC"һ���������������������͵��������ͼı���죡\n"NOR);
		message_vision(HIY + "$N������ܣ�һ�������"+where->query("short")+"��ȥ��\n" NOR, me);
                teacher->set_temp("meetmotou", 1);
		na = teacher->query("id");
		ob=new(__DIR__"motou");
		ob->move(where);
		ob->set_temp("killer", na);
		me->set("place", base_name(environment()));
		me->delete("startroom");
		me->move(where);
		remove_call_out("waiting");
		call_out("waiting", 1, me, 0);
		return 1;
	}
	teacher->start_busy(random(3));
	me->start_busy(random(3));
	return 1;
}

void waiting(object me,int wait_time)
{
	object teacher;
	string place;

	if (wait_time >= 100 || !query("teacher")) {
		message_vision(HIY + "$N�˺����ۣ��Ѿ�֧�ֲ�ס�ˣ�\n" NOR, me);
		me->die();
		return;
	}
	if (!objectp(teacher = present(query("teacher"), environment(me)))) {
		remove_call_out("waiting");
		call_out("waiting", 1, me, wait_time + 1);
		return;
	}
	message_vision(HIC "$N�Ѿ�ƣ��������$n����ϲ�����⣬ת���뿪ս����\n"NOR, me, teacher);
	place = me->query("place");
	me->move(place);
	me->set("startroom", place);
	message_vision(BLU"һ����ɫ�Ұ��������׹�Ĵ�һ����ס$N��˵����С�������ˣ��ϵı����ӣ�\n"NOR, teacher);
	teacher->start_busy(random(3));
}

void add_skill(string skill, int amount, int weak_mode)
{
	my_learned += amount;

	if (my_learned > (level + 1) * (level + 1)) {
		level++;
		my_learned = 0;
		set_skill(skill, level);
		set_skill(mpto[skill],level);
		map_skill(mpto[skill],skill);
		prepare_skill(mpto[skill],skill);
		message_vision("$Nץ��������һ��ϲ���Խ������ӡ�\n", this_object());
	}
}

void greeting(object ob)
{
	object me;

	me = this_object();
	if ( !ob || environment(ob) != environment() ) return;
	if (me->visible(ob) && interactive(ob) && ob->query_condition("lh_job") && !me->query("teacher"))
		say(me->name()+"˵������λ����ָ��Сɮ����?\n");
}

int query_level(int lvl)
{
	if(lvl) level = lvl;
	return level;
}

void unconcious()
{
	object ob=this_object(), me;

	me = ob->query_temp("last_damage_from");
	if (objectp(me))
		if (me != query("teacher"))
			command("party "+me->query("name")+"�����ɱ�ң�"
				+(query("teacher")?query("teacher")->query("name")+"�����ұ��𰡣�":""));
		else
			command("party* ghostlove "+me->query("id"));
	::unconcious();
}

void die()
{
	object ob=this_object(), me;

	me = ob->query_temp("last_damage_from");
	if (objectp(me))
		if (me != query("teacher"))
			command("party "+me->query("name")+"�����ɱ�ң�"
				+(query("teacher")?query("teacher")->query("name")+"�����ұ��𰡣�":""));
		else
			command("party* ghostlove "+me->query("id"));
	::die();
}
