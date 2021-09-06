// ���� by River@SJ 2002.6.5

inherit NPC;
#include <ansi.h>

string ask_me();
string ask_question();

void create()
{
	set_name("����", ({ "shu sheng", "shu", "sheng" }) );
	set("long", "����ͷ����ң���ֻ��۵��ȣ����һ����ڵĳ��룬ȷ�Ǹ���ѧ����ģ����\n");
	set("gender", "����" );
	set("age", 45);
	set("str", 25);
	set("con", 25);
	set("dex", 30);
	set("int", 30);
	set("per", 28);
	set("unique", 1);
	set("attitude", "friendly");

	set("max_qi", 5000);
	set("max_jing", 2800);
	set("eff_jingli", 3600);
	set("neili", 8000);
	set("qi", 5000);
	set("jingli", 3600);
	set("max_neili", 8000);
	set("jiali", 50);

	set("combat_exp", 2300000);
	set("score", 5000);

	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("sword", 280);
	set_skill("literate", 200);
	set_skill("qiantian-yiyang", 280);
	set_skill("duanjia-jianfa", 280);
	set_skill("tianlong-xiang", 280);
	set_skill("finger", 280);
	set_skill("yiyang-zhi", 280);
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "duanjia-jianfa");
	map_skill("force", "qiantian-yiyang");
	map_skill("finger", "yiyang-zhi");
	map_skill("sword","duanjia-jianfa");
	prepare_skill("finger","yiyang-zhi");

	set("inquiry", ([
		"һ�ƴ�ʦ" : (: ask_me :),
		"��Ŀ" : (: ask_question :),
	]));
	setup();

	carry_object(BINGQI_D("txs"))->wield();
	carry_object(ARMOR_D("b_cloth"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
}

void init()
{
	::init();
	add_action("do_answer", "answer");
}

string ask_me()
{
	object me = this_player();

	if ( me->query_temp("yideng/shusheng_pass"))
		return "��λ"+RANK_D->query_respect(me)+"����ʦ������ǰ�治Զ����ʯ���";

	if ( me->query_temp("yideng/ask_shusheng"))
		return "��ɻش�ĳ��ҵ����⣿";

	me->set_temp("yideng/ask_shusheng", 1);

	return "�ҳ�������Ŀ�����㣬���ǿ��ó����Ǿ�����ȥ����ʦ��������\n"+
		"һ�����У�ֻ����"+RANK_D->query_respect(me)+"��ԭ·��ȥ�ˡ�";
}

string ask_question()
{
	object me = this_player();

	if ( me->query_temp("yideng/shusheng_pass"))
		return "��λ"+RANK_D->query_respect(me)+"����ʦ������ǰ�治Զ����ʯ���";

	if ( ! me->query_temp("yideng/ask_shusheng"))
		return "��λ"+RANK_D->query_respect(me)+"������Ŀ������";

	if ( me->query_temp("yideng/quest_wait"))
		return "��λ"+RANK_D->query_respect(me)+"���ܴ���ҵ���Ŀ��";

	me->set_temp("yideng/quest_one", 1);
	me->set_temp("yideng/quest_wait", 1);
	return "������һ��ʫ��˵�������³������������ĸ��ֶ����㵹�²¿���\n\n"
		"\t\t�����̼����оã�һ��ʮ��ĥ���֡�\n"+
		"\t\t�ӻ�ͷ��һ֦�ᣬ��й���Ī¶�ڡ�\n"+
		"\t\tһ�����۴��綷��ȴ�ڰ봲�����С�\n"+
		"\t\t����ֱ���ҹڹ飬������Ŀ��֪��";
}

int do_answer(string arg)
{
	object me = this_player();

	if ( ! arg ) return 0;

	if ( !me->query_temp("yideng/quest_one")
	&& !me->query_temp("yideng/quest_two")
	&& !me->query_temp("yideng/quest_three")) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( me->query_temp("yideng/quest_one") && arg == "��δ״Ԫ"){
		me->delete_temp("yideng");
		message_vision(CYN"$N˵������������������һ����һ��һ����ʮ�����Ǹ��������֡����ӡ�����\n"+
			"�Ӻᡢ��ȥ���ڡ����Ǹ���δ���֡�����������ּӡ��󡯼�һ�㣬�Ǹ���״��\n"+
			"�֡����ꡯ�ҹڣ��Ǹ���Ԫ���֡���δ״Ԫ��ʧ��ʧ����ԭ����λ��δ�Ƶ�״\n"+
			"Ԫү����\n\n"NOR, me);
		command("look "+ me->query("id"));
		command("say �úã���Ȼ������һ�⣬����һ����������"+RANK_D->query_respect(me)+"�Զԡ�\n\n"
			"\t\t�����鵣�ǧ�ַ�ҡ�۵��ȡ�");
		me->set_temp("yideng/quest_two", 1);
		me->set_temp("yideng/ask_shusheng", 1);
		me->set_temp("yideng/quest_wait", 1);
		return 1;
	}
	if ( me->query_temp("yideng/quest_two") && arg == "˪���Ҷ�����Ź����ң��"){
		me->delete_temp("yideng");
		message_vision(CYN"$N��Ŀ�Ĺˣ�ֻ������ƽ������һ��СС��Ժ����ǰ��һ����������ʱ���½�\n"+
				"������ɽ�纮����Ҷ��Ȼ���˴�룬����һ����Ц�������ã��ҵ������ǣ�˪\n"+
				"���Ҷ�����Ź����ң����\n\n"NOR, me);
		command("haha");
		command("say �������������̹�������������֮����");
		command("say �һ���һ������"+RANK_D->query_respect(me)+"�Ը�������\n\n"
			"\t\t��ɪ���ã��˴���һ��ͷ�档");
		me->set_temp("yideng/quest_three", 1);
		me->set_temp("yideng/ask_shusheng", 1);
		me->set_temp("yideng/quest_wait", 1);
		return 1;
	}
	if ( me->query_temp("yideng/quest_three") && arg == "�������ˣ���С����Զǳ�"){
		me->delete_temp("yideng");
		message_vision(CYN"$N˵��������һ����һ����Ҫ�����桢�ԡ���������λ���Ҹ������ȣ�������\n"+
				"�ǣ��������ˣ���С����Զǳ�����\n"NOR, me);
		message_vision(CYN"\n$N�󾪣�վ������������һ�ӣ���$nһҾ���أ�˵���������°ݷ�������ת\n"+
				"���ݹ�Сȱ�ڣ���������ա���\n", this_object(), me);
		me->set_temp("yideng/shusheng_pass", 1);
		return 1;
	}
	command("shake");
	return 1;
}
